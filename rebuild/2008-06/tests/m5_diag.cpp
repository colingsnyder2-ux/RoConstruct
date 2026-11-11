// Diagnostic for M5 (not a milestone): why the XML place yields no workspace children after the
// RBXGSdecomp 42406f1 sync. Checks factory registration and direct creation of the place's classes.
#include <winsock2.h>
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "v8xml/SerializerV2.h"
#include "util/standardout.h"
#include "util/Name.h"
#include <sstream>
#include <cstdio>
#undef main

// Crash reporter installed before any other static initializer: prints the fault address and a raw
// backtrace (symbolize with work/rbxgs-rebase/symbolize.py against m5_diag.map).
#pragma warning(disable: 4074)
#pragma init_seg(compiler)
static LONG CALLBACK onFault(EXCEPTION_POINTERS* e)
{
    if (e->ExceptionRecord->ExceptionCode != EXCEPTION_ACCESS_VIOLATION)
        return EXCEPTION_CONTINUE_SEARCH;
    std::printf("FAULT at %p reading %p\n", e->ExceptionRecord->ExceptionAddress, (void*)e->ExceptionRecord->ExceptionInformation[1]);
    DWORD* ebp = (DWORD*)e->ContextRecord->Ebp;
    for (int i = 0; i < 24 && ebp && !IsBadReadPtr(ebp, 8); ++i, ebp = (DWORD*)ebp[0])
        std::printf("  frame %p\n", (void*)ebp[1]);
    DWORD* esp = (DWORD*)e->ContextRecord->Esp;
    for (int i = 0; i < 64 && !IsBadReadPtr(esp + i, 4); ++i)
        std::printf("  stack %p\n", (void*)esp[i]);
    std::fflush(stdout);
    ExitProcess(9);
}
static struct FaultTrap { FaultTrap() { AddVectoredExceptionHandler(1, onFault); } } faultTrap;

struct Echo : RBX::Listener<RBX::StandardOut, RBX::StandardOutMessage>
{
    virtual void onEvent(const RBX::StandardOut*, RBX::StandardOutMessage message) { std::printf("[output] %s\n", message.message.c_str()); }
} echo;

static void probe(const char* name)
{
    const RBX::Name& n = RBX::Name::lookup(name);
    boost::shared_ptr<RBX::Instance> i = RBX::AbstractFactoryProduct<RBX::Instance>::create(n);
    std::printf("create(%s): name@%p null=%d -> %s\n", name, (const void*)&n, n == RBX::Name::getNullName(),
                i ? i->getClassName().c_str() : "NULL");
}

int main()
{
    RBX::StandardOut::singleton()->addListener(&echo);
    std::printf("sPart=%s PartInstance::className@%p\n", RBX::sPart, (const void*)&RBX::PartInstance::className());
    probe("Part");
    probe("Workspace");
    probe("Model");

    boost::shared_ptr<RBX::DataModel> dataModel = RBX::DataModel::createDataModel();
    {
        RBX::DataModel::Lock lock(dataModel);
        std::istringstream stream("<roblox version=\"4\"><Item class=\"Workspace\"><Properties></Properties>"
                                  "<Item class=\"Part\" referent=\"RBX1\"><Properties><string name=\"Name\">Brick</string>"
                                  "</Properties></Item></Item></roblox>");
        SerializerV2 serializer;
        try { serializer.loadXML(stream, dataModel.get()); }
        catch (std::exception& e) { std::printf("load: %s\n", e.what()); }
        RBX::Workspace* workspace = dataModel->getWorkspace();
        std::printf("workspace children=%u, datamodel children=%u\n", workspace->numChildren(), dataModel->numChildren());
        for (size_t k = 0; k < dataModel->numChildren(); ++k)
            std::printf("  dm child %s (%s)\n", dataModel->getChild(k)->getName().c_str(), dataModel->getChild(k)->getClassName().c_str());
    }
    return 0;
}
