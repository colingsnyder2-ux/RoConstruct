// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_004edb60 {
    void *m_owner;
    void *m_ptr;
    void f(void *arg);
};

void S_func_004edb60::f(void *arg)
{
    m_owner = arg;
    m_ptr = 0;
    if (arg) {
        void **slot = (void **)((char *)arg + 8);
        if (slot) {
            slot[0] = arg;
            void *old = m_ptr;
            if (old != slot[1]) {
                if (old) {
                    _InterlockedExchangeAdd((volatile long *)((char *)old + 8), 1);
                }
                void *cur = slot[1];
                if (cur) {
                    if (_InterlockedExchangeAdd((volatile long *)((char *)cur + 8), -1) == 1) {
                        void **vt = *(void ***)cur;
                        ((void (__stdcall *)(void *))vt[2])(cur);
                    }
                }
                slot[1] = old;
            }
        }
    }
}
