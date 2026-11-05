// from server: 100% by user
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_partchunk_1deee3e8ce3d1eec.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
#include <G3D/ReferenceCount.h>

namespace RBX {

class Instance {
public:
    char padding[0x104];
    Instance* parent;
    bool isDescendentOf(const Instance*) const;
};

class Workspace : public Instance {
public:
    static Workspace* findWorkspace(const Instance*);
};

namespace Render {
class Chunk : public G3D::ReferenceCountedObject {
public:
    virtual ~Chunk();
};

class SceneManager {
public:
    virtual void unused1();
    virtual void unused2();
    virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>&);
};
}

namespace View {

class View {
public:
    void* unused;
    Render::SceneManager* sceneManager;
};

class PartChunk : public Render::Chunk {
public:
    virtual ~PartChunk();
    char padding[0xb0];
    boost::shared_ptr<Instance> partInstance;
    char padding2[0x0c];
    View* view;

    void onAncestorChanged(boost::shared_ptr<Instance> ancestor);
};

void PartChunk::onAncestorChanged(boost::shared_ptr<Instance> ancestor)
{
    Workspace* workspace = Workspace::findWorkspace(partInstance.get());
    Instance* parent;

    if (workspace == NULL ||
        (workspace != (parent = partInstance->parent) && (parent == NULL || !parent->isDescendentOf(workspace)))) {
        view->sceneManager->removeModel(this);
    }
}

}
}
