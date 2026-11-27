// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /GR
namespace RBX {
class Instance { public: virtual ~Instance(); };
class IAdornable
{
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void render(void *, int);
};
}
struct AnchorTool
{
    char pad[0x30];
    RBX::Instance *part;
    void f(void *adorn);
};
void AnchorTool::f(void *adorn)
{
    if (part)
        if (RBX::IAdornable *a = dynamic_cast<RBX::IAdornable *>(part))
            a->render(adorn, 0);
}