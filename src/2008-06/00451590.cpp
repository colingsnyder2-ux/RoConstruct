// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct Base {
    virtual void vfunc();
    char padding[80];
    Base();
    ~Base();
};
struct CRobloxDoc : Base {
    std::map<int,int> member;
    virtual void vfunc();
    CRobloxDoc();
};
CRobloxDoc::CRobloxDoc() : Base()
{
}
