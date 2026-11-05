// from server: 100% by atomic.potato
struct CNode_00421aa0 {
    void f_00421aa0(int);
};

struct COwner_00421c90 {
    char pad0[0xc];
    int m_0c;
    char pad1[0x4c];
    CNode_00421aa0* m_5c;
};

void __stdcall f_00421c90(COwner_00421c90* self, int* out)
{
    self->m_5c->f_00421aa0(self->m_0c);
    *out = 0;
}
