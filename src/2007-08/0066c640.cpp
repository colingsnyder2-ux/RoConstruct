// from server: 100% by auto
extern "C" void __cdecl G1_func_0066c640(void*);
struct S_func_0066c640 {
    virtual ~S_func_0066c640();
    void* m_p;
};
S_func_0066c640::~S_func_0066c640()
{
    if (m_p)
        G1_func_0066c640(m_p);
}
