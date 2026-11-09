// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
#include <string>

// 0x20-byte value: std::string at +0, dword at +0x1c zeroed by the string ctor.
struct Value {
    std::string s;
    int extra;
    Value(const std::string& v) : s(v), extra(0) {}
};

void construct(Value* p, const std::string& v)
{
    new (p) Value(v);
}