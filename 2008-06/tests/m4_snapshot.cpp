// Picture of what the rebuilt engine renders (not a milestone): a few parts drawn by RbxView::View
// through RenderLib into a G3D RenderDevice, saved as m4_snapshot.png. Same native render path as M4b
// (rbxgs's G3D renderer); the scene set-up here is harness code, not authentic 2008 content.
#include <winsock2.h>
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Camera.h"
#include "RbxView/View.h"
#include <GLG3D/RenderDevice.h>
#include <G3D/GImage.h>
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

static void addPart(RBX::Workspace* workspace, const G3D::Vector3& at, const G3D::Vector3& size, RBX::BrickColor color)
{
    boost::shared_ptr<RBX::PartInstance> part = RBX::Creatable<RBX::Instance>::create<RBX::PartInstance>();
    part->setAnchored(true);
    part->setPartSizeXml(size);
    part->setCoordinateFrame(G3D::CoordinateFrame(at));
    part->setColor(color);
    part->setParent(workspace);
}

int main()
{
    G3D::GWindow::Settings settings;
    settings.width = 640;
    settings.height = 480;
    G3D::RenderDevice* rd = new G3D::RenderDevice();
    if (!rd->init(settings)) { std::printf("render device init failed\n"); return 1; }

    std::printf("device ok\n"); std::fflush(stdout);
    boost::shared_ptr<RBX::DataModel> dataModel = RBX::DataModel::createDataModel();
    {
        RBX::DataModel::Lock lock(dataModel);
        RBX::Workspace* workspace = dataModel->getWorkspace();
        addPart(workspace, G3D::Vector3(0, -0.6f, 0), G3D::Vector3(32, 1.2f, 32), RBX::BrickColor(37));
        addPart(workspace, G3D::Vector3(-4, 1, 0), G3D::Vector3(4, 2, 2), RBX::BrickColor(21));
        addPart(workspace, G3D::Vector3(2, 2, -2), G3D::Vector3(2, 4, 2), RBX::BrickColor(23));
        addPart(workspace, G3D::Vector3(4, 0.6f, 4), G3D::Vector3(2, 1.2f, 4), RBX::BrickColor(24));
        if (RBX::Camera* camera = workspace->getCamera())
        {
            G3D::CoordinateFrame eye(G3D::Vector3(14, 10, 18));
            eye.lookAt(G3D::Vector3(0, 1, 0));
            camera->setCameraCoordinateFrameNoLerp(eye);
        }
    }

    {
        RBX::View::View view(dataModel);
        view.suppressSkybox();
        rd->beginFrame();
        rd->setColorClearValue(G3D::Color4(0.6f, 0.75f, 1.0f, 1.0f));
        rd->clear();
        {
            RBX::DataModel::Lock lock(dataModel);
            view.render(rd);
        }
        rd->endFrame();
        G3D::GImage frame;
        rd->screenshotPic(frame, true);
        std::printf("rendered\n"); std::fflush(stdout);
        frame.save("m4_snapshot.png");
        std::printf("saved m4_snapshot.png %dx%d\n", frame.width, frame.height);
    }
    RBX::DataModel::closeDataModel(dataModel, true);
    rd->cleanup();
    delete rd;
    return 0;
}
