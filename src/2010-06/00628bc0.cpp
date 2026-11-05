// from server: 40% by atomic.potato
struct Inner {
    char pad0[0x10];
    int field10;
};

struct Outer {
    char pad0[0xa0];
    int field_a0;
    char pad_a4[0x18];
    int field_bc;
};

extern "C" void __stdcall sub_622ef0(void*, void*);
extern "C" void __stdcall sub_628b70(int);
extern "C" void __stdcall sub_9ea90c();

struct S {
    char pad0[0xa0];
    int field_a0;
    char pad_a4[0x18];
    int field_bc;
    void method(int);
};

void S::method(int arg) {
    int local1;
    int local2;
    sub_622ef0(&field_a0, &local2);
    int edi = local1;
    int ebx = field_bc;
    int esi = field_a0;
    void (__stdcall *ebp)() = sub_9ea90c;
    if (edi != 0 && edi == esi) {
    } else {
        ebp();
    }
    esi = local2;
    if (esi != ebx) {
        if (edi != 0) {
            edi = *(int*)edi;
        } else {
            ebp();
            if (esi == *(int*)(edi + 0x18)) {
                ebp();
            }
            sub_628b70(*(int*)(esi + 0x10));
        }
    }
}
