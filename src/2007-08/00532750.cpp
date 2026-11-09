// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_native_app_workspace_2f9cd8f5e267977d.cpp

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
#include "v8datamodel/Selection.h"

static RBX::Reflection::BoundFuncDesc<RBX::Selection, boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance>>>(void), 0> func_getSelection(&RBX::Selection::getSelection2, "Get", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Selection, void(boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance>>>), 1> func_setSelection(&RBX::Selection::setSelection, "Set", "selection", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

namespace RBX
{
	Selection::Selection()
		: selection(std::vector<boost::shared_ptr<Instance>>())
	{
		setName("Selection");
	}

	Selection::~Selection()
	{
		RBXASSERT(size() == 0);
	}

	void Selection::addFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.push_back(fs);
	}

	void Selection::removeFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.erase(std::find(filteredSelections.begin(), filteredSelections.end(), fs));
	}

	void Selection::raiseAdded(boost::shared_ptr<Instance> instance)
	{
		SelectionChanged event(instance, boost::shared_ptr<Instance>());

		for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
		{
			(*iter)->onSelectionChanged(event);
		}

		Notifier<Selection, SelectionChanged>::raise(event);
	}

	void Selection::raiseRemoved(boost::shared_ptr<Instance> source)
	{
		SelectionChanged event(boost::shared_ptr<Instance>(), source);

		for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
		{
			(*iter)->onSelectionChanged(event);
		}

		Notifier<Selection, SelectionChanged>::raise(event);
	}

	void Selection::toggleSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = selection.write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared);

		if (found == sel->end())
		{
			sel->push_back(shared);
			instance->Notifier<Instance, AncestorChanged>::addListener(this);
			raiseAdded(shared);
		}
		else
		{
			sel->erase(found);
			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(shared);
		}
	}

	void Selection::addToSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);
		RBXASSERT(instance);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = selection.write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared);

		if (found == sel->end())
		{
			sel->push_back(shared);
			instance->Notifier<Instance, AncestorChanged>::addListener(this);
			raiseAdded(shared);
		}
	}
	
	void Selection::removeFromSelection(const Instance* instance)
	{
		RBXASSERT(instance);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = selection.write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared_from(instance));

		if (found != sel->end())
		{
			boost::shared_ptr<Instance> nonConst = *found;

			sel->erase(found);
			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(nonConst);
		}
	}

	void Selection::clearSelection()
	{
		while (!selection->empty())
		{
			boost::shared_ptr<Instance> instance = selection->back();
			selection.write()->pop_back();

			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(instance);
		}
	}

	void Selection::setSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> inst = shared_from(instance);
		
		while (!selection->empty())
		{
			boost::shared_ptr<Instance> item = selection->back();

			if (item == inst)
			{
				if (selection->size() == 1)
					return;

				boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = selection.write();
				sel->back() = sel->front();
				sel->front() = item;
			}
			else
			{
				selection.write()->pop_back();
				item->Notifier<Instance, AncestorChanged>::removeListener(this);
				raiseRemoved(item);
			}
		}

		if (inst)
		{
			selection.write()->push_back(inst);
			instance->Notifier<Instance, AncestorChanged>::addListener(this);
			raiseAdded(inst);
		}
	}

	void Selection::onEvent(const Instance* source, AncestorChanged event)
	{
		if (source->getRootAncestor() != this->getRootAncestor())
			removeFromSelection(source);
	}
}
