// from server: 43% by colin
typedef unsigned int DWORD;
typedef int BOOL;

extern "C" {
    int __stdcall GetDeviceCaps(void* hdc, int index);
    int __stdcall MulDiv(int a, int b, int c);
}

struct CScintillaView {
    char pad0[0x58];
    char pad58[0x70];
    int field_c8;
    int field_cc;
    int field_d0;
    int field_d4;
    char pad_d8[0x08];
    int field_e0;
    int field_e4;
    int field_e8;
    void Method(int a, int b, int c, int d);
};

void CScintillaView::Method(int a, int b, int c, int d)
{
    int local_c8, local_cc, local_d0, local_d4;
    int v1, v2, v3, v4;
    int cap;
    int* p;

    if (field_d4 != 0) {
        local_c8 = field_c8;
        local_cc = field_cc;
        local_d0 = field_d0;
        local_d4 = field_d4;
    } else {
        v1 = GetDeviceCaps((void*)a, 0x58);
        v2 = GetDeviceCaps((void*)b, 0x5a);
        cap = (field_e8 != 0) ? 0x9ec : 0x3e8;
        local_c8 = MulDiv(field_c8, v1, cap);
        local_cc = MulDiv(field_cc, v2, cap);
        local_d0 = MulDiv(field_d0, v1, cap);
        local_d4 = MulDiv(field_d4, v2, cap);
    }

    p = (int*)c;
    int r24 = p[9];
    int r28 = p[10];
    int r2c = p[11];
    int r30 = p[12];

    int t24 = p[9];
    int t28 = p[10];
    int t2c = p[11];
    int t30 = p[12];

    int x1 = t24 + local_d0;
    int y1 = t28 + local_cc;
    int x2 = t2c - 1 - local_d4;
    int y2 = t30 - 1 - local_c8;

    int out[10];
    out[0] = t24;
    out[1] = t28;
    out[2] = t2c;
    out[3] = t30;
    out[4] = x1;
    out[5] = y1;
    out[6] = x2;
    out[7] = y2;
    out[8] = d;
    out[9] = 0;

    if (field_e0 != 0) {
        void** vt = *(void***)this;
        void (*fn)(void*, int, int*, int*) = (void (*)(void*, int, int*, int*))vt[0x194/4];
        fn(this, c, out, (int*)d);
    }
    if (field_e4 != 0) {
        void** vt = *(void***)this;
        void (*fn)(void*, int, int*, int*) = (void (*)(void*, int, int*, int*))vt[0x198/4];
        fn(this, c, out, (int*)d);
    }

    int tmp = out[0];
    void* self = (char*)this + 0x58;
    void (*fn2)(void*, int*, int) = (void (*)(void*, int*, int))0x45c880;
    fn2(self, &tmp, 1);
}
