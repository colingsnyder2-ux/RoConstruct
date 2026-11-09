// from server: 34% by atomic.potato
struct Inner { char pad[0xacc]; int value; };
struct Outer { char pad[0xc]; Inner* p; };

extern "C" void* __cdecl sub_80A05E(unsigned int);
extern "C" void __cdecl sub_64F710(void*, int);

struct Obj {
    char pad[0xc];
    Outer* p;
    void* f();
};

void* Obj::f() {
    void* mem = sub_80A05E(0x28);
    if (mem != 0) {
        sub_64F710(mem, p->p->value);
        *(int*)((char*)mem + 0) = 0xab96c4;
        *(int*)((char*)mem + 4) = 0xab969c;
    }
    return mem;
}
