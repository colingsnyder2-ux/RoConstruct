// from server: 29% by atomic.potato
struct S {
    char pad[4];
    bool f();
};

extern "C" void* __stdcall sub_A40430(int, int, void*);
extern "C" int __stdcall sub_A40434(const char*, void*);
extern "C" void __stdcall sub_A404D0(void*);

bool S::f() {
    char buf[0x1c];
    sub_A40430(0xd, 0, buf);
    bool r = sub_A40434("rbxassetid://", buf) != 0;
    sub_A404D0(buf);
    return r;
}
