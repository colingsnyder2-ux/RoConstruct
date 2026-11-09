// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_espeon_aug2007_viewport_family_10f93c63ae7cb7e6.cpp

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
#include "gui/Gui.h"

namespace RBX
{
	const G3D::Color4& GuiItem::disabledFill()
	{
		static G3D::Color4 c(0.7f, 0.7f, 0.7f, 0.5f);
		return c;
	}

	const G3D::Color4& GuiItem::translucentBackdrop()
	{
		static G3D::Color4 c(0.6f, 0.6f, 0.6f, 0.6f);
		return c;
	}

	G3D::Vector2 GuiRoot::canvasSize;
	G3D::Matrix4 GuiRoot::oldProjectionMatrix;
	G3D::CoordinateFrame GuiRoot::oldCameraWorld;

	GuiItem::GuiItem() 
	{
		setName("Unnamed GuiItem");
	}

	const GuiItem* GuiItem::getGuiItem(int index) const
	{
		return dynamic_cast<const GuiItem*>(getChild(index));
	}

	GuiItem* GuiItem::getGuiItem(int index)
	{
		return dynamic_cast<GuiItem*>(getChild(index));
	}

	GuiResponse GuiItem::processNonFocus(const GuiEvent& event)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			GuiItem* current = getGuiItem((int)i);

			if (current && current != focus.get())
			{
				GuiResponse itemResponse = current->process(event);
				if (itemResponse.wasUsed())
				{
					this->loseFocus();

					focus = shared_from(current);
					focus->loseFocus();

					return itemResponse;
				}
			}
		}

		return GuiResponse::notUsed();
	}

	void GuiItem::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		if (instance == focus)
			loseFocus();

		Instance::onDescendentRemoving(instance);
	}

	Rect GuiItem::getMyRect() const
	{
		G3D::Vector2 pos = getPosition();
		return Rect(pos, pos + getSize());
	}

	const GuiItem* GuiItem::getGuiParent() const
	{
		return dynamic_cast<const GuiItem*>(getParent());
	}
	
	GuiResponse GuiItem::process(const GuiEvent& event)
	{
		if (event.isMouseEvent() && event.eventType == UIEvent::MOUSE_IDLE)
			return GuiResponse::notUsed();

		if (focus)
		{
			if (focus->canLoseFocus())
			{
				GuiResponse response = processNonFocus(event);
				if (response.wasUsed())
					return response;
			}

			GuiResponse focusResponse = focus->process(event);
			if (focusResponse.wasUsed())
				return focusResponse;

			loseFocus();
		}

		RBXASSERT(!focus);
		return processNonFocus(event);
	}

	void TopMenuBar::init()
	{
		layoutStyle = Layout::HORIZONTAL;
		backdropColor = G3D::Color4::clear();
		visible = true;
	}

	G3D::Vector2 TopMenuBar::getSize() const
	{
		G3D::Vector2 size(0.0f, 0.0f);

		for (size_t i = 0; i < numChildren(); i++)
		{
			const GuiItem* current = getGuiItem((int)i);

			if (current)
			{
				G3D::Vector2 childSize = current->getSize();
				switch (layoutStyle)
				{
				case Layout::VERTICAL:
					size.x = G3D::max(size.x, childSize.x);
					size.y += childSize.y;
					break;
				case Layout::HORIZONTAL:
					size.x += childSize.x;
					size.y = G3D::max(size.y, childSize.y);
					break;
				}
			}
		}

		return size;
	}

	void TopMenuBar::render2d(Adorn* adorn)
	{
		if (isVisible())
		{
			if (backdropColor != G3D::Color4::clear())
			{
				adorn->rect2d(getMyRect2D(), backdropColor);
			}

			for (size_t i = 0; i < numChildren(); i++)
			{
				GuiItem* current = getGuiItem((int)i);
				if (current)
					current->render2d(adorn);
			}
		}
	}

	GuiResponse TopMenuBar::process(const GuiEvent& event)
	{
		if (isVisible())
		{
			GuiResponse response = GuiItem::process(event);
			if (response.wasUsed())
			{
				return response;
			}

			if (backdropColor.a > 0.0f && event.isMouseEvent() && getMyRect().pointInRect(event.mousePosition))
			{
				return GuiResponse::used();
			}
		}

		return GuiResponse::notUsed();
	}

	void RelativePanel::init(const Layout& layout)
	{
		setName("RelativePanel");
		layoutStyle = layout.layoutStyle;
		backdropColor = layout.backdropColor;
		xLocation = layout.xLocation;
		yLocation = layout.yLocation;
		offset = layout.offset;
	}

	GuiRoot::GuiRoot() 
	{
		setName("GuiRoot");
	}

	int GuiRoot::normalizedFontSize(int fontSize)
	{
		static G3D::Vector2 percentSize(100.0f, 75.0f);
		return G3D::iRound(floorf(fontSize * toPixelSize(percentSize).x * 0.001f));
	}

	void GuiRoot::render2d(Adorn* adorn)
	{
		short height = static_cast<short>(adorn->getHeight());
		short width = static_cast<short>(adorn->getWidth());

		canvasSize = G3D::Vector2(width, height);

		for (size_t i = 0; i < numChildren(); i++)
		{
			GuiItem* current = getGuiItem((int)i);
			if (current)
				current->render2d(adorn);
		}
	}
}
