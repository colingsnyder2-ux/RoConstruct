#pragma once
// >>> native-status (generated) -- do not edit >>>
// LocalBackpack2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src ebff9c2f | roc native-status --write
// 2008-06 native RBX::LocalBackpack / RBX::LocalBackpackItem (inactive): the original LocalBackpack unit
// 005fb710..005fd330 (bounded by Kernel 005fb650 and Tool 005fd3a0). Shape after the donor tools/rbxgs
// v8datamodel/LocalBackpack.h; this header has its own path (no donor header lives at LocalBackpack2008/) so it shadows
// nothing. Changes against the donor / v8datamodel/LocalBackpack.h, all read from the 2008-06 binary
// (tests/record_native_local_backpack.py checks them):
//   * class-name template arguments are const char arrays (RTTI $1?sLocalBackpack@2@3QBDB / $1?sLocalBackpackItem@...);
//   * the descendant events are DescendantAdded / DescendantRemoving (RTTI .?AV?$Listener@VInstance@RBX@@UDescendant
//     Added@2@@RBX@@), not the donor's Descendent spelling;
//   * members without 2008 evidence (getBinId, cycleUp, cycleDown) are left out.
// LocalBackpackItem  vtable 0084164c .?AVLocalBackpackItem@RBX@@ -> DescribedCreatable<LocalBackpackItem, Widget,
//              sLocalBackpackItem> (vtables 00841454..) -> FactoryProduct (00841124..) -> Widget; GuiTarget +0x130.
//              Size 0x188 (Creatable<Instance>::create<LocalBackpackItem> 005780e0 mallocs 0x188, then 005fccd0).
//              Constructor 005fccd0: myItem +0x148 = {0, 0}, guiImageDraw +0x150 (GuiDrawImage() 005cf870, 0x38
//              bytes). Destructor 005fce00: ~GuiDrawImage 005cf360, myItem released, ~FactoryProduct 005fb710.
//              Slots: getSize 23 (005cf190, the ICF-shared BackpackItem::getSize body), render2d 24 (005fb900),
//              onClick 25 (005fc090: parent LocalBackpack::onClick(this)).
// LocalBackpack  vtable 00841364 .?AVLocalBackpack@RBX@@ -> DescribedCreatable<LocalBackpack, RelativePanel,
//              sLocalBackpack> (0084155c..) -> FactoryProduct (0084122c..) -> RelativePanel; GuiTarget +0x130;
//              Listener<Instance, ChildAdded> +0x168, <Instance, ChildRemoved> +0x16c, <Instance, DescendantAdded>
//              +0x170, <Instance, DescendantRemoving> +0x174, <Player, CharacterAdded> +0x178, <Player,
//              CharacterRemoving> +0x17c, empty Service +0x180 (RTTI mdisp; declared second). Size 0x1ac
//              (ServiceProvider factory 005771b0 mallocs 0x1ac, then 005fceb0). Constructor 005fceb0: players +0x180,
//              localPlayer +0x188, localBackpack +0x190, localCharacter +0x198, pendingClick +0x1a0 (shared_ptrs
//              zeroed), lastRemovedIndex +0x1a8 = -1, then yLocation (+0x160) = Rect::BOTTOM (1). Destructor 005fc450:
//              clearAll 005fc3b0, then the five shared_ptrs in reverse order, ~FactoryProduct 005fb7b0.
//              onServiceProvider is slot 12 (005fcfb0), write slot 14 (00416690, ICF `return NULL`).
#include "v8datamodel/Hopper.h"
#include "Network/Player.h"
#include "v8tree/InstanceEvents.h"

struct NativeLocalBackpackLayout;

namespace RBX
{
	class Backpack;
	namespace Network { class Players; }

	// By-value event payloads of the onEvent slots (only declared in the native v8tree/Instance.h): the ChildRemoved
	// listener 005fc230 returns `ret 0xc` (source + one shared_ptr<Instance>), the DescendantRemoving listener
	// 005fbd10 `ret 0x14` (source + two shared_ptrs) and destroys the payload with the two-shared_ptr destructor
	// 00422c60 (the same one the DescendantAdded listener 005fd330 uses). Same definitions as CRobloxReportView.h /
	// CInstanceExplorer.h; proposal: move both next to ChildAdded / DescendantAdded in v8tree/InstanceEvents.h.
	struct ChildRemoved
	{
		boost::shared_ptr<Instance> child;
	};
	struct DescendantRemoving
	{
		const boost::shared_ptr<Instance> instance;
		const boost::shared_ptr<Instance> parent;
	};

	extern const char sLocalBackpackItem[];
	class LocalBackpackItem : public DescribedCreatable<LocalBackpackItem, Widget, sLocalBackpackItem>
	{
		friend struct ::NativeLocalBackpackLayout;

	private:
		boost::shared_ptr<BackpackItem> myItem;                      // +0x148
		GuiDrawImage guiImageDraw;                                   // +0x150

	private:
		virtual bool askSetParent(const Instance* instance) const    // 00565ff0 (shared `return true`)
		{
			return true;
		}

		virtual G3D::Vector2 getSize() const;                        // slot 23, 005cf190 (ICF with BackpackItem's)
		virtual void render2d(Adorn* adorn);                         // slot 24, 005fb900
		virtual void onClick(const GuiEvent& event);                 // slot 25, 005fc090
	public:
		LocalBackpackItem();                                         // 005fccd0

		__declspec(noinline) void setItem(BackpackItem* item);       // 005fbf50 (called out of line by 005fd0b0)
		BackpackItem* getItem()
		{
			return myItem.get();
		}
	};

	extern const char sLocalBackpack[];
	class LocalBackpack : public DescribedCreatable<LocalBackpack, RelativePanel, sLocalBackpack>,
						  public Service,
						  public Listener<Instance, ChildAdded>,
						  public Listener<Instance, ChildRemoved>,
						  public Listener<Instance, DescendantAdded>,
						  public Listener<Instance, DescendantRemoving>,
						  public Listener<Network::Player, Network::CharacterAdded>,
						  public Listener<Network::Player, Network::CharacterRemoving>
	{
		friend struct ::NativeLocalBackpackLayout;

	private:
		boost::shared_ptr<Network::Players> players;                 // +0x180
		boost::shared_ptr<Network::Player> localPlayer;              // +0x188
		boost::shared_ptr<Backpack> localBackpack;                   // +0x190
		boost::shared_ptr<Instance> localCharacter;                  // +0x198
		boost::shared_ptr<BackpackItem> pendingClick;                // +0x1a0
		int lastRemovedIndex;                                        // +0x1a8

	private:
		virtual bool askSetParent(const Instance* instance) const    // 00565ff0
		{
			return true;
		}
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 005fcfb0
		virtual void onEvent(const Network::Player* source, Network::CharacterRemoving event);   // 005fc330 (+0x17c)
		virtual void onEvent(const Network::Player* source, Network::CharacterAdded event);      // 005fca40 (+0x178)
		virtual void onEvent(const Instance* source, DescendantRemoving event);                  // 005fbd10 (+0x174)
		virtual void onEvent(const Instance* source, DescendantAdded event);                     // 005fd330 (+0x170)
		virtual void onEvent(const Instance* source, ChildRemoved event);                        // 005fc230 (+0x16c)
		virtual void onEvent(const Instance* source, ChildAdded event);                          // 005fd220 (+0x168)
		void onLocalCharacterAdded(Instance* added);                 // 005fc730
		void onLocalPlayerAdded(Network::Player* added);             // 005fc810
		void onLocalBackpackAdded(Backpack* added);                  // 005fc940
		void clearAll();                                             // 005fc3b0
		void clearLocalCharacter();                                  // 005fc100
		void clearLocalPlayer();                                     // 005fc150
		void clearLocalBackpack();                                   // 005fc1d0
		void insertBackpackItem(BackpackItem* item);                 // 005fd0b0
		void removeBackpackItem(BackpackItem* item);                 // 005fbc80
	public:
		LocalBackpack();                                             // 005fceb0
		virtual ~LocalBackpack();                                    // 005fc450
		void onHeartbeat();                                          // 005fbd80 (called by DataModel 00578e50)
		void onClick(LocalBackpackItem* clickedItem);                // 005fbff0
		bool onKey(int key);                                         // 005fc0a0 (DataModel key handler 00575890)

		virtual XmlElement* write()                                  // slot 14, 00416690
		{
			return NULL;
		}
	};
}
