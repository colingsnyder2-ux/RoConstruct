// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Hopper.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Hopper.h"

#include "compat.h"
#include "reflection/enumconverter.h"
#include "reflection/property.h"
#include "reflection/signal.h"
#include "util/Name.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/Workspace.h"

namespace RBX {

static Reflection::PropDescriptor<BackpackItem, TextureId> desc_TextureId(
	"TextureId", "Data", &BackpackItem::getTextureId, &BackpackItem::setTextureId
);

static Reflection::EnumPropDescriptor<HopperBin, HopperBin::BinType> desc_BinType(
	"BinType", "Data", &HopperBin::getBinType, &HopperBin::setBinType
);

static Reflection::SignalDesc<HopperBin, void(boost::shared_ptr<Instance>)> desc_Selected("Selected", "mouse");
static Reflection::SignalDesc<HopperBin, void()> desc_Deselected("Deselected");

static Reflection::PropDescriptor<HopperBin, std::string> desc_legacyCommand(
	"Command", "Data", NULL, &HopperBin::setLegacyCommand, Reflection::PropertyDescriptor::LEGACY
);

static Reflection::PropDescriptor<HopperBin, std::string> desc_legacyTextureName(
	"TextureName", "Data", NULL, &HopperBin::setLegacyTextureName, Reflection::PropertyDescriptor::LEGACY
);

bool BackpackItem::inBackpack()
{
	return getParent() && dynamic_cast<Backpack*>(getParent()) != NULL;
}

int BackpackItem::getBinId() const
{
	return getParent() ? getParent()->findChildIndex(this) : -1;
}

// FUNCTION: WEBSERVICE 0x100c70f0
// FUNCTION: ROBLOX 0x005e13b0
const TextureId BackpackItem::getTextureId() const
{
	return textureId;
}

// FUNCTION: WEBSERVICE 0x100c7120
// FUNCTION: ROBLOX 0x005e13e0
bool Hopper::askAddChild(const Instance* instance) const
{
	return dynamic_cast<const BackpackItem*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x100c7870
// FUNCTION: ROBLOX 0x005e1ab0
Hopper::Hopper()
{
	yLocation = Rect::BOTTOM;
}

// STUB: WEBSERVICE 0x100c7b90
// STUB: ROBLOX 0x005e1da0
void StarterPackService::render2d(Adorn* adorn)
{
	Hopper::render2d(adorn);

	if (findFirstChildOfType<BackpackItem>()) {
		G3D::Rect2D viewPort = adorn->getViewport();

		int fontSize = GuiRoot::normalizedFontSize(12);
		G3D::Vector2 pos2d = viewPort.x0y1() + G3D::Vector2(4, -4);

		adorn->drawFont2D(
			"StarterPack - these items will be given to each new player",
			pos2d,
			fontSize,
			G3D::Color3::white(),
			G3D::Color4::clear(),
			Adorn::XALIGN_LEFT,
			Adorn::YALIGN_BOTTOM,
			Adorn::PROPORTIONAL_SPACING
		);
	}
}

// FUNCTION: WEBSERVICE 0x100c7ca0
// FUNCTION: ROBLOX 0x005e1eb0
LegacyHopperService::~LegacyHopperService()
{
}

// FUNCTION: WEBSERVICE 0x100c8440
// FUNCTION: ROBLOX 0x005e2520
template <>
Reflection::EnumDesc<HopperBin::BinType>::EnumDesc() : EnumDescriptor("BinType", typeid(HopperBin::BinType))
{
	addPair(HopperBin::SCRIPT_BIN, "Script");
	addPair(HopperBin::GAME_TOOL, "GameTool");
	addPair(HopperBin::GRAB_TOOL, "Grab");
	addPair(HopperBin::CLONE_TOOL, "Clone");
	addPair(HopperBin::HAMMER_TOOL, "Hammer");
	addPair(HopperBin::SLINGSHOT_TOOL, "Slingshot");
	addPair(HopperBin::ROCKET_TOOL, "Rocket");
	addPair(HopperBin::LASER_TOOL, "Laser");
}

// FUNCTION: WEBSERVICE 0x100c8c40
// FUNCTION: ROBLOX 0x005e2d10
void BackpackItem::render2d(Adorn* adorn)
{
	bool viewHack = false;
	Workspace* workspace = ServiceProvider::find<Workspace>(this);
	if (workspace && workspace->imageServerViewHack) {
		viewHack = true;
	}

	Rect draw = viewHack ? Rect(GuiRoot::getCanvasSize()) : getMyRect();

	int fontSize = GuiRoot::normalizedFontSize(12);

	float numberSize = draw.size().x * 0.2f;
	Rect numberRect = Rect::fromLowSize(
		G3D::Vector2(draw.low.x + 2, draw.high.y - 2 - numberSize), G3D::Vector2(numberSize, numberSize)
	);

	if (!viewHack) {
		adorn->rect2d(draw.toRect2D(), GuiItem::translucentBackdrop());
	}

	if (isEnabled()) {
		adorn->rect2d(numberRect.toRect2D(), G3D::Color4(G3D::Color3::gray(), 1));

		adorn->drawFont2D(
			StringConverter<int>::convertToString(getBinId() + 1),
			numberRect.center(),
			fontSize,
			G3D::Color3::white(),
			G3D::Color4::clear(),
			Adorn::XALIGN_CENTER,
			Adorn::YALIGN_CENTER,
			Adorn::PROPORTIONAL_SPACING
		);
	}

	if (drawSelected()) {
		adorn->outlineRect2d(draw.toRect2D(), 3.0f, G3D::Color4(G3D::Color3::green(), 1));
	}

	if (guiImageDraw.setImage(adorn, textureId)) {
#ifdef COMPAT_MODE
		Rect imageRect = draw.inset(fontSize);
		guiImageDraw.render2d(adorn, isEnabled() || viewHack, imageRect, widgetState);
#else
		guiImageDraw.render2d(adorn, isEnabled() || viewHack, draw.inset(fontSize), widgetState);
#endif
	}
	else {
		Widget::render2d(adorn);
	}
}

// FUNCTION: WEBSERVICE 0x100c8f80
// FUNCTION: ROBLOX 0x005e3050
void HopperBin::onSelectCommand()
{
	DataModel* dataModel = static_cast<DataModel*>(getRootAncestor());

	std::string command = Reflection::EnumDesc<BinType>::singleton().convertToString(binType) + "Tool";

	Verb* verb = dataModel->getVerb(command);

	if (verb->isEnabled()) {
		if (Workspace* workspace = ServiceProvider::find<Workspace>(this)) {
			verb->doIt(&workspace->getDataState());
		}
	}
}

// FUNCTION: WEBSERVICE 0x100c9070
// FUNCTION: ROBLOX 0x005e3140
void LegacyHopperService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Instance::onServiceProvider(oldProvider, newProvider);

	if (newProvider) {
		StarterPackService* starterPack = newProvider->find<StarterPackService>();

		while (numChildren() > 0) {
			getChild(0)->setParent(starterPack);
		}

		setParent(NULL);
	}
}

// FUNCTION: WEBSERVICE 0x100c9520
// FUNCTION: ROBLOX 0x005e35d0
StarterPackService::StarterPackService()
{
	setName(sStarterPackService);
}

// FUNCTION: WEBSERVICE 0x100c9620
// FUNCTION: ROBLOX 0x005e36d0
LegacyHopperService::LegacyHopperService()
{
	setName(sLegacyHopperService);
}

// FUNCTION: WEBSERVICE 0x100c9760
// FUNCTION: ROBLOX 0x005e3810
void BackpackItem::setTextureId(const TextureId& value)
{
	if (value != textureId) {
		textureId = value;

		std::string filename;
		ContentProvider::singleton().requestContentFile(value, filename);

		if (Workspace* workspace = ServiceProvider::find<Workspace>(this)) {
			workspace->raiseDrawChanged();
		}

		raisePropertyChanged(desc_TextureId);
	}
}

// FUNCTION: WEBSERVICE 0x100c9850
// FUNCTION: ROBLOX 0x005e3900
void HopperBin::onSelectScript()
{
	if (Workspace* workspace = ServiceProvider::find<Workspace>(this)) {
		ScriptMouseCommand* command = new ScriptMouseCommand(workspace);
		workspace->setMouseCommand(command);
		desc_Selected.fire(this, command->getMouse());
	}
}

// FUNCTION: WEBSERVICE 0x100c9950
// FUNCTION: ROBLOX 0x005e3a00
void HopperBin::onLocalClicked()
{
	if (!active) {
		active = true;
		if (binType == SCRIPT_BIN) {
			onSelectScript();
		}
		else {
			onSelectCommand();
		}
	}
	else {
		onLocalOtherClicked();
	}
}

// FUNCTION: WEBSERVICE 0x100c9980
// FUNCTION: ROBLOX 0x005e3a30
void HopperBin::onLocalOtherClicked()
{
	if (active) {
		if (binType == SCRIPT_BIN) {
			desc_Deselected.fire(this);
		}

		active = false;
		if (Workspace* workspace = ServiceProvider::find<Workspace>(this)) {
			workspace->setDefaultMouseCommand();
		}
	}
}

// FUNCTION: WEBSERVICE 0x100c99e0
// FUNCTION: ROBLOX 0x005e3a90
void HopperBin::setLegacyTextureName(const std::string& value)
{
	TextureId textureId = ContentId::fromAssets("Textures\\" + value + ".png");
	setTextureId(textureId);
}

// FUNCTION: WEBSERVICE 0x100c9bd0
// FUNCTION: ROBLOX 0x005e3c80
HopperBin::HopperBin() : binType(SCRIPT_BIN), active(false)
{
	setName("HopperBin");
}

// FUNCTION: WEBSERVICE 0x100c9cd0
// FUNCTION: ROBLOX 0x005e3da0
void HopperBin::setBinType(const BinType value)
{
	if (value != binType) {
		binType = value;
		raisePropertyChanged(desc_BinType);

		if (binType != SCRIPT_BIN) {
			std::string textureName = Reflection::EnumDesc<BinType>::singleton().convertToString(binType);
			setLegacyTextureName(textureName);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100c9d60
void HopperBin::setLegacyCommand(const std::string& text)
{
	BinType newBinType;
	if (!Reflection::EnumDesc<BinType>::singleton().convertToValue(text, newBinType)) {
		newBinType = SCRIPT_BIN;
	}

	setBinType(newBinType);
}

// FUNCTION: WEBSERVICE 0x100d5be0 FOLDED
// FUNCTION: ROBLOX 0x0060cb80 FOLDED
G3D::Vector2 BackpackItem::getSize() const
{
	float size = GuiRoot::toPixelSize(G3D::Vector2(10, 10)).x;
	return G3D::Vector2(size, size);
}

// FUNCTION: WEBSERVICE 0x100e44b0 FOLDED
// FUNCTION: ROBLOX 0x00633110 FOLDED
bool Hopper::askSetParent(const Instance* instance) const
{
	return true;
}

const char sLegacyHopperService[] = "Hopper";

const char sStarterPackService[] = "StarterPack";

const char sHopperBin[] = "HopperBin";

const char sBackpackItem[] = "BackpackItem";

} // namespace RBX

template class RBX::FactoryProduct<RBX::StarterPackService, RBX::Hopper, RBX::sStarterPackService>;
template class RBX::Reflection::Described<
	RBX::StarterPackService,
	RBX::sStarterPackService,
	RBX::FactoryProduct<RBX::StarterPackService, RBX::Hopper, RBX::sStarterPackService> >;
template class RBX::DescribedCreatable<RBX::StarterPackService, RBX::Hopper, RBX::sStarterPackService>;

template class RBX::FactoryProduct<RBX::LegacyHopperService, RBX::Hopper, RBX::sLegacyHopperService>;
template class RBX::Reflection::Described<
	RBX::LegacyHopperService,
	RBX::sLegacyHopperService,
	RBX::FactoryProduct<RBX::LegacyHopperService, RBX::Hopper, RBX::sLegacyHopperService> >;
template class RBX::DescribedCreatable<RBX::LegacyHopperService, RBX::Hopper, RBX::sLegacyHopperService>;

template class RBX::FactoryProduct<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin>;
template class RBX::Reflection::Described<
	RBX::HopperBin,
	RBX::sHopperBin,
	RBX::FactoryProduct<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin> >;
template class RBX::DescribedCreatable<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin>;

template class RBX::NonFactoryProduct<RBX::Widget, RBX::sBackpackItem>;
template class RBX::Reflection::
	Described<RBX::BackpackItem, RBX::sBackpackItem, RBX::NonFactoryProduct<RBX::Widget, RBX::sBackpackItem> >;
template class RBX::DescribedNonCreatable<RBX::BackpackItem, RBX::Widget, RBX::sBackpackItem>;

template const RBX::Name& RBX::Name::doDeclare<RBX::sBackpackItem>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();
