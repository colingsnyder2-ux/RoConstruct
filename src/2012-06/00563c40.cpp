// from server: 29% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Value { int x; };

struct Desc0 { int pad[8]; };
extern Desc0 g_00b7af8c;

Value& sub_0067f2e0(void*);
Value& func_00561ed0();
void* func_00561fb0();

extern "C" void __cdecl sub_004015a0(const char*, const char*);
extern "C" void __cdecl sub_004026a0();
extern "C" void __cdecl sub_005632f0(int*);
extern "C" int  __cdecl sub_00563960();
extern "C" int* __cdecl sub_005743d0(int*, int*, int*);
extern "C" void* __cdecl sub_0067f480();
extern "C" void __cdecl sub_00684200();
extern "C" void __cdecl sub_00972290(unsigned char, const char*);

extern unsigned char g_00e580b3;
extern unsigned char g_00e5809c;
extern int g_00b7af8c_dummy;

struct S {
    char pad0[0x84];
    int field84;
    char pad88[0x90 - 0x88];
    int field90;
    int field94;
    int f();
};

int S::f()
{
    if (sub_00563960() != 0)
        return 0;

    int local10 = 0;
    sub_005632f0(&local10);

    int edi = local10;

    sub_004015a0((const char*)0xe2435c, (const char*)0x562620);

    int idx = (int)func_00561fb0();
    int* arr = (int*)field84;
    arr[idx * 2] = edi;
    sub_004026a0();

    sub_00684200();

    if (edi != 0) {
        if ((edi + 0x80) != 0)
            *(unsigned char*)(edi + 0x61) = 1;
    }

    if (g_00e580b3 != 0) {
        void* ebx;
        if (g_00b7af8c_dummy == 0) {
            ebx = sub_0067f480();
        } else {
            sub_004015a0((const char*)0xe24354, (const char*)0x562510);
            ebx = (void*)&func_00561ed0();
        }
        void* eax = sub_0067f480();
        if (ebx != eax) {
            void* eax2;
            if (g_00b7af8c_dummy == 0) {
                eax2 = sub_0067f480();
            } else {
                sub_004015a0((const char*)0xe24354, (const char*)0x562510);
                eax2 = (void*)&func_00561ed0();
            }
            int ebx2 = field94;
            int tmp = (int)eax2;
            int* p = sub_005743d0(&field90, &tmp, &local10);
            if (*p == ebx2) {
                if (g_00e5809c != 0) {
                    if (((unsigned char(__cdecl*)(int, const char*, const char*))g_00e5809c)(0x67, (const char*)0xb466b8, (const char*)0xb46640) != 0)
                        goto done;
                }
                sub_00972290(g_00e580b3, (const char*)0xb46568);
            }
        }
    }
done:
    {
        int* esi = (int*)local10;
        if (esi != 0) {
            if (_InterlockedExchangeAdd((volatile long*)(esi + 1), -1) == 1) {
                void (__thiscall *fn)(void*) = *(void(__thiscall**)(void*))(*(int*)esi + 4);
                fn(esi);
                if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                    void (__thiscall *fn2)(void*) = *(void(__thiscall**)(void*))(*(int*)esi + 8);
                    fn2(esi);
                }
            }
        }
    }
    return edi;
}
