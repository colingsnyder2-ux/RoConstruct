// from server: 100% by EspClaude
// from server: 90% by king_originala_sol_resume_high
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-view roc_espclaude_8db6c33f163e0aa1.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <G3D/ReferenceCount.h>

namespace RBX {
class Instance {
public:
	virtual ~Instance();
	char pad[0x100];
	Instance* parent;
	Instance* getParent() const { return parent; }
	bool isDescendentOf(const Instance*) const;
};
class PartInstance : public Instance {
public:
	virtual ~PartInstance();
};
class Workspace {
public:
	static Workspace* findWorkspace(const Instance*);
};
template<class T> boost::shared_ptr<T> shared_from(T*);

namespace Render {
class Chunk : public G3D::ReferenceCountedObject {
public:
	char pad[0xb0];
};
class SceneManager {
public:
	virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>&);
	virtual void invalidateModel(const G3D::ReferenceCountedPointer<Chunk>&, bool);
	virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>&);
};
}
namespace View {
class View {
public:
	void* unk;
	Render::SceneManager* sceneManager;
};
class PartChunk : public Render::Chunk {
protected:
	boost::shared_ptr<PartInstance> partInstance;
	int material;
	bool materialInvalid;
	int mesh;
	View* view;
	void* specialShape;
	void invalidateMaterial();
	void invalidateMesh();
};
class Decal : public PartChunk {
	boost::shared_ptr<Instance> decal;
public:
	void onDecalAncestorChanged(boost::shared_ptr<Instance>);
};

void Decal::onDecalAncestorChanged(boost::shared_ptr<Instance> ancestor)
{
	if (!decal)
		return;
	{
		Workspace* workspace = Workspace::findWorkspace(decal.get());
		partInstance = shared_from(dynamic_cast<PartInstance*>(decal->getParent()));
		if (workspace && decal->isDescendentOf((Instance*)workspace))
		{
			invalidateMesh();
			invalidateMaterial();
		}
		if (!workspace || !decal->isDescendentOf((Instance*)workspace))
			view->sceneManager->removeModel(this);
	}
}
}
}
