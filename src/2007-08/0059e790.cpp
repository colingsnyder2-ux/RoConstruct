// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_viewport_inputs_2c79facee24123c4.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8datamodel/JointsService.h", "../roc_espeon_aug2007_joints_service_header_70eae11bae482e15.cpp")
#pragma include_alias(<v8datamodel/JointsService.h>, <../roc_espeon_aug2007_joints_service_header_70eae11bae482e15.cpp>)
#pragma include_alias("v8datamodel/DebrisService.h", "../roc_espeon_aug2007_debris_pinned_header_2c0ad23d27535ab8.cpp")
#pragma include_alias(<v8datamodel/DebrisService.h>, <../roc_espeon_aug2007_debris_pinned_header_2c0ad23d27535ab8.cpp>)
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
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)

#include "v8datamodel/Hopper.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Mouse.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/ScriptMouseCommand.h"

namespace RBX
{
	static Reflection::PropDescriptor<BackpackItem, TextureId> desc_TextureId("TextureId", "Data", &BackpackItem::getTextureId, &BackpackItem::setTextureId, Reflection::PropertyDescriptor::STANDARD);

	static Reflection::PropDescriptor<HopperBin, std::string> desc_legacyCommand("Command", "Data", NULL, &HopperBin::setLegacyCommand, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::PropDescriptor<HopperBin, std::string> desc_legacyTextureName("TextureName", "Data", NULL, &HopperBin::setLegacyTextureName, Reflection::PropertyDescriptor::LEGACY);
	static Reflection::EnumPropDescriptor<HopperBin, HopperBin::BinType> desc_BinType("BinType", "Data", &HopperBin::getBinType, &HopperBin::setBinType, Reflection::PropertyDescriptor::STANDARD);

	static Reflection::SignalDesc<HopperBin, void(void)> desc_Deselected("Deselected");
	static Reflection::SignalDesc<HopperBin, void(boost::shared_ptr<Instance>)> desc_Selected("Selected", "mouse");

	Hopper::Hopper()
	{
		yLocation = Rect::BOTTOM;
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

	const TextureId BackpackItem::getTextureId() const
	{
		return textureId;
	}

	bool BackpackItem::isEnabled()
	{
		return getParent() && dynamic_cast<Backpack*>(getParent()) != NULL;
	}

	void BackpackItem::setTextureId(const TextureId& value)
	{
		if (value != textureId)
		{
			textureId = value;

			std::string filename;
			ContentProvider::singleton().requestContentFile(value, filename);

			Workspace* workspace = ServiceProvider::find<Workspace>(this);
			if (workspace)
				workspace->raiseDrawChanged();

			raisePropertyChanged(desc_TextureId);
		}
	}

	G3D::Vector2 BackpackItem::getSize() const
	{
		float width = GuiRoot::toPixelSize(G3D::Vector2(10.0f, 10.0f)).x;
		return G3D::Vector2(width, width);
	}

	HopperBin::HopperBin()
		: binType(SCRIPT_BIN),
		  active(false)
	{
		setName("HopperBin");
	}

	void HopperBin::setBinType(const HopperBin::BinType value)
	{
		if (value != binType)
		{
			binType = value;
			raisePropertyChanged(desc_BinType);

			if (binType != SCRIPT_BIN)
			{
				std::string textureName = Reflection::EnumDesc<BinType>::singleton().convertToString(binType);
				setLegacyTextureName(textureName);
			}
		}
	}

	void HopperBin::setLegacyTextureName(const std::string& value)
	{
		TextureId textureId = ContentId::fromAssets("Textures\\" + value + ".png");
		setTextureId(textureId);
	}

	void HopperBin::setLegacyCommand(const std::string& text)
	{
		BinType newBinType;
		
		if (!Reflection::EnumDesc<BinType>::singleton().convertToValue(text, newBinType))
		{
			newBinType = SCRIPT_BIN;
		}
		
		setBinType(newBinType);
	}

	void HopperBin::onLocalClicked()
	{
		RBXASSERT(isEnabled());

		if (!active)
		{
			active = true;

			if (binType == SCRIPT_BIN)
			{
				onSelectScript();
			}
			else
			{
				onSelectCommand();
			}
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

			Workspace* workspace = ServiceProvider::find<Workspace>(this);
			if (workspace)
				workspace->setDefaultMouseCommand();
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

	void HopperBin::onSelectCommand()
	{
		RBXASSERT(binType != SCRIPT_BIN);

		DataModel* root = rbx_static_cast<DataModel*>(getRootAncestor());

		std::string command = Reflection::EnumDesc<BinType>::singleton().convertToString(binType) + "Tool";

		Verb* verb = root->getVerb(command);
		RBXASSERT(verb);

		if (verb->isEnabled())
		{
			Workspace* workspace = ServiceProvider::find<Workspace>(this);
			if (workspace)
				verb->doIt(&workspace->getDataState());
			else
				RBXASSERT(0);
		}
	}

	StarterPackService::StarterPackService()
	{
		setName("StarterPack");
	}

	//97.87% match
	//le EPIC TROLL
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
				G3D::Color4::clear(), 
				Adorn::XALIGN_LEFT, 
				Adorn::YALIGN_BOTTOM,
				Adorn::PROPORTIONAL_SPACING
			);
		}
	}

	LegacyHopperService::LegacyHopperService()
	{
		setName("Hopper");
	}

	LegacyHopperService::~LegacyHopperService()
	{
		RBXASSERT(numChildren() == 0);
	}

	void LegacyHopperService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Instance::onServiceProvider(oldProvider, newProvider);

		if (newProvider)
		{
			StarterPackService* starterPack = newProvider->find<StarterPackService>();
			RBXASSERT(starterPack);

			while (numChildren() > 0)
			{
				getChild(0)->setParent(starterPack);
			}

			setParent(NULL);
		}
	}
}
