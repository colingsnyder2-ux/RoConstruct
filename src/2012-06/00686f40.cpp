// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /GR
namespace RBX {
class Instance { public: virtual ~Instance(); };
class ICharacterSubject {
public:
    virtual ~ICharacterSubject();
    char pad[0x30];
    int state;
};
struct Camera {
    char pad[0x14c];
    Instance* subject;
    Instance* getSubject() const { return subject; }
    bool f() const;
};
bool Camera::f() const
{
    if (ICharacterSubject* p = dynamic_cast<ICharacterSubject*>(getSubject()))
        return p->state == 1;
    return false;
}
}
