// from server: 100% by king_originala
struct S {
    int reserved;
    int enabled;
    void apply(int*);
};

extern void __cdecl helper(void*, int*);

void __cdecl f(S* object, void* source)
{
    int value = 194;
    helper(source, &value);
    if (object->enabled != 0)
        object->apply(&value);
}
