#include "CSaveToRobloxDialog.h"

CSaveToRobloxDialog::CSaveToRobloxDialog(IDispatch* dispatch, const char* location, CWnd* parent)
    : CRobloxDHtmlDialog(0x71, location, parent)
{
    SetExternalDispatch(dispatch);
}
CSaveToRobloxDialog::~CSaveToRobloxDialog() {}
