// from server: 52% by colin
// from server: 52% by colin
extern "C" {
    unsigned long __stdcall GetCurrentProcessId();
    unsigned long __stdcall GetCurrentThreadId();
    void __stdcall GetSystemTimeAsFileTime(void*);
    unsigned long __stdcall GetTickCount();
    int __stdcall QueryPerformanceCounter(void*);
}

unsigned int g_8b5188;
unsigned int g_8b518c;

void func_006318b6()
{
    unsigned int v1 = 0;
    unsigned int v2 = 0;
    unsigned int eax = g_8b5188;
    unsigned int edi = 0xbb40e64e;
    unsigned int ebx = 0xffff0000;

    if (eax != edi && (ebx & eax) != 0)
    {
        g_8b518c = ~eax;
        return;
    }

    GetSystemTimeAsFileTime(&v1);
    unsigned int esi = v2 ^ v1;
    esi ^= GetCurrentProcessId();
    esi ^= GetCurrentThreadId();
    esi ^= GetTickCount();

    unsigned int v3 = 0;
    unsigned int v4 = 0;
    QueryPerformanceCounter(&v3);
    esi ^= v4 ^ v3;

    if (esi == edi)
    {
        esi = 0xbb40e64f;
    }
    else if ((ebx & esi) == 0)
    {
        esi |= esi << 16;
    }

    g_8b5188 = esi;
    g_8b518c = ~esi;
}
