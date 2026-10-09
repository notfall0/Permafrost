#ifndef PERMAFROST_IO_ERROR_H_
#define PERMAFROST_IO_ERROR_H_

#include <string_view>

namespace permafrost {

enum class IoError {
  kInvalidArgument,
  kEndOfStream
};

constexpr std::string_view IoErrorToString(IoError error) {
  using enum IoError;

  switch (error) {
    case kInvalidArgument: return "invalid argument";
    case kEndOfStream:     return "end of stream";
  }

  return "unknown error type";
}

}  // namespace permafrost

#endif  // PERMAFROST_IO_ERROR_H_
