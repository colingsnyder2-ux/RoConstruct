// from server: 77% by colin
struct VCLuaFunction {
    long __stdcall QueryInterface(void* ppvObject, void* riid, void* unused);
};

extern "C" void __cdecl sub_4055F0(void*);

extern void* dword_883164;
extern char byte_883158;

long __stdcall VCLuaFunction::QueryInterface(void* ppvObject, void* riid, void* unused) {
    if (ppvObject == 0) {
        return 0x80004003;
    }
    if (dword_883164 == 0) {
        sub_4055F0(&byte_883158);
    }
    *(void**)ppvObject = dword_883164;
    if (dword_883164 != 0) {
        void** vtbl = *(void***)dword_883164;
        void* fn = vtbl[1];
        ((void (__stdcall*)(void*))fn)(dword_883164);
    }
    return 0;
}
