// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
};
}
namespace RBX {
class Instance {};
class Mouse : public Instance {};
void slotCaller();
struct EquippedSignal { void fire(boost::shared_ptr<Instance> m); };
struct Signal0 { void fire(void (*f)()); };
class Workspace { public: void setDefaultMouseCommand(); };
class ToolMouseCommand;
class Tool {
public:
    enum ToolState { NOTHING, A1, A2, A3, A4, EQUIPPED, ACTIVATED };
    char pad0[0x108];
    Workspace* workspace;
    char pad1[0x120 - 0x10c];
    ToolState backendToolState;
    char pad2[0x15c - 0x124];
    ToolMouseCommand* toolMouseCommand;
    char pad3[0x188 - 0x160];
    EquippedSignal event_Equipped;
    Signal0* event_Activated;
    Signal0* event_Unequipped;
    Signal0* event_Deactivated;
    void onEquipping();
    boost::shared_ptr<Mouse> getMouse();
    void setBackendToolStateNoReplicate(int value);
};
void Tool::setBackendToolStateNoReplicate(int value)
{
    ToolState state = (ToolState)value;

    if (backendToolState < EQUIPPED && state >= EQUIPPED)
    {
        onEquipping();
        event_Equipped.fire(getMouse());
    }

    if (state == ACTIVATED)
        if (event_Activated) event_Activated->fire(&slotCaller);

    if (backendToolState == ACTIVATED)
        if (event_Deactivated) event_Deactivated->fire(&slotCaller);

    if (backendToolState >= EQUIPPED && state < EQUIPPED)
    {
        if (event_Unequipped) event_Unequipped->fire(&slotCaller);

        if (toolMouseCommand)
        {
            toolMouseCommand = 0;
            workspace->setDefaultMouseCommand();
            workspace = 0;
        }
    }

    backendToolState = state;
}
}
