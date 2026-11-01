// from server: 100% by auto
extern "C" void __cdecl G1_func_007ba400(void*);
struct S_func_007ba400 {
    virtual ~S_func_007ba400();
    void* m_p;
};
S_func_007ba400::~S_func_007ba400()
{
    if (m_p)
        G1_func_007ba400(m_p);
}
