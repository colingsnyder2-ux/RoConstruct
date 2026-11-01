#pragma once
#include <XTToolkitPro.h>
#include "ActiveDocView.h"
#include "util/MarshaledListener.h"

namespace RBX { class Selection; class SelectionChanged; }

// Inactive layout recovery. Remaining message handlers/virtual ABI and
// ActiveDocView callback pointee identities are not yet fully verified.
class CSelectionCaption : public CXTCaption,
                          public ActiveDocView,
                          public RBX::FilteredListener<RBX::Selection, RBX::SelectionChanged> {
    DECLARE_DYNAMIC(CSelectionCaption)
public:
    CSelectionCaption();
    virtual ~CSelectionCaption();
    virtual void update(boost::shared_ptr<RBX::DataModel>, boost::shared_ptr<RBX::Instance>);
    virtual void onMarshaledEvent(const RBX::Selection*, RBX::SelectionChanged);
    virtual bool filter(const RBX::Selection*, const RBX::SelectionChanged&,
                        const RBX::Selection*, const RBX::SelectionChanged&);
    void updateCaption();
    boost::shared_ptr<RBX::DataModel> dataModel;
    boost::shared_ptr<RBX::Selection> selection;
};
