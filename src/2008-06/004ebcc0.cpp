// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_a34f0d97c34e917c.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <G3D/ReferenceCount.h>
#include <boost/signals/slot.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
extern const float minimumValue;
namespace RBX { namespace ViewNew {
struct __declspec(novtable) Listener { virtual void onEvent() = 0; };
struct Chunk : G3D::ReferenceCountedObject {
    char prefix[8];
    float polygonOffset;
    
    Chunk(float);
};
struct PartInstance;
struct View;
struct SceneManager {
    virtual void s0()=0; virtual void s1()=0; virtual void s2()=0; virtual void s3()=0;
    virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>&, bool) = 0;
};
struct View { void* unused; SceneManager* sceneManager; };
struct Notif { void addListener(Listener*); };
struct SigSrc { char c; };
struct PartInstance {
    char prefix[0x14];
    SigSrc event;
    char padding[0x18b];
    Notif listeners;
    char listenerPadding[0x24];
    int mode;
};
struct SigDesc {
    boost::signals::connection connect(SigSrc*, const boost::slot<boost::function<void()> >&, int);
};
extern SigDesc dispatcher;
struct PartChunk : Chunk {
    char pad[0xd8-0x18];
    PartChunk(float, const boost::shared_ptr<PartInstance>&, View*);
    virtual ~PartChunk();
};
struct Part : PartChunk, Listener {
    boost::signals::scoped_connection connection;
    Part(const boost::shared_ptr<PartInstance>&, View*);
    virtual void onEvent();
    void callback();
    void update();
    void finish();
};
}}
using namespace RBX;
using namespace RBX::ViewNew;
Part::Part(const boost::shared_ptr<PartInstance>& partInstance, View* view)
    : PartChunk(0.0f, partInstance, view)
{
    if (partInstance.get()->mode == 0) {
        view->sceneManager->addModel(G3D::ReferenceCountedPointer<Chunk>(this), true);
        float v = polygonOffset;
        if (v < 1.0f)
            polygonOffset = 0.0f;
    } else {
        if (minimumValue > polygonOffset)
            polygonOffset = minimumValue;
    }
    if (partInstance)
        partInstance->listeners.addListener(this);
    connection = dispatcher.connect(partInstance.get() ? &partInstance->event : 0, boost::bind(&Part::callback, this), 10);
    update();
    finish();
}
