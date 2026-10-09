#ifndef PERMAFROST_IO_MEMORY_READER_H_
#define PERMAFROST_IO_MEMORY_READER_H_

#include <span>
#include <cstdint>

#include "result.h"

namespace permafrost {

class MemoryReader {
 public:
  explicit MemoryReader(std::span<const std::uint8_t> buffer)
      : buffer_(buffer) {}

  IoResult<std::size_t> Peek(void* buffer, std::size_t n_bytes);
  IoResult<std::size_t> Read(void* buffer, std::size_t n_bytes);

  IoResult<void> ReadExact(void* buffer, std::size_t n_bytes);

  IoResult<std::uint8_t> PeekByte();
  IoResult<std::uint8_t> ReadByte();

  std::size_t Position() const { return position_; }
  bool SetPosition(std::size_t new_pos);

 private:
  std::span<const std::uint8_t> buffer_;
  std::size_t position_ = 0;
};

}  // namespace permafrost

#endif  // PERMAFROST_IO_MEMORY_READER_H_
