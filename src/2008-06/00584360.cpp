// from server: 100% by king_originala
extern "C" void* __cdecl sub_6a17c6(void*, int, const void*, const void*, int);

struct Model {
    char pad[0x104];
    void* field_104;
    void* sub_5836d0();
    void sub_608aa0(int);
};

struct S {
    void method(int);
};

void S::method(int a) {
    Model* model = (Model*)((char*)this - 0x1a0);
    if (sub_6a17c6(model->field_104, 0,
                  (const void*)0x92907c, (const void*)0x947f1c, 0)) {
        void* previous = model->field_104;
        if (model->sub_5836d0() != previous)
            return;
    }
    if (*(unsigned char*)0x9753d9)
        model->sub_608aa0(a);
}
