// from server: 30% by colin
struct CXTPCommandBar {
    char pad0[0x28];
    int m_nWidth;
    int m_nHeight;
    int Draw(int, int, int, int, int, int, int);
};

extern "C" int __stdcall sub_648620(int);
extern "C" int __stdcall sub_630238(int);
extern "C" int __stdcall sub_680770(int, int, int);
extern "C" int __stdcall sub_7383ca(int, int, int, int, int, int);
extern "C" int __stdcall sub_73840c(int, int);
extern "C" int __stdcall sub_680880(int);
extern "C" int __stdcall sub_41f680(int);

extern "C" void* __stdcall CreateCompatibleBitmap(void*, int, int);
extern "C" int __stdcall DrawIconEx(void*, int, int, void*, int, int, int, void*, int, int);
extern "C" int __stdcall DrawStateA(void*, void*, int, int, int, int, int, int, int, int);

int CXTPCommandBar::Draw(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    if (sub_648620(a1) != 0)
        return 0;

    int width = a2;
    if (width == 0)
        width = m_nWidth;

    int height = a3;
    if (height == 0)
        height = (m_nHeight * width) / m_nWidth;

    int local50 = 0;
    int local4c = 0x788300;
    int local3c = a4;
    void* hdc = *(void**)(local3c + 4);

    void* hbm = CreateCompatibleBitmap(hdc, width, height);
    sub_630238((int)hbm);

    int local20 = 0;
    sub_680770((int)&local20, local3c, (int)&local4c);

    sub_7383ca((int)&local20, 0, 0, width, height, 0xffffff);

    int v = *(int*)(local20);
    DrawIconEx(*(void**)(local20), 0, 0, (void*)v, width, height, 0, 0, 3, 0);

    sub_680880((int)&local20);

    int r = sub_73840c((int)&local20, a7);
    if (r != 0)
        r = *(int*)(r + 4);

    DrawStateA(*(void**)(local3c + 4), (void*)r, 0, 0, 0, width, height, 0x84, 0, 0);

    sub_41f680((int)&local20);
    sub_41f680((int)&local4c);

    return 0;
}
