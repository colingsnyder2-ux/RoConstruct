// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Table<TextureArgs,TextureRef> member ctor (alignedMalloc(0x28,0x10) + memset, 10 buckets) is inlined by the compiler.
#include "GLG3D/TextureManager.h"

namespace G3D {

TextureManager::TextureManager(size_t _sizeHint) : size(0), sizeHint(_sizeHint) {}

}
