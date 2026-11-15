#include "ActiveDocView.h"

boost::shared_ptr<RBX::DataModel> getActiveDataModel()
{
    return activeDocDataModel;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::DataModel>;
