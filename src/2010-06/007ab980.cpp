// from server: 100% by auto
extern "C" void __cdecl G1_func_007ab980(void*);
struct S_func_007ab980 {
    virtual ~S_func_007ab980();
    void* m_p;
};
S_func_007ab980::~S_func_007ab980()
{
    if (m_p)
        G1_func_007ab980(m_p);
}
