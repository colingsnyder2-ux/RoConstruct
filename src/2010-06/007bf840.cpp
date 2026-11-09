// from server: 100% by auto
extern "C" void __cdecl G1_func_007bf840(void*);
struct S_func_007bf840 {
    virtual ~S_func_007bf840();
    void* m_p;
};
S_func_007bf840::~S_func_007bf840()
{
    if (m_p)
        G1_func_007bf840(m_p);
}
