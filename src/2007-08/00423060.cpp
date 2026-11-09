// from server: 16% by colin
struct CSelectionTreeCtrl {
    char pad[0x100];
    void sub_423060(int, int, int, int, int);
};

extern "C" void __stdcall sub_725750();
extern "C" void __stdcall sub_725770();
extern "C" void __stdcall sub_44f4c0();
extern "C" void __stdcall sub_49d670();
extern "C" void __stdcall sub_421640();
extern "C" void __stdcall sub_492360();
extern "C" void __stdcall sub_421fd0();
extern "C" void __stdcall sub_41da00();
extern "C" void __stdcall sub_77e6d8();

void CSelectionTreeCtrl::sub_423060(int a1, int a2, int a3, int a4, int a5)
{
    char *base = (char *)this;
    if (*(char *)(base + 0xe) != 0)
        goto loc_423213;

    if (a2 != 0)
    {
        char *ebx = base - 0xc;
        sub_725750();
        char *edi = base - 0x24;
        sub_44f4c0();
        int ebp = 0;
        int eax = *(int *)(edi + 4);
        if (ebp != 0 && ebp != (int)edi)
            sub_77e6d8();
        int edi2 = 0;
        if (edi2 != eax)
        {
            if (ebp != 0)
                sub_77e6d8();
            if (edi2 == *(int *)(ebp + 4))
                sub_77e6d8();
            int edx = *(int *)(base - 0xbc);
            int eax2 = *(int *)(edi2 + 0x10);
            edx = *(int *)(edx + 0x154);
            void *ecx2 = base - 0xbc;
            (*(void (__stdcall *)(int))edx)(eax2);
        }
        else
        {
            sub_49d670();
            sub_421640();
            sub_492360();
        }
        sub_725770();
    }

    if (a4 != 0)
    {
        char *ebx = base - 0xc;
        sub_725750();
        sub_421fd0();
        char *edi = base - 0x24;
        sub_44f4c0();
        int ebp = 0;
        int ecx = *(int *)(edi + 4);
        if (ebp != 0 && ebp != (int)edi)
            sub_77e6d8();
        int edi2 = 0;
        if (edi2 != ecx)
        {
            if (ebp == 0)
                sub_77e6d8();
            if (edi2 == *(int *)(ebp + 4))
                sub_77e6d8();
            int edx = *(int *)(base - 0xbc);
            int eax = *(int *)(edi2 + 0x10);
            edx = *(int *)(edx + 0x154);
            void *ecx2 = base - 0xbc;
            (*(void (__stdcall *)(int))edx)(eax);
        }
        sub_725770();
    }

loc_423213:
    sub_41da00();
}
