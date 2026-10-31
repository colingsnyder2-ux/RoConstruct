// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    shared_ptr& operator=(const shared_ptr& r) { px = r.px; pn = r.pn; return *this; }
    T* operator->() const { return px; }
};
}
namespace RBX {
class Workspace;
class MouseCommand;
class Instance { };
class Mouse : public Instance {
public:
    char pad[0xc0];
    MouseCommand* command;
    void setCommand(MouseCommand* c) { command = c; }
};
template<class Base> class Creatable {
public:
    template<class T> static boost::shared_ptr<T> create();
};
class ExeCmdBase { public: virtual ~ExeCmdBase(); };
class ExeCmdBase2 { public: virtual void f(); };
class MouseCommand : public ExeCmdBase, public ExeCmdBase2 {
public:
    MouseCommand(Workspace* workspace);
    virtual ~MouseCommand();
    char pad[0x14];
};
class ScriptMouseCommand : public MouseCommand {
private:
    boost::shared_ptr<Mouse> mouse;
public:
    ScriptMouseCommand(Workspace* workspace);
    virtual ~ScriptMouseCommand();
};
ScriptMouseCommand::ScriptMouseCommand(Workspace* workspace)
    : MouseCommand(workspace)
{
    mouse = Creatable<Instance>::create<Mouse>();
    mouse->setCommand(this);
}
}
