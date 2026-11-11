// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-dialog
// >>> native-status (generated) -- do not edit >>>
// CInsertObjectDialogCore | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 99a5d374 | roc native-status --write
#include "CInsertObjectDialog.h"
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8datamodel/DataModel.h"
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <algorithm>

IMPLEMENT_DYNAMIC(CInsertObjectDialog, CDialog)

BEGIN_MESSAGE_MAP(CInsertObjectDialog, CDialog)
    ON_NOTIFY(NM_DBLCLK, 1000, &CInsertObjectDialog::OnNMDblclk)
END_MESSAGE_MAP()

CInsertObjectDialog::CInsertObjectDialog(boost::shared_ptr<RBX::Instance> parent, CWnd* parentWindow)
    : CDialog(parent ? 107 : 214, parentWindow),
      parent(parent),
      className("")
{
}

CInsertObjectDialog::~CInsertObjectDialog() {}

BOOL CInsertObjectDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    list.SetFocus();
    return FALSE;
}

void CInsertObjectDialog::OnNMDblclk(NMHDR*, LRESULT* result)
{
    OnOK();
    *result = 0;
}

int CALLBACK CInsertObjectDialog::compareItems(LPARAM first, LPARAM second, LPARAM)
{
    return RBX::Name::compare(
        const_cast<RBX::Name&>(reinterpret_cast<RBX::Instance*>(first)->getClassName()),
        const_cast<RBX::Name&>(reinterpret_cast<RBX::Instance*>(second)->getClassName()));
}

void CInsertObjectDialog::DoDataExchange(CDataExchange* exchange)
{
    DDX_Control(exchange, 1000, list);
    if (exchange->m_bSaveAndValidate) {
        POSITION position = list.GetFirstSelectedItemPosition();
        if (position) {
            int item = list.GetNextSelectedItem(position);
            className = list.GetItemText(item, 0);
            selected = RBX::shared_from(reinterpret_cast<RBX::Instance*>(list.GetItemData(item)));
        }
    } else if (list.GetItemCount() == 0) {
        list.SetView(LV_VIEW_LIST);
        list.ModifyStyle(0, LVS_ALIGNLEFT);
        list.SetImageList(&images, LVSIL_SMALL);
        addClasses(&RBX::Reflection::ClassDescriptor::rootDescriptor());
        list.SortItems(&CInsertObjectDialog::compareItems, 0);
    }
}

