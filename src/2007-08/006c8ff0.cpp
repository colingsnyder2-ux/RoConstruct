// from server: 100% by auto
extern "C" void __cdecl G1_func_006c8ff0(void*);
struct S_func_006c8ff0 {
    virtual ~S_func_006c8ff0();
    void* m_p;
};
S_func_006c8ff0::~S_func_006c8ff0()
{
    if (m_p)
        G1_func_006c8ff0(m_p);
}
