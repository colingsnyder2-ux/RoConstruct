// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <cstddef>

namespace RBX {
namespace RenderBase {
// INFERRED: free function 00553f90 (AggregateChunk) used by 007f2bd0.
int AggregateChunk(const char* name, int size);
}
}

void func_007f2bd0()
{
    *(volatile int*)0x00973ec4 = RBX::RenderBase::AggregateChunk((const char*)0x0080f7cc, 0xbb8);
}
