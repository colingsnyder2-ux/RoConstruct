#pragma once
#include "CSelectionPropGrid.h"
#include "ActiveDocView.h"

class CDataModelPropGrid : public CSelectionPropGrid, public ActiveDocView {
    DECLARE_DYNAMIC(CDataModelPropGrid)
public:
    CDataModelPropGrid();
    virtual void update(boost::shared_ptr<RBX::DataModel>, boost::shared_ptr<RBX::DataModel>);
};
