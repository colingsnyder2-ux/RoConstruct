// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// HopperBin::onSelectScript. Layout facts from the binary: ScriptMouseCommand is 0x24 bytes
// (new 0x24; its ctor 006430e0 stores the mouse shared_ptr at +0x1c/+0x20), and the signal
// source base of HopperBin sits at +0x14 (lea edi,[ebx+0x14] with null check).
#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_, weak_count_;
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) {}
};
}
namespace RBX {
struct Primary { virtual ~Primary(); char state[0x10]; };
struct DescribedBase { virtual ~DescribedBase(); };
struct Instance : Primary, DescribedBase {};
struct Mouse : Instance {};
struct MouseCommand { virtual ~MouseCommand(); char state[0x18]; };
struct Workspace : Instance { void setMouseCommand(MouseCommand* command); };
struct ScriptMouseCommand : MouseCommand {
    boost::shared_ptr<Mouse> mouse;
    ScriptMouseCommand(Workspace* workspace);
    boost::shared_ptr<Mouse> getMouse();
};
struct ServiceProvider { template<class T> static T* find(const Instance* context); };
struct SelectedSignal { void fire(DescribedBase* source, boost::shared_ptr<Instance> mouse) const; };
extern SelectedSignal desc_Selected;
struct HopperBin : Instance { void onSelectScript(); };
void HopperBin::onSelectScript()
{
    Workspace* workspace = ServiceProvider::find<Workspace>(this);
    if (workspace)
    {
        ScriptMouseCommand* command = new ScriptMouseCommand(workspace);
        workspace->setMouseCommand(command);
        desc_Selected.fire(this, command->getMouse());
    }
}
}
typedef char command_size[sizeof(RBX::ScriptMouseCommand) == 0x24 ? 1 : -1];
