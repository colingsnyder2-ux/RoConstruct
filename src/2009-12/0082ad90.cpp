// from server: 100% by auto
extern "C" void __cdecl G1_func_0082ad90(void*);
struct S_func_0082ad90 {
    virtual ~S_func_0082ad90();
    void* m_p;
};
S_func_0082ad90::~S_func_0082ad90()
{
    if (m_p)
        G1_func_0082ad90(m_p);
}
