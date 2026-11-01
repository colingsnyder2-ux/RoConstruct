// from server: 100% by auto
extern "C" void __cdecl G1_func_00729a90(void*);
struct S_func_00729a90 {
    virtual ~S_func_00729a90();
    void* m_p;
};
S_func_00729a90::~S_func_00729a90()
{
    if (m_p)
        G1_func_00729a90(m_p);
}
