// from server: 100% by king_originala
struct Rect {
    int left, top, right, bottom;
};

struct Info {
    int unused0[2];
    int width, height;
    int minWidth, minHeight;
    int unused1[2];
    int maxWidth, maxHeight;
};

struct Object {
    int get_19c(int *out);
};

extern "C" Object *__cdecl getObject();

struct CDataModelPropGrid {
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void adjust(Rect *, int);

    char pad0[0xF4];
    unsigned char flagF8;
    unsigned char padF9;
    unsigned char flagFA;
    char padFB[9];
    unsigned char flag104;

    void prepare();
    void f(Info *);
};

void CDataModelPropGrid::f(Info *p) {
    prepare();
    Info *out = p;
    if (flagF8) {
        out->minWidth = 0;
        out->minHeight = 0;
    }
    if (!flagFA && !flagF8 && flag104) {
        getObject()->get_19c((int *)&p);
        Rect r;
        r.right = ((short *)&p)[0];
        r.bottom = ((short *)&p)[1];
        r.left = 0;
        r.top = 0;
        adjust(&r, 0);
        out->maxWidth = r.right - r.left;
        out->width = r.right - r.left;
        out->maxHeight = r.bottom - r.top;
        out->height = r.bottom - r.top;
    }
}
