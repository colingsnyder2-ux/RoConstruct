// from server: 100% by auto
extern "C" void __cdecl G1_func_0079ce70(void*);
struct S_func_0079ce70 {
    virtual ~S_func_0079ce70();
    void* m_p;
};
S_func_0079ce70::~S_func_0079ce70()
{
    if (m_p)
        G1_func_0079ce70(m_p);
}
