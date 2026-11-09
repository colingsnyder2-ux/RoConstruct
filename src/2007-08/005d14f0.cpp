// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_native_app_workspace_850d63d4cd68b745.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#include "v8datamodel/LocalBackpack.h"

namespace RBX
{
	LocalBackpackItem::LocalBackpackItem() {}

	void LocalBackpackItem::onClick(const GuiEvent& event)
	{
		LocalBackpack* parent = rbx_static_cast<LocalBackpack*>(getParent());

		parent->onClick(this);
	}

	G3D::Vector2 LocalBackpackItem::getSize() const
	{
		float width = GuiRoot::toPixelSize(G3D::Vector2(10.0f, 10.0f)).x;
		return G3D::Vector2(width, width);
	}

	LocalBackpack::LocalBackpack()
		: lastRemovedIndex(-1)
	{
		yLocation = Rect::BOTTOM;
	}

	LocalBackpack::~LocalBackpack()
	{
		clearAll();
	}

	void LocalBackpack::onEvent(const Instance* source, ChildAdded event)
	{
		Instance* child = event.child.get();

		if (Network::Player* player = dynamic_cast<Network::Player*>(child))
		{
			if (player == Network::Players::findLocalPlayer(this))
			{
				onLocalPlayerAdded(player);
			}
		}
		else
		{
			if (Backpack* backpack = dynamic_cast<Backpack*>(child))
			{
				onLocalBackpackAdded(backpack);
			}
			else if (BackpackItem* backpackItem = dynamic_cast<BackpackItem*>(child))
			{
				insertBackpackItem(backpackItem);
			}
		}
	}

	void LocalBackpack::onEvent(const Instance* source, ChildRemoved event)
	{
		Instance* child = event.child.get();

		if (Network::Player* player = dynamic_cast<Network::Player*>(child))
		{
			if (player == localPlayer.get())
			{
				clearLocalPlayer();
			}
		}
		else
		{
			if (Backpack* backpack = dynamic_cast<Backpack*>(child))
			{
				RBXASSERT(localBackpack);
				clearLocalBackpack();
			}
			else if (BackpackItem* backpackItem = dynamic_cast<BackpackItem*>(child))
			{
				removeBackpackItem(backpackItem);
			}
		}
	}

	void LocalBackpack::onEvent(const Instance* source, DescendentAdded event)
	{
		RBXASSERT(source == localCharacter.get());

		BackpackItem* backpackItem = dynamic_cast<BackpackItem*>(event.instance.get());
		if (backpackItem)
			insertBackpackItem(backpackItem);
	}

	void LocalBackpack::onEvent(const Instance* source, DescendentRemoving event)
	{
		RBXASSERT(source == localCharacter.get());

		BackpackItem* backpackItem = dynamic_cast<BackpackItem*>(event.instance.get());
		if (backpackItem)
			removeBackpackItem(backpackItem);
	}

	void LocalBackpack::onEvent(const Network::Player* source, Network::CharacterRemoving event)
	{
		RBXASSERT(source == localPlayer.get());
		
		if (localCharacter)
		{
			RBXASSERT(event.character == localCharacter);
			clearLocalCharacter();
		}
	}

	void LocalBackpack::onEvent(const Network::Player* source, Network::CharacterAdded event)
	{
		RBXASSERT(source == localPlayer.get());
		onLocalCharacterAdded(event.character.get());
	}

	void LocalBackpack::onClick(LocalBackpackItem* clickedItem)
	{
		pendingClick = shared_from(clickedItem->getItem());
	}

	void LocalBackpack::onLocalCharacterAdded(Instance* added)
	{
		localCharacter = shared_from(added);

		Notifier<Instance, DescendentAdded>::connect(localCharacter, this);
		Notifier<Instance, DescendentRemoving>::connect(localCharacter, this);
	}

	void LocalBackpack::onLocalPlayerAdded(Network::Player* added)
	{
		RBXASSERT(numChildren() == 0);
		RBXASSERT(added);

		localPlayer = shared_from(added);

		Notifier<Instance, ChildAdded>::connect(localPlayer, this);
		Notifier<Instance, ChildRemoved>::connect(localPlayer, this);
		Notifier<Network::Player, Network::CharacterAdded>::connect(localPlayer, this);
		Notifier<Network::Player, Network::CharacterRemoving>::connect(localPlayer, this);
	}

	void LocalBackpack::onLocalBackpackAdded(Backpack* added)
	{
		RBXASSERT(numChildren() <= 1);
		RBXASSERT(added->getParent() == localPlayer.get());

		localBackpack = shared_from(added);

		Notifier<Instance, ChildAdded>::connect(localBackpack, this);
		Notifier<Instance, ChildRemoved>::connect(localBackpack, this);
	}

	void LocalBackpack::clearAll()
	{
		clearLocalCharacter();
		clearLocalPlayer();
		clearLocalBackpack();

		if (players)
		{
			Notifier<Instance, ChildAdded>::disconnect(players.get(), this);
			Notifier<Instance, ChildRemoved>::disconnect(players.get(), this);

			players.reset();
		}
	}

	void LocalBackpack::clearLocalCharacter()
	{
		if (localCharacter)
		{
			Notifier<Instance, DescendentAdded>::disconnect(localCharacter, this);
			Notifier<Instance, DescendentRemoving>::disconnect(localCharacter, this);

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

	void LocalBackpack::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (oldProvider)
			clearAll();

		Instance::onServiceProvider(oldProvider, newProvider);

		if (newProvider)
		{
			players = shared_from(ServiceProvider::create<Network::Players>(this));

			Notifier<Instance, ChildAdded>::connect(players, this);
			Notifier<Instance, ChildRemoved>::connect(players, this);
		}
	}

	void LocalBackpack::insertBackpackItem(BackpackItem* item)
	{
		RBXASSERT(localBackpack);

		boost::shared_ptr<LocalBackpackItem> localItem = Creatable::create<LocalBackpackItem>();
		localItem->setParent(this);

		int maxId = (int)numChildren() - 1;
		int minId = lastRemovedIndex >= 0 ? G3D::min(lastRemovedIndex, maxId) : maxId;

		for (int i = maxId; i > minId; i--)
		{
			LocalBackpackItem* aItem = rbx_static_cast<LocalBackpackItem*>(getChild(i - 1));
			LocalBackpackItem* bItem = rbx_static_cast<LocalBackpackItem*>(getChild(i));

			bItem->setItem(aItem->getItem());
		}

		LocalBackpackItem* freeItem = rbx_static_cast<LocalBackpackItem*>(getChild(minId));
		freeItem->setItem(item);
		lastRemovedIndex = -1;
	}

	void LocalBackpack::removeBackpackItem(BackpackItem* item)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			LocalBackpackItem* current = getTypedChild<LocalBackpackItem>((int)i);
			if (current->getItem() == item)
			{
				lastRemovedIndex = (int)i;
				current->setParent(NULL);

				if (item == pendingClick.get())
					pendingClick.reset();

				return;
			}
		}

		RBXASSERT(lastRemovedIndex == -1);
	}

	void LocalBackpack::onHeartbeat()
	{
		BackpackItem* prevPendingClick = pendingClick.get();
		if (prevPendingClick)
		{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> c = getChildren().read();
			if (c)
			{
				for (std::vector<boost::shared_ptr<Instance>>::const_iterator it = c->begin(); it != c->end(); it++)
				{
					LocalBackpackItem* current = rbx_static_cast<LocalBackpackItem*>(it->get());
					if (current->getItem() != pendingClick.get())
						current->getItem()->onLocalOtherClicked();
				}
			}

			RBXASSERT(prevPendingClick == pendingClick.get());
			pendingClick->onLocalClicked();
			pendingClick.reset();
		}
	}
}
