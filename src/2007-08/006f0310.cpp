// from server: 29% by colin
// roc 2007-08 006f0310  unit: CXTPShadowsManager::CShadowWnd  size: 1313 bytes

extern "C" {
    void* __stdcall CreateDIBSection(void*, void*, unsigned int, void**, void*, unsigned int);
    int __stdcall DeleteObject(void*);
    void* __stdcall SelectObject(void*, void*);
}

struct CShadowWnd {
    char pad[0x20];
    int field20;
    char pad2[0x40];
    int field64;
    int field60;
    int field5c;
    void MakeShadow(int, int, int);
};

extern "C" void __cdecl sub_63023e();
extern "C" void __cdecl sub_630940();
extern "C" void __cdecl sub_630946();
extern "C" void __cdecl sub_630b8c();
extern "C" void __cdecl sub_63d780();
extern "C" void* __cdecl sub_643a40();
extern "C" int __cdecl sub_6efcd0(int, int, int, double);
extern "C" void* __cdecl sub_6effe0();
extern "C" void __cdecl sub_7383dc();
extern "C" void __cdecl sub_7383e2();
extern "C" void __cdecl sub_7388e6();

extern double g_7962e0;
extern double g_79f348;

void CShadowWnd::MakeShadow(int a, int b, int c)
{
    sub_63023e();
    if (a == 0) return;
    if (b == 0) return;
    sub_6effe0();
    if (*(int*)((char*)sub_6effe0() + 0x20) == 0) return;
    sub_6effe0();
    if (*(int*)sub_6effe0() == 0) return;
    if (this->field64 == 0) return;

    char local_5c = 0;
    char local_5d = 0;
    char local_5e = (char)0xff;
    char local_5f = 1;
    int local_78 = 0;
    int local_7c = 0;

    sub_630946();
    sub_7383e2();
    sub_63d780();
    sub_630b8c();

    int w = a;
    int h = b;
    int size = w * h * 4;

    void* hdc = 0;
    void* hbitmap = CreateDIBSection(0, 0, 0, 0, 0, 0);
    if (hbitmap == 0) goto cleanup;

    {
        void* obj = sub_643a40();
        int color = *(int*)((char*)obj + 0x20);
        int r = color & 0xff;
        int g = (color >> 8) & 0xff;
        int bl = (color >> 16) & 0xff;
        int flag = (this->field60 & 1) ? 2 : 1;
        int stride = flag * 0x3000000;

        if (this->field5c == 0) {
            int rowbytes = w * 4;
            int base = (h - 1) * w * 4 + 12;
            int xoff = -w * 4;
            int y = 1;
            int ystep = 1;
            int x = 0;
            int xstep = 4;
            int row = base;
            int col = 0;
            int cstep = 4;
            int i;
            for (i = 0; i < 4; i++) {
                int j;
                for (j = 0; j < 4; j++) {
                    double t = (double)(y + x) / g_7962e0;
                    int v = sub_6efcd0(r, g, bl, t);
                    *(int*)((char*)hbitmap + row + col) = v + stride;
                    row += xoff;
                    stride += flag * 0x3000000;
                }
                base -= 4;
                y += ystep;
                xstep--;
            }
            for (i = 1; i <= 4; i++) {
                double t = (double)i * g_79f348;
                int v = sub_6efcd0(r, g, bl, t);
                int off = (4 - (i + 2)) * flag * 0xf000000;
                v += off;
                int k;
                for (k = h - 4; k > 0; k--) {
                    *(int*)((char*)hbitmap + (i + 2) * 4 + (h - 4 - k) * w * 4) = v;
                }
            }
        } else {
            int y = 1;
            int x = 0;
            int xstep = 4;
            int row = 0;
            int col = 0;
            int cstep = 4;
            int i;
            for (i = 0; i < 4; i++) {
                int j;
                for (j = 0; j < 4; j++) {
                    double t = (double)(y + x) / g_7962e0;
                    int v = sub_6efcd0(r, g, bl, t);
                    *(int*)((char*)hbitmap + row + col) = v + stride;
                    row += w * 4;
                    stride += flag * 0x3000000;
                }
                x += 4;
                y += 1;
                xstep--;
            }
            for (i = 1; i <= 4; i++) {
                double t = (double)i * g_79f348;
                int v = sub_6efcd0(r, g, bl, t);
                int off = i * flag * 0xf000000;
                v += off;
                int k;
                for (k = h - 4; k > 4; k--) {
                    *(int*)((char*)hbitmap + (i - 1) * 4 + (h - 4 - k) * w * 4) = v;
                }
            }
            for (i = 1; i <= 4; i++) {
                double t = (double)i * g_79f348;
                int v = sub_6efcd0(r, g, bl, t);
                int off = i * flag * 0xf000000;
                v += off;
                int k;
                for (k = 0; k < 4; k++) {
                    *(int*)((char*)hbitmap + (i - 1) * 4 + (h - 4 - k) * w * 4) = v;
                }
            }
        }

        void* old = SelectObject(hdc, hbitmap);
        int* p = (int*)hbitmap;
        (void)p;
        void* obj2 = sub_6effe0();
        void* vtable = *(void**)obj2;
        (*(void(__thiscall*)(void*, int, int, int, int, int, int, int, int, int))vtable)(obj2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        SelectObject(hdc, old);
        DeleteObject(hbitmap);
        sub_7388e6();
    }

cleanup:
    sub_7383dc();
    sub_630940();
}
