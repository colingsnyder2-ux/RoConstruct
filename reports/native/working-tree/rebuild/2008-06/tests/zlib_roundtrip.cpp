// zlib: compress and uncompress 64 KB of patterned data; the bytes must survive.
#include "zlib.h"
#include <stdio.h>
#include <string.h>

static unsigned char input[65536], packed[70000], output[65536];

int main()
{
    for (unsigned i = 0; i < sizeof(input); ++i)
        input[i] = (unsigned char)((i * 7) ^ (i >> 5));
    uLongf packedSize = sizeof(packed), outputSize = sizeof(output);
    if (compress2(packed, &packedSize, input, sizeof(input), 9) != Z_OK)
        return printf("compress failed\n"), 2;
    if (uncompress(output, &outputSize, packed, packedSize) != Z_OK || outputSize != sizeof(input))
        return printf("uncompress failed\n"), 3;
    int same = memcmp(input, output, sizeof(input)) == 0;
    printf("zlib %s packed=%lu same=%d\n", zlibVersion(), (unsigned long)packedSize, same);
    return same && strcmp(zlibVersion(), "1.2.3") == 0 ? 0 : 1;
}
