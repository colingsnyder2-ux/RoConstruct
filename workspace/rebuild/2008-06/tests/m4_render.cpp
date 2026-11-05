// Runtime milestone M4 (second half): the rebuilt engine renders one part. A DataModel with a Part in its
// Workspace is drawn by RbxView::View through RenderLib into a G3D RenderDevice; the frame is read back and
// the part's colour must cover the centre of the screen. The renderer is rbxgs's G3D path (2007); 2008
// rendered through Ogre (rgmain.dll), which is not rebuilt, so this proves the engine-to-screen path only.
// The harness is not authentic 2008 code.
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

int main()
{
    G3D::GWindow::Settings settings;
    settings.width = 320;
    settings.height = 240;
    G3D::RenderDevice* rd = new G3D::RenderDevice();
    if (!rd->init(settings)) { std::printf("render device init failed\n"); return 1; }

    int failures = 0;
    boost::shared_ptr<RBX::DataModel> dataModel = RBX::DataModel::createDataModel();
    {
        RBX::DataModel::Lock lock(dataModel);
        RBX::Workspace* workspace = dataModel->getWorkspace();
        boost::shared_ptr<RBX::PartInstance> part = RBX::Creatable<RBX::Instance>::create<RBX::PartInstance>();
        part->setAnchored(true);
        part->setCoordinateFrame(G3D::CoordinateFrame(G3D::Vector3(0.0f, 0.0f, 0.0f)));
        part->setParent(workspace);
        if (RBX::Camera* camera = workspace->getCamera())
            camera->setCameraCoordinateFrameNoLerp(G3D::CoordinateFrame(G3D::Vector3(0.0f, 0.0f, 8.0f)));
    }

    {
        RBX::View::View view(dataModel);
        view.suppressSkybox();
        rd->beginFrame();
        rd->setColorClearValue(G3D::Color4(1.0f, 0.0f, 1.0f, 1.0f));
        rd->clear();
        {
            RBX::DataModel::Lock lock(dataModel);
            view.render(rd);
        }
        rd->endFrame();

        G3D::GImage frame;
        rd->screenshotPic(frame, true);
        int drawn = 0;
        for (int y = 0; y < frame.height; ++y)
            for (int x = 0; x < frame.width; ++x)
            {
                const G3D::uint8* p = frame.byte() + (y * frame.width + x) * frame.channels;
                if (!(p[0] > 240 && p[1] < 16 && p[2] > 240))
                    ++drawn;
            }
        const G3D::uint8* c = frame.byte() + ((frame.height / 2) * frame.width + frame.width / 2) * frame.channels;
        bool centre = !(c[0] > 240 && c[1] < 16 && c[2] > 240);
        std::printf("frame %dx%d, %d pixels drawn, centre rgb=(%d,%d,%d) %s\n", frame.width, frame.height, drawn,
                    c[0], c[1], c[2], centre ? "covered" : "background");
        if (!centre) ++failures;
    }
    RBX::DataModel::closeDataModel(dataModel, true);
    rd->cleanup();
    delete rd;
    std::printf("failures=%d\n", failures);
    return failures;
}
