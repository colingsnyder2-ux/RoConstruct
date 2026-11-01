// from server: 100% by colin
extern "C" __declspec(dllimport) void *__stdcall GetCurrentProcess();
extern "C" __declspec(dllimport) int __stdcall FlushInstructionCache(void *hProcess, const void *lpBaseAddress, unsigned long dwSize);

extern "C" void *__cdecl sub_725437();

struct S {
    int field0;
    int field4;
    int field8;
    void *fieldC;
    int f(int a, int b);
};

int S::f(int a, int b)
{
    if (this->fieldC == 0) {
        void *p = sub_725437();
        this->fieldC = p;
        if (p == 0)
            return 0;
    }
    unsigned char *base = (unsigned char *)this->fieldC;
    int delta = a - (int)base - 0xd;
    *(int *)(base + 0) = 0x42444c7;
    *(int *)(base + 4) = b;
    *(unsigned char *)(base + 8) = 0xe9;
    *(int *)(base + 9) = delta;
    FlushInstructionCache(GetCurrentProcess(), base, 0xd);
    return 1;
}
