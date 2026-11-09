// from server: 75% by atomic.potato
struct Slot {
    char pad0[4];
    int field4;
    char pad8[4];
    int fieldC;
};

struct Ctx {
    char pad0[4];
    Slot* slot;
};

extern "C" void* __cdecl sub_78a660(void* a, int b, void* c);
extern "C" void __cdecl sub_788f50(void* a, int b);

extern void* g_00b62b5c;

int __cdecl FactoryProduct(void* arg)
{
    void* a = sub_78a660(arg, 2, g_00b62b5c);
    void* b = sub_78a660(arg, 1, g_00b62b5c);
    int eq = 0;
    if (*(float*)b == *(float*)a) {
        if (*(short*)((char*)b + 4) == *(short*)((char*)a + 4)) {
            if (*(float*)((char*)b + 8) == *(float*)((char*)a + 8)) {
                if (*(short*)((char*)b + 0xc) == *(short*)((char*)a + 0xc)) {
                    eq = 1;
                }
            }
        }
    }
    sub_788f50(arg, eq);
    return 1;
}
