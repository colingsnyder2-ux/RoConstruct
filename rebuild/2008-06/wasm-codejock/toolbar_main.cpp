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
        const char* castleLabels[]={"Scene: Castle Island","Run","Pause","Reset camera","Shadows","Orbit","Sun / Moon","Wireframe","+3 hours","Fullscreen"};
        const int castleCommands[]={120,100,101,102,103,104,105,106,107,109};
        int count=embedded?10:4;
        for(int i=0;i<count;++i) {
            CXTPControl* button;
            if(embedded&&i==0) {
                auto* popup=new CXTPControlPopup;
                popup->m_bShowShadow=FALSE;
                auto* menu=new CXTPPopupBar;
                menu->owner=&owner;
                const char* scenes[]={"Castle Island","Windmill Island","Temple Island"};
                for(int j=0;j<3;++j) {
                    auto* item=new DemoButton;item->m_pParent=menu;item->m_nIndex=j;
                    item->caption=scenes[j];item->id=200+j;menu->controls.controls.push_back(item);
                }
                popup->m_pCommandBar=menu;button=popup;
            } else button=new DemoButton;
            button->m_pParent=&bar; button->m_nIndex=i;
            button->caption=embedded?castleLabels[i]:demoLabels[i];button->id=embedded?castleCommands[i]:100+i;
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
