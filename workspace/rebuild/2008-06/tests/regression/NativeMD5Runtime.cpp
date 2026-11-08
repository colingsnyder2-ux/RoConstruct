#include "util/MD5Hasher2008.h"
#include <sstream>
#include <stdio.h>
#include <string.h>

int nativeMD5RuntimeSelfTest()
{
    const char* inputs[] = {"", "a", "abc", "message digest", "abcdefghijklmnopqrstuvwxyz"};
    const char* expected[] = {"d41d8cd98f00b204e9800998ecf8427e", "0cc175b9c0f1b6a831c399e269772661",
        "900150983cd24fb0d6963f7d28e17f72", "f96b697d7cb7938d525a2f31aaf161d0", "c3fcd3d76192e4007dfb496cca67e13b"};
    for (int i = 0; i < 5; ++i)
        for (int mode = 0; mode < 3; ++mode) {
            RBX::MD5Hasher* hash = RBX::MD5Hasher::create();
            if (mode == 0) hash->addData(inputs[i], strlen(inputs[i]));
            else if (mode == 1) hash->addData(std::string(inputs[i]));
            else { std::istringstream stream(inputs[i]); hash->addData(stream); }
            if (hash->toString() != expected[i] || strcmp(hash->c_str(), expected[i])) return 1;
            delete hash;
        }
    puts("native MD5: 15 vectors PASS (all three input paths, both result paths)");
    return 0;
}

#ifdef ROC_MD5_STANDALONE
int main() { return nativeMD5RuntimeSelfTest(); }
#endif
