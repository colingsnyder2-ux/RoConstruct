// from server: 34% by atomic.potato
typedef void (__cdecl *FunctionType)(void *);

extern "C" void __cdecl Function_0080A058(void *);

struct CVideoStreamFilter_004A3390 {
    char pad0[8];
    void *m_head;
    void f();
};

void CVideoStreamFilter_004A3390::f()
{
    void *p = m_head;
    while (p != 0) {
        void *next = *((void **)p + 1);
        Function_0080A058(p);
        p = next;
    }
}
