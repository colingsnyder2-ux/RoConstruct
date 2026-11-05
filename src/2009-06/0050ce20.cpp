// from server: 100% by why2
extern "C" void __cdecl sub_718A32(void*);

struct S {
    int field_0;
    int field_4;
    int field_8;
    void* field_C;
    void method();
};

void S::method() {
    if (field_8 != 0) {
        sub_718A32(field_C);
    }
}
