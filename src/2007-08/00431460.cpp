// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall EnumDisplaySettingsExA(const char*, unsigned long, void*, unsigned long);
extern "C" unsigned long __stdcall GetLastError();

extern "C" void* __cdecl sub_56C3B0(void*);
extern "C" void __cdecl sub_56C0A0(int, int, const char*, unsigned long);
extern "C" void __cdecl sub_630B8C(void*, int, unsigned long);
extern "C" void __cdecl sub_630A1E();

struct CMainFrame {
    char pad0[0x28];
    int field28;
    char pad2c[0x68 - 0x2c];
    int field68;
    int field6c;
    int field70;
    char pad74[0x78 - 0x74];
    int field78;
    char pad7c[0x9c - 0x7c];
    char devmode[0x9c];
};

CMainFrame* CMainFrame_ctor(CMainFrame* self, int a, int b);

CMainFrame* CMainFrame_ctor(CMainFrame* self, int a, int b)
{
    char buf[0x9c];
    int i;
    unsigned long err;
    void* p;
    int* pi;
    double ratio;
    int w, h;
    int best;
    int bestDiff;
    int diff1, diff2;
    int idx;

    sub_630B8C(buf, 0, 0x9c);
    *(unsigned short*)(buf + 0x30) = 0x9c;

    if (EnumDisplaySettingsExA(0, 0xffffffff, buf, 0) == 0) {
        p = sub_56C3B0(&buf[0]);
        pi = (int*)p;
        err = GetLastError();
        sub_56C0A0(*pi, 3, "EnumDisplaySettings failed. GetLastError() == %d", err);
        if (p) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
                (*(void(**)(void*))(*(int*)p + 4))(p);
            }
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                (*(void(**)(void*))(*(int*)p + 8))(p);
            }
        }
    }

    w = *(int*)(buf + 0x6c);
    h = *(int*)(buf + 0x70);
    ratio = (double)w / (double)h;

    for (i = 0; i < 0x27; i++) {
        ((int*)self)[i] = ((int*)buf)[i];
    }

    idx = 0;
    for (;;) {
        if (EnumDisplaySettingsExA(0, idx, buf, 0) == 0)
            break;
        idx++;
        w = *(int*)(buf + 0x6c);
        h = *(int*)(buf + 0x70);
        {
            double r2 = (double)w / (double)h;
            double d = r2 - ratio;
            if (d < 0) d = -d;
            if (d / ratio < *(double*)0x78b128) {
                if (self->field68 == *(int*)(buf + 0x68) &&
                    self->field78 == *(int*)(buf + 0x78)) {
                    diff1 = a - self->field70 * self->field6c;
                    if (diff1 < 0) diff1 = -diff1;
                    diff2 = a - h * w;
                    if (diff2 < 0) diff2 = -diff2;
                    if (diff2 < diff1) {
                        for (i = 0; i < 0x27; i++) {
                            ((int*)self)[i] = ((int*)buf)[i];
                        }
                    }
                }
            }
        }
    }

    self->field28 = 0x180000;
    return self;
}
