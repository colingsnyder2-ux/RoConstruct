// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

struct S_func_0071edc0 {
    char pad0[8];
    int* f(int);
};

struct S_func_0075e8b0 {
    int f();
};

struct S_func_0075e9f0 {
    int f(int, int);
};

struct S_func_0080b2ea {
    int f(int, int, int, int, int);
};

struct S_func_006eb330 {
    int f(int, int, int, int, int);
};

struct S_00605430 {
    char pad0[0x48];
    void* m_48;
    int __cdecl f(int);
};

int S_00605430::f(int a)
{
    int result = 0;
    S_func_0080b2ea* p = (S_func_0080b2ea*)0;
    int r = ((int (__cdecl*)(int,int,int,int,int))0x80b2ea)(a, 0, 0xc071f8, 0xc0beec, 0);
    if (r != 0) {
        S_func_0066c140* obj = (S_func_0066c140*)r;
        int* pi = obj->f();
        int i = 0;
        do {
            S_func_0071edc0* q = (S_func_0071edc0*)pi;
            int* r2 = q->f(i);
            S_func_0075e8b0* s = (S_func_0075e8b0*)r2;
            if (s->f() == 2) {
                S_func_0071edc0* q2 = (S_func_0071edc0*)pi;
                int* r3 = q2->f(i);
                S_func_0075e9f0* t = (S_func_0075e9f0*)r3;
                t->f(0, 3);
            }
            i++;
        } while (i < 6);
    }
    if (m_48 != 0) {
        void* v = m_48;
        int* edx = *(int**)((char*)v + 8);
        int* eax = *(int**)((char*)v + 4);
        ((int (__cdecl*)(int*, int, int*, int, int))0x6eb330)((int*)&result, (int)eax, edx, 0x605430, a);
    }
    if (a != 0) {
        volatile long* ref = (volatile long*)((char*)a + 4);
        if (_InterlockedExchangeAdd(ref, -1) == 1) {
            int* vt = *(int**)a;
            ((void (__cdecl*)(int))vt[1])(a);
            volatile long* ref2 = (volatile long*)((char*)a + 8);
            if (_InterlockedExchangeAdd(ref2, -1) == 1) {
                int* vt2 = *(int**)a;
                ((void (__cdecl*)(int))vt2[2])(a);
            }
        }
    }
    return result;
}
