// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
namespace boost {
template<class T> class shared_ptr {
public:
	T* px; void* pn;
	shared_ptr(const shared_ptr& o);
	~shared_ptr();
};
}
namespace RBX {
struct Script {
	unsigned char padding[0xd4];
	bool disabled;
	bool isDisabled() const { return disabled; }
};
template<typename T> boost::shared_ptr<T> shared_from(T* p);
class ScriptContext {
	unsigned char pad[0xb0];
	std::set<Script*> scripts;
public:
	void startScript(boost::shared_ptr<Script> script);
	void addScript(Script* script);
};
void ScriptContext::addScript(Script* script) {
	scripts.insert(script);
	if (!script->isDisabled())
		startScript(shared_from(script));
}
}
