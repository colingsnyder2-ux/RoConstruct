// from server: 100% by auto
extern "C" void __cdecl G1_func_0083f860(void*);
struct S_func_0083f860 {
    virtual ~S_func_0083f860();
    void* m_p;
};
S_func_0083f860::~S_func_0083f860()
{
    if (m_p)
        G1_func_0083f860(m_p);
}
