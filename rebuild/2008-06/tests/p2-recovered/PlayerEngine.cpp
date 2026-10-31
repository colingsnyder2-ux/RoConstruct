#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "v8xml/SerializerV2.h"
#include "script/ScriptContext.h"
#include "security/SecurityContext.h"
#include "util/standardout.h"
#include "util/Utilities.h"
#include <G3D/Vector3.h>
#include <sstream>
#include <cstdio>
#include <cstring>

static boost::shared_ptr<RBX::DataModel> g_dataModel;
static boost::shared_ptr<RBX::PartInstance> g_brickRef;
static RBX::PartInstance* g_brick = NULL;

struct Echo : RBX::Listener<RBX::StandardOut, RBX::StandardOutMessage>
{
    virtual void onEvent(const RBX::StandardOut*, RBX::StandardOutMessage message) { std::printf("[output] %s\n", message.message.c_str()); }
} g_echo;

extern "C" int LoadPlace(const char* text)
{
    RBX::StandardOut::singleton()->addListener(&g_echo);
    g_dataModel = RBX::DataModel::createDataModel();
    RBX::DataModel::Lock lock(g_dataModel);
    std::istringstream stream(text ? text : "");
    SerializerV2 serializer;
    try { serializer.loadXML(stream, g_dataModel.get()); }
    catch (std::exception& e) { std::printf("load: %s\n", e.what()); return 1; }
    RBX::Workspace* workspace = g_dataModel->getWorkspace();
    g_brick = dynamic_cast<RBX::PartInstance*>(workspace->findFirstChildByName("Brick"));
    if (!g_brick && workspace->getChildren()) {
        const std::vector<boost::shared_ptr<RBX::Instance> >& children = *workspace->getChildren();
        for (size_t i = 0; i < children.size(); ++i) {
            g_brick = dynamic_cast<RBX::PartInstance*>(children[i].get());
            if (g_brick) break;
        }
    }
    if (!g_brick) { std::printf("no Part in place (empty control)\n"); g_brickRef.reset(); }
    else {
        g_brickRef = boost::static_pointer_cast<RBX::PartInstance>(g_brick->shared_from_this());
        const G3D::Vector3& size = g_brick->getPartSizeXml();
        G3D::Color3 color = g_brick->getColor3();
        const G3D::Vector3& pos = g_brick->getCoordinateFrame().translation;
        std::printf("loaded part '%s' pos=(%g,%g,%g) size=(%g,%g,%g) color=(%g,%g,%g)\n",
            g_brick->getName().c_str(), pos.x, pos.y, pos.z, size.x, size.y, size.z,
            color.r, color.g, color.b);
    }
    return 0;
}

RBX::DataModel* EngineDataModel()
{
    return g_dataModel.get();
}

extern "C" void GetPartPosition(float* x, float* y, float* z)
{
    if (!g_brick) { if (x) *x=0; if (y)*y=0; if (z)*z=0; return; }
    RBX::DataModel::Lock lock(g_dataModel);
    G3D::Vector3 t = g_brick->getCoordinateFrame().translation;
    if (x) *x = t.x; if (y) *y = t.y; if (z) *z = t.z;
}

extern "C" void GetPartExtent(float* x, float* y, float* z)
{
    if (!g_brick) { if (x) *x=0; if (y)*y=0; if (z)*z=0; return; }
    RBX::DataModel::Lock lock(g_dataModel);
    G3D::Vector3 s = g_brick->getPartSizeXml();
    if (x) *x = s.x; if (y) *y = s.y; if (z) *z = s.z;
}

extern "C" void GetPartColor(float* r, float* g, float* b)
{
    if (!g_brick) { if (r) *r=0; if (g)*g=0; if (b)*b=0; return; }
    RBX::DataModel::Lock lock(g_dataModel);
    G3D::Color3 c = g_brick->getColor3();
    if (r) *r = c.r; if (g) *g = c.g; if (b) *b = c.b;
}

extern "C" int PartAlive(void)
{
    return g_brick && g_brickRef && g_brick->getParent() != NULL;
}

extern "C" void StepEngine(float dt)
{
    if (!g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    g_dataModel->step(dt);
}

extern "C" void MovePartTo(float x, float y, float z)
{
    if (!g_brick || !g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ScriptContext* scripts = RBX::ServiceProvider::create<RBX::ScriptContext>(g_dataModel.get());
    char command[160];
    _snprintf(command, sizeof(command),
        "game.Workspace.Brick.CFrame = CFrame.new(%g,%g,%g)", x, y, z);
    try { scripts->executeInNewThread(RBX::Security::CmdLine, command, "move"); }
    catch (std::exception& e) { std::printf("script: %s\n", e.what()); }
    g_dataModel->step(1.0f / 30.0f);
}

extern "C" void RemovePart()
{
    if (!g_brick || !g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ScriptContext* scripts = RBX::ServiceProvider::create<RBX::ScriptContext>(g_dataModel.get());
    try { scripts->executeInNewThread(RBX::Security::CmdLine, "game.Workspace.Brick.Parent = nil", "remove"); }
    catch (std::exception& e) { std::printf("script: %s\n", e.what()); }
    g_dataModel->step(1.0f / 30.0f);
}

extern "C" void ClosePlace()
{
    g_brick = NULL;
    g_brickRef.reset();
    if (g_dataModel) { RBX::DataModel::closeDataModel(g_dataModel, true); g_dataModel.reset(); }
}