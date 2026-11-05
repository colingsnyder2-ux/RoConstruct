// from server: 35% by atomic.potato
struct RoundRobinPhysicsSender {
    char pad0[0x10];
    int field10;
    char pad14[0x14];
    int field28;
    char pad2c[0x8];
    int field34;
    int field38;
    int method();
};

struct C1 { void f(void*, int); };
struct C2 { void f(void*, void*); };
struct C3 { void f(void*, int); };
struct C4 { void f(void*, int, void*); };

extern "C" void* __cdecl sub_80A05E(unsigned int);
extern "C" int __cdecl sub_5179C0();

int RoundRobinPhysicsSender::method() {
    void* p = sub_80A05E(0x114);
    void* local = p;
    int flag = 0;
    if (p) {
        ((C1*)p)->f(p, field10);
    } else {
        local = 0;
    }
    void* esi = (char*)this + 0x14;
    ((C2*)esi)->f(esi, local);
    flag = -1;
    int v = *(int*)esi;
    ((C3*)esi)->f(esi, 0x1b);
    int r = sub_5179C0();
    int v2 = *(int*)esi;
    int tmp = r;
    ((C4*)esi)->f(esi, v2, &tmp);
    int v3 = *(int*)esi;
    ((C3*)esi)->f(esi, 0x83);
    int* ea = *(int**)esi;
    int ec = *ea;
    field34++;
    field38 = ec;
    return tmp;
}
