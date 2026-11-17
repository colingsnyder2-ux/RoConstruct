#include "v8datamodel/Hopper.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/Mouse.h"
#ifdef NATIVE_HOPPERBINSELECT_PENDING
#include "v8datamodel/DataModel.h"
#include "v8tree/Verb.h"
#endif

namespace RBX
{
	extern Reflection::SignalDesc<HopperBin, void(boost::shared_ptr<Instance>)> desc_Selected;
	extern Reflection::PropDescriptor<BackpackItem, TextureId> desc_TextureId;

	void StarterPackService::render2d(Adorn* adorn)
	{
		TopMenuBar::render2d(adorn);

		if (findFirstChildOfType<BackpackItem>())
		{
			G3D::Rect2D viewPort = adorn->getViewport();
			int fontSize = GuiRoot::normalizedFontSize(12);
			G3D::Vector2 pos2d = viewPort.x0y1() + G3D::Vector2(4.0f, -4.0f);

			adorn->drawFont2D(
				"StarterPack - these items will be given to each new player",
				pos2d,
				fontSize,
				G3D::Color3::white(),
				G3D::Color4::zero(),
				Adorn::XALIGN_LEFT,
				Adorn::YALIGN_BOTTOM,
				Adorn::PROPORTIONAL_SPACING
			);
		}
	}

	void BackpackItem::setTextureId(const TextureId& value)
	{
		if (value != textureId)
		{
			textureId = value;

			Workspace* workspace = ServiceProvider::find<Workspace>(this);
			if (workspace)
				workspace->raiseDrawChanged();

			raisePropertyChanged(desc_TextureId);
		}
	}

	void HopperBin::onSelectScript()
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(this);
		if (workspace)
		{
			ScriptMouseCommand* command = new ScriptMouseCommand(workspace);
			workspace->setMouseCommand(command);
			desc_Selected.fire(this, command->getMouse());
		}
	}

#ifdef NATIVE_HOPPERBINSELECT_PENDING
	void HopperBin::onSelectCommand()
	{
		DataModel* root = static_cast<DataModel*>(getRootAncestor());

		std::string command = Reflection::EnumDesc<BinType>::singleton().convertToString(binType) + "Tool";

		Verb* verb = root->getVerb(command);

		if (verb->isEnabled())
		{
			Workspace* workspace = ServiceProvider::find<Workspace>(this);
			if (workspace)
				verb->doIt(&workspace->getDataState());
		}
	}
#endif
}

#include "v8datamodel/Backpack.h"

namespace RBX
{
	const char sBackpackItem[] = "BackpackItem";        // 0083a730 (doDeclare / classDescriptor)
	const char sHopperBin[] = "HopperBin";              // 0083a740
	const char sStarterPackService[] = "StarterPack";   // 0083a74c (also the constructor's setName)
	const char sLegacyHopperService[] = "Hopper";       // 0083a758 (also the constructor's setName)

	// Template members the shared headers only declare (same definitions as Team.cpp / Flag.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	Reflection::PropDescriptor<BackpackItem, TextureId> desc_TextureId("TextureId", "Data", &BackpackItem::getTextureId, &BackpackItem::setTextureId, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<HopperBin, HopperBin::BinType> desc_BinType("BinType", "Data", &HopperBin::getBinType, &HopperBin::setBinType, Reflection::PropertyDescriptor::STANDARD);
	Reflection::SignalDesc<HopperBin, void(boost::shared_ptr<Instance>)> desc_Selected("Selected", "mouse");
	static Reflection::SignalDesc<HopperBin, void(void)> desc_Deselected("Deselected");
	static Reflection::PropDescriptor<HopperBin, std::string> desc_legacyCommand("Command", "Data", NULL, &HopperBin::setLegacyCommand, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::PropDescriptor<HopperBin, std::string> desc_legacyTextureName("TextureName", "Data", NULL, &HopperBin::setLegacyTextureName, Reflection::PropertyDescriptor::LEGACY);

	const TextureId BackpackItem::getTextureId() const
	{
		return textureId;
	}

	G3D::Vector2 BackpackItem::getSize() const
	{
		float width = GuiRoot::toPixelSize(G3D::Vector2(10.0f, 10.0f)).x;
		return G3D::Vector2(width, width);
	}

	bool Hopper::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const BackpackItem*>(instance) != NULL;
	}

	bool Hopper::askSetParent(const Instance* instance) const
	{
		return true;
	}

	bool BackpackItem::askSetParent(const Instance* instance) const
	{
		return true;
	}

	bool BackpackItem::askAddChild(const Instance* instance) const
	{
		return true;
	}

	Hopper::Hopper()
	{
		yLocation = Rect::BOTTOM;
	}

	bool BackpackItem::isEnabled()
	{
		return getParent() && dynamic_cast<Backpack*>(getParent()) != NULL;
	}

	LegacyHopperService::~LegacyHopperService()
	{
	}

	void LegacyHopperService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (newProvider)
		{
			StarterPackService* starterPack = ServiceProvider::create<StarterPackService>(newProvider);
			while (numChildren() > 0)
				getChild(0)->setParent(starterPack);
			setParent(NULL);
		}
	}

	StarterPackService::StarterPackService()
	{
		setName(sStarterPackService);
	}

	LegacyHopperService::LegacyHopperService()
	{
		setName(sLegacyHopperService);
	}

	void HopperBin::onLocalClicked()
	{
		if (!active)
		{
			active = true;
			if (binType == SCRIPT_BIN)
				onSelectScript();
			else
				onSelectCommand();
		}
		else
		{
			onLocalOtherClicked();
		}
	}

	void HopperBin::onLocalOtherClicked()
	{
		if (active)
		{
			if (binType == SCRIPT_BIN)
				desc_Deselected.fire(this);
			active = false;
			if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
				workspace->setDefaultMouseCommand();
		}
	}

	HopperBin::HopperBin()
		: binType(SCRIPT_BIN),
		  active(false)
	{
		setName("HopperBin");
	}
}

template class RBX::Reflection::EnumDesc<enum RBX::HopperBin::BinType>;
template class RBX::Reflection::SignalDescImpl<0,void __cdecl(void)>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::HopperBin::BinType>;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::HopperBin::BinType> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::HopperBin::BinType> > >;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::HopperBin::BinType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::HopperBin::BinType> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::HopperBin::BinType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::HopperBin::BinType> >,0> >;
template class std::_Vector_val<enum RBX::HopperBin::BinType,std::allocator<enum RBX::HopperBin::BinType> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::HopperBin::BinType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::HopperBin::BinType> >,0> >::_Node *>;
template class std::map<RBX::Name const *,enum RBX::HopperBin::BinType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::HopperBin::BinType> > >;
template class std::vector<enum RBX::HopperBin::BinType,std::allocator<enum RBX::HopperBin::BinType> >;

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();

template void RBX::Name::callDoDeclare<RBX::sHopperBin>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();
