// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <strstream>
struct S {
    char pad[0xc];
    std::strstreambuf sb;
    char* str();
};
char* S::str() { return sb.str(); }
