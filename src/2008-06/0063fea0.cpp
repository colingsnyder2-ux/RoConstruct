// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    volatile int storage[7];
    int f(int);
};

struct Clone : Base {
    volatile int first;
    volatile int second;
    Clone(int);
};

inline Clone::Clone(int value)
{
    f(value);
    storage[0] = 0x84a4dc;
    storage[1] = 0x84a4c0;
    first = 0;
    second = 0;
}

struct Tool {
    char storage[0x18];
    int value;
    Clone* clone();
};

Clone* Tool::clone()
{
    return new Clone(value);
}
