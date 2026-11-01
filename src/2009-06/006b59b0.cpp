// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count { sp_counted_base* pi_; public: ~shared_count() { if (pi_ != 0) pi_->release(); } };
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; T* operator->() const { return px; } };
}
namespace RBX {
class Mouse { public: char pad[0xc0]; void* command; };
class INamed { public: virtual ~INamed(); virtual const char* name() const = 0; };
class IRenderable { public: virtual void render(); };
class MouseCommand : public INamed, public IRenderable { public: int pad[5]; ~MouseCommand(); };
class ScriptMouseCommand : public MouseCommand {
    boost::shared_ptr<Mouse> mouse;
public:
    ~ScriptMouseCommand();
    virtual const char* name() const;
};
ScriptMouseCommand::~ScriptMouseCommand() { mouse->command = 0; }
}
