#ifndef PERMAFROST_IO_RESULT_H_
#define PERMAFROST_IO_RESULT_H_

#include "permafrost/result.h"

#include "error.h"

namespace permafrost {

template <typename T>
using IoResult = Result<T, IoError>;

}  // namespace permafrost

#endif  // PERMAFROST_IO_RESULT_H_
