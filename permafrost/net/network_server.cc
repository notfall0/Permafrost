#include "network_server.h"

#include <iostream>

#include "client_session.h"

namespace permafrost {

void NetworkServer::Start(const asio::ip::tcp::endpoint& bind_address) {
  acceptor_.open(bind_address.protocol());
  acceptor_.set_option(asio::socket_base::reuse_address{ true });
  acceptor_.bind(bind_address);
  acceptor_.listen();

  DoAccept();
  std::cout << "Listening on " << bind_address << "...\n";
  io_context_.run();
}

void NetworkServer::DoAccept() {
  acceptor_.async_accept([this](std::error_code error, asio::ip::tcp::socket socket) {
    if (!error) {
      std::cout << "Got a connection from " << socket.remote_endpoint() << '\n';

      auto session_ptr = std::make_shared<ClientSession>(std::move(socket));
      asio::co_spawn(io_context_, session_ptr->Run(), asio::detached);
    }

    DoAccept(); // Continue accepting
  });
}

}  // namespace permafrost
