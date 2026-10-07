add_library(asio INTERFACE)
target_include_directories(asio INTERFACE ${VENDOR_DIR}/asio/include)
target_compile_definitions(asio INTERFACE ASIO_STANDALONE)
