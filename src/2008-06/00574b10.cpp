// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace boost {
template<class T> class shared_ptr {
    T* px;
    void* pn;
public:
    T* get() const { return px; }
    T* operator->() const { return px; }
    void reset();
};
}
namespace RBX {
class UIEvent { public: enum EventType { MOUSE_IDLE = 7 }; };
class GuiEvent { public: UIEvent::EventType eventType; };
class GuiResponse {
    void* target;
    int flags;
public:
    GuiResponse() : target(0), flags(0) {}
    static GuiResponse notUsed() { return GuiResponse(); }
    bool wasUsed() const { return target != 0; }
};
class GuiTarget {
public:
    virtual GuiResponse process(const GuiEvent& event) = 0;
};
class GuiBase {
public:
    virtual ~GuiBase();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void releaseFocus();
    virtual bool isActive();
    GuiResponse process(const GuiEvent& event);
    char pad[0x130 - 4];
};
class GuiItem : public GuiBase, public GuiTarget {
    boost::shared_ptr<GuiItem> focus;
public:
    void clearFocus() { if (focus.get()) focus->releaseFocus(); focus.reset(); }
    virtual GuiResponse process(const GuiEvent& event);
};
GuiResponse GuiItem::process(const GuiEvent& event)
{
    if ((int)event.eventType >= 1 && event.eventType == UIEvent::MOUSE_IDLE)
        return GuiResponse::notUsed();
    if (focus.get()) {
        if (focus->isActive()) {
            GuiResponse result = GuiBase::process(event);
            if (result.wasUsed())
                return result;
        }
        GuiResponse result = focus->process(event);
        if (result.wasUsed())
            return result;
        clearFocus();
    }
    return GuiBase::process(event);
}
}
