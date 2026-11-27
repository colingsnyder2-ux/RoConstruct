// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
class CTreeBase
{
public:
    CTreeBase();
    virtual ~CTreeBase();
    char pad[0xf0];
};struct V3 { int a,b,c; V3():a(0),b(0),c(0){} };
class CMemberTreeView : public CTreeBase
{
public:
    CMemberTreeView();
    virtual ~CMemberTreeView();
    V3 x,y,z;
};
CMemberTreeView::CMemberTreeView()
{
}
