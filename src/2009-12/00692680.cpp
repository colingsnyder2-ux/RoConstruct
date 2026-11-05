// from server: 40% by atomic.potato
struct RBX_Tool
{
    char pad0[0x4c];
    void* field_4c;
    int method();
};

extern "C" int __cdecl sub_6AA8F0();
extern "C" char __cdecl sub_6998B0(void*);
extern "C" int __cdecl sub_692260(void*, void*);
extern "C" int __cdecl sub_46D0C0(void*);
extern "C" int __cdecl sub_7F4AAA(void*, void*, void*, void*, void*);
extern "C" int __cdecl sub_6959B0(void*, int, int);

int RBX_Tool::method()
{
    int edi;
    if (sub_6AA8F0() == 0)
    {
        edi = 0;
    }
    else if (!sub_6998B0(this))
    {
        edi = 1;
    }
    else
    {
        edi = sub_692260(this, field_4c);
    }

    void* eax;
    if (this != 0)
    {
        eax = field_4c;
        if (eax != 0)
        {
            void* ecx = *(void**)((char*)eax + 0x4c);
            if (ecx != 0)
            {
                sub_46D0C0(ecx);
            }
        }
        else
        {
            eax = this;
        }
        if (eax != 0)
        {
            eax = (void*)sub_7F4AAA(eax, 0, (void*)0xaffe40, (void*)0xb03de8, 0);
            if (eax == 0)
                eax = 0;
        }
    }
    else
    {
        eax = 0;
    }

    return sub_6959B0(this, edi, (int)eax);
}
