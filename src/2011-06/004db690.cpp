// from server: 39% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

struct Str {
    char pad[16];
    Str();
    ~Str();
};

struct Obj {
    void* vfptr;
    long ref1;
    long ref2;
};

struct Big {
    char pad0[0x1dc];
    Obj* p1dc;
    Obj* p1e0;
    void* p1e4;

    void method(void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7);
};

extern "C" {
    void __cdecl sub_4c9c90(void*);
    void __cdecl sub_4c97e0(void*, void*);
    void __cdecl sub_86b640(void*, void*, void*);
    void __cdecl sub_4f1550(void*, int);
    void __cdecl sub_4f1600(void*, void*);
    void __cdecl sub_4c8ab0(void*, void*, int);
    void __cdecl sub_4c7ba0(void*);
    void __cdecl sub_4d3bb0(void*);
    void __cdecl sub_4d3c90(void*, void*);
    void __cdecl sub_4d9d90(void*, void*);
    void __cdecl sub_4eeac0(void*, void*, int, int, int, int, int, int, void*);
    void* __cdecl sub_4ec800(void*);
    void __cdecl sub_a404d0(void*);
}

extern void* g_cb6d20;
extern void* g_cb6d24;

void Big::method(void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7)
{
    Str s1;
    void* p;
    void* edi;
    void* tmp;

    sub_4c9c90(&s1);

    p = malloc(0x114);
    if (p) {
        edi = sub_4ec800(p);
    } else {
        edi = 0;
    }

    sub_4c97e0(&s1, edi);
    sub_86b640(&s1, edi, edi);
    sub_4f1550(edi, 0x85);

    tmp = this->p1dc;
    {
        Obj* o = (Obj*)tmp;
        void* local[2];
        local[0] = o;
        local[1] = this->p1e0;
        if (local[1]) {
            _InterlockedExchangeAdd((volatile long*)((char*)local[1] + 4), 1);
        }
        sub_4d3c90(this, local);
    }

    sub_4d3bb0(edi);
    sub_4f1600(edi, &s1);

    {
        void* a = g_cb6d20;
        void* b = g_cb6d24;
        void* local[2];
        local[0] = edi;
        local[1] = this->p1e0;
        if (local[1]) {
            _InterlockedExchangeAdd((volatile long*)((char*)local[1] + 4), 1);
        }
        sub_4eeac0(this->p1e4, local, 1, 2, 2, (int)b, (int)a, 1, 0);
    }

    {
        void* local[2];
        local[0] = this->p1dc;
        local[1] = this->p1e0;
        if (local[1]) {
            _InterlockedExchangeAdd((volatile long*)((char*)local[1] + 4), 1);
        }
        sub_4c8ab0(&s1, local, 1);
    }

    sub_4d9d90(this, &s1);
    sub_4c7ba0(&s1);

    if (edi) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)edi + 4), -1) == 1) {
            void** vt = *(void***)edi;
            ((void (__thiscall*)(void*))vt[1])(edi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)edi + 8), -1) == 1) {
                void** vt2 = *(void***)edi;
                ((void (__thiscall*)(void*))vt2[2])(edi);
            }
        }
    }

    sub_a404d0(&s1);
}
