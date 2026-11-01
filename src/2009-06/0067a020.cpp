// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
	T* get() const { return px; }
	void reset();
	T* px;
	void* pn;
};
}
namespace RBX {
class Instance { public: virtual void onChildRemoving(Instance* child); };
struct Slot;
void callSlot(Slot* s, bool b);
template<class F, class A> struct BindT {
	F f;
	A a;
	BindT(F f_, A a_) : f(f_), a(a_) {}
};
struct SignalImpl {
	template<class F> void visit(F f);
};
class Lighting : public Instance {
	char pad[0x234 - 4];
	SignalImpl* lightingChanged;
	boost::shared_ptr<Instance> sky;
	void fireLightingChanged(bool skyboxChanged)
	{
		BindT<void (*)(Slot*, bool), bool> f(&callSlot, skyboxChanged);
		if (lightingChanged)
			lightingChanged->visit(f);
	}
public:
	virtual void onChildRemoving(Instance* child);
};
void Lighting::onChildRemoving(Instance* child)
{
	if (sky.get() == child)
	{
		sky.reset();
		fireLightingChanged(true);
	}
}
}
