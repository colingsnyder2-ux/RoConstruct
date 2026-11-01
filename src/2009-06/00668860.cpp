// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost { template<class T> class shared_ptr; }
namespace RBX {
class Primitive;
class Instance {
public:
	virtual ~Instance();
	char pad[0x44];
	Instance* parent;
	char ipad[0x13c - 0x4c];
	Instance* getParent() const { return parent; }
	template<class F> void visitDescendents(const F& f);
};
class ModelInstance : public Instance {};
class ICharacterSubject {
public:
	virtual void getIgnorePrims(std::vector<const Primitive*>& ignore);
};
class Humanoid : public Instance, public ICharacterSubject {
public:
	virtual void getIgnorePrims(std::vector<const Primitive*>& ignore);
};
struct Collector {
	void (*f)(boost::shared_ptr<Instance>, std::vector<Primitive*>&);
	std::vector<Primitive*>* v;
	Collector(void (*f_)(boost::shared_ptr<Instance>, std::vector<Primitive*>&), std::vector<Primitive*>& v_) : f(f_), v(&v_) {}
};
void collectAllDescendantCharacterPrims(boost::shared_ptr<Instance> descendent, std::vector<Primitive*>& primitives);
static ModelInstance* getCharacterFromHumanoid(Humanoid* h)
{
	return h ? dynamic_cast<ModelInstance*>(h->getParent()) : 0;
}
void Humanoid::getIgnorePrims(std::vector<const Primitive*>& ignore)
{
	if (ModelInstance* character = getCharacterFromHumanoid(this))
		character->visitDescendents(Collector(&collectAllDescendantCharacterPrims, (std::vector<Primitive*>&)ignore));
}
}
