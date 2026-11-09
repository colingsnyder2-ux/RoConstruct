// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_f740c1278594c036.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals.hpp>
#include <G3D/ReferenceCount.h>
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class SignalSource { public: virtual ~SignalSource(); };
class InstanceBase0 { public: virtual ~InstanceBase0(); char pad[0x10]; };
class Instance : public InstanceBase0, public SignalSource {
public:
    template<class F> void visitChildren(F f);
};
class PartInstance : public Instance { };
template<class Sig> class TSignalDesc {
public:
    boost::signals::connection connect(SignalSource* source, const boost::slot<boost::function<Sig> >& slot, int pos);
};
extern TSignalDesc<void(boost::shared_ptr<Instance>)> event_childAdded;
extern TSignalDesc<void(boost::shared_ptr<Instance>)> event_childRemoved;
extern TSignalDesc<void(boost::shared_ptr<Instance>)> event_ancestryChanged;
extern TSignalDesc<void(const Reflection::PropertyDescriptor*)> event_propertyChanged;
namespace Render {
class Chunk : public G3D::ReferenceCountedObject {
public:
    Chunk(float polygonOffset);
    virtual ~Chunk();
    char pad[0x1c];
};
class Material : public G3D::ReferenceCountedObject { };
class Mesh : public G3D::ReferenceCountedObject { };
class SceneManager {
public:
    virtual void v0();
    virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk);
};
}
namespace ViewNew {
struct CFrame { CFrame(); float m[12]; };
class View { public: int pad; Render::SceneManager* sceneManager; };
class SpecialShape;
class PartChunk : public Render::Chunk {
private:
    CFrame coordinateFrame;
    boost::signals::scoped_connection childAddedConnection;
    boost::signals::scoped_connection childRemovedConnection;
    boost::signals::scoped_connection ancestorChangedConnection;
    boost::signals::scoped_connection propertyChangedConnection;
    boost::signals::scoped_connection shapePropertyChangedConnection;
protected:
    boost::shared_ptr<PartInstance> partInstance;
    G3D::ReferenceCountedPointer<Render::Material> material;
    bool materialInvalid;
    G3D::ReferenceCountedPointer<Render::Mesh> mesh;
    View* view;
    SpecialShape* specialShape;
public:
    PartChunk(float polygonOffset, const boost::shared_ptr<PartInstance>& partInstance, View* view);
    virtual ~PartChunk();
    void onAncestorChanged(boost::shared_ptr<Instance> ancestor);
    void onChildAdded(boost::shared_ptr<Instance> child);
    void onChildRemoved(boost::shared_ptr<Instance> child);
    virtual void onPropertyChanged(const Reflection::PropertyDescriptor* descriptor);
};
PartChunk::PartChunk(float polygonOffset, const boost::shared_ptr<PartInstance>& partInstance, View* view)
    : Render::Chunk(polygonOffset),
      partInstance(partInstance),
      view(view),
      materialInvalid(true),
      specialShape(NULL)
{
    view->sceneManager->addModel(this);
    childAddedConnection = event_childAdded.connect(partInstance.get(), boost::bind(&PartChunk::onChildAdded, this, _1), 10);
    childRemovedConnection = event_childRemoved.connect(partInstance.get(), boost::bind(&PartChunk::onChildRemoved, this, _1), 10);
    ancestorChangedConnection = event_ancestryChanged.connect(partInstance.get(), boost::bind(&PartChunk::onAncestorChanged, this, _1), 10);
    propertyChangedConnection = event_propertyChanged.connect(partInstance.get(), boost::bind(&PartChunk::onPropertyChanged, this, _1), 10);
    if (partInstance)
        partInstance->visitChildren(boost::bind(&PartChunk::onChildAdded, this, _1));
}
}
}
