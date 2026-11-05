// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_c3c890fa834d4f27.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <stdio.h>

namespace RBX {
class Instance { public: virtual ~Instance(); };
class DataModel : public Instance {
public:
    class scoped_lock {
    public:
        scoped_lock(boost::shared_ptr<const DataModel> dataModel);
        ~scoped_lock();
        void* p;
        void* q;
        void* r;
    };
    double getFrameRate();
};
}

class CCmdUI {
public:
    virtual void Enable(int bOn = 1);
    virtual void SetCheck(int nCheck = 1);
    virtual void SetRadio(int bOn = 1);
    virtual void SetText(const char* lpszText);
};

class CGame {
public:
    boost::shared_ptr<RBX::DataModel> getDataModel();
};

class CRobloxDoc {
public:
    char pad[0x94];
    CGame* game;
    boost::shared_ptr<RBX::DataModel> getDataModel();
    void OnUpdateFrameRate(CCmdUI* pCmdUI);
};

void CRobloxDoc::OnUpdateFrameRate(CCmdUI* pCmdUI)
{
    if (getDataModel()) {
        RBX::DataModel::scoped_lock lock(game->getDataModel());
        double value = getDataModel()->getFrameRate() * 100.0;
        char buf[32];
        sprintf(buf, "%.3g%%", value);
        pCmdUI->SetText(buf);
    }
}
