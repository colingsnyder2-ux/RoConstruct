// from server: 100% by auto
extern "C" void __cdecl G1_func_00823010(void*);
struct S_func_00823010 {
    virtual ~S_func_00823010();
    void* m_p;
};
S_func_00823010::~S_func_00823010()
{
    if (m_p)
        G1_func_00823010(m_p);
}
