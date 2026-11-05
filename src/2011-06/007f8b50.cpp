// from server: 41% by atomic.potato
extern "C" void __declspec(noreturn) __stdcall DebugBreak();

void Function007f8b50()
{
    extern unsigned char g_flag;
    if (g_flag)
        DebugBreak();
}
