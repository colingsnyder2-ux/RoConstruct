// from server: 100% by king_originala
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
