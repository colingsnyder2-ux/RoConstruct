// from server: 100% by tester
namespace RBX {
class ICameraOwner { public: virtual void f(); };
class Instance {
public:
    virtual void g();
    char pad[0x100];
    Instance* parent;
};
class Camera : public Instance {
public:
    ICameraOwner* getCameraOwner();
};
ICameraOwner* Camera::getCameraOwner() {
    for (Instance* p = parent; p; p = p->parent) {
        ICameraOwner* o = dynamic_cast<ICameraOwner*>(p);
        if (o) return o;
    }
    return 0;
}
}
