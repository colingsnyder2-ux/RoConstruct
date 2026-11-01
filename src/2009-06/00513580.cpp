// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string.h>
void CopyWords(unsigned int* dst, unsigned int n, const unsigned int* src)
{
    memcpy(dst, src, n * sizeof(unsigned int));
}
