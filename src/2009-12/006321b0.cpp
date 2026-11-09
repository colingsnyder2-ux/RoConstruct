// from server: 29% by atomic.potato
struct Inner
{
    char pad0[0x18];
    void* field18;
};

struct Outer
{
    void* field0;
    char pad4[0x14];
    Inner* field18;
    void f();
};

extern "C" void __stdcall sub_0098b760();
extern "C" void __stdcall sub_0098b6e4();
extern "C" void __cdecl sub_007f385a(void*);
extern "C" void __fastcall sub_0047a910(void*);
extern "C" void __fastcall sub_007a0270(void*);

void Outer::f()
{
    void* ebp = field18->field18;
    void* esi = field0;
    int flag = 0;
    for (;;)
    {
        Inner* ebx = field18;
        void* eax = field0;
        if (esi != 0)
        {
            if (esi == eax)
                goto L203;
        }
        sub_0098b760();
    L203:
        if (ebp == ebx)
            break;
        if (esi != 0)
        {
            esi = *(void**)esi;
            goto L211;
        }
        sub_0098b760();
    L211:
        if (ebp == *(void**)((char*)esi + 0x18))
        {
            sub_0098b760();
        }
        esi = *(void**)((char*)ebp + 0x28);
        if (esi != 0)
        {
            sub_0098b6e4();
            sub_007f385a(esi);
        }
        sub_0047a910(&esi);
        ebp = *(void**)((char*)&ebp);
        esi = *(void**)((char*)&esi);
    }
    flag = -1;
    sub_007a0270(this);
}
