// from server: 19% by colin
struct CXTPImageManagerIcon {
    int func(int, int);
};

extern "C" void* __stdcall CreateCompatibleDC(void*);
extern "C" void* __stdcall CreateDIBSection(void*, void*, unsigned int, void**, void*, unsigned int);
extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);

extern "C" void __stdcall sub_7383E2(void*);
extern "C" void __stdcall sub_7383D0(void*, void*);
extern "C" void __stdcall sub_738436(void*);
extern "C" void __stdcall sub_738424(void);
extern "C" void __stdcall sub_7383DC(void*);
extern "C" int __stdcall sub_6498C0(void*, int, int*, int*, int*);
extern "C" void __stdcall sub_62FC6E(void);

extern "C" void* __stdcall GetDC(void*);

int CXTPImageManagerIcon::func(int a, int b) {
    char buf[0x40];
    int v1c = 0;
    int v18 = 0;
    int v20 = 0;
    int v14 = 0;
    int v24 = 0;
    void* hdc;
    void* hbitmap;
    int result;

    sub_7383E2(buf);
    sub_7383D0(buf, GetDC(0));
    sub_738436(&v1c);

    result = sub_6498C0(buf, a, &v1c, &v18, &v20);
    if (result == 0) {
        sub_738424();
        sub_7383DC(buf);
        return 0;
    }

    hbitmap = CreateDIBSection((void*)v1c, (void*)v18, 0, (void**)&v14, 0, 0);
    hdc = CreateCompatibleDC((void*)v1c);
    v24 = (int)hdc;
    if (v14 == 0 || hdc == 0) {
        sub_62FC6E();
    }

    memcpy_s((void*)v14, v20, (const void*)v18, v20);
    v18 = 0;

    unsigned int i = 0;
    while (i < (unsigned int)v20) {
        unsigned char alpha = *(unsigned char*)(i + v18 + 3);
        unsigned char r = *(unsigned char*)(i + v18);
        unsigned char g = *(unsigned char*)(i + v18 + 1);
        unsigned char bl = *(unsigned char*)(i + v18 + 2);
        int t;
        t = (int)r * (int)alpha;
        *(unsigned char*)(i + v14) = (unsigned char)((t + (t >> 31 & 0x7f)) >> 7);
        t = (int)g * (int)alpha;
        *(unsigned char*)(i + v14 + 1) = (unsigned char)((t + (t >> 31 & 0x7f)) >> 7);
        t = (int)bl * (int)alpha;
        *(unsigned char*)(i + v14 + 2) = (unsigned char)((t + (t >> 31 & 0x7f)) >> 7);

        if (b != 0) {
            if (alpha == 0) {
                v18 = 1;
                i += 4;
                continue;
            }
            if (alpha == 0xff && v18 == 0) {
                i += 4;
                continue;
            }
            *(int*)b = 1;
        }
        i += 4;
    }

    if (b != 0 && *(int*)b == 0) {
        memcpy_s((void*)v14, v20, (const void*)v18, v20);
    }

    return 1;
}
