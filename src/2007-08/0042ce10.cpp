// from server: 100% by EspClaude
// from server: 93% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_claude_540d34b8fd539a0c.cpp

// Candidate translation unit (score above; library headers required).
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

struct lua_State;
class Service {
public:
    void setCallback(boost::function0<void> f);
};
extern Service* theService;

class BinderBase {
public:
    virtual ~BinderBase();
};

class Binder : public BinderBase, public boost::enable_shared_from_this<Binder> {
public:
    char pad[0x18 - 0xc];
    bool bound;
    void unbind();
    void bind();
};

void Binder::bind()
{
    if (!bound) {
        theService->setCallback(boost::bind(&Binder::unbind, shared_from_this()));
        bound = true;
    }
}
