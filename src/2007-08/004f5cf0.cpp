// from server: 33% by colin
// roc 2007-08 004f5cf0  unit: boost::bad_lexical_cast  size: 1163 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f5cf0

extern "C" {
    extern unsigned char* g_008bfbc0;
    extern int g_008bfbc4;
}

struct Obj {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
};

struct Container {
    int c0;
    int c4;
    int c8;
    int cc;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    int c28;
    int c2c;
    int c30;
    int c34;
    int c38;
    int c3c;
};

struct Arg {
    int a0;
    int a4;
    int a8;
    int ac;
    int b0;
    int b4;
    int b8;
    int bc;
    int c0;
    int c4;
    int c8;
    int cc;
    int d0;
    int d4;
    int d8;
    int dc;
    int e0;
    int e4;
    int e8;
    int ec;
    int f0;
    int f4;
    int f8;
    int fc;
};

extern "C" void __stdcall sub_4d9920(int, int*, int*);
extern "C" void __stdcall sub_4f49d0(int, float*, int*);
extern "C" void __stdcall sub_4f4b00(int, float*, float*);

void __stdcall target(Arg* arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    Container* ebx = (Container*)arg1;
    Obj* esi = (Obj*)arg2;
    int ebp = arg3;

    int ecx = 0;
    int edx = 0;
    while (ecx < ebx->c28) {
        float f0 = *(float*)((char*)esi + 0);
        float f8 = *(float*)((char*)esi + 8);
        float f24 = *(float*)((char*)esi + 0x24);
        float val = f0 * f24 + f8 * f24;
        float cmp = *(float*)((char*)esi + 0x24);
        int res;
        if (val == cmp) {
            res = 1;
        } else {
            res = 0;
        }
        g_008bfbc0[ecx] = (unsigned char)res;
        ecx++;
        edx += 0xc;
    }

    if (*(char*)(ebp + 0x18) != 0) {
        int i = 0;
        int off = 0;
        while (i < g_008bfbc4) {
            if (g_008bfbc0[i] == 0) {
                int* p = (int*)(ebp + 0x14);
                int v = p[1];
                int a = v + 2;
                int b = v + 1;
                int tmp1 = a;
                int tmp2 = b;
                sub_4d9920(*(int*)(ebp + 0x10), &tmp2, &tmp1);

                int* base = (int*)(ebx->c30 + off);
                int idx0 = base[0];
                int idx1 = base[1];
                int idx2 = base[2];
                int* mat = (int*)ebx->c3c;
                float* p0 = (float*)(mat + idx0 * 3);
                float* p1 = (float*)(mat + idx1 * 3);
                float* p2 = (float*)(mat + idx2 * 3);

                float x0 = p0[0];
                float y0 = p0[1];
                float z0 = p0[2];
                float x1 = p1[0];
                float y1 = p1[1];
                float z1 = p1[2];
                float x2 = p2[0];
                float y2 = p2[1];
                float z2 = p2[2];

                float sx = esi->f0;
                float sy = esi->f4;
                float sz = esi->f8;
                float sw = esi->f24;

                float r0 = x0 * sx + y0 * sy + z0 * sz + sw;
                float r1 = x1 * sx + y1 * sy + z1 * sz + sw;
                float r2 = x2 * sx + y2 * sy + z2 * sz + sw;

                float out[3];
                out[0] = r0;
                out[1] = r1;
                out[2] = r2;

                sub_4f4b00(*(int*)(ebp + 0x14), out, out + 1);
            }
            off += 0x18;
            i++;
        }
    }

    int j = 0;
    int off2 = 0;
    while (j < ebx->c1c) {
        int* entry = (int*)(ebx->c18 + off2);
        int idxA = entry[2];
        int idxB = entry[3];
        unsigned char ca = g_008bfbc0[idxA];
        unsigned char cb = g_008bfbc0[idxB];
        if (ca != cb) {
            int idx0 = entry[0];
            int idx1 = entry[1];
            int* mat = (int*)ebx->c3c;
            float* p0 = (float*)(mat + idx0 * 3);
            float* p1 = (float*)(mat + idx1 * 3);

            float x0 = p0[0];
            float y0 = p0[1];
            float z0 = p0[2];
            float x1 = p1[0];
            float y1 = p1[1];
            float z1 = p1[2];

            float sx = esi->f0;
            float sy = esi->f4;
            float sz = esi->f8;
            float sw = esi->f24;

            float r0 = x0 * sx + y0 * sy + z0 * sz + sw;
            float r1 = x1 * sx + y1 * sy + z1 * sz + sw;

            float out[3];
            out[0] = r0;
            out[1] = r1;
            out[2] = 0.0f;

            int* p = (int*)(ebp + 0x14);
            int v = p[1];
            int tmp = v;
            sub_4f49d0(*(int*)(ebp + 0x10), out, &tmp);

            if (ca != 0) {
                tmp = v;
                v++;
            } else {
                tmp = v + 1;
            }

            int tmp2 = v;
            int tmp3 = 0;
            sub_4d9920(*(int*)(ebp + 0x10), &tmp2, &tmp3);
        }
        off2 += 0x10;
        j++;
    }
}
