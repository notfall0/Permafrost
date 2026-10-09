#ifndef PERMAFROST_NET_CLIENT_SESSION_H_
#define PERMAFROST_NET_CLIENT_SESSION_H_

#include <memory>
#include <array>
#include <cstdint>

#include <asio.hpp>

namespace permafrost {

class ClientSession : public std::enable_shared_from_this<ClientSession> {
 public:
  explicit ClientSession(asio::ip::tcp::socket socket)
      : socket_(std::move(socket)), alive_(true) {}

  asio::awaitable<void> Run();

 private:
  bool alive_ = false;
  asio::ip::tcp::socket socket_;
  std::array<std::uint8_t, 1024> buffer_;
};

}  // namespace permafrost

#endif  // PERMAFROST_NET_CLIENT_SESSION_H_
