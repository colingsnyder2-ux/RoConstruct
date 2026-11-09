// from server: 21% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct P_func_007517d0 { void g(); };
struct S_func_007517d0 {
    char pad[408];
    P_func_007517d0* m_p;
    void f();
};

struct P_func_00757f80 { void g(); };
struct S_func_00757f80 {
    char pad[408];
    P_func_00757f80* m_p;
    void f();
};

struct P_func_00751220 { int g(); };
struct S_func_00751220 {
    char pad[408];
    P_func_00751220* m_p;
    int f();
};

struct P_func_00439330 { void g(); };
struct S_func_00439330 {
    char pad[408];
    P_func_00439330* m_p;
    void f();
};

struct S_func_0082ece0 {
    char pad[4];
    char* m_begin;
    char* m_end;
    void f();
};

void S_func_0082ece0::f()
{
    char* begin = m_begin;
    char* end = m_end;
    int count = (int)((end - begin) >> 3);
    for (int i = 0; i < count; ++i) {
        char* elem = begin + i * 8;
        void* local[2];
        ((S_func_00439330*)elem)->f();
        void* p0 = local[0];
        void* p1 = local[1];
        void* args[2];
        args[0] = p0;
        args[1] = p1;
        if (p1) {
            _InterlockedExchangeAdd((volatile long*)((char*)p1 + 4), 1);
        }
        if (((S_func_00751220*)args)->f()) {
            ((S_func_00757f80*)p0)->f();
            ((S_func_007517d0*)p0)->f();
        }
        if (p1) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)p1 + 4), -1) == 1) {
                (*(void(**)(void*))p1)(p1);
                if (_InterlockedExchangeAdd((volatile long*)((char*)p1 + 8), -1) == 1) {
                    (*(void(**)(void*))p1)(p1);
                }
            }
        }
    }
}
