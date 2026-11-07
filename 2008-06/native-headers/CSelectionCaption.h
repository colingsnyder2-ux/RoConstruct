#pragma once
// >>> native-status (generated) -- do not edit >>>
// CSelectionCaption | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 9f8154f9 | roc native-status --write
#include <XTToolkitPro.h>
#include "ActiveDocView.h"
#include "util/MarshaledListener.h"
#include "v8datamodel/Selection.h"


// Inactive layout recovery. Remaining message handlers/virtual ABI and
// Marshal framework and full virtual bindings remain under verification.
class CSelectionCaption : public CXTCaption,
                          public ActiveDocView,
                          public RBX::FilteredListener<RBX::Selection, RBX::SelectionChanged> {
    DECLARE_DYNAMIC(CSelectionCaption)
    DECLARE_MESSAGE_MAP()
public:
    CSelectionCaption();
    virtual ~CSelectionCaption();
    virtual void update(boost::shared_ptr<RBX::DataModel>, boost::shared_ptr<RBX::DataModel>);
    virtual void onMarshaledEvent(const RBX::Selection*, RBX::SelectionChanged);
    virtual bool filter(const RBX::Selection*, const RBX::SelectionChanged&,
                        const RBX::Selection*, const RBX::SelectionChanged&);
    void updateCaption();
    virtual BOOL PreCreateWindow(CREATESTRUCT&);
    virtual BOOL Create(LPCTSTR, DWORD, const RECT&, CWnd*, UINT);
    afx_msg int OnCreate(LPCREATESTRUCT);
    boost::shared_ptr<RBX::DataModel> dataModel;
    boost::shared_ptr<RBX::Selection> selection;
};
