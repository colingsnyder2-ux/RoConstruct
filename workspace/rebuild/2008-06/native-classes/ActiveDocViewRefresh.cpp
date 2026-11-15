#include "ActiveDocView.h"

void ActiveDocView::refresh()
{
    update(activeDocDataModel, boost::shared_ptr<RBX::DataModel>());
}
