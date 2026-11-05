// from server: 27% by atomic.potato
struct InterpolatingPhysicsReceiver {
    char pad0[4];
    void* field4;
    char pad8[8];
    double field10;
    char pad18[4];
    void* field1c;
    char pad20[0x38];
    int field58;
    char pad5c[4];
    double field60;
    char pad68[0x70];
    unsigned int fieldd8;

    unsigned char f(void* a, int b);
};

extern "C" unsigned char __stdcall sub_637A70(void*);
extern "C" void* __stdcall sub_6779F0(void*);
extern "C" unsigned char __stdcall sub_4D9360(void*, void*);
extern "C" void __stdcall sub_4D92C0(void*, void*);
extern "C" void __stdcall sub_5101E0(void*, void*, void*, float);
extern "C" void __stdcall sub_512220(void*, int);

extern double dbl_a05248;
extern float flt_a169bc;

unsigned char InterpolatingPhysicsReceiver::f(void* a, int b) {
    if (sub_637A70(*(void**)this)) {
        return 0;
    }
    void* p = sub_6779F0(*(void**)(*(char**)this + 0x168));
    if (!p) {
        return 0;
    }
    if (!sub_4D9360(a, this)) {
        return 0;
    }
    void* ecx = *(void**)((char*)this + 0x18);
    int eax = *(int*)((char*)ecx + 4);
    if (eax == 0) {
        return 1;
    }
    if (eax == 1) {
        void* edi = ecx;
        int v = *(int*)edi;
        sub_4D92C0(a, (char*)edi + v * 24 + 8);
        return 1;
    }
    double d = (double)b;
    if (b < 0) d += dbl_a05248;
    d -= *(double*)((char*)this + 0x10);
    int ebx = 0;
    int esi = 0;
    if (eax > 0) {
        void* edi2 = *(void**)((char*)this + 0x18);
        void* esp1c = edi2;
        int edi3 = *(int*)edi2;
        edi3 += 0x28;
        while (1) {
            int eax2 = edi3;
            int edx2 = eax2 % 0x28;
            void* eax3 = esp1c;
            int edx3 = edx2 * 3;
            float fv = (float)*(int*)((char*)eax3 + edx3 * 8 + 0x18);
            void* ecx2 = (char*)eax3 + edx3 * 8 + 8;
            int edx4 = *(int*)((char*)ecx2 + 0x10);
            if (edx4 < 0) fv += flt_a169bc;
            if (d <= (double)fv) {
                if (ebx == 0) {
                    ebx = (int)ecx2;
                    break;
                }
                double d2 = (double)edx4;
                if (edx4 < 0) d2 += dbl_a05248;
                int eax4 = edx4;
                double d3 = d - d2;
                int edx5 = *(int*)((char*)ebx + 0x10);
                edx5 -= eax4;
                double d4 = (double)edx5;
                if (edx5 < 0) d4 += dbl_a05248;
                float fv2 = (float)(d3 / d4);
                sub_5101E0(a, (void*)ebx, ecx2, fv2);
                esi++;
                sub_512220(a, esi);
                return 1;
            }
            esi++;
            edi3--;
            if (esi >= b) break;
            ebx = (int)ecx2;
        }
    }
    if (esi > this->fieldd8) {
        this->fieldd8 = esi;
    }
    this->field58++;
    double d5 = (double)esi;
    if (esi < 0) d5 += dbl_a05248;
    d5 += this->field60;
    this->field60 = d5;
    sub_4D92C0(a, (void*)ebx);
    return 1;
}
