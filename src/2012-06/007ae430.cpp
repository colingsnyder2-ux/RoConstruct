// from server: 51% by Intel
extern unsigned long gpFunc;
extern unsigned char gFlag;

typedef int (__cdecl *FuncType)(int, const char*, const char*);
typedef void (__cdecl *VoidFuncType)(const char*, unsigned char);

struct TextureContentProvider {
};

int __cdecl unknown(int arg)
{
    if (arg != 0) {
        return 0;
    }
    int eax = arg - 1;
    if (eax == 0) {
        return 1;
    }
    eax = eax - 1;
    if (eax == 0) {
        return 2;
    }
    if (gFlag == 0) {
        return 0;
    }
    FuncType f = reinterpret_cast<FuncType>(gpFunc);
    if (f) {
        int r = f(0x4b, reinterpret_cast<const char*>(0xbb72a0), reinterpret_cast<const char*>(0xb460cc));
        if (r != 0) {
            return 0;
        }
    }
    VoidFuncType vf = reinterpret_cast<VoidFuncType>(0x972290);
    vf(reinterpret_cast<const char*>(0xbb72f8), gFlag);
    return 0;
}
