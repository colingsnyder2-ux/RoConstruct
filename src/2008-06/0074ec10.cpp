// from server: 100% by auto
extern "C" void __cdecl G1_func_0074ec10(void*);
struct S_func_0074ec10 {
    virtual ~S_func_0074ec10();
    void* m_p;
};
S_func_0074ec10::~S_func_0074ec10()
{
    if (m_p)
        G1_func_0074ec10(m_p);
}
