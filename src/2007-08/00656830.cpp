// from server: 100% by colin
struct CXTPReportRow_Batch {
    int GetValue();
};

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v21();
    virtual void v22();
    virtual int v23(int);
};

int CXTPReportRow_Batch::GetValue() {
    int idx = *(int*)((char*)this + 0xcc);
    if (idx != -1) {
        Inner* p = *(Inner**)((char*)this + 0xa0);
        return p->v23(idx);
    }
    return 0;
}
