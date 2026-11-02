#pragma once
#include <XTToolkitPro.h>

namespace RBX { class Instance; }

// CInstanceExplorer: CRuntimeClass 0080f638 (size 0x3cc, create 004219f0, base getter 00420770 ->
// CXTPReportView 00852c1c). Only the declarations CSettingsDialog uses are given here; its data
// layout (listeners at +0x378/+0x39c, root shared_ptr at +0x3c0, flag at +0x3c8 per 00421a50) is
// left for the CInstanceExplorer recovery, so sizeof is not asserted.
class CInstanceExplorer : public CXTPReportView {
    DECLARE_DYNCREATE(CInstanceExplorer)
public:
    // Original 00421a50 (callers 00421c09, 004670f9): replaces the explored root instance.
    void setRoot(RBX::Instance*);
};
