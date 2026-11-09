// from server: 100% by auto
extern "C" void __cdecl G1_func_0077bc70(void*);
struct S_func_0077bc70 {
    virtual ~S_func_0077bc70();
    void* m_p;
};
S_func_0077bc70::~S_func_0077bc70()
{
    if (m_p)
        G1_func_0077bc70(m_p);
}
