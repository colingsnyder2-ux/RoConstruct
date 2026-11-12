#include <afxwin.h>
#include "../../native-headers/CWorkspace.h"
#include "../../native-headers/v8datamodel/DataModel.h"
#include "../../native-headers/v8datamodel/Selection.h"
#include "../../native-headers/v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"

// 0046ab60: ATL/base constructors and both shared owners initialize themselves.
CWorkspace::CWorkspace() {}

// 0046a940: return the retained DataModel owner by value.
boost::shared_ptr<RBX::DataModel> CWorkspace::getDataModel() { return dataModel; }

// 0046a970: the data model's Workspace, or NULL without a data model.
RBX::Workspace* CWorkspace::getWorkspace()
{
    return dataModel ? dataModel->getWorkspace() : NULL;
}

// 0046ab90: serialize DataModel children under its native lock.
std::auto_ptr<XmlElement> CWorkspace::writeXmlModel() {
    std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
    RBX::DataModel::Lock lock(dataModel);
    getDataModel()->writeChildren(root.get());
    return root;
}

// 0046b0e0: detach typed notifier listeners before releasing owners.
void CWorkspace::cleanup() {
    if (dataModel) {
        {
            RBX::DataModel::Lock lock(dataModel);
            RBX::Listener<RBX::Selection, RBX::SelectionChanged>* first = this;
            RBX::Selection* selection = dataModel->find<RBX::Selection>();
            if (selection) selection->RBX::Notifier<RBX::Selection, RBX::SelectionChanged>::removeListener(first);
            RBX::Listener<RBX::Workspace, RBX::DrawChanged>* second = this;
            RBX::Workspace* workspace = dataModel->getWorkspace();
            if (workspace)
                workspace->RBX::Notifier<RBX::Workspace, RBX::DrawChanged>::removeListener(second);
        }
        runService.reset();
        RBX::DataModel::closeDataModel(dataModel, true);
        dataModel.reset();
    }
}
