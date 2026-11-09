// from server: 100% by king_originala
struct Value {
    unsigned int words[3];
};

struct S {
    unsigned int reserved;
    unsigned int count;
    void apply(Value*);
};

extern void __cdecl prepare(void*, Value*);

void __cdecl function(S* object, void* source)
{
    Value value;
    prepare(source, &value);
    if (object->count != 0)
        object->apply(&value);
}
