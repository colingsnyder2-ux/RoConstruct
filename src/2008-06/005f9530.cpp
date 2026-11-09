// from server: 100% by king_originala
struct S {
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
    virtual void flush();

    char padding04[12];
    int *p10;
    int *p14;
    char padding18[8];
    int *p20;
    int *p24;
    char padding28[8];
    int *p30;
    int *p34;
    char padding38[32];
    unsigned int flags;

    void f(int mode);
};

void S::f(int mode)
{
    if (mode == 1) {
        if (!(flags & 2)) {
            *p10 = 0;
            *p20 = 0;
            *p30 = 0;
            flags |= 2;
        }
    } else if (mode == 2) {
        if (!(flags & 4)) {
            flush();
            *p14 = 0;
            *p24 = 0;
            *p34 = 0;
            flags |= 4;
        }
    }
}
