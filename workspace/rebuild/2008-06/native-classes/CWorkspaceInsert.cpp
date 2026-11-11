// >>> native-status (generated) -- do not edit >>>
// CWorkspaceInsert | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src fec648b6 | roc native-status --write
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/SerializerV2.h"
#include "util/RunStateOwner.h"
#include <algorithm>
#include <boost/bind.hpp>

void CWorkspace::insert(std::istream& stream, bool tree)
{
    if (dataModel->findFirstChildByClassName("NetworkClient")) return;
    RBX::DataModel::Lock lock(dataModel);
    RBX::Selection* selection = RBX::ServiceProvider::create<RBX::Selection>(
        dataModel ? dataModel->getWorkspace() : NULL);
    RBX::Instance* parent = tree && selection->size() == 1
        ? selection->front().get() : (dataModel ? dataModel->getWorkspace() : NULL);
    RBX::InsertMode mode = tree ? RBX::INSERT_TO_TREE : RBX::INSERT_TO_3D_VIEW;
    RBX::PromptMode prompts = tree ? RBX::SUPPRESS_PROMPTS : RBX::ALLOW_PROMPTS;
    std::vector<boost::shared_ptr<RBX::Instance> > instances;
    try {
        {
            TextXmlParser parser(stream.rdbuf());
            std::auto_ptr<XmlElement> root(parser.parse());
            SerializerV2 serializer;
            serializer.loadInstances(root.get(), instances);
        }
        (dataModel ? dataModel->getWorkspace() : NULL)->insertInstances(instances, parent, mode, prompts);
        if (runService->getRunState() == RBX::RS_NORMAL)
            selection->setSelection(instances.begin(), instances.end());
    } catch (std::exception&) {
        std::for_each(instances.begin(), instances.end(),
            boost::bind(&RBX::Instance::setParent, _1, static_cast<RBX::Instance*>(NULL)));
        throw;
    }
}
