// from server: 100% by king_originala
struct Primary {
    virtual ~Primary();
    char padding[0x5c];
};

struct Secondary {
    virtual ~Secondary();
    char padding[0x3c];
};

struct Base : Primary, Secondary {
    Base();
    virtual ~Base();
};

struct Member {
    Member();
    ~Member();
    char storage[8];
};

struct CDeclarationView : Base {
    Member member;
    int value;

    CDeclarationView();
    virtual ~CDeclarationView();
};

CDeclarationView::CDeclarationView()
    : Base(), member(), value(0)
{
}
