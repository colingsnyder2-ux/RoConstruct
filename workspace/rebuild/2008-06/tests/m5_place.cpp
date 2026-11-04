// Runtime milestone M5: in the rebuilt engine a local place loads from XML (SerializerV2::loadXML), a Lua
// script runs against it (ScriptContext), and physics steps (an unanchored part falls). The place text and
// this harness are not authentic 2008 content.
#include <winsock2.h>
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "v8xml/SerializerV2.h"
#include "script/ScriptContext.h"
#include "security/SecurityContext.h"
#include "util/standardout.h"
#include <sstream>
#include <cstdio>
#undef main
#include <cstdlib>
// an invalid CRT parameter ends the process without an exception: fault instead so a debugger sees the caller
#pragma warning(disable: 4073)
#pragma init_seg(lib)
static void invalidParameter(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, uintptr_t)
{
    std::printf("invalid CRT parameter\n");
    *(volatile int*)0 = 0;
}
static struct InvalidParameterTrap { InvalidParameterTrap() { _set_invalid_parameter_handler(invalidParameter); } } invalidParameterTrap;

// engine output (script errors and the like) goes to the console
struct Echo : RBX::Listener<RBX::StandardOut, RBX::StandardOutMessage>
{
    virtual void onEvent(const RBX::StandardOut*, RBX::StandardOutMessage message) { std::printf("[output] %s\n", message.message.c_str()); }
} echo;

static const char* place =
    "<roblox version=\"4\">"
    "<Item class=\"Workspace\"><Properties></Properties>"
    "<Item class=\"Part\" referent=\"RBX1\"><Properties>"
    "<string name=\"Name\">Brick</string>"
    "<bool name=\"Anchored\">false</bool>"
    "<CoordinateFrame name=\"CFrame\"><X>0</X><Y>20</Y><Z>0</Z>"
    "<R00>1</R00><R01>0</R01><R02>0</R02><R10>0</R10><R11>1</R11><R12>0</R12><R20>0</R20><R21>0</R21><R22>1</R22>"
    "</CoordinateFrame>"
    "</Properties></Item>"
    "</Item></roblox>";

int main()
{
    int failures = 0;
    RBX::StandardOut::singleton()->addListener(&echo);
    boost::shared_ptr<RBX::DataModel> dataModel = RBX::DataModel::createDataModel();
    {
        RBX::DataModel::Lock lock(dataModel);
        std::istringstream stream(place);
        SerializerV2 serializer;
        try { serializer.loadXML(stream, dataModel.get()); }
        catch (std::exception& e) { std::printf("load: %s\n", e.what()); return 1; }

        RBX::Workspace* workspace = dataModel->getWorkspace();
        RBX::PartInstance* brick = dynamic_cast<RBX::PartInstance*>(workspace->findFirstChildByName("Brick"));
        if (!brick) { std::printf("place did not load the brick (workspace children=%u)\n", workspace->numChildren()); return 2; }
        float startY = brick->getCoordinateFrame().translation.y;
        std::printf("loaded brick at y=%.2f\n", startY);

        RBX::ScriptContext* scripts = RBX::ServiceProvider::create<RBX::ScriptContext>(dataModel.get());
        try { scripts->executeInNewThread(RBX::Security::CmdLine, "game.Workspace.Brick.Name = 'Ran'", "m5"); }
        catch (std::exception& e) { std::printf("script: %s\n", e.what()); ++failures; }
        if (brick->getName() != "Ran") { std::printf("script did not run (name=%s)\n", brick->getName().c_str()); ++failures; }

        for (int i = 0; i < 60; ++i)
            dataModel->step(1.0f / 30.0f);
        float endY = brick->getCoordinateFrame().translation.y;
        std::printf("after 2s of physics y=%.2f\n", endY);
        if (!(endY < startY - 1.0f)) { std::printf("part did not fall\n"); ++failures; }
    }
    RBX::DataModel::closeDataModel(dataModel, true);
    std::printf("failures=%d\n", failures);
    return failures;
}
