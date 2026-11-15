#pragma once
#include "CPropGrid.h"
#include <boost/shared_ptr.hpp>
namespace RBX { class Selection; class SelectionChanged; }

class CSelectionPropGrid : public CPropGrid,
                           public RBX::Listener<RBX::Selection, RBX::SelectionChanged> {
    DECLARE_DYNAMIC(CSelectionPropGrid)
public:
    CSelectionPropGrid() {}
    virtual ~CSelectionPropGrid();
    virtual void onEvent(const RBX::Selection*, RBX::SelectionChanged);
    void setSelection(RBX::Selection*);
    boost::shared_ptr<RBX::Selection> selection;
};
