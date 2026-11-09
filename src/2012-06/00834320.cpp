// from server: 46% by Intel
struct SlotData {
    int field0;
    int field4;
    int field8;
};

struct PoolHeader {
    int field10;
    int field40;
    int field44;
};

struct Pool {
    PoolHeader* header;
};

extern "C" int __cdecl sub_832B40(Pool* pool, int arg);
extern "C" void __cdecl sub_832340(int global, int constant, int arg);
extern "C" void __cdecl sub_8326D0(int constant, int arg);

int* g_global = (int*)0xDE13C0;

int __cdecl sub_834320(SlotData* slot, int arg) {
    int esi = slot->field0;
    int edi = slot->field4;
    int ebx = slot->field8;

    Pool pool;
    pool.header = (PoolHeader*)arg;

    int eax = sub_832B40(&pool, arg);
    if (eax) {
        *(int*)eax = esi;
        *(int*)(eax + 4) = edi;
        *(int*)(eax + 8) = ebx;
    }

    sub_832340(*g_global, -10000, arg);
    sub_8326D0(-2, arg);

    return 0;
}
