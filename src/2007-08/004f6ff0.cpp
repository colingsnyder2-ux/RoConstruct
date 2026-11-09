// from server: 27% by colin
// roc 2007-08 004f6ff0  unit: boost::bad_lexical_cast  size: 1232 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f6ff0

extern "C" void __cdecl sub_474f70();
extern "C" void __cdecl sub_4f40f0();
extern "C" void __cdecl sub_4f4920();
extern "C" void __cdecl sub_4f4e70();
extern "C" void __cdecl sub_4ff810();
extern "C" void __cdecl sub_50f870();
extern "C" void __cdecl sub_50fdd0();
extern "C" void __cdecl sub_511530();
extern "C" float __cdecl sub_630e0c(float);

struct S {
    char pad0[0x18];
    int field18;
    int field1c;
    char pad20[4];
    int field24;
    int field28;
    char pad2c[4];
    int field30;
    int field34;
    char pad38[4];
    int field3c;
    char pad40[8];
    int field48;
    void f(int* arg);
};

void S::f(int* arg) {
    int* p = arg;
    sub_474f70();
    sub_4f40f0();
    int local74 = 0;
    int local78 = 0;
    int local7c = 0;
    int localac = 0;
    int i = 0;
    int count = *(int*)((char*)p + 0x10);
    if (count > 0) {
        do {
            int idx = *(int*)((char*)(*(int*)((char*)p + 0xc)) + i * 4);
            float* base = (float*)0x8bfb20;
            float v0 = base[idx * 3];
            float v1 = base[idx * 3 + 1];
            float v2 = base[idx * 3 + 2];
            float tmp[3];
            tmp[0] = v0;
            tmp[1] = v1;
            tmp[2] = v2;
            sub_4f4920();
            i++;
        } while (i < *(int*)((char*)p + 0x10));
    }
    int local30 = 0;
    int local34 = 0;
    int local38 = 0;
    localac = 1;
    if (*(int*)((char*)p + 0x18) == 2) {
        sub_50f870();
    } else {
        int local24 = 0;
        int local28 = 0;
        int local2c = 0;
        sub_50f870();
        int v = *(int*)((char*)p + 0x18);
        int local40;
        sub_4f4e70();
        sub_4ff810();
    }
    int local24b = 0;
    int local28b = 0;
    int local2cb = 0;
    int local54 = 0;
    int local58 = 0;
    int local5c = 0;
    int local68 = 0;
    int local6c = 0;
    int local70 = 0;
    double d = *(double*)0x79f740;
    sub_511530();
    int j = 0;
    if (local34 > 0) {
        do {
            int* arr = (int*)local30;
            int idx = arr[j];
            int* tbl = (int*)local54;
            arr[j] = tbl[idx];
            j++;
        } while (j < local34);
    }
    int local48 = 0;
    int local4c = 0;
    int local50 = 0;
    sub_50fdd0();
    int n = field1c;
    int k = 0;
    if (n > 0) {
        do {
            k++;
        } while (k < n);
    }
    sub_4f40f0();
    if (field28 > 0) {
        int local60 = 0;
        int local64 = 0;
        int local40b = 0;
        do {
            float tmp[9];
            tmp[0] = 0.0f;
            tmp[1] = 0.0f;
            tmp[2] = 0.0f;
            int* edx = (int*)(field30 + local40b);
            int* edi = (int*)field3c;
            int idx0 = edx[0];
            float* f0 = (float*)((char*)edi + idx0 * 12);
            tmp[0] = f0[0];
            tmp[1] = f0[1];
            tmp[2] = f0[2];
            int idx1 = edx[1];
            float* f1 = (float*)((char*)edi + idx1 * 12);
            tmp[3] = f1[0];
            tmp[4] = f1[1];
            tmp[5] = f1[2];
            int idx2 = edx[2];
            float* f2 = (float*)((char*)edi + idx2 * 12);
            tmp[6] = f2[0];
            tmp[7] = f2[1];
            tmp[8] = f2[2];
            float a0 = tmp[3] - tmp[0];
            float a1 = tmp[4] - tmp[1];
            float a2 = tmp[5] - tmp[2];
            float b0 = tmp[6] - tmp[0];
            float b1 = tmp[7] - tmp[1];
            float b2 = tmp[8] - tmp[2];
            float c0 = a1 * b2 - a2 * b1;
            float c1 = a2 * b0 - a0 * b2;
            float c2 = a0 * b1 - a1 * b0;
            float len = c0 * c0 + c1 * c1 + c2 * c2;
            float inv = 1.0f / sub_630e0c(len);
            float r0 = c0 * inv;
            float r1 = c1 * inv;
            float r2 = c2 * inv;
            int* out = (int*)(field24 + local64);
            *(float*)out = r0;
            *(float*)((char*)out + 4) = r1;
            *(float*)((char*)out + 8) = r2;
            local40b += 0x18;
            local64 += 0xc;
            local60++;
        } while (local60 < field28);
    }
    int m = 0;
    localac = 5;
    if (local4c > 0) {
        int off = 0;
        do {
            int* esi = (int*)(local48 + off);
            sub_4ff810();
            esi[3] = 0;
            esi[4] = 0;
            esi[5] = 0;
            sub_4ff810();
            esi[0] = 0;
            esi[1] = 0;
            esi[2] = 0;
            m++;
            off += 0x18;
        } while (m < local4c);
    }
    sub_4ff810();
    sub_4ff810();
    sub_4ff810();
    sub_4ff810();
    sub_4ff810();
    sub_4ff810();
}
