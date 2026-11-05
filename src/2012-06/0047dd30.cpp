// from server: 49% by tester
struct S {
    char pad[0x4c];
    void* field_4c;
    void f();
};

extern "C" void* __cdecl sub_47B720(void*, void*, void*);
extern "C" void __cdecl sub_47DC30(void*);

void S::f() {
    if (field_4c == 0) {
        sub_47B720(0, 0, 0);
        return;
    }
    char* p = (char*)field_4c;
    sub_47DC30(sub_47B720(p, p + 0x1c, p + 0x38));
}
