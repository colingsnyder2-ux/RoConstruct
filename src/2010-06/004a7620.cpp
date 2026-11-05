// from server: 44% by atomic.potato
struct VValue {
    char pad0[0x50];
    void* field50;
    int f();
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" int __cdecl sub_7a8bea(void*, void*, void*, int, void*);

int VValue::f()
{
    void* esi = this->field50;
    if (esi == 0)
        return 0;

    void* ebx = *(void**)0x9ea90c;
    void* eax = *(void**)((char*)esi + 0x10);
    void* esp10 = eax;

    if (*(unsigned*)((char*)esi + 0xc) > (unsigned)eax)
        ((void (__stdcall*)())ebx)();

    void* ebp = *(void**)esi;
    esi = this->field50;
    void* edi = *(void**)((char*)esi + 0xc);

    if ((unsigned)edi > *(unsigned*)((char*)esi + 0x10))
        ((void (__stdcall*)())ebx)();

    esi = *(void**)esi;
    if (esi != 0)
    {
        if (esi != ebp)
            ((void (__stdcall*)())ebx)();
    }
    else
    {
        ((void (__stdcall*)())ebx)();
    }

    if (edi == esp10)
        return 0;

    while (1)
    {
        if (esi != 0)
        {
            eax = *(void**)esi;
        }
        else
        {
            ((void (__stdcall*)())ebx)();
            eax = 0;
            if ((unsigned)edi < *(unsigned*)((char*)eax + 0x10))
                ((void (__stdcall*)())ebx)();
        }

        eax = *(void**)edi;
        int r = sub_7a8bea(eax, (void*)0xb78e40, (void*)0xb87d70, 0, 0);
        if (r != 0)
            return r;

        if (esi != 0)
        {
            eax = *(void**)esi;
        }
        else
        {
            ((void (__stdcall*)())ebx)();
            eax = 0;
            if ((unsigned)edi < *(unsigned*)((char*)eax + 0x10))
                ((void (__stdcall*)())ebx)();
        }

        edi = (char*)edi + 8;

        if (edi == esp10)
            return 0;
    }
}
