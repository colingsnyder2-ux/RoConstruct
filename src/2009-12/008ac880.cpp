// from server: 100% by auto
extern "C" void __cdecl G1_func_008ac880(void*);
struct S_func_008ac880 {
    virtual ~S_func_008ac880();
    void* m_p;
};
S_func_008ac880::~S_func_008ac880()
{
    if (m_p)
        G1_func_008ac880(m_p);
}
