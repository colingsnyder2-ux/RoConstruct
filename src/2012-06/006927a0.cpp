// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct S { std::string s; int v; };
struct Shirt {
    char pad[0x8c];
    S value;
    S GetValue();
};
S Shirt::GetValue() { return value; }