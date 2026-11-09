// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
template<class T, class C> class ComputeProp {
public:
    mutable T val;
    mutable bool dirty;
    C* object;
    char getFunc[16];
    bool setDirty() const { dirty = true; return dirty; }
};
class Controller;
template<class T> class Ref { public: T* p; };
class Instance {
public:
    virtual ~Instance();
    char pad0[0x104 - 4];
    Instance* parent;
    Instance* getParent() const { return parent; }
};
class PVInstance : public Instance {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void onChildControllerChanged();
    char pad1[0x140 - 0x108];
    ComputeProp<bool, PVInstance> IsControllable;
    ComputeProp<bool, PVInstance> IsTopFlag;
    ComputeProp<Ref<Controller>, PVInstance> TopPVController;
};
void PVInstance::onChildControllerChanged()
{
    TopPVController.setDirty();
    IsControllable.setDirty();
    IsTopFlag.setDirty();
    PVInstance* pv = dynamic_cast<PVInstance*>(this->parent);
    if (pv != 0)
        pv->onChildControllerChanged();
}
}
