// from server: 42% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_630D23(void*);
extern "C" void __cdecl sub_725750(void*);
extern "C" void __cdecl sub_725770(void*);
extern "C" void __cdecl sub_4245E0(void*, void*);
extern "C" void __cdecl sub_402A60(void*, void*);
extern "C" void* __cdecl sub_62FF02();
extern "C" void __cdecl sub_62FF1A(void*, void*);
extern "C" void __cdecl sub_40AA00(void*, void*, void*);
extern "C" void __cdecl sub_444900(void*, void*);

extern "C" void* __stdcall func_77ddac(void*);
extern "C" void* __stdcall func_77dd98(void*);
extern "C" void* __stdcall func_77ddb8(void*, void*);
extern "C" void* __stdcall func_77dcc8(void*);
extern "C" void* __stdcall func_77d560(void*, void*);
extern "C" void* __stdcall func_77ebd4(void*);
extern "C" void* __stdcall func_77d55c(void*, void*);
extern "C" void* __stdcall func_77e698(void*);
extern "C" void* __stdcall func_77ddbc(void*);

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakRefCount;
};

struct GlobalState {
    void* field0;
    void* field4;
};

extern GlobalState g_state_8bba14;
extern void* g_ptr_8bba18;
extern int g_flag_8bba1c;

struct VItemResult {
    void* field0;
    void* field4;
};

void __cdecl sub_444B70(VItemResult* result)
{
    void* local_10 = 0;
    void* local_14 = 0;
    void* local_18 = 0;
    void* local_1c = 0;

    if ((g_flag_8bba1c & 1) == 0) {
        g_flag_8bba1c |= 1;
        g_state_8bba14.field0 = 0;
        g_state_8bba14.field4 = 0;
        sub_630D23((void*)0x777a90);
    }

    sub_725750((void*)0x8bbacc);

    if (g_state_8bba14.field0 == 0) {
        sub_4245E0(&local_18, 0);
        g_state_8bba14.field0 = *(void**)local_18;
        sub_402A60((void*)0x8bba18, (char*)local_18 + 4);

        RefCounted* rc = (RefCounted*)local_1c;
        if (rc != 0) {
            if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
                void** vt = (void**)rc->vptr;
                typedef void (__stdcall *Fn)(void*);
                ((Fn)vt[1])(rc);
                if (_InterlockedExchangeAdd(&rc->weakRefCount, -1) == 1) {
                    ((Fn)vt[2])(rc);
                }
            }
        }

        func_77ddac(&local_10);

        void* p = sub_62FF02();
        void* q = *(void**)((char*)p + 4);
        void* r = *(void**)((char*)q + 0x44);
        sub_62FF1A(&local_10, r);

        void* s = func_77dd98(&local_10);
        func_77ddb8(&local_10, s);

        void* t = func_77dcc8(&local_14);
        void* u = func_77d560(&local_10, t);
        func_77ebd4(u);

        func_77d55c(&local_10, (void*)-1);

        sub_40AA00(&local_18, &local_10, (void*)0x78f9b0);

        void* v = func_77dd98(&local_18);
        void* w = func_77e698(v);
        sub_444900((void*)g_state_8bba14.field0, w);

        func_77ddbc(&local_14);
        func_77ddbc(&local_10);
        func_77ddbc(&local_18);
    }

    sub_725770((void*)0x8bbacc);

    result->field0 = g_state_8bba14.field0;
    result->field4 = g_state_8bba14.field4;

    if (g_state_8bba14.field4 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)g_state_8bba14.field4 + 4), 1);
    }
}
