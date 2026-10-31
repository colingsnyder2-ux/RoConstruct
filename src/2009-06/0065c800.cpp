// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Part { public: Part(); Part(const Part&); Part& operator=(const Part&); char d[0x68]; };
class VB { public: virtual ~VB(); };
class PBase { public: virtual ~PBase(); char pad[0x8c]; };
class PartInstance : public PBase, public virtual VB { public: Part computePart() const; };
template <class T, class Class>
class ComputeProp
{
public:
	typedef T (Class::*GetFunc)() const;
	T getValue() const
	{
		if (dirty) {
			val = (object->*getFunc)();
			dirty = false;
			changed = true;
		}
		return val;
	}
private:
	mutable T val;
	mutable bool dirty;
	Class* object;
	GetFunc getFunc;
	mutable bool changed;
};
template class ComputeProp<Part, PartInstance>;
}
