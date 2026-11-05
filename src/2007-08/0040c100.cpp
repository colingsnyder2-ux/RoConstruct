// from server: 69% by colin
struct VCBrowserViewExternal_CComObjectNoLock {
    int Release(int);
};

extern "C" void __stdcall sub_466B20();
extern "C" void __stdcall sub_62FC62(void*);

int VCBrowserViewExternal_CComObjectNoLock::Release(int)
{
    int* p = (int*)this;
    int count = p[6] - 1;
    p[6] = count;
    int result = count;
    if (count == 0 && this != 0) {
        p[0] = 0x785bc0;
        p[1] = 0x785ba8;
        p[2] = 0x785b84;
        p[5] = 0x785b5c;
        p[6] = (int)0xc0000001;
        sub_466B20();
        sub_62FC62(this);
    }
    return result;
}
