#include <afxwin.h>
#include <algorithm>
#include <boost/bind.hpp>
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "v8xml/SerializerV2.h"

void __cdecl collectSelection(XmlElement* root, boost::shared_ptr<RBX::Instance> instance);

std::auto_ptr<XmlElement> CWorkspace::writeXmlSelection() {
    std::auto_ptr<XmlElement> result(SerializerV2::newRootElement());
    RBX::DataModel::Lock lock(dataModel);
    RBX::Selection* selection = RBX::ServiceProvider::create<RBX::Selection>(dataModel ? dataModel->getWorkspace() : 0);
    std::for_each(selection->selection->begin(), selection->selection->end(), boost::bind(&collectSelection, result.get(), _1));
    return result;
}

void __cdecl collectSelection(XmlElement* root, boost::shared_ptr<RBX::Instance> instance) {
    if (XmlElement* node = instance->write())
        root->addChild(node);
}
