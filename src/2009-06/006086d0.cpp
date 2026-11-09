// from server: 100% by EspClaude
// roc 2009-06 006086d0  unit: RBX::GuiItem::onDescendentRemoving
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px;
    void* pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
    operator bool() const { return px != 0; }
    void reset();
};
}
namespace RBX {
using boost::shared_ptr;
class Instance {
public:
    virtual void onDescendentRemoving(const shared_ptr<Instance>& instance);
    char pad[0x8c];
};
class GuiItem : public Instance {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void onLoseFocus();   // slot 17 (0x44)
    shared_ptr<GuiItem> focus;    // 0x90
    void loseFocus() {
        if (focus) focus->onLoseFocus();
        focus.reset();
    }
    virtual void onDescendentRemoving(const shared_ptr<Instance>& instance);
};
void GuiItem::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
    if (instance.get() == focus.get()) {
        loseFocus();
    }
    Instance::onDescendentRemoving(instance);
}
}
