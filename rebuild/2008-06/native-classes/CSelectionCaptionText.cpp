// >>> native-status (generated) -- do not edit >>>
// CSelectionCaptionText | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 738d52a7 | roc native-status --write
#include "CSelectionCaption.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"

// Original 00465e40. Name access identified through AbstractFactoryProduct RTTI.
void CSelectionCaption::updateCaption()
{
    if (!m_hWnd)
        return;
    CString caption;
    std::string name;
    if (selection) {
        RBX::DataModel::Lock request(dataModel);
        std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator it = selection->selection->begin();
        if (it != selection->selection->end()) {
            name = (*it)->getName();
            const RBX::Name* commonClass = &(*it)->getClassName();
            while (++it != selection->selection->end()) {
                if ((*it)->getName() != name) {
                    name = "";
                    if (!commonClass)
                        break;
                }
                if (&(*it)->getClassName() != commonClass) {
                    commonClass = 0;
                    if (name == "")
                        break;
                }
            }
            if (commonClass) {
                if (name != "") {
                    if (selection->selection->size() > 1) {
                        const char* className = commonClass->name.c_str();
                        caption.Format(0xb5, className, name.c_str(), (int)selection->selection->size());
                    } else {
                        const char* className = commonClass->name.c_str();
                        caption.Format(0xb4, className, name.c_str());
                    }
                } else
                    caption.Format(0xb6, commonClass->name.c_str(), (int)selection->selection->size());
            } else
                caption.Format(0xb7, (int)selection->selection->size());
        }
    }
    UpdateCaption(caption, NULL);
}
