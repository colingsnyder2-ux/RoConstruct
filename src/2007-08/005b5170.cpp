// from server: 73% by colin
struct Primitive {
    char pad0[0x1c];
    void* field1c;
    void* field20;
    char pad24[0x40];
    void* field64;
    void* field68;
    char pad6c[0x18];
    void* field84;

    void method_530100();
    bool method_4730e0(void* arg);
    void method_5e2010(void* arg);
    void method_5e2c30();
    void method_5a9080(void* arg);
    void method_60ba80(void* arg);
    void method_5a9570(void* arg);
    void method_5a91c0(void* arg);

    void func(void* arg);
};

void Primitive::func(void* arg) {
    void* p = field64;
    ((Primitive*)p)->method_530100();
    void* p84 = (char*)p + 0x84;
    if (((Primitive*)arg)->method_4730e0(p84)) {
        if (field20 != 0) {
            ((Primitive*)field64)->method_5e2010(p84);
            ((Primitive*)field68)->method_5e2c30();
            if (field1c != 0) {
                ((Primitive*)field1c)->method_5a9080(this);
                return;
            }
        } else {
            void* eax = *(void**)((char*)field20 + 0x20);
            bool eq;
            if (eax != 0) {
                eax = *(void**)((char*)eax + 8);
                eq = (*(void**)((char*)eax + 0x24) == this);
            } else {
                eq = (*(void**)((char*)field20 + 0x24) == this);
            }
            if (eq) {
                ((Primitive*)this)->method_60ba80(p84);
                ((Primitive*)field1c)->method_5a9570(field20);
                if (*(int*)((char*)field20 + 0x28) == 0) {
                    ((Primitive*)field1c)->method_5a91c0(this);
                }
            }
        }
    }
}
