// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace G3D { class CoordinateFrame { public: float m[12]; CoordinateFrame operator*(const CoordinateFrame& o) const; }; }
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } T* operator->() const { return px; } T& operator*() const { return *px; } typedef T* shared_ptr::*ub; operator ub() const { return px ? &shared_ptr::px : 0; } };
}
namespace RBX {
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
class Instance {
public:
	virtual ~Instance();
	char pad[0x48];
	boost::shared_ptr<const Instances> children;
	int numChildren() const { return children ? (int)children->size() : 0; }
	Instance* getChild(int i) const { return (*children)[i].get(); }
};
class PVInstance : public Instance {
public:
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
	virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
	virtual void legacyTraverseState(const G3D::CoordinateFrame& parentState);
};
template<class T> class ScopedPtr { T* p; public: T& operator*() const { return *p; } };
class ModelInstance : public PVInstance {
public:
	char pad2[0x98 - 0x54];
	ScopedPtr<G3D::CoordinateFrame> legacyOffset;
	virtual void legacyTraverseState(const G3D::CoordinateFrame& parentState);
};
void ModelInstance::legacyTraverseState(const G3D::CoordinateFrame& parentState)
{
	int count = numChildren();
	if (count > 0) {
		G3D::CoordinateFrame state = parentState * *legacyOffset;
		for (int i = 0; i < count; i++) {
			PVInstance* pv = dynamic_cast<PVInstance*>(getChild(i));
			if (pv != NULL) {
				pv->legacyTraverseState(state);
			}
		}
	}
}
}
