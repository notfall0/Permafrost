add_library(permafrost_net STATIC
    network_server.h
    network_server.cc
    client_session.h
    client_session.cc)

target_link_libraries(permafrost_net PUBLIC asio)
