// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_9613e5a148134ff1.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/function.hpp>
#include <boost/bind.hpp>
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
    char pad[0x28 - 0xc];
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
