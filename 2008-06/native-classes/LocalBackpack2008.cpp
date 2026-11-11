// 2008-06 native RBX::LocalBackpack / RBX::LocalBackpackItem (inactive): the original LocalBackpack unit
// 005fb710..005fd330. Evidence in native-headers/LocalBackpack2008/LocalBackpack2008.h; verified by
// tests/record_native_local_backpack.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "LocalBackpack2008/LocalBackpack2008.h"
#include "v8datamodel/Backpack.h"
#include "Network/Players.h"
#include "util/Utilities.h"

namespace RBX
{
	const char sLocalBackpackItem[] = "LocalBackpackItem";
	const char sLocalBackpack[] = "LocalBackpack";

	// Template members the shared headers only declare (same definitions as Hopper.cpp / Team.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	// ServiceProvider::create<Network::Players>(const Instance*) 005fcc80 (same definition as SoundServiceProvider.cpp).
	template<class Class> Class* ServiceProvider::create(const Instance* context)
	{
		while (context)
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(context))
				return provider->create<Class>();
			context = context->getParent();
		}
		return NULL;
	}

	// ---- LocalBackpackItem ---------------------------------------------------------------------------------------
	LocalBackpackItem::LocalBackpackItem()
	{
	}

	G3D::Vector2 LocalBackpackItem::getSize() const
	{
		float width = GuiRoot::toPixelSize(G3D::Vector2(10.0f, 10.0f)).x;
		return G3D::Vector2(width, width);
	}

#ifdef NATIVE_LOCAL_BACKPACK_PENDING
	// 005fb900 needs Instance::findChildIndex(const Instance*) const (00558ac0, called on the parent +0x104), which the
	// native v8tree/Instance.h does not declare: pending build only (proposal in tests/record_native_local_backpack.py).
	void LocalBackpackItem::render2d(Adorn* adorn)
	{
		int fontSize = GuiRoot::normalizedFontSize(12);
		Rect rect = getMyRect();
		float side = rect.size().x * 0.2f;
		Rect numberRect = Rect::fromLowSize(G3D::Vector2(rect.low.x + 2.0f, rect.high.y - 2.0f - side), G3D::Vector2(side, side));
		adorn->rect2d(rect.toRect2D(), translucentBackdrop());
		adorn->rect2d(numberRect.toRect2D(), G3D::Color3::gray());
		{
			G3D::Color4 fontColor(G3D::Color3::white());
			int number = getParent()->findChildIndex(this) + 1;
			adorn->drawFont2D(StringConverter<int>::convertToString(number), numberRect.center(), fontSize, fontColor,
							  G3D::Color4::clear(), Adorn::XALIGN_CENTER, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
		}
		if (myItem.get())
		{
			if (myItem->drawSelected())
				adorn->outlineRect2d(rect.toRect2D(), 3.0f, G3D::Color3::green());
			if (guiImageDraw.setImage(adorn, myItem->getTextureId()))
			{
				Rect imageRect(rect);
				imageRect.low.x = rect.low.x + fontSize;
				imageRect.low.y = rect.low.y + fontSize;
				imageRect.high.x = rect.high.x - fontSize;
				imageRect.high.y = rect.high.y - fontSize;
				guiImageDraw.render2d(adorn, myItem->drawEnabled(), imageRect, widgetState);
			}
			else
			{
				setName(myItem->getName());
				Widget::render2d(adorn);
			}
		}
		else
		{
			Widget::render2d(adorn);
		}
	}
#endif

	void LocalBackpackItem::onClick(const GuiEvent& event)
	{
		static_cast<LocalBackpack*>(getParent())->onClick(this);
	}

	void LocalBackpackItem::setItem(BackpackItem* item)
	{
		myItem = shared_from(item);
	}

	// ---- LocalBackpack -------------------------------------------------------------------------------------------
	LocalBackpack::LocalBackpack()
		: lastRemovedIndex(-1)
	{
		yLocation = Rect::BOTTOM;
	}

	LocalBackpack::~LocalBackpack()
	{
		clearAll();
	}

	void LocalBackpack::onClick(LocalBackpackItem* clickedItem)
	{
		pendingClick = shared_from(clickedItem->getItem());
	}

	bool LocalBackpack::onKey(int key)
	{
		if (key <= numChildren())
		{
			onClick(static_cast<LocalBackpackItem*>(getChild(key - 1)));
			return true;
		}
		return false;
	}

	void LocalBackpack::onHeartbeat()
	{
		if (pendingClick.get())
		{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = children.read();
			if (c)
			{
				for (std::vector<boost::shared_ptr<Instance> >::const_iterator iter = c->begin(); iter != c->end(); ++iter)
				{
					LocalBackpackItem* item = static_cast<LocalBackpackItem*>(iter->get());
					if (item->getItem() != pendingClick.get())
						item->getItem()->onLocalOtherClicked();
				}
			}
			pendingClick->onLocalClicked();
			pendingClick.reset();
		}
	}

	void LocalBackpack::clearLocalCharacter()
	{
		if (localCharacter)
		{
			Notifier<Instance, DescendantAdded>::disconnect(localCharacter, this);
			Notifier<Instance, DescendantRemoving>::disconnect(localCharacter, this);
			localCharacter.reset();
		}
	}

	void LocalBackpack::clearLocalPlayer()
	{
		removeAllChildren();
		if (localPlayer)
		{
			Notifier<Instance, ChildAdded>::disconnect(localPlayer, this);
			Notifier<Instance, ChildRemoved>::disconnect(localPlayer, this);
			Notifier<Network::Player, Network::CharacterAdded>::disconnect(localPlayer, this);
			Notifier<Network::Player, Network::CharacterRemoving>::disconnect(localPlayer, this);
			localPlayer.reset();
		}
	}

	void LocalBackpack::clearLocalBackpack()
	{
		removeAllChildren();
		if (localBackpack)
		{
			Notifier<Instance, ChildAdded>::disconnect(localBackpack, this);
			Notifier<Instance, ChildRemoved>::disconnect(localBackpack, this);
			localBackpack.reset();
		}
		lastRemovedIndex = -1;
	}

	void LocalBackpack::clearAll()
	{
		clearLocalCharacter();
		clearLocalPlayer();
		clearLocalBackpack();
		if (players)
		{
			players->Notifier<Instance, ChildAdded>::removeListener(this);
			Notifier<Instance, ChildRemoved>::disconnect(players, this);
			players.reset();
		}
	}

	void LocalBackpack::onLocalCharacterAdded(Instance* added)
	{
		localCharacter = shared_from(added);
		Notifier<Instance, DescendantAdded>::connect(localCharacter, this);
		Notifier<Instance, DescendantRemoving>::connect(localCharacter, this);
	}

	void LocalBackpack::onLocalPlayerAdded(Network::Player* added)
	{
		localPlayer = shared_from(added);
		Notifier<Instance, ChildAdded>::connect(localPlayer, this);
		Notifier<Instance, ChildRemoved>::connect(localPlayer, this);
		Notifier<Network::Player, Network::CharacterAdded>::connect(localPlayer, this);
		Notifier<Network::Player, Network::CharacterRemoving>::connect(localPlayer, this);
	}

	void LocalBackpack::onLocalBackpackAdded(Backpack* added)
	{
		localBackpack = shared_from(added);
		Notifier<Instance, ChildAdded>::connect(localBackpack, this);
		Notifier<Instance, ChildRemoved>::connect(localBackpack, this);
	}

	void LocalBackpack::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (oldProvider)
			clearAll();
		if (newProvider)
		{
			players = shared_from(ServiceProvider::create<Network::Players>(this));
			Notifier<Instance, ChildAdded>::connect(players, this);
			Notifier<Instance, ChildRemoved>::connect(players, this);
		}
	}

	void LocalBackpack::insertBackpackItem(BackpackItem* item)
	{
		boost::shared_ptr<LocalBackpackItem> localItem = Creatable<Instance>::create<LocalBackpackItem>();
		localItem->setParent(this);
		int last = (int)numChildren() - 1;
		int insertAt = lastRemovedIndex >= 0 ? std::min(lastRemovedIndex, last) : last;
		for (int i = last; i > insertAt; --i)
		{
			LocalBackpackItem* previous = static_cast<LocalBackpackItem*>(getChild(i - 1));
			LocalBackpackItem* current = static_cast<LocalBackpackItem*>(getChild(i));
			current->setItem(previous->getItem());
		}
		static_cast<LocalBackpackItem*>(getChild(insertAt))->setItem(item);
		lastRemovedIndex = -1;
	}

	void LocalBackpack::removeBackpackItem(BackpackItem* item)
	{
		for (int i = 0; i < numChildren(); ++i)
		{
			Instance* child = getChild(i);
			if (static_cast<LocalBackpackItem*>(child)->getItem() == item)
			{
				lastRemovedIndex = i;
				child->setParent(NULL);
				if (item == pendingClick.get())
					pendingClick.reset();
				break;
			}
		}
	}

	void LocalBackpack::onEvent(const Instance* source, ChildAdded event)
	{
		if (Network::Player* player = dynamic_cast<Network::Player*>(event.child.get()))
		{
			if (player == Network::Players::findLocalPlayer(this))
				onLocalPlayerAdded(player);
		}
		else if (Backpack* backpack = dynamic_cast<Backpack*>(event.child.get()))
		{
			onLocalBackpackAdded(backpack);
		}
		else if (BackpackItem* item = dynamic_cast<BackpackItem*>(event.child.get()))
		{
			insertBackpackItem(item);
		}
	}

	void LocalBackpack::onEvent(const Instance* source, ChildRemoved event)
	{
		if (Network::Player* player = dynamic_cast<Network::Player*>(event.child.get()))
		{
			if (player == localPlayer.get())
				clearLocalPlayer();
		}
		else if (dynamic_cast<Backpack*>(event.child.get()))
		{
			clearLocalBackpack();
		}
		else if (BackpackItem* item = dynamic_cast<BackpackItem*>(event.child.get()))
		{
			removeBackpackItem(item);
		}
	}

	void LocalBackpack::onEvent(const Instance* source, DescendantAdded event)
	{
		if (BackpackItem* item = dynamic_cast<BackpackItem*>(event.instance.get()))
			insertBackpackItem(item);
	}

	void LocalBackpack::onEvent(const Instance* source, DescendantRemoving event)
	{
		if (BackpackItem* item = dynamic_cast<BackpackItem*>(event.instance.get()))
			removeBackpackItem(item);
	}

	void LocalBackpack::onEvent(const Network::Player* source, Network::CharacterAdded event)
	{
		onLocalCharacterAdded(event.character.get());
	}

	void LocalBackpack::onEvent(const Network::Player* source, Network::CharacterRemoving event)
	{
		if (localCharacter)
			clearLocalCharacter();
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Listener<RBX::Instance,RBX::DescendantAdded>;
template class RBX::Listener<RBX::Instance,RBX::DescendantRemoving>;
template class RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded>;
template class RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving>;
template class boost::shared_ptr<RBX::LocalBackpackItem>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Instance,RBX::DescendantAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantAdded> *> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Instance,RBX::DescendantRemoving> *,std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantRemoving> *> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded> *,std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded> *> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving> *,std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Instance,RBX::DescendantAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantAdded> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Instance,RBX::DescendantRemoving> *,std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantRemoving> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded> *,std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving> *,std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving> *> >;
template class std::vector<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded> *,std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterAdded> *> >;
template class std::vector<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving> *,std::allocator<RBX::Listener<RBX::Network::Player,RBX::Network::CharacterRemoving> *> >;
