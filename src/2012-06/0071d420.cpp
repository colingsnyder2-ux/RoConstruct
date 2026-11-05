// from server: 33% by atomic.potato
extern "C" void __stdcall func_00982114(void*);
extern "C" void* __stdcall func_0098211a(int);
extern "C" void* __stdcall func_0071aa10(void*, int, int, int, int, int);
extern "C" void* __stdcall func_0042ddf0(int, int);
extern "C" void __stdcall func_0040ccf0(void*, void*);
extern "C" void __stdcall func_00972290(int, void*);
extern "C" int __stdcall func_00b229ec(void*);

struct S {
    void f(int, int, int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    int local1 = 0;
    int local2 = 0;
    void* p = func_0071aa10(&local1, a1, a2, a3, a4, a5);
    int v = *(int*)p;
    *(int*)p = 0;
    local2 = 0;
    int* q = &local2;
    *q = v;
    void* r = func_0042ddf0(a6, a7);
    func_0040ccf0(this, r);
    func_00982114((void*)a8);
    *(int*)this = 0xba3658;
    if (*(volatile char*)0xe580b3 != 0) {
        if (func_00b229ec((void*)0xd6f7f4) != 0) {
            if (*(void**)0xe5809c != 0) {
                if (((int(__stdcall*)(int, void*, void*))*(void**)0xe5809c)(0xae, (void*)0xb58618, (void*)0xb44978) != 0) {
                    return;
                }
            }
            func_00972290(*(unsigned char*)0xe580b3, (void*)0xb58680);
        }
    }
}
