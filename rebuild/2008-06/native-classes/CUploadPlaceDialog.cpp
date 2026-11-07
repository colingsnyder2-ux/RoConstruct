// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// CUploadPlaceDialog | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src f5f0a362 | roc native-status --write
#include "CUploadPlaceDialog.h"

// Original 004060d0 returns the application-owned base URL CString.
CString applicationBaseUrl();

// Original 0044f5c0; only caller 004553b2 constructs it on the stack.
CUploadPlaceDialog::CUploadPlaceDialog(IDispatch* dispatch, CWnd* parent)
    : CSaveToRobloxDialog(dispatch, applicationBaseUrl() + "/Game/Upload.aspx", parent) {}
