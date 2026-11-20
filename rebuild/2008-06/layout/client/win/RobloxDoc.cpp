#include "CUploadPlaceDialog.h"

CString applicationBaseUrl();

CUploadPlaceDialog::CUploadPlaceDialog(IDispatch* dispatch, CWnd* parent)
    : CSaveToRobloxDialog(dispatch, applicationBaseUrl() + "/Game/Upload.aspx", parent) {}
