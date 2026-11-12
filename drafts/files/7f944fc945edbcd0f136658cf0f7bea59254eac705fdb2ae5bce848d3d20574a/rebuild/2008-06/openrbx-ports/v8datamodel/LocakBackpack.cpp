// PORT: 2008 MSVC build uses original API; no modern-compiler compatibility prelude.
#include "network/Player.h"
#include "network/Players.h"
#include "util/Events.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/LocalBackpack.h"

#include <algorithm>

namespace RBX {

const char sLocalBackpack[] = "LocalBackpack";

const char sLocalBackpackItem[] = "LocalBackpackItem";

// FUNCTION: WEBSERVICE 0x100d5be0 FOLDED
// FUNCTION: ROBLOX 0x0060cb80 FOLDED
G3D::Vector2 LocalBackpackItem::getSize() const
{
	float size = GuiRoot::toPixelSize(G3D::Vector2(10, 10)).x;
	return G3D::Vector2(size, size);
}

// FUNCTION: WEBSERVICE 0x100d5d80
// FUNCTION: ROBLOX 0x0060cd60
void LocalBackpackItem::render2d(Adorn* adorn)
{
	int fontSize = GuiRoot::normalizedFontSize(12);

	Rect draw = getMyRect();
	float numberSize = draw.size().x * 0.2f;
	Rect numberRect = Rect::fromLowSize(
		G3D::Vector2(draw.low.x + 2, draw.high.y - 2 - numberSize), G3D::Vector2(numberSize, numberSize)
	);

	adorn->rect2d(draw.toRect2D(), GuiItem::translucentBackdrop());

	adorn->rect2d(numberRect.toRect2D(), G3D::Color4(G3D::Color3::gray(), 1));

	adorn->drawFont2D(
		StringConverter<int>::convertToString(getBinId()),
		numberRect.center(),
		fontSize,
		G3D::Color3::white(),
		G3D::Color4::clear(),
		Adorn::XALIGN_CENTER,
		Adorn::YALIGN_CENTER,
		Adorn::PROPORTIONAL_SPACING
	);

	if (myItem) {
		if (myItem->drawSelected()) {
			adorn->outlineRect2d(draw.toRect2D(), 3.0f, G3D::Color4(G3D::Color3::green(), 1));
		}

		if (guiImageDraw.setImage(adorn, myItem->getTextureId())) {
#ifdef COMPAT_MODE
			Rect imageRect = draw.inset(fontSize);
			guiImageDraw.render2d(adorn, myItem->drawEnabled(), imageRect, widgetState);
#else
			guiImageDraw.render2d(adorn, myItem->drawEnabled(), draw.inset(fontSize), widgetState);
#endif
			return;
		}

		setName(myItem->getName());
	}

	Widget::render2d(adorn);
}

// FUNCTION: WEBSERVICE 0x100d6100
// FUNCTION: ROBLOX 0x0060d0e0
void LocalBackpack::removeBackpackItem(BackpackItem* item)
{
	for (unsigned int i = 0; i < numChildren(); ++i) {
		LocalBackpackItem* localItem = static_cast<LocalBackpackItem*>(getChild(i));
		if (localItem->getItem() == item) {
			lastRemovedIndex = i;
			localItem->setParent(NULL);
			if (item == pendingClick.get()) {
				pendingClick.reset();
			}
			return;
		}
	}

	debugAssert(false);
}

// FUNCTION: WEBSERVICE 0x100d61c0
// FUNCTION: ROBLOX 0x0060d1a0
void LocalBackpack::onHeartbeat()
{
	if (pendingClick.get()) {
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = getChildren().read();
		if (c) {
			for (std::vector<boost::shared_ptr<Instance> >::const_iterator iter = c->begin(); iter != c->end();
				 ++iter) {
				LocalBackpackItem* item = static_cast<LocalBackpackItem*>(iter->get());
				if (item->getItem() != pendingClick.get()) {
					item->getItem()->onLocalOtherClicked();
				}
			}
		}

		pendingClick->onLocalClicked();
		pendingClick.reset();
	}
}

// FUNCTION: WEBSERVICE 0x100d6300
// FUNCTION: ROBLOX 0x0060d2e0
void LocalBackpack::onEvent(const Instance* source, DescendentRemoving event)
{
	if (BackpackItem* item = dynamic_cast<BackpackItem*>(event.instance.get())) {
		removeBackpackItem(item);
	}
}

// FUNCTION: WEBSERVICE 0x100d6450
// FUNCTION: ROBLOX 0x0060d510
void LocalBackpack::onClick(LocalBackpackItem* clickedItem)
{
	pendingClick = shared_from(clickedItem->getItem());
}

// FUNCTION: WEBSERVICE 0x100d6520
// FUNCTION: ROBLOX 0x0060d5b0
void LocalBackpackItem::onClick(const GuiEvent& event)
{
	static_cast<LocalBackpack*>(getParent())->onClick(this);
}

// FUNCTION: WEBSERVICE 0x100d6530
// FUNCTION: ROBLOX 0x0060d5c0
void LocalBackpack::clearLocalCharacter()
{
	if (localCharacter) {
		stopListening(localCharacter, static_cast<Listener<Instance, DescendentAdded>*>(this));
		stopListening(localCharacter, static_cast<Listener<Instance, DescendentRemoving>*>(this));
		localCharacter.reset();
	}
}

// FUNCTION: WEBSERVICE 0x100d65c0
// FUNCTION: ROBLOX 0x0060d650
void LocalBackpack::clearLocalPlayer()
{
	removeAllChildren();

	if (localPlayer) {
		stopListening(localPlayer, static_cast<Listener<Instance, ChildAdded>*>(this));
		stopListening(localPlayer, static_cast<Listener<Instance, ChildRemoved>*>(this));
		stopListening(localPlayer, static_cast<Listener<Network::Player, Network::CharacterAdded>*>(this));
		stopListening(localPlayer, static_cast<Listener<Network::Player, Network::CharacterRemoving>*>(this));
		localPlayer.reset();
	}
}

// FUNCTION: WEBSERVICE 0x100d6690
// FUNCTION: ROBLOX 0x0060d720
void LocalBackpack::clearLocalBackpack()
{
	removeAllChildren();

	if (localBackpack) {
		stopListening(localBackpack, static_cast<Listener<Instance, ChildAdded>*>(this));
		stopListening(localBackpack, static_cast<Listener<Instance, ChildRemoved>*>(this));
		localBackpack.reset();
	}

	lastRemovedIndex = -1;
}

// FUNCTION: ROBLOX 0x0060d7d0
bool LocalBackpack::FUN_0060d7d0(unsigned int index)
{
	if (index <= numChildren()) {
		onClick(static_cast<LocalBackpackItem*>(getChild(index - 1)));
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100d6740
// FUNCTION: ROBLOX 0x0060d840
void LocalBackpack::onEvent(const Instance* source, ChildRemoved event)
{
	if (Network::Player* player = dynamic_cast<Network::Player*>(event.child.get())) {
		if (player == localPlayer.get()) {
			clearLocalPlayer();
		}
	}
	else if (dynamic_cast<Backpack*>(event.child.get())) {
		clearLocalBackpack();
	}
	else if (BackpackItem* item = dynamic_cast<BackpackItem*>(event.child.get())) {
		removeBackpackItem(item);
	}
}

// FUNCTION: WEBSERVICE 0x100d6830
// FUNCTION: ROBLOX 0x0060d930
void LocalBackpack::onEvent(const Network::Player* source, Network::CharacterRemoving event)
{
	if (localCharacter) {
		clearLocalCharacter();
	}
}

// FUNCTION: WEBSERVICE 0x100d68b0
// FUNCTION: ROBLOX 0x0060d9b0
void LocalBackpack::clearAll()
{
	clearLocalCharacter();
	clearLocalPlayer();
	clearLocalBackpack();
	if (players) {
		stopListening(players.get(), static_cast<Listener<Instance, ChildAdded>*>(this));
		stopListening(players, static_cast<Listener<Instance, ChildRemoved>*>(this));
		players.reset();
	}
}

// FUNCTION: WEBSERVICE 0x100d6950
// FUNCTION: ROBLOX 0x0060dac0
LocalBackpack::~LocalBackpack()
{
	clearAll();
}

// FUNCTION: WEBSERVICE 0x100d6ce0
// FUNCTION: ROBLOX 0x0060ddc0
void LocalBackpack::onLocalCharacterAdded(Instance* added)
{
	localCharacter = shared_from(added);

	startListening(localCharacter, static_cast<Listener<Instance, DescendentAdded>*>(this));
	startListening(localCharacter, static_cast<Listener<Instance, DescendentRemoving>*>(this));
}

// FUNCTION: WEBSERVICE 0x100d6dc0
// FUNCTION: ROBLOX 0x0060dea0
void LocalBackpack::onLocalPlayerAdded(Network::Player* added)
{
	localPlayer = shared_from(added);

	startListening(localPlayer, static_cast<Listener<Instance, ChildAdded>*>(this));
	startListening(localPlayer, static_cast<Listener<Instance, ChildRemoved>*>(this));
	startListening(localPlayer, static_cast<Listener<Network::Player, Network::CharacterAdded>*>(this));
	startListening(localPlayer, static_cast<Listener<Network::Player, Network::CharacterRemoving>*>(this));
}

// FUNCTION: WEBSERVICE 0x100d6ef0
// FUNCTION: ROBLOX 0x0060dfd0
void LocalBackpack::onLocalBackpackAdded(Backpack* added)
{
	localBackpack = shared_from(added);

	startListening(localBackpack, static_cast<Listener<Instance, ChildAdded>*>(this));
	startListening(localBackpack, static_cast<Listener<Instance, ChildRemoved>*>(this));
}

// FUNCTION: WEBSERVICE 0x100d6fd0
// FUNCTION: ROBLOX 0x0060e0b0
void LocalBackpack::onEvent(const Network::Player* source, Network::CharacterAdded event)
{
	onLocalCharacterAdded(event.character.get());
}

// FUNCTION: WEBSERVICE 0x100d72e0
// FUNCTION: ROBLOX 0x0060e380
LocalBackpackItem::LocalBackpackItem()
{
}

// FUNCTION: WEBSERVICE 0x100d74c0
// FUNCTION: ROBLOX 0x0060e560
LocalBackpack::LocalBackpack() : lastRemovedIndex(-1)
{
	yLocation = Rect::BOTTOM;
}

// FUNCTION: WEBSERVICE 0x100d75b0
// FUNCTION: ROBLOX 0x0060e650
void LocalBackpack::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	if (oldProvider) {
		clearAll();
	}

	Instance::onServiceProvider(oldProvider, newProvider);

	if (newProvider) {
		players = shared_from(ServiceProvider::create<Network::Players>(this));
		startListening(players, static_cast<Listener<Instance, ChildAdded>*>(this));
		startListening(players, static_cast<Listener<Instance, ChildRemoved>*>(this));
	}
}

// FUNCTION: WEBSERVICE 0x100d76c0
// FUNCTION: ROBLOX 0x0060e760
void LocalBackpack::insertBackpackItem(BackpackItem* item)
{
	boost::shared_ptr<LocalBackpackItem> localItem = Creatable<Instance>::create<LocalBackpackItem>();

	localItem->setParent(this);

	int maxId = numChildren() - 1;

	int insertIndex = lastRemovedIndex >= 0 ? std::min(lastRemovedIndex, maxId) : maxId;

	for (int i = maxId; i > insertIndex; --i) {
		LocalBackpackItem* prev = static_cast<LocalBackpackItem*>(getChild(i - 1));
		LocalBackpackItem* next = static_cast<LocalBackpackItem*>(getChild(i));
		next->setItem(prev->getItem());
	}

	static_cast<LocalBackpackItem*>(getChild(insertIndex))->setItem(item);

	lastRemovedIndex = -1;
}

// FUNCTION: WEBSERVICE 0x100d7850
// FUNCTION: ROBLOX 0x0060e8f0
void LocalBackpack::onEvent(const Instance* source, ChildAdded event)
{
	if (Network::Player* player = dynamic_cast<Network::Player*>(event.child.get())) {
		if (player == Network::Players::findLocalPlayer(this)) {
			onLocalPlayerAdded(player);
		}
	}
	else if (Backpack* backpack = dynamic_cast<Backpack*>(event.child.get())) {
		onLocalBackpackAdded(backpack);
	}
	else if (BackpackItem* item = dynamic_cast<BackpackItem*>(event.child.get())) {
		insertBackpackItem(item);
	}
}

// FUNCTION: WEBSERVICE 0x100d7950
// FUNCTION: ROBLOX 0x0060e9f0
void LocalBackpack::onEvent(const Instance* source, DescendentAdded event)
{
	if (BackpackItem* item = dynamic_cast<BackpackItem*>(event.instance.get())) {
		insertBackpackItem(item);
	}
}

} // namespace RBX

template boost::shared_ptr<RBX::Network::Player> RBX::shared_from(RBX::Network::Player* r);
template void RBX::Notifier<RBX::Network::Player, RBX::Network::CharacterAdded>::addListener(
	RBX::Listener<RBX::Network::Player, RBX::Network::CharacterAdded>* listener
) const;
template void RBX::Notifier<RBX::Network::Player, RBX::Network::CharacterAdded>::removeListener(
	RBX::Listener<RBX::Network::Player, RBX::Network::CharacterAdded>* listener
) const;
template void RBX::Notifier<RBX::Network::Player, RBX::Network::CharacterRemoving>::addListener(
	RBX::Listener<RBX::Network::Player, RBX::Network::CharacterRemoving>* listener
) const;
template void RBX::Notifier<RBX::Network::Player, RBX::Network::CharacterRemoving>::removeListener(
	RBX::Listener<RBX::Network::Player, RBX::Network::CharacterRemoving>* listener
) const;
