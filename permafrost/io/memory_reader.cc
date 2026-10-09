#include "memory_reader.h"

#include <algorithm>
#include <cstring>

namespace permafrost {

IoResult<std::size_t> MemoryReader::Peek(void* buffer, std::size_t n_bytes) {
  if (!buffer && n_bytes != 0) {
    return MakeError(IoError::kInvalidArgument);
  }

  if (n_bytes == 0) {
    return 0;
  }

  if (position_ > buffer_.size()) {
    return MakeError(IoError::kEndOfStream);
  }

  std::size_t to_read = std::min(n_bytes, buffer_.size() - position_);
  std::memcpy(buffer, buffer_.data() + position_, to_read);
  return to_read;
}

IoResult<std::size_t> MemoryReader::Read(void* buffer, std::size_t n_bytes) {
  auto result = Peek(buffer, n_bytes);
  if (!result) {
    return result;
  }

  position_ += *result;
  return result;
}

IoResult<void> MemoryReader::ReadExact(void* buffer, std::size_t n_bytes) {
  if (!buffer && n_bytes != 0) {
    return MakeError(IoError::kInvalidArgument);
  }

  if (position_ > buffer_.size() || n_bytes > buffer_.size() - position_) {
    return MakeError(IoError::kEndOfStream);
  }

  if (n_bytes == 0) {
    return IoResult<void>{};
  }

  std::memcpy(buffer, buffer_.data() + position_, n_bytes);
  position_ += n_bytes;
  return IoResult<void>{};
}

IoResult<std::uint8_t> MemoryReader::PeekByte() {
  if (position_ >= buffer_.size()) {
    return MakeError(IoError::kEndOfStream);
  }

  return buffer_[position_];
}

IoResult<std::uint8_t> MemoryReader::ReadByte() {
  if (position_ >= buffer_.size()) {
    return MakeError(IoError::kEndOfStream);
  }

  return buffer_[position_++];
}

bool MemoryReader::SetPosition(std::size_t new_pos) {
  if (new_pos > buffer_.size()) {
    return false;
  }

  position_ = new_pos;
  return true;
}

}  // namespace permafrost
