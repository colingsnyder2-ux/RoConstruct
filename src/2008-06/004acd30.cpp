// from server: 100% by king_originala
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
