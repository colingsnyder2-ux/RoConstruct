// from server: 49% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" void* __cdecl sub_642ee0();
extern "C" void* __cdecl sub_7f3860(int);
extern "C" void __cdecl sub_7890d0(void*, int, int);
extern "C" void __cdecl sub_789310(void*, int, int);
extern "C" void __cdecl sub_6a5ba0(void*, void*);

extern void* g_98b760;
extern int g_b8ffe0;
extern void* g_9ba1d4;

struct S {
    int f(void* a, void* b, void* c, void* d, void* e);
};

int S::f(void* a, void* b, void* c, void* d, void* e)
{
    void (*fail)() = (void (*)())g_98b760;
    if (a != 0 && a != b) {
    } else {
        fail();
    }

    int n = ((int)c - (int)b) >> 3;
    sub_7890d0(e, n, 0);

    void* p = 0;
    if (a != 0 && a != b) {
    } else {
        fail();
    }

    void* cur = b;
    void* end = c;
    while (cur != end) {
        void* obj = a;
        if (obj == 0) {
            fail();
            obj = a;
            if (obj == 0) {
                obj = 0;
            } else {
                obj = *(void**)obj;
            }
        } else {
            obj = *(void**)obj;
        }
        if ((unsigned)cur < *(unsigned*)((char*)obj + 0x10)) {
        } else {
            fail();
        }

        void* esi = cur;
        g_b8ffe0++;
        sub_642ee0();
        void* mem = sub_7f3860(0xc);
        if (mem != 0) {
            *(void**)mem = &g_9ba1d4;
            *(void**)((char*)mem + 4) = *(void**)esi;
            void* rc = *(void**)((char*)esi + 4);
            *(void**)((char*)mem + 8) = rc;
            if (rc != 0) {
                _InterlockedExchangeAdd((volatile long*)((char*)rc + 4), 1);
            }
        } else {
            mem = 0;
        }
        void* tmp = mem;
        sub_6a5ba0(&tmp, e);
        void* q = tmp;
        if (q != 0) {
            (*(void (***)(void*, int))q)[0](q, 1);
        }
        int idx = *(int*)((char*)&tmp + 0);
        idx++;
        *(int*)((char*)&tmp + 0) = idx;
        sub_789310(e, -2, idx);

        void* obj2 = a;
        if (obj2 == 0) {
            fail();
            obj2 = a;
            if (obj2 == 0) {
                obj2 = 0;
            } else {
                obj2 = *(void**)obj2;
            }
        } else {
            obj2 = *(void**)obj2;
        }
        if ((unsigned)cur < *(unsigned*)((char*)obj2 + 0x10)) {
        } else {
            fail();
        }
        cur = (char*)cur + 8;
    }
    return 1;
}
