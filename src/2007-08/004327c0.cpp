// from server: 62% by colin
struct CMainFrame {
    char pad[0x3c8];
    void* field3c8;
    char pad2[0x3c8 + 4 - 0x3c8 - 4];

    int func(int a1);
};

extern "C" int __stdcall sub_6305C8(int);
extern "C" int __stdcall sub_692CE0(void*, int, int, int);
extern "C" int __stdcall sub_693A20(void*, const char*, int);
extern "C" int __stdcall sub_42F140(void*, const char*);
extern "C" int __stdcall sub_691ED0(void*, int);
extern "C" int __stdcall sub_63DCB0(int);
extern "C" int __stdcall sub_66E8F0(void*, void*, int);
extern "C" int __stdcall sub_66F770(void*, int);
extern "C" int __stdcall sub_68B250(void*, void*, int);
extern "C" int __stdcall sub_689740(void*);
extern "C" int __stdcall sub_689BB0(void*, int);
extern "C" int __stdcall sub_6321F0(void*, int, int);
extern "C" int __stdcall sub_64E990(void*);
extern "C" int __stdcall sub_631B60(void*, int);
extern "C" int __stdcall sub_632200(void*, int);
extern "C" int __stdcall sub_694D30(void*);
extern "C" int __stdcall sub_64DFD0(void);
extern "C" int __stdcall sub_632AE0(void*, void*);
extern "C" int __stdcall sub_4317A0(void*, int);
extern "C" int __stdcall sub_42FB70(void*);
extern "C" int __stdcall sub_430970(void*);
extern "C" int __stdcall sub_62FF02(void);
extern "C" int __stdcall sub_6305C2(void*, const char*, const char*, int);
extern "C" int __stdcall sub_432380(void*, int);
extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);
extern "C" int __stdcall InterlockedIncrement(int*);

int CMainFrame::func(int a1)
{
    int result = sub_6305C8(a1);
    if (result == -1)
        return result;
    if (sub_692CE0((char*)this + 0x3c8, 0x50008200, 0xe801, (int)this) == 0)
        goto end;
    if (sub_693A20((char*)this + 0x3c8, (const char*)0x8869f0, 5) == 0)
        goto end;
    if (sub_42F140(this, (const char*)0x78a6d4) == 0)
        return -1;
    sub_691ED0((char*)this + 0x39c, 2);
    sub_63DCB0(4);
    sub_66E8F0((char*)this + 0x120, this, 1);
    sub_66F770((char*)this + 0x120, 9);
    sub_68B250((char*)this + 0x26c, this, 0);
    {
        int* p = (int*)sub_689740((char*)this + 0x26c);
        p[9] = 0;
    }
    sub_689BB0((char*)this + 0x26c, 1);
    {
        void* edi = *(void**)((char*)this + 0xd8);
        if (edi == 0)
            goto end;
        {
            void* eax = (void*)sub_6321F0(edi, 0x91, 0);
            sub_64E990(eax);
        }
        *(int*)((char*)this + 0x218) = 1;
        *(int*)((char*)this + 0x21c) = 1;
        sub_631B60(*(void**)((char*)edi + 0x74), 2);
        {
            void* eax = (void*)sub_632200(edi, 2);
            sub_694D30(eax);
        }
        {
            int eax = sub_64DFD0();
            PostMessageA((void*)(eax + 4), 0, 0, 0);
        }
        {
            int eax = sub_64DFD0();
            sub_632AE0(edi, (void*)eax);
        }
        {
            int eax = sub_64DFD0();
            sub_64E990((void*)eax);
        }
        *(char*)((char*)this + 0xec) = 1;
        sub_4317A0(this, 1);
        {
            int eax = sub_64DFD0();
            sub_42FB70((void*)eax);
        }
        sub_430970(this);
        {
            int eax = sub_62FF02();
            int* p = *(int**)(eax + 4);
            int r = sub_6305C2(p, (const char*)0x78b110, (const char*)0x78b11c, 0);
            if (r == 1)
                sub_432380(this, r);
        }
        PostMessageA(*(void**)((char*)this + 0x20), 0x111, 0x8101, 0);
    }
end:
    return 0;
}
