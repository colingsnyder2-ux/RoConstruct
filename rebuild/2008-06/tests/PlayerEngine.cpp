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
    if (!g_brick) {
        const std::vector<boost::shared_ptr<RBX::Instance> >& children = *workspace->getChildren();
        for (size_t i = 0; i < children.size(); ++i) {
            g_brick = dynamic_cast<RBX::PartInstance*>(children[i].get());
            if (g_brick) break;
        }
    }
    if (!g_brick) { std::printf("no Part in place\n"); return 2; }
    std::printf("loaded part '%s'\n", g_brick->getName().c_str());
    return 0;
}

extern "C" void GetPartPosition(float* x, float* y, float* z)
{
    if (!g_brick) { if (x) *x=0; if (y)*y=0; if (z)*z=0; return; }
    RBX::DataModel::Lock lock(g_dataModel);
    G3D::Vector3 t = g_brick->getCoordinateFrame().translation;
    if (x) *x = t.x; if (y) *y = t.y; if (z) *z = t.z;
}

extern "C" void StepEngine(float dt)
{
    if (!g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    g_dataModel->step(dt);
}

extern "C" void MovePart()
{
    if (!g_brick || !g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ScriptContext* scripts = RBX::ServiceProvider::create<RBX::ScriptContext>(g_dataModel.get());
    try { scripts->executeInNewThread(RBX::Security::CmdLine, "game.Workspace.Brick.CFrame = CFrame.new(5,0,0)", "move"); }
    catch (std::exception& e) { std::printf("script: %s\n", e.what()); }
    g_dataModel->step(1.0f / 30.0f);
}

extern "C" void ClosePlace()
{
    if (g_dataModel) { RBX::DataModel::closeDataModel(g_dataModel, true); g_dataModel.reset(); g_brick = NULL; }
}