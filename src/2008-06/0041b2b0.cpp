// from server: 100% by EspClaude
// from server: 56% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_espclaude_cb4ac364beeaaffd.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

template<class Class>
boost::shared_ptr<Class> shared_from(Class* r);

struct lua_State;
class Service {
public:
    void setCallback(boost::function0<void> f);
};
extern Service* theService;

class BinderBase0 { public: virtual ~BinderBase0(); };
class BinderBase1 { public: virtual ~BinderBase1(); };
class Binder : public BinderBase0, public BinderBase1 {
public:
    static bool enabled;
    void onBind();
    void bind();
};

void Binder::bind()
{
    if (enabled)
        theService->setCallback(boost::bind(&Binder::onBind, shared_from(this)));
}
