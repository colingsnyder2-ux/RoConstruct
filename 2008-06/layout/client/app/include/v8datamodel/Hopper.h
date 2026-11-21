#pragma once
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
