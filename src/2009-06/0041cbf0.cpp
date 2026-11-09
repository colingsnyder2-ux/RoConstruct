// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
	virtual ~Instance();
	char pad[0x44];
	Instance* parent;
	Instance* getParent() const { return parent; }
};
namespace Reflection { namespace Metadata {
class Class : public Instance {
public:
	char pad2[0xac - 0x4c];
	int value;
	int get() const;
};
int Class::get() const {
	if (value) return value;
	return dynamic_cast<Class*>(getParent()) && dynamic_cast<Class*>(getParent())->get();
}
}}}
