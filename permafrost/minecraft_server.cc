#include "minecraft_server.h"

#include <iostream>

namespace permafrost {

void MinecraftServer::Start() {
  try {
    net_server_.Start({ asio::ip::tcp::v4(), 25565 });
  } catch (const std::exception& ex) {
    std::cerr << ex.what() << '\n';
  }
}

}  // namespace permafrost
