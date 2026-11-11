#pragma once
// >>> native-status (generated) -- do not edit >>>
// CMainFrameBases | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ba6da74d | roc native-status --write
#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <afxmt.h>
#include <XTToolkitPro.h>
#include "util/Events.h"

namespace RBX { class FillToolColor; class BrickColor; }

// Inactive base layout. Complete CMainFrame storage and virtuals remain open.
class CMainFrameBases : public CXTPMDIFrameWnd,
                        public RBX::Listener<RBX::FillToolColor, RBX::BrickColor> {};

// Consecutive original members at CMainFrame offsets 0x10c, 0x138, 0x284.
struct CMainFrameXtpComponents {
    CXTWindowPos windowPosition;
    CXTPDockingPaneManager dockingPanes;
    CXTPTabClientWnd tabClient;
};

class CDataModelPropGrid;
class CSelectionCaption;
// Consecutive owning pointers at original frame offsets 0x3a8, 0x3ac, 0x3b0.
struct CMainFramePanePointers {
    CXTSplitterWnd* splitter;
    CDataModelPropGrid* propertyGrid;
    CSelectionCaption* selectionCaption;
};
