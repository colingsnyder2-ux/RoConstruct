// from server: 46% by atomic.potato
extern "C" int __stdcall strncpy_s(char*, unsigned int, const char*, unsigned int);
extern "C" void __stdcall DebugBreak();

extern "C" unsigned char g_flag;
extern "C" void* g_fn1;
extern "C" void* g_fn2;

void f(char* dst)
{
    if (g_flag)
    {
        strncpy_s(dst, 0x80, (const char*)0, 0x80);
        DebugBreak();
    }
}
