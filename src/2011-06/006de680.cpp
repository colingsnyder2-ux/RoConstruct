// from server: 37% by atomic.potato
struct S_func_006de680 {
    void* m_p;
    void f(void* arg);
};

extern "C" void __stdcall sub_006de5c0(void*, void*);
extern "C" void __cdecl sub_00422920(void*, int, void*);

void S_func_006de680::f(void* arg)
{
    void* p = m_p;
    if (p) {
        void* tmp = arg;
        sub_006de5c0((char*)p + 0xc, &tmp);
        m_p = 0;
    }
    void* q = arg;
    if (q) {
        char* c = (char*)q + 0xc;
        void** begin = *(void***)(c + 4);
        void** end = *(void***)(c + 8);
        void** cap = *(void***)(c + 0xc);
        int n = begin ? (int)((char*)cap - (char*)begin) >> 2 : 0;
        int m = (int)((char*)end - (char*)begin) >> 2;
        if (m < n) {
            *(void**)end = this;
            *(void***)(c + 8) = end + 1;
            m_p = q;
        } else {
            void* tmp = this;
            sub_00422920(end, 1, &tmp);
            m_p = q;
        }
    }
}
