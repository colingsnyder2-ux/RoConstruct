// from server: 66% by atomic.potato
struct TypedPropertyDescriptor {
    char pad0[0x114];
    char flag114;
    char pad1[3];
    void* ptr120;
    void method(int);
};

extern "C" void __stdcall sub_76c200(void*, int);
extern "C" void __fastcall sub_5395b0(void*);

void TypedPropertyDescriptor::method(int tag) {
    if (tag != 0xb91134)
        return;
    if (flag114 != 0)
        return;
    void** p = &ptr120;
    void* v = *p;
    if (v != 0) {
        sub_76c200(v, 0);
        sub_5395b0(p);
    }
}
