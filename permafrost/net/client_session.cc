#include "client_session.h"

#include <iostream>

#include "permafrost/protocol/minecraft_reader.h"

namespace permafrost {

asio::awaitable<void> ClientSession::Run() {
  auto self = shared_from_this();
  try {
    while (alive_) {
      const std::size_t bytes_read =
          co_await socket_.async_read_some(asio::buffer(buffer_), asio::use_awaitable);

      auto slice = std::span{ buffer_ }.subspan(0, bytes_read);
      MemoryReader mem_reader(slice);
      MinecraftReader minecraft_reader(mem_reader);

      auto packet_id = minecraft_reader.ReadUByte();
      if (!packet_id) {
        continue;
      }

      if (*packet_id == 0x00) {
        auto protocol_version = minecraft_reader.ReadUByte();
        if (!protocol_version) {
          continue;
        }

        auto username = minecraft_reader.ReadString();
        if (!username) {
          continue;
        }

        auto verification_key = minecraft_reader.ReadString();
        if (!verification_key) {
          continue;
        }

        (void)minecraft_reader.ReadUByte();

        std::cout << static_cast<int>(*protocol_version) << ' '
            << username->ToTrimmedString() << ' '
            << verification_key->ToTrimmedString() << '\n';
      }
    }
  } catch (const std::system_error&) {
    alive_ = false;
  }
}

}  // namespace permafrost
