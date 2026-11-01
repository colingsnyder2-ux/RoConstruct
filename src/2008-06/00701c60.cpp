// from server: 100% by auto
extern "C" void __cdecl G1_func_00701c60(void*);
struct S_func_00701c60 {
    virtual ~S_func_00701c60();
    void* m_p;
};
S_func_00701c60::~S_func_00701c60()
{
    if (m_p)
        G1_func_00701c60(m_p);
}
