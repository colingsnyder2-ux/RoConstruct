// from server: 41% by Intel
struct PolyContact {
    int f();
};

extern "C" int __stdcall sub_965150(void* thisptr, void* arg);
extern "C" int __stdcall sub_965030(void* thisptr, void* arg);
extern "C" int __cdecl sub_972290(int a1, const char* a2);
extern "C" int __stdcall g_logCallback(int a1, const char* a2, const char* a3);

int* g_logCallbackPtr = (int*)0x00E5809C;
char* g_debugFlag = (char*)0x00E580B3;
const char* g_filePath = (const char*)0x00C07520;
const char* g_str1 = (const char*)0x00C077CC;
const char* g_str2 = (const char*)0x00C07750;
const char* g_str3 = (const char*)0x00C07734;
const char* g_str4 = (const char*)0x00C076B8;

int PolyContact::f() {
    char buffer[164];
    int vtableFn;
    int* vtable = *(int**)this;
    vtableFn = vtable[11];
    sub_965150(this, buffer);
    if (*g_debugFlag) {
        if (*(int*)((char*)this + 164) > 8) {
            int callback = *g_logCallbackPtr;
            if (callback) {
                if (((int(__stdcall*)(int, const char*, const char*))callback)(0x63, g_filePath, g_str1)) {
                    return 0;
                }
            }
            sub_972290(*g_debugFlag, g_str2);
        }
    }
    sub_965030(this, (void*)((char*)this + 44));
    int* src = (int*)buffer;
    int* dst = (int*)((char*)this + 44);
    for (int i = 0; i < 41; ++i) {
        *dst++ = *src++;
    }
    if (*g_debugFlag) {
        if (*(int*)((char*)this + 204) > 8) {
            int callback = *g_logCallbackPtr;
            if (callback) {
                if (((int(__stdcall*)(int, const char*, const char*))callback)(0x69, g_filePath, g_str3)) {
                    return 0;
                }
            }
            sub_972290(*g_debugFlag, g_str4);
        }
    }
    return 0;
}
