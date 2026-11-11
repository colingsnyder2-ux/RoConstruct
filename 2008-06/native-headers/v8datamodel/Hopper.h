#pragma once
// >>> native-status (generated) -- do not edit >>>
// Hopper | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b43abcdd | roc native-status --write
// 2008-06 native RBX::Hopper, StarterPackService, LegacyHopperService, BackpackItem and HopperBin (inactive). Shape
// after the donor tools/rbxgs v8datamodel/Hopper.h; the one change is the class-name template argument (a const char
// array, as the RTTI mangles it: $1?sX@2@3QBDB). Every base, field and size below is read from the 2008-06 binary
// (tests/record_native_hopper.py checks them):
//   Hopper     vtable 0083ac0c .?AVHopper@RBX@@ -> RelativePanel -> TopMenuBar -> GuiItem -> Instance (+ GuiTarget
//              +0x130). Constructor 005cf900: RelativePanel() 005cf770, the 11 Hopper vtables, yLocation (+0x160) =
//              Rect::BOTTOM (1). Non-virtual size 0x168 (StarterPackService / LegacyHopperService allocations).
//   StarterPackService   DescribedCreatable<StarterPackService, Hopper, sStarterPackService> + Service; size 0x168
//              (factory 0048ea00 allocates 0x168 and calls 005d0fc0). Class name "StarterPack" (0083a74c), also
//              passed to setName by the constructor 005d0fc0. render2d 005cfcd0 (not attempted here).
//   LegacyHopperService  DescribedCreatable<LegacyHopperService, Hopper, sLegacyHopperService> + Service; size 0x168
//              (factory 0048ec70 -> 005d10a0). Class name "Hopper" (0083a758), also the constructor's setName.
//              onServiceProvider 005d0910 (vtable slot 12) moves every child into the StarterPackService
//              (ServiceProvider::create<StarterPackService> 00490d70) and unparents itself; no base call in 2008.
//              ~LegacyHopperService 005cfb50 has an empty body (no assert in the 2008 build).
//   BackpackItem vtable 0083b2f4 .?AVBackpackItem@RBX@@ -> DescribedNonCreatable<BackpackItem, Widget,
//              sBackpackItem> -> NonFactoryProduct<Widget, sBackpackItem> -> Widget -> GuiItem. Implicit constructor
//              005d0c10 (out of line; called by the HopperBin and Tool FactoryProduct constructors 005d1170 /
//              005ff590): guiImageDraw +0x148 (GuiDrawImage() 005cf870, 0x38 bytes), textureId +0x180 (std::string
//              + Name* +0x19c = Name::getNullName()); destructor 005cfe50 in reverse order. Size 0x1a0 (HopperBin
//              fields start there). Class name "BackpackItem" 0083a730.
//   HopperBin  DescribedCreatable<HopperBin, BackpackItem, sHopperBin>; size 0x1a8 (Creatable::create<HopperBin>
//              0048e790 allocates 0x1a8 and calls 005d15a0); constructor: binType +0x1a0 = 0, active +0x1a4 = false,
//              setName("HopperBin") (literal 0083b6f8; the class-name array is 0083a740).
//   descriptors (dynamic initializers 007f5df0..007f5ef0, "Data" category 00822490): desc_TextureId (PropDescriptor
//              <BackpackItem, TextureId> "TextureId", getter 005cf160, setter 005d11e0), desc_BinType ("BinType",
//              EnumPropDescriptor ctor 005d0d80), desc_Selected (SignalDesc "Selected"/"mouse", ctor 005d0b40),
//              desc_Deselected ("Deselected"), desc_legacyCommand ("Command") and desc_legacyTextureName
//              ("TextureName"), both set-only LEGACY PropDescriptor<HopperBin, std::string>.
#include "v8tree/Service.h"
#include "gui/Widget.h"
#include "gui/GuiDraw.h"

struct NativeHopperLayout;

namespace RBX
{
	class Hopper : public RelativePanel
	{
	protected:
		virtual bool askSetParent(const Instance* instance) const;   // 00565ff0 (shared `return true`)
		virtual bool askAddChild(const Instance* instance) const;    // 005cf1c0 (dynamic_cast to BackpackItem)
	public:
		Hopper();                                                    // 005cf900
	};

	extern const char sStarterPackService[];
	class StarterPackService : public DescribedCreatable<StarterPackService, Hopper, sStarterPackService>,
							   public Service
	{
	public:
		StarterPackService();                                        // 005d0fc0
		virtual void render2d(Adorn* adorn);                         // 005cfcd0 (not attempted)
	};

	extern const char sLegacyHopperService[];
	class LegacyHopperService : public DescribedCreatable<LegacyHopperService, Hopper, sLegacyHopperService>,
								public Service
	{
	private:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 005d0910
	public:
		LegacyHopperService();                                       // 005d10a0
		virtual ~LegacyHopperService();                              // 005cfb50
	};

	extern const char sBackpackItem[];
	class BackpackItem : public DescribedNonCreatable<BackpackItem, Widget, sBackpackItem>
	{
		friend struct ::NativeHopperLayout;

	private:
		GuiDrawImage guiImageDraw;                                   // +0x148
		TextureId textureId;                                         // +0x180

	private:
		bool inBackpack();
		virtual bool askSetParent(const Instance* instance) const;   // 00565ff0
		virtual bool askAddChild(const Instance* instance) const;    // 00565ff0
	protected:
		virtual G3D::Vector2 getSize() const;                        // 005cf190 (/fp:fast)
		virtual void render2d(Adorn*);                               // 005d05d0 (not attempted)
		virtual bool isEnabled();                                    // 005cff30 (dynamic_cast<Backpack*>(parent))
		int getBinId() const;
	public:
		void setTextureId(const TextureId& value);                   // 005d11e0
		const TextureId getTextureId() const;                        // 005cf160

		virtual bool drawEnabled() const
		{
			return true;
		}

		virtual bool drawSelected() const
		{
			return false;
		}

		virtual void onLocalClicked()
		{
			return;
		}

		virtual void onLocalOtherClicked()
		{
			return;
		}
	};

	extern const char sHopperBin[];
	class HopperBin : public DescribedCreatable<HopperBin, BackpackItem, sHopperBin>
	{
		friend struct ::NativeHopperLayout;

	public:
		enum BinType
		{
			SCRIPT_BIN,
			GAME_TOOL,
			GRAB_TOOL,
			CLONE_TOOL,
			HAMMER_TOOL,
			SLINGSHOT_TOOL,
			ROCKET_TOOL,
			LASER_TOOL
		};

	private:
		BinType binType;                                             // +0x1a0
		bool active;                                                 // +0x1a4

	private:
		void onSelectScript();
		void onSelectCommand();                                      // 005d0ec0
		int getCursor();
		virtual bool drawSelected() const                            // 005d1670
		{
			return active;
		}
	public:
		HopperBin();                                                 // 005d15a0
	public:
		BinType getBinType() const
		{
			return binType;
		}

		void setBinType(const BinType value);
		virtual void onLocalClicked();                               // 005d1340
		virtual void onLocalOtherClicked();                          // 005d1370
		void setLegacyCommand(const std::string& text);
		void setLegacyTextureName(const std::string& value);         // 005d13d0
	};
}
