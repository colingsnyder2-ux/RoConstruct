// from server: 100% by king_originala
struct Value {
    void* first;
    void* second;
};

struct S {
    int first;
    int enabled;
    void apply(Value*);
};

extern void __cdecl convert(void*, Value*);

void __cdecl f(S* object, void* source)
{
    Value value;
    convert(source, &value);
    if (object->enabled != 0)
        object->apply(&value);
}
