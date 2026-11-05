// from server: 78% by atomic.potato
struct S_func_00552fa0 {
    struct VTable {
        char pad0[36];
        unsigned int value;
    };

    int __cdecl f(unsigned int *a, VTable *b);
};

int S_func_00552fa0::f(unsigned int *a, VTable *b)
{
    unsigned int x = *a;
    unsigned int y = b->value;

    if (x < y)
        return -1;

    return x != y;
}
