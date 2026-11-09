// from server: 82% by atomic.potato
extern "C" {
    __declspec(dllimport) void* __stdcall GetCurrentProcess();
    __declspec(dllimport) void* __stdcall GetCurrentThread();
    __declspec(dllimport) int __stdcall GetProcessAffinityMask(void*, unsigned*, unsigned*);
    __declspec(dllimport) int __stdcall QueryPerformanceCounter(long long*);
    __declspec(dllimport) int __stdcall QueryPerformanceFrequency(long long*);
    __declspec(dllimport) unsigned __stdcall SetThreadAffinityMask(void*, unsigned);
}

extern "C" {
    int __cdecl sub_7A9270(unsigned, unsigned, unsigned, unsigned);
    long long __cdecl sub_7A8BB0(unsigned, unsigned, unsigned, unsigned);
    long long __cdecl sub_7A8C70(unsigned, unsigned, unsigned, unsigned);
}

extern unsigned char byte_C07B7C;
extern unsigned dword_C07B68;
extern unsigned dword_C07B6C;
extern unsigned dword_C07B70;
extern unsigned dword_C07B74;
extern unsigned dword_C07B78;
extern unsigned dword_C07B88;
extern unsigned dword_C07B8C;

void sub_50FD90()
{
    if (byte_C07B7C == 0) {
        byte_C07B7C = 1;
        void* proc = GetCurrentProcess();
        GetProcessAffinityMask(proc, &dword_C07B6C, &dword_C07B78);
        dword_C07B68 = (unsigned)GetCurrentThread();
        QueryPerformanceFrequency((long long*)&dword_C07B70);
    }

    unsigned thread = dword_C07B68;
    SetThreadAffinityMask((void*)thread, 1);

    long long counter;
    QueryPerformanceCounter(&counter);

    unsigned freqLo = dword_C07B6C;
    unsigned thread2 = dword_C07B68;
    SetThreadAffinityMask((void*)thread2, freqLo);

    unsigned v74 = dword_C07B74;
    unsigned v70 = dword_C07B70;
    unsigned cLo = (unsigned)counter;
    unsigned cHi = (unsigned)((unsigned long long)counter >> 32);

    int r = sub_7A9270(cLo, cHi, v70, v74);
    unsigned rLo = (unsigned)r;
    unsigned rHi = (unsigned)((unsigned long long)r >> 32);

    long long a = sub_7A8BB0(0, 1000000, rLo, rHi);
    unsigned aLo = (unsigned)a;
    unsigned aHi = (unsigned)((unsigned long long)a >> 32);

    long long b = sub_7A8C70(aLo, aHi, v70, v74);
    unsigned bLo = (unsigned)b;
    unsigned bHi = (unsigned)((unsigned long long)b >> 32);

    long long c = sub_7A8BB0(0, 1000000, cLo, cHi);
    unsigned cLo2 = (unsigned)c;
    unsigned cHi2 = (unsigned)((unsigned long long)c >> 32);

    unsigned sumLo = bLo + cLo2;
    unsigned sumHi = bHi + cHi2 + (sumLo < bLo ? 1 : 0);

    if (sumHi > dword_C07B8C || (sumHi == dword_C07B8C && sumLo >= dword_C07B88)) {
        dword_C07B88 = sumLo;
        dword_C07B8C = sumHi;
    }
}
