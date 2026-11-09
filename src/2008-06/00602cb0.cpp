// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_guibuilder_native_palette_9d2f31ec2bed2e23.cpp

// Candidate translation unit (score above; library headers required).
#include <v8datamodel/GuiBuilder.h>
#include <gui/Button.h>
#include <gui/MenuItem.h>
namespace RBX {
// Native601fd0/601f00/601e30/601db0: genuine constructor argument types
// and native copies/cleanup establish these external factory prototypes.
boost::shared_ptr<TopMenuBar> nativeBuilderPanel(const char*,Layout::Style);
boost::shared_ptr<ImageButton> nativeBuilderImageButton(Adorn*,Verb*,const char*);
boost::shared_ptr<MenuItem> nativeBuilderMenuItem(Verb*,const char*);
boost::shared_ptr<TopMenuBar> nativeBuilderRelativePanel(Layout);
class BuilderGuiApi {
public:
    unsigned numChildren() const {
        const boost::shared_ptr<Instances>& children=*(const boost::shared_ptr<Instances>*)((const char*)this+0x108);
        return children ? children->size() : 0;
    }
    void setGuiSize(const G3D::Vector2& value) { *(G3D::Vector2*)((char*)this+0x13c)=value; }
};
// Actual Workspace VerbContainer base begins at2ec in every native lookup.
// Genuine public getVerb(std::string) performs the lookup, not a substitute map.
__forceinline Verb* GuiBuilder::getVerb(const std::string& name) {
    return ((VerbContainer*)((char*)workspace+0x2ec))->getVerb(name);
}
void GuiBuilder::buildRightPaletteItems(Adorn* adorn,boost::shared_ptr<TopMenuBar> palette) {
    palette->addGuiItem(nativeBuilderImageButton(adorn,getVerb("FirstPersonIndicator"),"FirstPersonIndicator"));
    palette->addGuiItem(nativeBuilderImageButton(adorn,getVerb("ReportAbuse"),"ReportAbuse"));
    boost::shared_ptr<TopMenuBar> left=nativeBuilderPanel("CameraLeft",Layout::VERTICAL);
    left->addGuiItem(nativeBuilderImageButton(adorn,getVerb("CameraTiltUp"),"Tilt Up"));
    left->addGuiItem(nativeBuilderImageButton(adorn,getVerb("CameraTiltDown"),"Tilt Down"));
    boost::shared_ptr<TopMenuBar> right=nativeBuilderPanel("CameraRight",Layout::VERTICAL);
    right->addGuiItem(nativeBuilderImageButton(adorn,getVerb("CameraZoomIn"),"Zoom In"));
    right->addGuiItem(nativeBuilderImageButton(adorn,getVerb("CameraZoomOut"),"Zoom Out"));
    boost::shared_ptr<TopMenuBar> camera=nativeBuilderPanel("CameraPanel",Layout::HORIZONTAL);
    camera->addGuiItem(left);
    camera->addGuiItem(right);
    palette->addGuiItem(camera);
}
boost::shared_ptr<TopMenuBar> GuiBuilder::buildMenu() {
    Layout layout;
    layout.backdropColor=GuiItem::translucentBackdrop();
    boost::shared_ptr<TopMenuBar> menu=nativeBuilderRelativePanel(layout);
    menu->setName("MainMenu");
    menu->addGuiItem(nativeBuilderMenuItem(getVerb("TogglePlayMode"),"Tools"));
    menu->addGuiItem(nativeBuilderMenuItem(getVerb("ToggleToolbox"),"Insert"));
    menu->addGuiItem(nativeBuilderMenuItem(getVerb("ToggleFullScreen"),"Fullscreen"));
    menu->addGuiItem(nativeBuilderMenuItem(getVerb("Help"),"Help..."));
    menu->addGuiItem(nativeBuilderMenuItem(getVerb("Exit"),"   Exit"));
    for(unsigned i=0;i<((BuilderGuiApi*)menu.get())->numChildren();++i) {
        GuiItem* item=menu->getGuiItem(i);
        if(item) ((BuilderGuiApi*)item)->setGuiSize(G3D::Vector2(100.0f,20.0f));
    }
    return menu;
}
}
