// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /I C:/Users/colin/RoConstruct/tools/libs/boost_1_34_1

#include <set>
#include <boost/shared_ptr.hpp>

namespace RBX {
struct Script {
    unsigned char padding[0x158];
    bool disabled;
    bool isDisabled() const { return disabled; }
};

template<typename T>
boost::shared_ptr<T> shared_from(T* p) { return boost::shared_ptr<T>(p); }

class ScriptContext {
    unsigned char pad[0x15c];
    std::set<Script*> scripts;
public:
    void startScript(boost::shared_ptr<Script> script);
    void addScript(Script* script);
};

void ScriptContext::addScript(Script* script) {
    if (scripts.insert(script).second == true) {
        if (!script->isDisabled())
            startScript(shared_from(script));
    }
}
}