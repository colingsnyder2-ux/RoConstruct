// from server: 31% by atomic.potato
extern "C" void __cdecl func_00982114(int);
extern "C" void __cdecl func_00972290(int, int);
extern "C" void __cdecl func_00782fb0();
extern "C" void* __cdecl func_007d5000();
extern "C" void __cdecl func_00558900();

struct S {
    void f(int, int, int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    int local0 = 0;
    int local1 = 0;
    void* p = func_007d5000();
    int v = *(int*)p;
    *(int*)p = 0;
    local0 = v;
    func_00782fb0();
    func_00558900();
    func_00982114(a10);
    *(int*)this = 0xbc0dd4;
    if (*(unsigned char*)0xe580b3 != 0) {
        if (!((bool (__stdcall*)(int))0xb229ec)(0xdc08c8)) {
            if (*(void**)0xe5809c != 0) {
                if (((bool (__stdcall*)(int,int,int))*(void**)0xe5809c)(0xae, 0xb58618, 0xb44978)) {
                    goto done;
                }
            }
            func_00972290(*(unsigned char*)0xe580b3, 0xb58680);
        }
    }
done:
    ;
}
