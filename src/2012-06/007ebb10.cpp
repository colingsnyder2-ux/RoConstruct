// from server: 100% by tajop
struct D_6c8100 {
    bool is(void* desc);
};

struct Q_1c {
    char pad0[0xc];
    D_6c8100* m_c;
};

struct Inst_54 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool v21();
};

void* get_52aac0();

bool __stdcall func_007ebb10(Inst_54* p)
{
    if (p != 0) {
        Q_1c* q = (Q_1c*)((char*)p + 0x1c);
        if (q != 0) {
            D_6c8100* d = q->m_c;
            if (d->is(get_52aac0())) {
                Inst_54* r = (Inst_54*)((char*)q - 0x1c);
                if (r != 0) {
                    return !r->v21();
                }
            }
        }
    }
    return false;
}
