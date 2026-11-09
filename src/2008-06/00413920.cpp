// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Verb {
    virtual ~Verb();
    Verb(void*, void*, std::string);
};
struct CopyVerb : Verb {
    CopyVerb(void*);
};
CopyVerb::CopyVerb(void* object)
    : Verb(object ? static_cast<char*>(object) + 0x1c8 : 0, object, "Cut")
{
}
__declspec(noinline) void use() { CopyVerb x(0); }
