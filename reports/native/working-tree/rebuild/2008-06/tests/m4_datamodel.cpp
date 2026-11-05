// Runtime milestone M4 (first half): the rebuilt engine creates a DataModel with its Workspace, a Part is
// inserted into the Workspace and moved, and the DataModel closes cleanly. Rendering the part (Ogre in
// 2008, rgmain.dll) is the second half and is not covered here. The harness is not authentic 2008 code.
#include <winsock2.h>
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include <cstdio>
#undef main  // SDL.h renames main to SDL_main; this harness has its own entry

int main()
{
    int failures = 0;
    boost::shared_ptr<RBX::DataModel> dataModel = RBX::DataModel::createDataModel();
    {
        RBX::DataModel::Lock lock(dataModel);
        RBX::Workspace* workspace = dataModel->getWorkspace();
        if (!workspace) { std::printf("no workspace\n"); return 1; }

        boost::shared_ptr<RBX::PartInstance> part = RBX::Creatable<RBX::Instance>::create<RBX::PartInstance>();
        part->setName("Brick");
        part->setParent(workspace);
        if (workspace->findFirstChildByName("Brick") != part.get()) { std::printf("part not in workspace\n"); ++failures; }

        part->setCoordinateFrame(G3D::CoordinateFrame(G3D::Vector3(0.0f, 10.0f, 0.0f)));
        if (part->getCoordinateFrame().translation.y != 10.0f) { std::printf("move\n"); ++failures; }
        std::printf("workspace children=%u class=%s\n", workspace->numChildren(), part->getClassName().toString().c_str());
    }
    RBX::DataModel::closeDataModel(dataModel, true);
    std::printf("failures=%d\n", failures);
    return failures;
}
