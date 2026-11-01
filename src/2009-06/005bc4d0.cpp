// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /MD
#include <algorithm>
unsigned int clampit(unsigned int a, unsigned int b)
{
    unsigned int z = 0;
    return std::max(z, std::min(b, a));
}
