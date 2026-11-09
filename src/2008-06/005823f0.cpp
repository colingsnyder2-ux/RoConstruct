// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claudeNA_0b091297c4a19e75.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <boost/shared_ptr.hpp>
#include <G3D/CoordinateFrame.h>
#include <vector>
namespace RBX {
class Extents {
public:
    G3D::Vector3 low;
    G3D::Vector3 high;
    void unionWith(const Extents& other);
    G3D::Vector3 center() const { return (this->high + this->low) * 0.5f; }
};
class PVInstance {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual Extents getExtentsWorld() const;
};
class Selection {
public:
    char pad[0x13c];
    std::vector<PVInstance*> items;
    size_t size() const { return items.size(); }
    const std::vector<PVInstance*>& getItems() const { return items; }
    PVInstance* operator[](size_t i) const { return items[i]; }
};
class Instance;
class ServiceProvider { public: void raiseChanged(int what); };
ServiceProvider* __cdecl findServiceProvider(const Instance* context);
template<class T> class ServiceClient {
public:
    explicit ServiceClient(Instance* c) : context(c) {}
    __declspec(noalias) T* get(bool create);
    Instance* context;
    boost::shared_ptr<T> service;
};
class Camera {
public:
    enum CameraType { FIXED_CAMERA = 0 };
    void setCameraType(CameraType t);
    void setCameraCoordinateFrame(const G3D::CoordinateFrame& cf);
};
class ICameraOwner { public: virtual ~ICameraOwner(); virtual Camera* getCamera(); };
class Workspace { public: char pad[0x288]; ICameraOwner cameraOwner; };
class IDataState { public: virtual void setDirty(bool dirty) = 0; };

class CameraCenterCommand {
public:
    void* vptr;
    char pad[8];
    Workspace* workspace;
    void doIt(IDataState& dataState);
};

void CameraCenterCommand::doIt(IDataState& dataState)
{
    ServiceClient<Selection> selection((Instance*)workspace);
    G3D::Vector3 center;
    if (selection.get(true)->size() >= 1) {
        const std::vector<PVInstance*>& items(selection.get(true)->getItems());
        Extents extents = items[0]->getExtentsWorld();
        for (size_t i = 1; i < items.size(); ++i) {
            extents.unionWith(items[i]->getExtentsWorld());
        }
        center = extents.center();
    } else {
        center = G3D::Vector3::zero();
    }
    workspace->cameraOwner.getCamera()->setCameraType(Camera::FIXED_CAMERA);
    workspace->cameraOwner.getCamera()->setCameraCoordinateFrame(G3D::CoordinateFrame(center));
    findServiceProvider((Instance*)workspace)->raiseChanged(11);
    dataState.setDirty(true);
    dataState.setDirty(true);
}
}
