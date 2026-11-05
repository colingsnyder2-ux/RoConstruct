// from server: 35% by colin
struct RBX_View_Decal {
    char pad[0xb8];
    int field_b8;
    char field_bc;
    char pad_bd[0x0f];
    int field_cc;
    int field_c4;
    int field_d0;
    int field_d4;
    int field_d8;
    int field_dc;
    int field_e0;
    int field_e4;
    int field_e8;
    int field_ec;
    int field_f0;
    int field_f4;
    int field_f8;
    int field_fc;
    int field_100;
    int field_104;
    int field_108;
    int field_10c;
    int field_110;
    void method(int* out);
};

extern "C" {
    void __stdcall sub_77e6a4(void* p);
    void __stdcall sub_77e69c(void* dst, void* src);
    void __stdcall sub_77e6ac(void* p);
    void* __cdecl sub_62fef6(unsigned int size);
    void __cdecl sub_4cfe90(void* dst, void* src);
    void __cdecl sub_4d09f0(void* dst, int a, void* b);
    void __cdecl sub_474f70(void* self, void* val);
    void __cdecl sub_4fb8c0(void* self);
    void __cdecl sub_4fb9c0(void* self);
    void* __cdecl sub_408740();
    char __cdecl sub_549260(void* self);
    extern float G_89820c;
    extern float G_898210;
    extern float G_898214;
}

void RBX_View_Decal::method(int* out)
{
    if (this->field_bc != 0) {
        char local_cc[0x20];
        sub_77e6a4(local_cc);

        char local_ac[0x20];
        sub_4cfe90(local_ac, local_cc);

        char local_8c[0x20];
        sub_77e69c(local_8c, local_ac);
        *(int*)(local_8c + 0x1c) = *(int*)(local_ac + 0x1c);

        void* p = sub_408740();
        char result = sub_549260(p);

        sub_77e6ac(local_ac);

        if (result != 0) {
            void* obj = sub_62fef6(0x18);
            if (obj != 0) {
                sub_4fb9c0(obj);
            } else {
                obj = 0;
            }
            sub_474f70(&this->field_b8, obj);

            void* obj2 = sub_62fef6(0x4c);
            void* edx;
            if (obj2 != 0) {
                int* p2 = (int*)this->field_c4;
                int v = *(int*)((char*)p2 + 0x50);
                sub_4d09f0(obj2, v, local_cc);
                edx = obj2;
            } else {
                edx = 0;
            }

            int* pcc = (int*)this->field_cc;
            float f0 = 0.0f;
            float f1 = *(float*)((char*)pcc + 0x110);
            float f2 = *(float*)((char*)pcc + 0x10c);

            float args[7];
            args[0] = G_89820c;
            args[1] = G_898210;
            args[2] = G_898214;
            args[3] = f2;
            args[4] = f1;
            args[5] = f0;
            args[6] = f0;

            sub_474f70(&this->field_b8, edx);
            sub_4fb8c0(*(void**)&this->field_b8);
            this->field_bc = 0;
        }
        sub_77e6ac(local_cc);
    }

    *out = 0;
    sub_474f70(out, (void*)this->field_b8);
}
