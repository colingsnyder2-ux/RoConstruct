#include "CUploadPlaceDialog.h"

// Original 004060d0 returns the application-owned base URL CString.
CString applicationBaseUrl();

// Original 0044f5c0; only caller 004553b2 constructs it on the stack.
CUploadPlaceDialog::CUploadPlaceDialog(IDispatch* dispatch, CWnd* parent)
    : CSaveToRobloxDialog(dispatch, applicationBaseUrl() + "/Game/Upload.aspx", parent) {}
