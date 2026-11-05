// from server: 100% by king_originala
struct Primary
{
    virtual ~Primary();
    char padding[0x5c];
};

struct Secondary
{
    virtual ~Secondary();
    char padding[0x3c];
};

struct CXTTreeCtrlBase : Primary, Secondary
{
    CXTTreeCtrlBase();
    virtual ~CXTTreeCtrlBase();
};

struct Member
{
    Member();
    ~Member();
    char storage[8];
};

struct CMemberTreeView : CXTTreeCtrlBase
{
    CMemberTreeView();
    virtual ~CMemberTreeView();

    Member member;
    bool enabled;
    int value;
};

CMemberTreeView::CMemberTreeView()
{
    enabled = true;
    value = 0;
}
