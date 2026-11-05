// from server: 18% by colin
struct G3D_Vector3 { float x, y, z; };
struct G3D_Color4 { float r, g, b, a; };

struct Part {
    char pad0[0xb0];
    void* field_b0;
    char pad_b4[4];
    void* field_b8;
    unsigned char field_bc;
    char pad_bd[3];
    void* field_c0;
    void* field_c4;
    void* field_c8;

    void method(void* out);
};

struct RefCounted {
    void* vtable;
    long refcount;
};

struct String {
    void* rep;
};

extern "C" {
    long __stdcall InterlockedDecrement(long volatile*);
}

extern "C" void __stdcall sub_77E6A4(void*);
extern "C" void __stdcall sub_77E69C(void*, void*);
extern "C" void __stdcall sub_77E6AC(void*);

extern float g_797eb0;

void sub_408740();
void sub_457DD0(void*);
void sub_4637D0(void*, void*);
void sub_4637F0(void*);
void sub_4708F0(void*, void*);
void sub_474F70(void*, void*);
void sub_4D03D0();
void sub_4D04C0(void*, void*);
void sub_4D04E0(void*, void*);
void sub_4D09F0(void*, void*, void*);
void sub_4D8E20(void*, void*);
void sub_4D9000(void*, void*);
void sub_4FB8C0(void*, void*);
void sub_4FB9C0(void*);
void sub_50B380(void*, void*);
void sub_549260(void*, void*);
void sub_587870(void*, void*, void*);
void* sub_62FEF6(unsigned int);

void Part::method(void* out) {
    if (this->field_bc) {
        void* p = this->field_b0;
        float f0 = *(float*)((char*)p + 0x198);
        int edi = *(int*)((char*)p + 0x194);
        float f1 = 1.0f - f0;
        float f2 = *(float*)((char*)p + 0x1e0);
        float f3 = f1 * f2;
        float f4 = 1.0f - f3;
        float f5 = *(float*)((char*)p + 0x19c);
        float local_d8 = (float)edi;
        float local_dc = f4;
        float local_e0 = f5;

        sub_4D03D0();
        if (*(unsigned char*)&f0) {
            void* q = this->field_c4;
            void* r = *(void**)((char*)q + 0x54);
            void* tmp;
            sub_4D8E20(&tmp, &local_d8);
            void* v = *(void**)&tmp;
            sub_474F70((char*)this + 0xb8, v);
            if (tmp) {
                if (InterlockedDecrement((long*)((char*)tmp + 4)) == 0) {
                    sub_457DD0(tmp);
                    if (tmp) {
                        (*(void(__thiscall**)(void*, int))*(void**)tmp)(tmp, 1);
                    }
                }
            }
            this->field_bc = 0;
        }
    }

    *(void**)out = 0;
    sub_474F70(out, this->field_b8);
    return;
}
