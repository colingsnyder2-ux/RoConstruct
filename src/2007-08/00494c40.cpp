// from server: 43% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct SharedPtr {
    void* px;
    void* pn;
};

struct Vec {
    SharedPtr* begin;
    SharedPtr* end;
    SharedPtr* cap;
};

struct S {
    void* field0;
    void func(int, int);
};

extern "C" void __cdecl sub_417F10(void*, int, void*);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void S::func(int a, int b)
{
    Vec v;
    v.begin = 0;
    v.end = 0;
    v.cap = 0;

    void* local18 = 0;
    void* local1C = 0;
    void* local20 = 0;
    void* local24 = 0;
    void* local28 = 0;
    void* local38 = 0;
    void* local40 = 0;

    sub_417F10(&v, 1, &v);

    if (v.begin == 0 || ((char*)v.end - (char*)v.begin) >> 2 == 0) {
        _invalid_parameter_noinfo();
    }

    SharedPtr* esi = v.begin;
    void* ebp = local40;

    void* mem = sub_62FEF6(0xC);
    if (mem != 0) {
        void* edx = local38;
        *(void**)mem = (void*)0x787840;
        *(void**)((char*)mem + 4) = edx;
        *(void**)((char*)mem + 8) = ebp;
        if (ebp != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)ebp + 4), 1);
        }
    } else {
        mem = 0;
    }

    void* old = esi->px;
    esi->px = mem;
    if (old != 0) {
        void* vt = *(void**)old;
        void* fn = *(void**)vt;
        ((void (__thiscall*)(void*, int))fn)(old, 1);
    }

    void* ecx = *(void**)this;
    void* vt2 = *(void**)ecx;
    void* fn2 = *(void**)((char*)vt2 + 4);
    ((void (__thiscall*)(void*, void*))fn2)(ecx, &local18);

    SharedPtr* esi2 = v.begin;
    if (esi2 != 0) {
        SharedPtr* edi = v.end;
        if (esi2 != edi) {
            do {
                void* c = esi2->px;
                if (c != 0) {
                    void* vt3 = *(void**)c;
                    void* fn3 = *(void**)vt3;
                    ((void (__thiscall*)(void*, int))fn3)(c, 1);
                }
                esi2++;
            } while (esi2 != edi);
            esi2 = v.begin;
        }
        sub_62FC62(esi2);
    }

    v.begin = 0;
    v.end = 0;
    v.cap = 0;

    if (ebp != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 4), -1) == 1) {
            void* vt4 = *(void**)ebp;
            void* fn4 = *(void**)((char*)vt4 + 4);
            ((void (__thiscall*)(void*))fn4)(ebp);
            if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 8), -1) == 1) {
                void* vt5 = *(void**)ebp;
                void* fn5 = *(void**)((char*)vt5 + 8);
                ((void (__thiscall*)(void*))fn5)(ebp);
            }
        }
    }
}
