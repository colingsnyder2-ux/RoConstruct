// from server: 100% by auto
extern "C" void __cdecl G1_func_0082d840(void*);
struct S_func_0082d840 {
    virtual ~S_func_0082d840();
    void* m_p;
};
S_func_0082d840::~S_func_0082d840()
{
    if (m_p)
        G1_func_0082d840(m_p);
}
