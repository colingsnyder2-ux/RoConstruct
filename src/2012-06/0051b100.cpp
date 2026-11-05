// from server: 63% by atomic.potato
struct S_func_0051b100 {
    void* m_ptr;
    void f(void* arg);
};

extern "C" bool __cdecl sub_007ccd90(void*, void*);
extern "C" void __cdecl sub_00983144(void*, void*);
extern "C" void* __cdecl sub_00b229dc();

void S_func_0051b100::f(void* arg)
{
    if (!sub_007ccd90(m_ptr, arg)) {
        void* e = sub_00b229dc();
        sub_00983144(e, (void*)0xce064c);
    }
}
