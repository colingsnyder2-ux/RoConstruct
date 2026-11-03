#include "../native-headers/CRobloxView.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "../native-headers/v8tree/Verb.h"
#include <exception>

template<>
BOOL VerbBinder<CRobloxView, CView>::OnCmdMsg(UINT id, int code, void* extra, AFX_CMDHANDLERINFO* info)
{
    if (code == 0 || code == -1) {
        std::map<DWORD, const RBX::Name*>::iterator it = commandNames.find(id);
        if (it != commandNames.end() && it->second) {
            CRobloxView* view = static_cast<CRobloxView*>(this);
            boost::shared_ptr<const RBX::DataModel> model = view->getDataModel();
            RBX::DataModel::Lock lock(model);
            const RBX::Name* name = it->second;
            RBX::Verb* verb = view->getVerb(*name);
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
