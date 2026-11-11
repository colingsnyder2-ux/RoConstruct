#pragma once
// >>> native-status (generated) -- do not edit >>>
// CDataModelPropGrid | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 12177b48 | roc native-status --write
#include "CSelectionPropGrid.h"
#include "ActiveDocView.h"

class CDataModelPropGrid : public CSelectionPropGrid, public ActiveDocView {
    DECLARE_DYNAMIC(CDataModelPropGrid)
public:
    CDataModelPropGrid();
    virtual void update(boost::shared_ptr<RBX::DataModel>, boost::shared_ptr<RBX::DataModel>);
};
