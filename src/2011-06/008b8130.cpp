// from server: 100% by auto
extern "C" void __cdecl G1_func_008b8130(void*);
struct S_func_008b8130 {
    virtual ~S_func_008b8130();
    void* m_p;
};
S_func_008b8130::~S_func_008b8130()
{
    if (m_p)
        G1_func_008b8130(m_p);
}
