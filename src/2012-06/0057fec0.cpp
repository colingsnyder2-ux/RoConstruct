// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_004015a0(void*, void*);
extern "C" void __cdecl sub_00575830(void*, void*);
extern "C" void* __cdecl sub_0051c0f0();
extern "C" int __cdecl sub_005243f0();
extern "C" void __cdecl sub_00684200(void*, void*, int);
extern "C" void* __cdecl sub_0067f480();
extern "C" void __cdecl sub_0051b6b0();
extern "C" void __cdecl sub_00972290(int, void*);
extern "C" void* __cdecl sub_005743d0(void*, void*, void*);
extern "C" void __cdecl sub_004026a0(void*, void*);

struct S
{
    char pad0[0x84];
    int field84;
    char pad1[0x90 - 0x88];
    int field90;
    int field94;

    void __thiscall f();
};

void __thiscall S::f()
{
    void* edi;
    int local;

    if (sub_005243f0() != 0)
        return;

    sub_00575830(&local, &edi);

    sub_004015a0((void*)0xe1e19c, (void*)0x51d540);
    sub_0051c0f0();

    int idx = *(int*)((char*)this + 0x84);
    int* p = (int*)(idx + (int)sub_0051c0f0() * 8);
    *p = local;
    sub_004026a0(p + 1, &local);

    sub_00684200(edi, this, 0);

    if (edi != 0)
    {
        if ((char*)edi + 0xb8 != 0)
            *((char*)edi + 0x61) = 1;
    }

    if (*(char*)0xe580b3 != 0)
    {
        void* v;
        if (*(int*)0xb9fe10 == 0)
            v = sub_0067f480();
        else
        {
            sub_004015a0((void*)0xe1e144, (void*)0x51d0e0);
            sub_0051b6b0();
            v = 0;
        }

        void* w = sub_0067f480();
        if (v != w)
        {
            void* x;
            if (*(int*)0xb9fe10 == 0)
                x = sub_0067f480();
            else
            {
                sub_004015a0((void*)0xe1e144, (void*)0x51d0e0);
                sub_0051b6b0();
                x = 0;
            }

            int ebx = *(int*)((char*)this + 0x94);
            int tmp = (int)x;
            int* r = (int*)sub_005743d0((char*)this + 0x90, &tmp, &tmp);
            if (*r == ebx)
            {
                void* fn = *(void**)0xe5809c;
                if (fn != 0)
                {
                    if (((char(__cdecl*)(int, void*, void*))fn)(0x67, (void*)0xb466b8, (void*)0xb46640))
                        goto done;
                }
                sub_00972290(*(unsigned char*)0xe580b3, (void*)0xb46568);
            }
        }
    }

done:
    void* obj = edi;
    if (obj != 0)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 4), -1) == 1)
        {
            void** vt = *(void***)obj;
            ((void(__thiscall*)(void*))vt[1])(obj);
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 8), -1) == 1)
            {
                void** vt2 = *(void***)obj;
                ((void(__thiscall*)(void*))vt2[2])(obj);
            }
        }
    }
}
