#ifndef PERMAFROST_NET_NETWORK_SERVER_H_
#define PERMAFROST_NET_NETWORK_SERVER_H_

#include <asio.hpp>

namespace permafrost {

class NetworkServer {
 public:
  explicit NetworkServer(asio::io_context& io_context)
      : io_context_(io_context) {}

  void Start(const asio::ip::tcp::endpoint& bind_address);

 private:
  void DoAccept();

  asio::io_context& io_context_;
  asio::ip::tcp::acceptor acceptor_{ io_context_ };
};

}  // namespace permafrost

#endif  // PERMAFROST_NET_NETWORK_SERVER_H_