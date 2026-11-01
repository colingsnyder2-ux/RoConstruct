// from server: 100% by auto
extern "C" void __cdecl G1_func_0081de00(void*);
struct S_func_0081de00 {
    virtual ~S_func_0081de00();
    void* m_p;
};
S_func_0081de00::~S_func_0081de00()
{
    if (m_p)
        G1_func_0081de00(m_p);
}
