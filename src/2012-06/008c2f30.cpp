// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc;
extern Desc g_desc;
struct Data { char pad[0x90]; unsigned char b; };
struct S {
    char pad0[204];
    Data* m_data;
    void raise(const Desc&);
    void f(unsigned char value);
};
void S::f(unsigned char value)
{
    if (m_data->b != value) {
        m_data->b = value;
        raise(g_desc);
    }
}
