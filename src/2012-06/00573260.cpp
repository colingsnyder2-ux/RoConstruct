// from server: 100% by Xemicl
// copied from an identical function in another client (function ?f@ns_ROCX00001c@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX00001c {
struct Value {
    float x, y, z;
};

struct S {
    Value get();
};

void __cdecl consume(void* destination, const Value& value);

void __cdecl f(S* source, void* destination)
{
    consume(destination, source->get());
}
}
