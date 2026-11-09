// from server: 34% by Viper
typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef void* HMODULE;
typedef void* HRSRC;
typedef void* HGLOBAL;
typedef void* LPVOID;
typedef int BOOL;

extern "C" {
    HRSRC __stdcall FindResourceA(HMODULE, const char*, const char*);
    HGLOBAL __stdcall LoadResource(HMODULE, HRSRC);
    LPVOID __stdcall LockResource(HGLOBAL);
    DWORD __stdcall SizeofResource(HMODULE, HRSRC);
    BOOL __stdcall FreeResource(HGLOBAL);
}

struct RBX_BrickColor {
    int r;
    int g;
    int b;
};

struct RBX_DataModel;

struct RBX_Listener {
    bool __cdecl evaluate(RBX_DataModel* dataModel);
};

extern "C" void* __stdcall sub_630478(void*, void*);
extern "C" void* __stdcall sub_77D2D0(void*, void*, void*);
extern "C" void* __stdcall sub_77D2D4(void*, void*);
extern "C" void* __stdcall sub_77D268(void*);
extern "C" void* __stdcall sub_77D2D8(void*, void*, int);
extern "C" void __stdcall sub_77D26C(void*);
extern "C" void* __stdcall sub_5068D0(void*, void*, void*, int);
extern "C" void __stdcall sub_442710(void*);
extern "C" void __stdcall sub_442820(void*);
extern "C" int __stdcall sub_4429E0(void*, void*, int, int, int);
extern "C" void __stdcall sub_442700(void*);
extern "C" void __stdcall sub_4426D0(void*, int, int);
extern "C" void __stdcall sub_630D4C(void*, void*, int);
extern "C" void* __stdcall sub_648630(void*, int, int, int);
extern "C" void __stdcall sub_6485C0(void*, void*);
extern "C" int __stdcall sub_64D160(void*, void*);
extern "C" void __stdcall sub_5053C0(void*);

bool RBX_Listener::evaluate(RBX_DataModel* dataModel)
{
    void* hModule = (void*)0x8b5188;
    void* resInfo = sub_630478(hModule, (void*)0x78ab40);
    if (!resInfo)
        return false;

    void* resData = sub_77D2D0(hModule, resInfo, (void*)0x78ab40);
    if (!resData)
        return false;

    void* resLock = sub_77D2D4(resData, resInfo);
    if (!resLock)
        return false;

    void* resSize = sub_77D268(resLock);
    if (!resSize)
        return false;

    int size = (int)sub_77D2D8(resData, resInfo, 5);
    void* buffer = sub_5068D0(resSize, resLock, (void*)size, 0);

    int width = *(int*)((char*)buffer + 4);
    int height = *(int*)((char*)buffer + 8);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char* pixel = (char*)buffer + (y * width + x) * 4;
            char tmp = pixel[2];
            pixel[2] = pixel[0];
            pixel[0] = tmp;
        }
    }

    void* region = (void*)((char*)buffer + 0x10);
    sub_442710(region);

    int type = *(int*)((char*)buffer + 0x0c);
    int flag = (type == 4) ? 1 : 0;
    int stride = type * 8;

    int result = sub_4429E0(region, (void*)((char*)buffer + 0x10), width, stride, flag);
    if (result == 0) {
        sub_442820(region);
        sub_5053C0((void*)((char*)buffer + 0x04));
        return false;
    }

    sub_442700(region);

    for (int y = 0; y < height; y++) {
        sub_4426D0(region, 0, y);
        int rowSize = width * 2;
        void* rowData = (void*)((char*)buffer + (y * width) * 4);
        sub_630D4C(rowData, rowData, rowSize);
    }

    void* tex = sub_648630((void*)((char*)buffer + 0x10), 0, 0, 0);
    sub_6485C0(tex, (void*)((char*)buffer + 0x10));

    int check = sub_64D160((void*)((char*)buffer + 0x10), dataModel);
    bool ok = (check != 0);

    sub_77D26C(resLock);
    sub_442820(region);
    sub_5053C0((void*)((char*)buffer + 0x04));

    return ok;
}
