// from server: 52% by Intel
extern "C" unsigned char g_e580b3;
extern "C" int g_e16540;
extern "C" int g_e16588;
extern "C" int g_b57680;
extern "C" int (__cdecl *g_e5809c)(const char*, const char*, unsigned int);
extern "C" void __cdecl sub_972290(unsigned char, const char*);

extern "C" const char str_b42f90[];
extern "C" const char str_b42fa8[];
extern "C" const char str_b43010[];
extern "C" const char str_b43080[];
extern "C" const char str_b4311c[];
extern "C" const char str_b43160[];
extern "C" const char str_b431d0[];
extern "C" const char str_b431e8[];
extern "C" const char str_b43284[];
extern "C" const char str_40ca10[];

struct Value { int x; };
Value& func_0040bee0();
void* sub_004015a0(int, int);
void* sub_004019d0(void*);
void* sub_00466420(void*);
void* sub_00457100(void*);
void sub_0067f480();

struct FactoryProduct {
    void* method();
};

void* FactoryProduct::method()
{
    int v1;
    int v2;
    int v3;

    int* this_ptr = &v1;
    this_ptr = (int*)this;

    *this_ptr = 0xb44710;

    if (g_b57680 == 0)
    {
        sub_0067f480();
    }
    else
    {
        sub_004015a0((int)str_40ca10, g_e16588);
        func_0040bee0();
    }

    void* edi = sub_004019d0(&v2);

    if (g_e580b3 != 0)
    {
        v3 = (int)edi;
        void* esi_ptr = sub_004019d0(&v2);
        int esi = *(int*)((int)esi_ptr + 4);
        void* eax_ptr = sub_004019d0(&v3);
        int eax_val = *(int*)sub_00466420(eax_ptr);

        if (eax_val != esi)
        {
            if (g_e5809c != 0)
            {
                if (g_e5809c(str_b43284, str_b42fa8, 0xd7))
                {
                    goto LABEL_C0;
                }
            }
            sub_972290(g_e580b3, str_b431e8);
        }
    LABEL_C0:
        if (g_e580b3 != 0)
        {
            if (g_e16540 != 0x29a)
            {
                if (g_e5809c != 0)
                {
                    if (g_e5809c(str_b431d0, str_b42fa8, 0xd8))
                    {
                        goto LABEL_10B;
                    }
                }
                sub_972290(g_e580b3, str_b43160);
            }
        LABEL_10B:
            v3 = (int)edi;
            void* esi_ptr2 = sub_004019d0(&v2);
            int esi2 = *(int*)((int)esi_ptr2 + 4);
            void* eax_ptr2 = sub_004019d0(&v3);
            int eax_val2 = *(int*)sub_00466420(eax_ptr2);

            if (eax_val2 == esi2)
            {
                if (g_e580b3 != 0)
                {
                    if (g_e16540 == 0x29a)
                    {
                        if (g_e5809c != 0)
                        {
                            if (g_e5809c(str_b4311c, str_b42fa8, 0xdd))
                            {
                                goto LABEL_1E0;
                            }
                        }
                        sub_972290(g_e580b3, str_b43080);
                    }
                }
            }
            else
            {
                if (g_e580b3 != 0)
                {
                    if (g_e16540 != 0x29a)
                    {
                        if (g_e5809c != 0)
                        {
                            if (g_e5809c(str_b42f90, str_b42fa8, 0xde))
                            {
                                goto LABEL_1E0;
                            }
                        }
                        sub_972290(g_e580b3, str_b43010);
                    }
                }
            }
        LABEL_1E0:;
        }
    }

    v3 = (int)edi;
    void* eax_ptr3 = sub_004019d0(&v3);
    *(int*)sub_00457100(eax_ptr3) = (int)this_ptr;

    g_e16540 = 0x29a;

    return this_ptr;
}
