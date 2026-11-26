// from server: 100% by Xemicl
// copied from an identical function in another client (function ??1CClassTreeView@ns_ROCX00002f@@UAE@XZ)

namespace ns_ROCX00002f {
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

struct Base : Primary, Secondary
{
    virtual ~Base();
};

struct Member
{
    ~Member();
};

struct CClassTreeView : Base
{
    Member member;
    virtual ~CClassTreeView();
};

CClassTreeView::~CClassTreeView()
{
}
}
