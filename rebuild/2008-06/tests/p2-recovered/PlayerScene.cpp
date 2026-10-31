// Model side of the 2008-06 Ogre player.
//
// Smallest runnable reimplementation of the path verified in the original
// Roblox.exe:
//
//   ViewRbxGfx::ViewRbxGfx                  0x004D9990
//     workspace->visitDescendents           0x004D7C00  (thunk 0x004DB5F0)
//     Instance::event_descendentAdded       0x00973E40
//   ViewRbxGfx::onWorkspaceDescendentAdded  0x004DB7C0
//     alloc 0xF0 + ViewNew::Part::Part      0x004EBCC0
//     ViewNew::PartChunk::PartChunk         0x004EAAE0
//       view->sceneManager->addModel        SimpleSceneManager 0x004D7DB0
//                                           -> RenderNew::RenderScene 0x004D7AE0
//   RenderNew::RenderScene::render          0x007AB0A0
//     models[this+8 .. this+0xC]; chunk geometry via vtable slot 6
//     Ogre::Mesh::getSubMesh + RbxEntity::addSubEntity 0x0067D9B0
//
// The original Part/PartChunk/RenderScene machine code lives only inside
// Roblox.exe and is not exported by rgmain.dll or rgdx.dll, so the wiring is
// reproduced here against the rebuilt DataModel.  Where the original stores a
// G3D::ReferenceCountedPointer<Render::Mesh>, this integration retains the
// recovered block producer and measured Level/vertex-bank ownership.

#include "PlayerScene.h"

#include "v8tree/Instance.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "reflection/property.h"

#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>
#include <G3D/Color3.h>

#include <boost/bind.hpp>
#include <boost/signals.hpp>

#include <vector>
#include <algorithm>
#include <cstdio>

RBX::DataModel* EngineDataModel();


#include "RbxEntity.h"

namespace ViewNew
{

struct MeshData
{
    G3D::Vector3 size;
    G3D::Color3 color;
    PlayerBlockMesh::MeshRef geometry;
    bool valid;

    MeshData() : size(1, 1, 1), color(0.5f, 0.5f, 0.5f), valid(false) {}
};

class View;

// Render::Chunk analogue: a renderable owned by the scene manager.  The
// original vtable slot 6 is getMesh(); here the renderer calls mesh() and
// cframe().
class Chunk
{
public:
    explicit Chunk(float polygonOffset) : polygonOffset(polygonOffset) {}
    virtual ~Chunk() {}

    virtual const MeshData& mesh() = 0;

protected:
    float polygonOffset;
};

// RenderBase::SimpleSceneManager analogue.
class SceneManager
{
public:
    SceneManager(std::vector<Chunk*>* models, std::vector<Chunk*>* removed)
        : models(models), removed(removed) {}

    void addModel(Chunk* chunk)
    {
        models->push_back(chunk);
    }

    // Called from signal handlers, possibly while the renderer is walking the
    // model list, so the chunk is only unlinked here and deleted at the next
    // SceneBeginFrame().
    void removeModel(Chunk* chunk)
    {
        std::vector<Chunk*>::iterator it = std::find(models->begin(), models->end(), chunk);
        if (it != models->end())
        {
            models->erase(it);
            removed->push_back(chunk);
        }
    }

private:
    std::vector<Chunk*>* models;
    std::vector<Chunk*>* removed;
};

class PartChunk : public Chunk
{
public:
    PartChunk(float polygonOffset,
              const boost::shared_ptr<RBX::PartInstance>& partInstance,
              View* view);

    const MeshData& mesh()
    {
        if (!meshData.valid)
            updateMesh();
        return meshData;
    }

    // The original asks the part for its CFrame every frame; geometry is
    // invalidated separately by propertyChanged.
    const G3D::CoordinateFrame& cframe()
    {
        coordinateFrame = partInstance->getCoordinateFrame();
        return coordinateFrame;
    }

    void invalidateMesh()
    {
        meshData.valid = false;
    }

protected:
    void updateMesh();
    void onAncestryChanged(boost::shared_ptr<RBX::Instance> ancestor);
    void onPropertyChanged(const RBX::Reflection::PropertyDescriptor* descriptor);

private:
    boost::shared_ptr<RBX::PartInstance> partInstance;
    View* view;
    G3D::CoordinateFrame coordinateFrame;
    MeshData meshData;
    boost::signals::scoped_connection ancestorChangedConnection;
    boost::signals::scoped_connection propertyChangedConnection;
};

class Part : public PartChunk
{
public:
    Part(const boost::shared_ptr<RBX::PartInstance>& partInstance, View* view)
        : PartChunk(0.0f, partInstance, view)
    {
        invalidateMesh();
    }
};

class View
{
public:
    explicit View(RBX::DataModel* dataModel);
    ~View();

    // ViewRbxGfx::onWorkspaceDescendentAdded
    bool onWorkspaceDescendentAdded(boost::shared_ptr<RBX::Instance> instance);

    std::vector<Chunk*> models;
    std::vector<Chunk*> removed;
    SceneManager sceneManager;

private:
    RBX::DataModel* dataModel;
    RBX::Workspace* workspace;
    boost::signals::scoped_connection workspaceConnection;
};

PartChunk::PartChunk(float polygonOffset,
                     const boost::shared_ptr<RBX::PartInstance>& partInstance,
                     View* view)
    : Chunk(polygonOffset),
      partInstance(partInstance),
      view(view)
{
    view->sceneManager.addModel(this);

    ancestorChangedConnection = RBX::Instance::event_ancestryChanged.connect(
        partInstance.get(), boost::bind(&PartChunk::onAncestryChanged, this, _1));
    propertyChangedConnection = RBX::Instance::event_propertyChanged.connect(
        partInstance.get(), boost::bind(&PartChunk::onPropertyChanged, this, _1));
}

void PartChunk::updateMesh()
{
    meshData.size = partInstance->getPartSizeXml();
    meshData.color = partInstance->getColor3();
    RBX::View::RenderSurfaceTypes surfaces;
    for (int face=0;face<6;++face) {
        unsigned type=RBX::View::FLAT;
        switch(partInstance->getSurfaces()[static_cast<RBX::NormalId>(face)].getSurfaceType()) {
        case RBX::STUDS: type=RBX::View::STUDS;break;
        case RBX::INLET: type=RBX::View::INLET;break;
        case RBX::WELD: type=RBX::View::WELD;break;
        case RBX::GLUE: type=RBX::View::GLUE;break;
        }
        surfaces.data|=type<<(3*face);
    }
    // 004e5f80 -> 004e58b0 -> 004e53c0 -> 004e2c80 ordinary small block path.
    // Other shapes require their own recovered producer; never substitute a box.
    meshData.geometry=PlayerBlockMesh::MeshRef();
    if(partInstance->getPartType()==RBX::Part::BLOCK_PART &&
       std::max(meshData.size.x,std::max(meshData.size.y,meshData.size.z))<30.0f)
        meshData.geometry=new PlayerBlockMesh::BlockMesh(meshData.size,surfaces,partInstance->getColor());
    meshData.valid = true;
}

void PartChunk::onAncestryChanged(boost::shared_ptr<RBX::Instance>)
{
    RBX::Workspace* workspace = RBX::Workspace::findWorkspace(partInstance.get());
    if (!workspace || !partInstance->isDescendentOf(workspace))
        view->sceneManager.removeModel(this);
}

void PartChunk::onPropertyChanged(const RBX::Reflection::PropertyDescriptor* descriptor)
{
    if (*descriptor == RBX::PartInstance::prop_Size ||
        *descriptor == RBX::PartInstance::prop_Color ||
        *descriptor == RBX::PartInstance::prop_shapeXml ||
        RBX::Surfaces::isSurfaceDescriptor(*descriptor))
    {
        invalidateMesh();
    }
}

View::View(RBX::DataModel* dataModel)
    : dataModel(dataModel),
      workspace(dataModel ? dataModel->getWorkspace() : NULL),
      sceneManager(&models, &removed)
{
    if (!workspace)
        return;

    // ViewRbxGfx ctor: visitDescendents(BindInstance(...)) then connect
    // descendantAdded.
    workspace->visitDescendents(
        boost::bind(&View::onWorkspaceDescendentAdded, this, _1));
    workspaceConnection = RBX::Instance::event_descendentAdded.connect(
        workspace, boost::bind(&View::onWorkspaceDescendentAdded, this, _1));
}

View::~View()
{
    workspaceConnection.disconnect();
    for (size_t i = 0; i < models.size(); ++i)
        delete models[i];
    for (size_t i = 0; i < removed.size(); ++i)
        delete removed[i];
    models.clear();
    removed.clear();
}

bool View::onWorkspaceDescendentAdded(boost::shared_ptr<RBX::Instance> instance)
{
    // Original: Instance::fastCast with type tags 0x92907C / 0x92DD50 at
    // 0x006A17C6.  The rebuilt model exposes RTTI, so dynamic_cast does the
    // same job.
    RBX::PartInstance* part = dynamic_cast<RBX::PartInstance*>(instance.get());
    if (!part)
        return false;

    new Part(boost::static_pointer_cast<RBX::PartInstance>(instance), this);
    return true;
}

} // namespace ViewNew

static ViewNew::View* g_view = NULL;

extern "C" int SceneAttach(void)
{
    if (g_view)
        return 0;

    RBX::DataModel* dataModel = EngineDataModel();
    if (!dataModel)
        return 1;

    g_view = new ViewNew::View(dataModel);
    std::printf("scene attached: %d model(s)\n", (int)g_view->models.size());
    return 0;
}

extern "C" int SceneBeginFrame(void)
{
    if (!g_view)
        return 0;

    // Chunks unlinked during the last frame's signal dispatch are safe to
    // destroy now.
    for (size_t i = 0; i < g_view->removed.size(); ++i)
        delete g_view->removed[i];
    g_view->removed.clear();
    return (int)g_view->models.size();
}

extern "C" int SceneModelCount(void)
{
    return g_view ? (int)g_view->models.size() : 0;
}

extern "C" int SceneModelGet(int index, SceneModel* out)
{
    if (!g_view || index < 0 || index >= (int)g_view->models.size() || !out)
        return 1;

    ViewNew::Chunk* chunk = g_view->models[index];
    ViewNew::PartChunk* partChunk = dynamic_cast<ViewNew::PartChunk*>(chunk);
    if (!partChunk)
        return 2;

    const ViewNew::MeshData& mesh = chunk->mesh();
    const G3D::CoordinateFrame& frame = partChunk->cframe();

    if(mesh.geometry.isNull())return 3;
    out->id = chunk;
    out->geometry = mesh.geometry.operator->();
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            out->rotation[row * 3 + col] = frame.rotation[row][col];
    out->position[0] = frame.translation.x;
    out->position[1] = frame.translation.y;
    out->position[2] = frame.translation.z;
    out->size[0] = mesh.size.x;
    out->size[1] = mesh.size.y;
    out->size[2] = mesh.size.z;
    out->color[0] = mesh.color.r;
    out->color[1] = mesh.color.g;
    out->color[2] = mesh.color.b;
    return 0;
}

extern "C" void SceneDetach(void)
{
    delete g_view;
    g_view = NULL;
}




