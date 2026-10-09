#ifndef PERMAFROST_PROTOCOL_MINECRAFT_READER_H_
#define PERMAFROST_PROTOCOL_MINECRAFT_READER_H_

#include "permafrost/io/memory_reader.h"

#include "minecraft_string.h"

namespace permafrost {

class MinecraftReader {
 public:
  explicit MinecraftReader(MemoryReader& reader)
      : reader_(reader) {}

  IoResult<std::uint8_t> ReadUByte();
  IoResult<std::int8_t> ReadSByte();
  IoResult<std::int16_t> ReadShort();
  IoResult<MinecraftString> ReadString();

 private:
  MemoryReader&  reader_;
};

}  // namespace permafrost

#endif  // PERMAFROST_PROTOCOL_MINECRAFT_READER_H_
