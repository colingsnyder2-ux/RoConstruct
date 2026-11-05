// from server: 14% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);
extern "C" void __cdecl _invalid_parameter_noinfo();

struct T4_007453a0 {
    char pad0[0x10];
    int m_refcount;
    char pad14[0x0c];
    char m_queue[0x38];
    int m_field58;

    void f_007453a0(int a1, int a2, int a3, int a4);
};

struct H1 { void f(void*, void*, void*, void*, void*, void*); };
struct H2 { void f(void*, void*); };
struct H3 { void f(void*, void*, void*, void*); };
struct H4 { void f(void*, int); };
struct H5 { void f(void*); };
struct H6 { void f(void*, void*, void*); };

extern "C" int __cdecl sub_00745180(T4_007453a0*, int);
extern "C" void __cdecl sub_00418840(void*);
extern "C" void __cdecl sub_00741c10(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_007432b0(void*, void*);
extern "C" void __cdecl sub_00743820(void*, void*, void*, void*);
extern "C" void __cdecl sub_007407e0(void*, int);
extern "C" void __cdecl sub_00743320(void*);
extern "C" void __cdecl sub_00743670(void*, void*);
extern "C" void __cdecl sub_00740fb0(void*, void*);
extern "C" void __cdecl sub_005e9bb0(void*, void*);
extern "C" void __cdecl sub_0066fe00(void*, void*);
extern "C" void __cdecl sub_00742ec0(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_00741ae0(void*, void*, void*);
extern "C" void __cdecl sub_00743a00(void*, void*);
extern "C" void __cdecl sub_006ace50(void*, void*);
extern "C" void __cdecl sub_00410cb0();

void T4_007453a0::f_007453a0(int a1, int a2, int a3, int a4)
{
    if (sub_00745180(this, a1))
        return;

    sub_00418840(&this->m_refcount);

    int* p = (int*)&this->m_queue;
    int v = p[5];
    int w = p[0];
    sub_00741c10(&p[0], (void*)w, (void*)v, (void*)w, (void*)v, (void*)a1);

    if (p[0] != 0 && p[0] != w)
        _invalid_parameter_noinfo();

    if (p[5] != v)
    {
        if (a3 != 0)
        {
            sub_0066fe00(&p[0], (void*)a3);
            sub_00740fb0(&p[0], 0);
            sub_005e9bb0(&p[0], 0);
            sub_00743670(&p[0], 0);
        }
        goto done;
    }

    sub_007432b0(&p[0], 0);
    int e = p[5];
    sub_00743820(&p[0], (void*)e, *(void**)(e + 4), 0);
    sub_007407e0(&p[0], 1);
    *(int*)(e + 4) = 0;
    sub_00743320(&p[0]);

    int* q = (int*)p[5];
    int* r = (int*)p[0];
    if (r == 0)
        _invalid_parameter_noinfo();
    if (q[5] == 0)
        _invalid_parameter_noinfo();
    if (r == 0)
        _invalid_parameter_noinfo();
    if (q[5] == 0)
        _invalid_parameter_noinfo();

    sub_00741ae0(&q[2], (void*)a4, 0);
    if (r == 0)
        _invalid_parameter_noinfo();
    if (q[5] == 0)
        _invalid_parameter_noinfo();

    *(float*)(q + 0x3c) = *(float*)&a2;

    if (a3 != 0)
    {
        sub_0066fe00(&p[0], (void*)a3);
        sub_00740fb0(&p[0], 0);
        sub_005e9bb0(&p[0], 0);
        sub_00743670(&p[0], 0);
    }

    sub_00742ec0(&p[0], this, r, q, 0, 0);
    sub_00741ae0(&p[0], (void*)0x7447b0, 0);
    sub_00743a00(&p[0], 0);
    sub_006ace50(&this->m_field58, 0);

done:
    if (--*(int*)&this->m_refcount == 0)
    {
        _InterlockedExchangeAdd((volatile long*)&this->m_refcount, -1);
        if (_InterlockedExchangeAdd((volatile long*)&this->m_refcount, 0x80000000) == 0x80000000)
        {
            sub_00410cb0();
            SetEvent(0);
        }
    }
}
