// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_arrowpanel_native_family_d5e2c720e07b3169.cpp

// Candidate translation unit (score above; library headers required).
#include <gui/ArrowPanel.h>
namespace RBX {
// Native factory call boundaries601fd0/657000/656f60/657190/6026e0.
// Genuine public constructor types plus native argument copies/cleanup prove
// these prototypes. External factories retain their native allocations/owners;
// no synthetic object sizes, padding, deleters or virtual slots are modeled.
boost::shared_ptr<TopMenuBar> nativeArrowColumn(const char*,Layout::Style);
boost::shared_ptr<TopMenuBar> nativeNamedArrowColumn(std::string,Layout::Style);
boost::shared_ptr<ImageWidget> nativeArrowImage(Adorn*,std::string);
boost::shared_ptr<ArrowButton> nativeArrowButton(Adorn*,std::string,SDLKey,Controller::ControllerType,DataModel*);
boost::shared_ptr<MenuSpacer> nativeArrowSpacer(float,float);
void ArrowPanel::init(Adorn* adorn,const std::string& title,const std::string& up,const std::string& down,const std::string& left,const std::string& right,SDLKey upKey,SDLKey downKey,SDLKey leftKey,SDLKey rightKey) {
    boost::shared_ptr<TopMenuBar> leftPanel=nativeArrowColumn("LeftPanel",Layout::VERTICAL);
    leftPanel->addGuiItem(nativeArrowImage(adorn,title));
    leftPanel->addGuiItem(nativeArrowButton(adorn,left,leftKey,*(Controller::ControllerType*)((char*)this+0x160),*(DataModel**)((char*)this+0x15c)));
    boost::shared_ptr<TopMenuBar> forwardBackPanel=nativeArrowColumn("ForwardBackPanel",Layout::VERTICAL);
    forwardBackPanel->addGuiItem(nativeArrowButton(adorn,up,upKey,*(Controller::ControllerType*)((char*)this+0x160),*(DataModel**)((char*)this+0x15c)));
    forwardBackPanel->addGuiItem(nativeArrowButton(adorn,down,downKey,*(Controller::ControllerType*)((char*)this+0x160),*(DataModel**)((char*)this+0x15c)));
    boost::shared_ptr<TopMenuBar> rightPanel=nativeNamedArrowColumn(right,Layout::VERTICAL);
    rightPanel->addGuiItem(nativeArrowSpacer(32.0f,32.0f));
    rightPanel->addGuiItem(nativeArrowButton(adorn,right,rightKey,*(Controller::ControllerType*)((char*)this+0x160),*(DataModel**)((char*)this+0x15c)));
    addGuiItem(leftPanel);
    addGuiItem(forwardBackPanel);
    addGuiItem(rightPanel);
}
ArrowPanel::ArrowPanel(Adorn* adorn,DataModel* model,Controller::ControllerType type)
    :TopMenuBar("ArrowPanel",Layout::HORIZONTAL,false) {
    // Native own members15c/160, later than the older SDK's inherited layout.
    *(DataModel**)((char*)this+0x15c)=model;
    *(Controller::ControllerType*)((char*)this+0x160)=type;
    switch(type) {
    case Controller::PLAYER_CONTROLLER:
        init(adorn,"Character","W_key","S_key","A_key","D_key",SDLK_w,SDLK_s,SDLK_a,SDLK_d);
        break;
    case Controller::SECONDARY_CONTROLLER:
        init(adorn,"Controller2","W_key","S_key","A_key","D_key",SDLK_w,SDLK_s,SDLK_a,SDLK_d);
        break;
    case Controller::PRIMARY_CONTROLLER:
        init(adorn,"Controller1","U_key","J_key","H_key","K_key",SDLK_u,SDLK_j,SDLK_h,SDLK_k);
        break;
    }
}
}
