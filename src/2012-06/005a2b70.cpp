// from server: 73% by atomic.potato
extern "C" void* __stdcall CreateSemaphoreA(void* a, long b, long c, const char* d);
extern "C" void __stdcall boost_thread_resource_error_ctor(void* p);
extern "C" void __cdecl sub_983144(void* a, void* b);

struct S_func_005a2b70 {
};

void __cdecl f(int a1, int a2)
{
    char buf[16];
    if (CreateSemaphoreA(0, a1, a2, 0) == 0) {
        boost_thread_resource_error_ctor(buf);
        sub_983144((void*)0xcd6fe8, buf);
    }
}
