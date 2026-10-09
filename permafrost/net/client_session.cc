#include "client_session.h"

namespace permafrost {

asio::awaitable<void> ClientSession::Run() {
  auto self = shared_from_this();
  try {
    while (alive_) {
      const std::size_t bytes_read =
          co_await socket_.async_read_some(asio::buffer(buffer_), asio::use_awaitable);
    }
  } catch (const std::system_error&) {
    alive_ = false;
  }
}

}  // namespace permafrost
