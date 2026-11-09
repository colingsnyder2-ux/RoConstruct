// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct Base {
    virtual void vfunc();
    char padding[84];
    Base();
    ~Base();
};
struct CRobloxView : Base {
    std::map<int,int> member;
    virtual void vfunc();
    CRobloxView();
};
CRobloxView::CRobloxView() : Base()
{
}
