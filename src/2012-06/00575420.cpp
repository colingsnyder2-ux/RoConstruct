// from server: 100% by Xemicl
// copied from an identical function in another client (function ?f@ns_ROCX0000a5@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX0000a5 {
struct S {
    unsigned int reserved;
    unsigned int count;
    void apply(unsigned int*);
};

extern void __cdecl prepare(void*, unsigned int*);

void __cdecl f(S* object, void* source)
{
    unsigned int value;
    prepare(source, &value);
    if (object->count != 0)
        object->apply(&value);
}
}
