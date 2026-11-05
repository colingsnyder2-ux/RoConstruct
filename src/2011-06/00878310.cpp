// from server: 100% by auto
extern "C" void __cdecl G1_func_00878310(void*);
struct S_func_00878310 {
    virtual ~S_func_00878310();
    void* m_p;
};
S_func_00878310::~S_func_00878310()
{
    if (m_p)
        G1_func_00878310(m_p);
}
