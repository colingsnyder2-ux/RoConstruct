#include "ToolbarSubset.h"
#include <cstdio>

// Application customization of Codejock's virtual execute handler. The original
// OnClick / ClickToolBarButton machinery decides whether activation occurs.
class DemoButton : public CXTPControlButton {
public:
    void OnExecute() override { NotifyExecute(this,m_pParent->GetOwnerSite()); }
};
int main() {
    try {
        CWnd owner;
        CXTPToolBar bar;
        bar.owner=&owner;
        bar.controls.m_pParent=&bar;
        const char* labels[]={"&Run","&Pause","&Reset","Disabled"};
        for(int i=0;i<4;++i) {
            auto* button=new DemoButton;
            button->m_pParent=&bar; button->m_nIndex=i;
            button->caption=labels[i];button->id=100+i;
            button->enabled=i!=3;button->beginGroup=i==2;
            bar.controls.controls.push_back(button);
        }
        BrowserInit(&bar);
        std::puts("Codejock toolbar source subset initialized");
        while(true) { MSG message;GetMessage(&message,nullptr,0,0);DispatchMessage(&message); }
    } catch(const std::exception& e) {
        std::fprintf(stderr,"Codejock port failed: %s\n",e.what());return 1;
    }
}
