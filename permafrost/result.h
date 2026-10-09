#ifndef PERMAFROST_RESULT_H_
#define PERMAFROST_RESULT_H_

#include <expected>

namespace permafrost {
  
template <typename T, typename E>
using Result = std::expected<T, E>;

template <typename E>
constexpr auto MakeError(E&& error) {
  return std::unexpected<std::remove_cvref_t<E>>(std::forward<E>(error));
}

}  // namespace permafrost

#endif  // PERMAFROST_RESULT_H_
