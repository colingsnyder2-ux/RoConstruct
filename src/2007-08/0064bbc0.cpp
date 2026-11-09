// from server: 1% by colin
struct CXTPImageManagerIcon {
    char pad[0x50];
    int sub_64b280(int);
    int sub_649660(int);
    int sub_648740();
    int sub_648630(int*, int*, int*);

    int sub_64bbc0();
};

struct CImageInfo {
    int width;
    int height;
    int bmWidth;
    int bmHeight;
    int bmBitsPixel;
    int bmBits;
};

struct CIconInfo {
    int fIcon;
    int xHotspot;
    int yHotspot;
    int hbmMask;
    int hbmColor;
};

extern "C" {
    void* __stdcall CreateCompatibleDC(void*);
    int __stdcall DeleteObject(void*);
    int __stdcall GetObjectA(void*, int, void*);
    unsigned int __stdcall GetPixel(void*, int, int);
    int __stdcall SetPixel(void*, int, int, unsigned int);
    int __stdcall CreateIconIndirect(void*);
    int __stdcall GetIconInfo(void*, void*);
}

extern int g_8b5188;
extern double g_7a06b8;

int CXTPImageManagerIcon::sub_64bbc0() {
    return 0;
}
