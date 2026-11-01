// from server: 100% by auto
extern "C" void __cdecl G1_func_007bf900(void*);
struct S_func_007bf900 {
    virtual ~S_func_007bf900();
    void* m_p;
};
S_func_007bf900::~S_func_007bf900()
{
    if (m_p)
        G1_func_007bf900(m_p);
}
