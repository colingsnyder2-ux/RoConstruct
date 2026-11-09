// from server: 72% by atomic.potato
extern "C" void* __stdcall CreateSemaphoreA(void*, long, long, const char*);
extern "C" void __stdcall thread_resource_error_ctor(void*);

void __cdecl sub_7F4878(void*, const char*);

void __cdecl sub_7E2190(int b, int a)
{
    char buf[16];
    if (CreateSemaphoreA(0, b, 0, (const char*)a) == 0)
    {
        thread_resource_error_ctor(buf);
        sub_7F4878(buf, (const char*)0xA90D64);
    }
}
