#include "minecraft_reader.h"

namespace permafrost {

IoResult<std::uint8_t> MinecraftReader::ReadUByte() {
  return reader_.ReadByte();
}

IoResult<std::int8_t> MinecraftReader::ReadSByte() {
  auto result = reader_.ReadByte();
  if (!result) {
    return MakeError(result.error());
  }

  return static_cast<std::int8_t>(*result);
}

IoResult<std::int16_t> MinecraftReader::ReadShort() {
  std::uint8_t bytes[2];

  auto result = reader_.ReadExact(bytes, sizeof(bytes));
  if (!result) {
    return MakeError(result.error());
  }

  std::uint16_t out = (static_cast<std::uint16_t>(bytes[0]) << 8)
      | static_cast<std::uint16_t>(bytes[1]);

  return static_cast<std::int16_t>(out);
}

IoResult<MinecraftString> MinecraftReader::ReadString() {
  std::array<char, MinecraftString::kSize> data{};

  auto result = reader_.ReadExact(data.data(), data.size());
  if (!result) {
    return MakeError(result.error());
  }

  return IoResult<MinecraftString>{ MinecraftString{ std::move(data) } };
}

}  // namespace permafrost
