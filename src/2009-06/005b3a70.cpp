// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MD
#include <stdlib.h>

struct Key
{
    int a, b;
    unsigned int words[12];
};

class Hasher
{
public:
    unsigned int hashCode(const Key& key);
    long hash(const Key& key);
};

long Hasher::hash(const Key& key)
{
    long n = hashCode(key) & 0x7fffffff;
    ldiv_t p = ldiv(n, 127773);
    if ((p.rem = 16807 * p.rem - 2836 * p.quot) < 0)
        p.rem += 0x7fffffff;
    return p.rem;
}
