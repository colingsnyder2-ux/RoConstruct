// from server: 41% by atomic.potato
extern "C" int __stdcall sub_0080a62e(void*);
extern "C" int __stdcall sub_0080a34c(void*);
extern "C" int __stdcall sub_004151e0(void);
extern "C" int __stdcall IsZoomed(void*);
extern "C" int __stdcall SystemParametersInfoA(unsigned int, unsigned int, void*, unsigned int);

struct CChildFrame
{
    char pad0[0x20];
    void* field_20;
};

int __stdcall sub_00415320(CChildFrame* self, int* param)
{
    sub_0080a62e(self);
    int* p = (int*)sub_0080a34c(self);
    if (p != 0 && *(char*)((char*)p + 0x100) != 0)
    {
        int* q = *(int**)((char*)p + 0xec);
        if (*(int*)((char*)q + 0x84) == 0)
        {
            param[2] += 0x28;
            param[3] += 0x28;
            param[8] += 0x28;
            param[9] += 0x28;
        }
    }
    if (IsZoomed(self->field_20) == 0)
    {
        int v = sub_004151e0();
        int raw = *(int*)(v + 0x94 + 0x66);
        short a = (short)raw;
        int b = (int)((unsigned int)raw >> 0x10);
        short sa = (short)a;
        short sb = (short)b;
        int r1 = 0;
        int r2 = 0;
        ((void (__stdcall*)(CChildFrame*, int*, int))((*(int**)self)[0x70/4]))(self, &r1, 0);
        int dx = r2 - r1;
        int dy = 0;
        (void)dx;
        (void)dy;
        int out[4];
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
        out[3] = 0;
        if (SystemParametersInfoA(0x30, 0, out, 0) != 0)
        {
            int w = out[2] - out[0];
            int h = out[3] - out[1];
            short sw = (short)(w < sa ? w : sa);
            short sh = (short)(h < sb ? h : sb);
            param[8] = sw;
            param[9] = sh;
        }
    }
    return 0;
}
