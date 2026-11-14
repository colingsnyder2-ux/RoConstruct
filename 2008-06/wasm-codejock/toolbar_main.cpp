#include "ToolbarSubset.h"
#include <cstdio>
#include <emscripten.h>

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
        bool embedded=EM_ASM_INT({return !!Module.toolbarEmbedded;});
        const char* demoLabels[]={"&Run","&Pause","&Reset","Disabled"};
        const char* castleLabels[]={"Run","Pause","Reset camera","Shadows","Orbit","Sun / Moon","Wireframe","+3 hours","Help","Fullscreen","Copy view"};
        int count=embedded?11:4;
        for(int i=0;i<count;++i) {
            auto* button=new DemoButton;
            button->m_pParent=&bar; button->m_nIndex=i;
            button->caption=embedded?castleLabels[i]:demoLabels[i];button->id=100+i;
            button->enabled=embedded||i!=3;button->beginGroup=i==2||embedded&&i==7;
            bar.controls.controls.push_back(button);
        }
        BrowserInit(&bar);
        std::puts("Codejock toolbar source subset initialized");
        while(true) { MSG message;GetMessage(&message,nullptr,0,0);DispatchMessage(&message); }
    } catch(const std::exception& e) {
        std::fprintf(stderr,"Codejock port failed: %s\n",e.what());return 1;
    }
}
