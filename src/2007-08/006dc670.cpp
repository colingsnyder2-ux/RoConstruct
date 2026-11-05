// from server: 100% by auto
extern "C" void __cdecl G1_func_006dc670(void*);
struct S_func_006dc670 {
    virtual ~S_func_006dc670();
    void* m_p;
};
S_func_006dc670::~S_func_006dc670()
{
    if (m_p)
        G1_func_006dc670(m_p);
}
