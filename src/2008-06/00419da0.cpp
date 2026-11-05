// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct S {
    char padding[8];
    void consume(void* address, std::string text);
};
void __cdecl dispatch(S** source)
{
    S* object = *source;
    char* address = reinterpret_cast<char*>(object) + 8;
    object->consume(address, *reinterpret_cast<std::string*>(address + 8));
}
