// from server: 43% by colin
struct VCBrowserViewExternal_CComObjectNoLock {
    int method(int a, int b);
};

extern "C" int __stdcall sub_403e40(void*, void*, int, int);
extern "C" void __stdcall sub_401150(void*);
extern "C" void __stdcall sub_630a1e(void);

extern int dword_8BAF54;
extern int dword_784FE0;

int VCBrowserViewExternal_CComObjectNoLock::method(int a, int b)
{
    int result = -2147024882;
    int* p;
    int* q;
    int i;

    if (dword_8BAF54 != 0) {
        p = (int*)this;
        q = (int*)a;
        while (*q != -1) {
            if (*q == -2) {
                int (*fn)(int) = (int (*)(int))q[1];
                q = (int*)fn(0);
            } else {
                *p = *q + a;
                p++;
                q++;
            }
        }
    }

    result = sub_403e40((void*)this, (void*)((char*)this + 4), a, 3);
    if (result < 0) {
        (*(void (__stdcall **)(int))(*(int*)this + 0x1c))(1);
        sub_401150((void*)((char*)this - 0x18));
        return result;
    }

    result = (*(int (__stdcall **)(void*, int, int))(*(int*)this))(this, dword_784FE0, b);
    if (result < 0) {
        (*(void (__stdcall **)(int))(*(int*)this + 0x1c))(1);
    }
    sub_401150((void*)((char*)this - 0x18));
    return result;
}
