#include <afxwin.h>
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"

CWorkspace::CWorkspace() {}

boost::shared_ptr<RBX::DataModel> CWorkspace::getDataModel() { return dataModel; }

std::auto_ptr<XmlElement> CWorkspace::writeXmlModel() {
    std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
    RBX::DataModel::Lock lock(dataModel);
    getDataModel()->writeChildren(root.get());
    return root;
}

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

template class ATL::IDispatchImpl<IWorkspace,&IID_IWorkspace,&LIBID_RobloxLib,1,2,ATL::CComTypeInfoHolder>;
template class ATL::IObjectWithSiteImpl<CWorkspace>;
template class RBX::Listener<RBX::Workspace,RBX::DrawChanged>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Workspace,RBX::DrawChanged> *,std::allocator<RBX::Listener<RBX::Workspace,RBX::DrawChanged> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Workspace,RBX::DrawChanged> *,std::allocator<RBX::Listener<RBX::Workspace,RBX::DrawChanged> *> >;

RBX::Workspace* CWorkspace::getWorkspace()
{
    if (dataModel)
        return dataModel->getWorkspace();
    return 0;
}

#include "util/RunStateOwner.h"

HRESULT CWorkspace::FinalConstruct() {
    dataModel = RBX::DataModel::createDataModel(true);
    RBX::DataModel::Lock lock(dataModel);
    runService = RBX::shared_from(dataModel->create<RBX::RunService>());
    RBX::Notifier<RBX::Workspace, RBX::DrawChanged>::connect(dataModel->getWorkspace(), this);
    RBX::Notifier<RBX::Selection, RBX::SelectionChanged>::connect(dataModel->create<RBX::Selection>(), this);
    return S_OK;
}
