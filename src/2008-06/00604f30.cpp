// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_hud_native_widths_f832140a2f3f7f31.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_instance_genuine_guiditem_headerf016862b4461fbce.cpp")
#define _CPPUNWIND 1
#include "gui/Layout.h"
#include "gui/Gui.h"
namespace RBX { inline void TextDisplay::setFontSize(int size) { fontSize=size; setGuiSize(G3D::Vector2(fontSize*10.0f,fontSize*2.0f)); } }
#include "util/Utilities.h"
#include <G3D/Color3.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <string>
// 2008 interfaces/offsets from 006041d0 and 00604f30. No full object layout claimed.
namespace HudRecovery {
class Item { public: virtual ~Item(); virtual void setName(const std::string&); };
class Text : public Item { public:
 void setFontSize(int value) { reinterpret_cast<RBX::TextDisplay*>(this)->setFontSize(value); }
 void setFontColor(const G3D::Color4& value) { *reinterpret_cast<G3D::Color4*>(reinterpret_cast<char*>(this)+0x164)=value; }
 void setBorderColor(const G3D::Color4& value) { *reinterpret_cast<G3D::Color4*>(reinterpret_cast<char*>(this)+0x174)=value; }
 void setGuiSize(const G3D::Vector2& value) { *reinterpret_cast<G3D::Vector2*>(reinterpret_cast<char*>(this)+0x13c)=value; }
};
class Panel : public Item { public:
 void addGuiItem(boost::shared_ptr<Item>);
 const RBX::CopyOnWrite<std::vector<boost::shared_ptr<Item> > >& children() const {return *reinterpret_cast<const RBX::CopyOnWrite<std::vector<boost::shared_ptr<Item> > >*>(reinterpret_cast<const char*>(this)+0x108);}
 size_t numChildren() const {return children()?children()->size():0;}
 Item* child(size_t index) const {return (*children())[index].get();}
 void setVisible(bool value) { *reinterpret_cast<bool*>(reinterpret_cast<char*>(this)+0x158)=value; }
};
class RelativePanel : public Panel {};
class Equation : public Text {};
boost::shared_ptr<RelativePanel> createPanel(RBX::Layout);
boost::shared_ptr<Text> createText(const char*,const char*);
boost::shared_ptr<Equation> createEquation(const char*,const char*);
boost::shared_ptr<Text> shareText(void*);
const G3D::Color4& background();
class Builder {public: boost::shared_ptr<Panel> stats1();boost::shared_ptr<Panel> stats2();};
boost::shared_ptr<Panel> Builder::stats1() {
 RBX::Layout layout; layout.xLocation=RBX::Rect::LEFT;layout.yLocation=RBX::Rect::BOTTOM;layout.offset.x=50;layout.offset.y=40;layout.layoutStyle=RBX::Layout::VERTICAL;layout.backdropColor=background();
 boost::shared_ptr<RelativePanel> panel=createPanel(layout);
 panel->setName("StatsHud1");
 panel->addGuiItem(createText("","----- World ----"));
 panel->addGuiItem(createEquation("Primitives    : ","numPrimitives"));
 panel->addGuiItem(createEquation("Joints        : ","numJoints"));
 panel->addGuiItem(createEquation("Contacts      : ","numContacts"));
 panel->addGuiItem(createEquation("Tree          : ","maxTreeDepth"));
 panel->addGuiItem(createText("","----- Timing -----"));
 panel->addGuiItem(createEquation("FPS           : ","FPS"));
 panel->addGuiItem(createEquation("SimCpu        : ","SimCpu"));
 panel->addGuiItem(createEquation("GfxCpu        : ","GfxCpu"));
 panel->addGuiItem(createEquation("UiCpu         : ","UiCpu"));
 panel->addGuiItem(createEquation("IdleCpu       : ","IdleCpu"));
 panel->addGuiItem(createEquation("Gfx           : ","GfxTime"));
 panel->addGuiItem(createText("","----- Graphics ----"));
 panel->addGuiItem(createEquation("Mode          : ","graphicsMode"));
 panel->addGuiItem(createEquation("Video Memory  : ","videoMemory"));
 panel->addGuiItem(createEquation("Shadows:      : ","Shadows"));
 panel->addGuiItem(createEquation("Anti-Aliasing : ","antiAliasing"));
 panel->addGuiItem(createEquation("Bevels        : ","bevels"));
 panel->addGuiItem(createEquation("FrameId       : ","drawId"));
 panel->addGuiItem(createText("","----- Throttles ----"));
 panel->addGuiItem(createEquation("eThrottle %   : ","eThrottle"));
 panel->addGuiItem(createEquation("FRM           : ","FRM"));
 panel->addGuiItem(createEquation("Particles     : ","Particles"));
 for(size_t i=0;i<panel->numChildren();++i) {
  Item* item=panel->child(i);
  boost::shared_ptr<Text> text=shareText(item?reinterpret_cast<char*>(item)+0xe4:0);
  text->setFontSize(14);text->setFontColor(G3D::Color4(G3D::Color3::purple(),1.0f));text->setBorderColor(G3D::Color4::clear());text->setGuiSize(G3D::Vector2(310.0f,22.0f));
 }
 panel->setVisible(false);
 return panel;
}
boost::shared_ptr<Panel> Builder::stats2() {
 RBX::Layout layout; layout.xLocation=RBX::Rect::RIGHT;layout.yLocation=RBX::Rect::BOTTOM;layout.offset.x=50;layout.offset.y=40;layout.layoutStyle=RBX::Layout::VERTICAL;layout.backdropColor=background();
 boost::shared_ptr<RelativePanel> panel=createPanel(layout);
 panel->setName("StatsHud2");
 panel->addGuiItem(createText("","----- Contacts ----"));
 panel->addGuiItem(createEquation("CtctStageCtcts: ","numContactsInCollisionStage"));
 panel->addGuiItem(createEquation("SteppingCtcts : ","numSteppingContacts"));
 panel->addGuiItem(createEquation("TouchingCtcts : ","numTouchingContacts"));
 panel->addGuiItem(createEquation("% Pair Hit    : ","contactPairHitRatio"));
 panel->addGuiItem(createEquation("% Feature Hit : ","contactFeatureHitRatio"));
 panel->addGuiItem(createEquation("# link(p)     : ","numLinkCalls"));
 panel->addGuiItem(createEquation("sH Nodes Out  : ","numHashNodes"));
 panel->addGuiItem(createEquation("sH Max Bucket : ","maxBucketSize"));
 panel->addGuiItem(createText("","----- Kernel ----"));
 panel->addGuiItem(createEquation("Solver Iteratn: ","solverIterations"));
 panel->addGuiItem(createEquation("Matrix Size   : ","matrixSize"));
 panel->addGuiItem(createEquation("Bodies        : ","numBodies"));
 panel->addGuiItem(createEquation("Leaves        : ","numLeafBodies"));
 panel->addGuiItem(createEquation("grpJobs       : ","numGroupJobs"));
 panel->addGuiItem(createEquation("projJobs      : ","numProjectileJobs"));
 panel->addGuiItem(createEquation("Constraints   : ","numConstraints"));
 panel->addGuiItem(createEquation("Points        : ","numPoints"));
 panel->addGuiItem(createEquation("% Active CC's : ","percentConnectorsActive"));
 panel->addGuiItem(createEquation("Energy B      : ","energyBody"));
 panel->addGuiItem(createEquation("Energy C      : ","energyConnector"));
 panel->addGuiItem(createEquation("Energy T      : ","energyTotal"));
 for(size_t i=0;i<panel->numChildren();++i) {
  Item* item=panel->child(i);
  boost::shared_ptr<Text> text=shareText(item?reinterpret_cast<char*>(item)+0xe4:0);
  text->setFontSize(14);text->setFontColor(G3D::Color4(G3D::Color3::purple(),1.0f));text->setBorderColor(G3D::Color4::clear());text->setGuiSize(G3D::Vector2(260.0f,22.0f));
 }
 panel->setVisible(false);
 return panel;
}
}
