#ifndef PERMAFROST_PROTOCOL_MINECRAFT_STRING_H_
#define PERMAFROST_PROTOCOL_MINECRAFT_STRING_H_

#include <array>
#include <string_view>
#include <algorithm>
#include <ranges>

namespace permafrost {

class MinecraftString {
 public:
  static constexpr std::size_t kSize = 64;

  constexpr MinecraftString() noexcept { data_.fill(' '); }

  constexpr explicit MinecraftString(std::string_view text) noexcept {
    data_.fill(' ');
    std::copy_n(text.begin(), std::min(text.size(), kSize), data_.begin());
  }

  constexpr MinecraftString(const MinecraftString& other) noexcept {
    if (this != &other) {
      data_ = other.data_;
    }
  }

  constexpr MinecraftString(MinecraftString&& other) noexcept {
    if (this != &other) {
      data_ = std::move(other.data_);
      other.data_.fill(' ');
    }
  }

  constexpr explicit MinecraftString(std::array<char, kSize>&& data) noexcept
      : data_(std::move(data)) {}

  constexpr MinecraftString& operator=(const MinecraftString& other) noexcept {
    if (this != &other) {
      data_ = other.data_;
    }

    return *this;
  }

  constexpr MinecraftString& operator=(MinecraftString&& other) noexcept {
    if (this != &other) {
      data_ = std::move(other.data_);
      other.data_.fill(' ');
    }

    return *this;
  }

  constexpr MinecraftString& operator=(std::array<char, kSize>&& data) noexcept {
    data_ = std::move(data);
    return *this;
  }

  constexpr bool Empty() const noexcept {
    return std::ranges::all_of(data_, [](char c) {
      return c == ' ';
    });
  }

  constexpr std::string_view Data() const noexcept {
    return { data_.data(), data_.size() };
  }

  constexpr std::string_view ToTrimmedString() const noexcept {
    if (Empty()) {
      return {};
    }

    std::string_view string{ data_.data(), data_.size() };
    const std::size_t end_pos = string.find_last_not_of(' ');
    return string.substr(0, end_pos + 1);
  }

 private:
  std::array<char, kSize> data_;
};

}  // namespace permafrost

#endif  // PERMAFROST_PROTOCOL_MINECRAFT_STRING_H_
