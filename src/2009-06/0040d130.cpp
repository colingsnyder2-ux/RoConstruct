// from server: 100% by why2
extern "C" void (__cdecl *free)(void*);

struct S_func_0040d130 {
    void* m_ptr;
    int m_count;
    void f();
};

void S_func_0040d130::f()
{
    if (m_count > 0) {
        free(m_ptr);
    }
}
