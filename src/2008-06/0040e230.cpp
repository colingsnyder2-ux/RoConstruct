// from server: 100% by king_originala
struct B {
    virtual ~B();
};

struct S : B {
    ~S();
};

struct P {
    void release();
};

struct CBrowserView : S {
    char padding[244];
    P* p;
    ~CBrowserView();
};

CBrowserView::~CBrowserView()
{
    if (p)
        p->release();
}
