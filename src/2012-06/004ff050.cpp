// from server: 44% by Intel
struct SpecializedMeshGen {
    int field_0;
    int field_4;
    int field_8;
    int field_C;

    int sub_4FF050(int arg);
};

extern "C" void __stdcall sub_4FB590(int, int, SpecializedMeshGen*, int, int, int);
extern "C" void __stdcall sub_4FE970(SpecializedMeshGen*, int, int*);

int SpecializedMeshGen::sub_4FF050(int arg) {
    int v4 = this->field_4;
    int ecx_val;
    if (!v4) {
        ecx_val = 0;
    } else {
        int v6 = this->field_C - v4;
        int edx = (v6 * 0x78787879) >> 32;
        int eax = edx >> 5;
        ecx_val = eax - (eax >> 31);
    }

    int v8 = this->field_8;
    int edx2 = v8 - v4;
    int edx3 = (edx2 * 0x78787879) >> 32;
    int eax2 = edx3 >> 5;
    int eax3 = eax2 - (eax2 >> 31);

    if (eax3 >= ecx_val) {
        sub_4FE970(this, arg, &arg);
    } else {
        int zero = 0;
        sub_4FB590(arg, arg, this, zero, 1, v8);
        this->field_8 = v8 + 0x44;
    }
    return 0;
}
