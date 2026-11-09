// from server: 38% by Viper
struct CRbxPlayDocTemplate
{
    char pad[0x20];
    void* field_0x20;
    void* field_0x24;
    void* field_0x28;
    void* field_0x2c;
    void sub_6306ca(void*);
    void* func_00447f30(void*);
    void sub_6306d6();
};

extern "C" void* __stdcall sub_62fef6(unsigned int);

extern "C" void __stdcall sub_630724(void*, void*, void*, int);
extern "C" void* __stdcall sub_453520();
extern "C" void* __stdcall sub_455e10();
extern "C" void* __stdcall sub_40ec30();
extern "C" void* __stdcall sub_44d010();
extern "C" void* __stdcall sub_40a7c0();
extern "C" void* __stdcall sub_40ec20();
extern "C" void* __stdcall sub_40a7f0();
extern "C" void* __stdcall sub_45f910();
extern "C" void* __stdcall sub_630304();
extern "C" void* __stdcall sub_45f8f0();
extern "C" void* __stdcall sub_434180();
extern "C" void* __stdcall sub_434040();

void* CRbxPlayDocTemplate::func_00447f30(void* arg)
{
    void* p;
    void* q;

    sub_6306d6();
    *(void**)this = (void*)0x790524;

    p = sub_62fef6(0x94);
    if (p != 0)
    {
        if (*(unsigned char*)arg != 0)
            q = sub_453520();
        else
            q = sub_455e10();
        void* a = sub_40ec30();
        void* b = sub_44d010();
        sub_630724(q, a, b, 0x81);
        *(void**)p = (void*)0x79048c;
        *(void**)((char*)p + 0x90) = 0;
    }
    else
    {
        p = 0;
    }
    sub_6306ca(p);
    field_0x24 = p;

    p = sub_62fef6(0x90);
    if (p != 0)
    {
        void* a = sub_40a7c0();
        void* b = sub_40ec20();
        void* c = sub_40a7f0();
        sub_630724(a, b, c, 0xb9);
        *(void**)p = (void*)0x7903f4;
    }
    else
    {
        p = 0;
    }
    sub_6306ca(p);
    field_0x20 = p;

    p = sub_62fef6(0x90);
    if (p != 0)
    {
        void* a = sub_45f910();
        void* b = sub_630304();
        void* c = sub_45f8f0();
        sub_630724(a, b, c, 0xcf);
        *(void**)p = (void*)0x7903f4;
    }
    else
    {
        p = 0;
    }
    sub_6306ca(p);
    field_0x28 = p;

    p = sub_62fef6(0x90);
    if (p != 0)
    {
        void* a = sub_434180();
        void* b = sub_630304();
        void* c = sub_434040();
        sub_630724(a, b, c, 0x8a);
        *(void**)p = (void*)0x7903f4;
    }
    else
    {
        p = 0;
    }
    sub_6306ca(p);
    field_0x2c = p;

    return this;
}
