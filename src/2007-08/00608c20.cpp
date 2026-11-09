// from server: 100% by colin
struct SimJobStage {
    void* m_vtbl;
    char pad0[4];
    void* m_ptr8;
    char pad1[4];
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;

    void* dtor(char flag);
};

extern "C" void __fastcall sub_726E80(void*);
extern "C" void __cdecl sub_62FC62(void*);

void* SimJobStage::dtor(char flag)
{
    this->m_vtbl = (void*)0x7c2d24;
    sub_726E80(&this->m_field10);
    void* p = this->m_ptr8;
    this->m_vtbl = (void*)0x7ba614;
    if (p) {
        void** vt = *(void***)p;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vt[0];
        fn(p, 1);
    }
    if (flag & 1) {
        sub_62FC62(this);
    }
    return this;
}
