#ifndef PERMAFROST_MINECRART_SERVER_H_
#define PERMAFROST_MINECRART_SERVER_H_

#include <asio.hpp>

#include "net/network_server.h"

namespace permafrost {

class MinecraftServer {
 public:
  void Start();

 private:
  asio::io_context io_context_;
  NetworkServer net_server_{ io_context_ };
};

}  // namespace permafrost

#endif  // PERMAFROST_MINECRART_SERVER_H_
