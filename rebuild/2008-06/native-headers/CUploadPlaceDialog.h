#pragma once
// >>> native-status (generated) -- do not edit >>>
// CUploadPlaceDialog | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 85d76acc | roc native-status --write
#include "CSaveToRobloxDialog.h"

// Inactive layout recovery. RTTI (COL of vtables 0081757c/00817550): CUploadPlaceDialog ->
// CSaveToRobloxDialog -> CRobloxDHtmlDialog -> CDHtmlDialog, CDHtmlEventSink subobject at +0x74.
// No CRuntimeClass of its own (slot 0 is CRobloxDHtmlDialog::GetRuntimeClass 0044ee90) and no
// own message/event-sink/DHTML maps (slots reuse CSaveToRobloxDialog 004012c0/0045fe70/0045fe40).
// Constructor 0044f5c0 stores only the two vtable pointers after the base constructor and the
// scalar deleting destructor 0044f5a0 calls ~CSaveToRobloxDialog (0045fe20) directly, so the class
// adds no data members: sizeof == sizeof(CSaveToRobloxDialog) == 0x130.
class CUploadPlaceDialog : public CSaveToRobloxDialog {
public:
    CUploadPlaceDialog(IDispatch*, CWnd*);
};
