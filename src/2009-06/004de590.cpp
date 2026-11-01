// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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