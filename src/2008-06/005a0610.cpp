// from server: 100% by tester
struct S {
    char pad[0x3b0];
    void* field_3b0;
    void* field_3b4;
    void f();
};

void* __cdecl sub_5a0280(void* p);

void S::f() {
    void* p = field_3b4;
    if (p) {
        (*(void (__thiscall**)(void*, int))(*(char**)p + 0x30))(p, 1);
    }
    field_3b4 = 0;
    void* r = sub_5a0280(this);
    void* q = field_3b0;
    if (r != q) {
        if (q) {
            (*(void (__thiscall**)(void*, int))(*(char**)q + 0x30))(q, 1);
        }
    }
    field_3b0 = r;
}
