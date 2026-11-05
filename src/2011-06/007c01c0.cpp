// from server: 40% by atomic.potato
struct AdvRunDragger {
    char pad0[0x2c];
    int field2c;
    char pad30[0xc];
    int field3c;
    int field40;
    int field44;
    float field48;
    float field4c;
    float field50;
    float field54;
    float field58;
    float field5c;
    float field60;
    float field64;
    float field68;
    char pad6c[0x20];
    int field8c;
    char pad90[0x22];
    unsigned char fieldb2;
    bool func7bf630();
    void func7bdfd0(int*, int*, int*);
};

struct Vec4 {
    int a;
    int b;
    int c;
    float d;
    float e;
    float f;
    float g;
    float h;
    float i;
    float j;
    float k;
    float l;
};

extern "C" void __stdcall sub_63f850(void*);
extern "C" void __stdcall sub_70dbd0(void*);
extern "C" bool __stdcall sub_74a3f0(int, int, int, int, float);
extern "C" void __stdcall sub_74cc30(void*, int, int);
extern "C" void __stdcall sub_511500(void*, void*);

bool AdvRunDragger::func7bf630() {
    return false;
}

void AdvRunDragger::func7bdfd0(int* a, int* b, int* c) {
}

bool __stdcall AdvRunDragger_007c01c0(AdvRunDragger* self, char* out) {
    char local[0x40];
    sub_63f850(local);
    int saved = 0;
    bool result;
    if (self->field3c == 0) {
        result = true;
    } else {
        int* edi = &self->field44;
        int ebx = 1;
        while (true) {
            if (sub_74a3f0(self->field3c, *edi, self->field2c, self->field8c, 1.0f)) {
                break;
            }
            int idx = *(int*)(local + 4);
            int cap = *(int*)(local + 8);
            int* base = *(int**)(local + 0);
            if (idx < cap) {
                int* slot = base + idx;
                if (slot) {
                    *slot = *edi;
                }
                idx += ebx;
                *(int*)(local + 4) = idx;
            } else {
                if (edi < (int*)base || edi >= (int*)(base + idx)) {
                    sub_74cc30(local, idx + 1, 0);
                    int* base2 = *(int**)(local + 0);
                    int idx2 = *(int*)(local + 4);
                    base2[idx2 - 1] = *edi;
                } else {
                    int tmp = *edi;
                    sub_511500(local, &tmp);
                }
            }
            Vec4 v;
            self->func7bdfd0((int*)&v, (int*)local, (int*)&self->field3c);
            self->field3c = v.a;
            self->field40 = v.b;
            self->field44 = v.c;
            self->field48 = v.d;
            self->field4c = v.e;
            self->field50 = v.f;
            self->field54 = v.g;
            self->field58 = v.h;
            self->field5c = v.i;
            self->field60 = v.j;
            self->field64 = v.k;
            self->field68 = v.l;
            if (self->field3c == 0) {
                break;
            }
            self->fieldb2 = (unsigned char)ebx;
            *out = self->func7bf630() ? 1 : 0;
            if (self->field3c == 0) {
                break;
            }
        }
        result = (self->field3c == 0);
    }
    sub_70dbd0(local);
    return result;
}
