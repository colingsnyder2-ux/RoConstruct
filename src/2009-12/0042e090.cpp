// from server: 28% by atomic.potato
struct CObjectBrowser {
    char pad0[0x58];
    char field58[0x18];
    char pad70[0x8];
    void* field78;
    char pad7c[0x114];
    char field190[0x4];
    char pad194[0x0];

    void func(int a, int b, int c);
};

extern "C" int __stdcall GetClientRect(void* hwnd, void* rect);

extern "C" void __stdcall sub_7f3e30();
extern "C" void __stdcall sub_7f3c32();
extern "C" void __stdcall sub_7f4382();
extern "C" void __stdcall sub_7f42e6();

void CObjectBrowser::func(int a, int b, int c)
{
    sub_7f3e30();
    if (a == 1)
        return;
    if (field78 == 0)
        return;
    int rect[4];
    GetClientRect(field78, rect);
    int w = rect[2] - rect[0];
    int h = rect[3] - rect[1];
    sub_7f3c32();
    if (*(int*)((char*)this + 0x190) != 0) {
        sub_7f4382();
        int v = h - w + b;
        int lo = c - 0x96;
        if (v < lo) v = lo;
        if (v > 0x32) v = 0x32;
        sub_7f42e6();
        (*(void(**)(void))((char*)this + 0x170))();
    }
}
