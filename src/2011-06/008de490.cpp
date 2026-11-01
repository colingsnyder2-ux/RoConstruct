// from server: 100% by auto
extern "C" void __cdecl G1_func_008de490(void*);
struct S_func_008de490 {
    virtual ~S_func_008de490();
    void* m_p;
};
S_func_008de490::~S_func_008de490()
{
    if (m_p)
        G1_func_008de490(m_p);
}
