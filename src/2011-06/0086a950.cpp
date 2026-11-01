// from server: 100% by auto
extern "C" void __cdecl G1_func_0086a950(void*);
struct S_func_0086a950 {
    virtual ~S_func_0086a950();
    void* m_p;
};
S_func_0086a950::~S_func_0086a950()
{
    if (m_p)
        G1_func_0086a950(m_p);
}
