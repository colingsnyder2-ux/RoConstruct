// from server: 100% by king_originala
struct Primary {
    virtual ~Primary();
    char padding[0x5c];
};

struct Secondary {
    virtual ~Secondary();
    char padding[0x3c];
};

struct CXTTreeView : Primary, Secondary {
    virtual ~CXTTreeView();
};

struct Member {
    ~Member();
};

struct CMemberTreeView : CXTTreeView {
    Member member;
    virtual ~CMemberTreeView();
};

CMemberTreeView::~CMemberTreeView()
{
}
