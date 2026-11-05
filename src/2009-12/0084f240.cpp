// from server: 100% by auto
extern "C" void __cdecl G1_func_0084f240(void*);
struct S_func_0084f240 {
    virtual ~S_func_0084f240();
    void* m_p;
};
S_func_0084f240::~S_func_0084f240()
{
    if (m_p)
        G1_func_0084f240(m_p);
}
