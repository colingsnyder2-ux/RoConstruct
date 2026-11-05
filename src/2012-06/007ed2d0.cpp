// from server: 26% by atomic.potato
extern "C" float __cdecl sub_736080(int);
extern "C" float __cdecl sub_7eb680(int, int, int, int, float);
extern "C" int __cdecl sub_7ecce0();
extern "C" int __cdecl sub_7ecd30(int, void*);
extern "C" void* __cdecl sub_4c32b0(void*, void*);
extern "C" void* __cdecl sub_627310();
extern "C" void* __cdecl sub_7ae4f0(int, int, int, int);
extern "C" void* __cdecl sub_7ae490(int, int);
extern "C" void* __cdecl sub_7ae430(int, int);

extern "C" float g_b62770;
extern "C" float g_b5abb8;

struct VFrame {
    char pad0[0xb0];
    char flag_b0;
    void* method(int, int, int, int, int, int, int, int, int, int, int, int);
};

void* VFrame::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    float f = sub_736080(a1);
    int* esi = (int*)a2;
    float local10 = 0.0f;
    float local14 = 0.0f;
    float half = g_b62770;

    if (a5 != 0)
    {
        float r = sub_7eb680(a1, a2, a3, a4, f);
        f = r;
    }

    int eax = a9;
    if (eax == 0)
    {
        local10 = *(float*)esi;
    }
    else if (eax == 1)
    {
        local10 = *(float*)((char*)esi + 8);
    }
    else if (eax == 2)
    {
        local10 = (*(float*)((char*)esi + 8) + *(float*)esi) * half;
    }

    int ebx = a10;
    if (ebx == 0)
    {
        local14 = *(float*)((char*)esi + 4);
    }
    else if (ebx == 1)
    {
        local14 = (*(float*)((char*)esi + 0xc) + *(float*)((char*)esi + 4)) * half;
    }
    else if (ebx == 2)
    {
        local14 = *(float*)((char*)esi + 0xc);
    }

    int r = sub_7ecce0();
    float local28[4];
    void* ebp;

    if (r != 0)
    {
        sub_7ecd30(r, local28);
        if (flag_b0 != 0)
        {
            void* p = sub_4c32b0(local28, esi);
            local28[0] = *(float*)p;
            local28[1] = *(float*)((char*)p + 4);
            local28[2] = *(float*)((char*)p + 8);
            local28[3] = *(float*)((char*)p + 0xc);
        }
        float local18[2];
        void* eax2;
        if (a6 != 0)
        {
            local18[0] = *(float*)((char*)esi + 8) - *(float*)esi;
            local18[1] = *(float*)((char*)esi + 0xc) - *(float*)((char*)esi + 4);
            eax2 = local18;
        }
        else
        {
            eax2 = sub_627310();
        }
        int* edi = (int*)a1;
        int* esi2 = (int*)*edi;
        void* v1 = sub_7ae4f0(ebx, 0, (int)eax2, (int)local28);
        void* v2 = sub_7ae490(a9, (int)v1);
        void* v3 = sub_7ae430(a7, (int)v2);
        int* vt = (int*)((char*)esi2 + 0x44);
        int (*fn)(int, int, int, int, int, int, int, int, int, int, int, int) = (int (*)(int, int, int, int, int, int, int, int, int, int, int, int))vt[0];
        fn(a1, a7, a8, (int)local28, a11, a12, (int)v3, a3, a4, a5, a6, a10);
        return (void*)ebx;
    }
    else
    {
        if (flag_b0 != 0)
        {
            ebp = esi;
        }
        else
        {
            local28[0] = g_b5abb8;
            local28[1] = g_b5abb8;
            local28[2] = g_b5abb8;
            local28[3] = g_b5abb8;
            ebp = local28;
        }
        float local18[2];
        void* eax2;
        if (a6 != 0)
        {
            local18[0] = *(float*)((char*)esi + 8) - *(float*)esi;
            local18[1] = *(float*)((char*)esi + 0xc) - *(float*)((char*)esi + 4);
            eax2 = local18;
        }
        else
        {
            eax2 = sub_627310();
        }
        int* edi = (int*)a1;
        int* esi2 = (int*)*edi;
        void* v1 = sub_7ae4f0(ebx, 0, (int)eax2, (int)ebp);
        void* v2 = sub_7ae490(a9, (int)v1);
        void* v3 = sub_7ae430(a7, (int)v2);
        int* vt = (int*)((char*)esi2 + 0x44);
        int (*fn)(int, int, int, int, int, int, int, int, int, int, int, int) = (int (*)(int, int, int, int, int, int, int, int, int, int, int, int))vt[0];
        fn(a1, a7, a8, (int)local28, a11, a12, (int)v3, a3, a4, a5, a6, a10);
        return (void*)ebx;
    }
}
