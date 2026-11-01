// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class ICameraOwner { public: virtual ~ICameraOwner(); };
class Instance {
public:
    virtual ~Instance();
    char pad[0x44];
    Instance* parent;
    Instance* getParent() const { return parent; }
};
class Camera : public Instance {
    ICameraOwner* getCameraOwner();
};
ICameraOwner* Camera::getCameraOwner()
{
    Instance* p = getParent();
    while (p) {
        if (ICameraOwner* o = dynamic_cast<ICameraOwner*>(p))
            return o;
        p = p->getParent();
    }
    return 0;
}
}
