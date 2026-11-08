// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-count-copy
// >>> native-status (generated) -- do not edit >>>
// ViewCommandRouting | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 413f44ff | roc native-status --write
#include "../../native-headers/CRobloxView.h"
#include "../../native-headers/v8datamodel/DataModel.h"
#include "../../native-headers/v8tree/Verb.h"
#include <exception>

template<>
BOOL VerbBinder<CRobloxView, CView>::OnCmdMsg(UINT id, int code, void* extra, AFX_CMDHANDLERINFO* info)
{
    if (code == 0 || code == -1) {
        std::map<UINT, const RBX::Name*>::iterator it = commandNames.find(id);
        if (it != commandNames.end() && it->second) {
            CRobloxView* view = static_cast<CRobloxView*>(this);
            const boost::shared_ptr<const RBX::DataModel> model = view->getDataModel();
            RBX::DataModel::Lock lock(model);
            const RBX::Name* name = it->second;
            RBX::VerbContainer* verbs = static_cast<RBX::VerbContainer*>(view);
            RBX::Verb* verb = verbs ? verbs->getVerb(*name) : 0;
            if (verb) {
                if (code == 0) {
                    try { verb->doIt(model ? const_cast<RBX::DataModel*>(model.get()) : 0); }
                    catch (std::exception& error) { AfxMessageBox(error.what(), 0, 0); }
                } else {
                    CCmdUI* ui = static_cast<CCmdUI*>(extra);
                    ui->Enable(verb->isEnabled() ? TRUE : FALSE);
                    ui->SetCheck(verb->isChecked() ? 1 : 0);
                }
            }
            return TRUE;
        }
    }
    return CView::OnCmdMsg(id, code, extra, info);
}
