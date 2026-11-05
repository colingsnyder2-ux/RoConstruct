// from server: 47% by atomic.potato
struct S
{
    char pad0[0x8c];
    void* field_8c;
    char pad90[0x4];
    int field_94;
    void func(char* arg);
};

extern "C" void* __stdcall sub_89E524(void*, const char*, int, int);
extern "C" void* __stdcall sub_89E430(void*, void*);
extern "C" void* __stdcall sub_89E4B8(void*, void*);
extern "C" void* __cdecl sub_718A38(unsigned int);
extern "C" void __stdcall sub_5DAB80(void*, void*);
extern "C" void __cdecl sub_613640(void*, void*);
extern "C" void __cdecl sub_40C2D0(void*, void*);

extern unsigned int* g_89E46C;
extern void* g_A4B2EC;

void S::func(char* arg)
{
    if (sub_89E524(arg, (const char*)0x8D8F84, 0, 0xf) != (void*)*g_89E46C)
    {
        field_94 = 2;
        return;
    }
    if (sub_89E524(arg, (const char*)0x8D8F50, 0, 0x30) != (void*)*g_89E46C)
    {
        field_94 = 2;
        return;
    }
    if (sub_89E524(arg, (const char*)0x8D8F10, 0, 0x3e) != (void*)*g_89E46C)
    {
        field_94 = 2;
        return;
    }
    if (sub_89E430(&field_8c, arg))
    {
        void* p = sub_718A38(0x1c);
        void* tmp = 0;
        if (p)
        {
            sub_89E4B8(p, arg);
        }
        else
        {
            p = 0;
        }
        sub_5DAB80(&tmp, p);
        sub_613640(&field_8c, &tmp);
        sub_40C2D0(this, g_A4B2EC);
    }
}
