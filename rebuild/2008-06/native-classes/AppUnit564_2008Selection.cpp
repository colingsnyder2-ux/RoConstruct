// 2008-06 native RBX::Selection rows of the application range 00564000..00570000 (inactive), against the native
// v8datamodel/Selection.h (read-only; its layout is proven by tests/NativeSelectionLayout.cpp: size 0x174,
// selection +0x154, filteredSelections +0x15c).
#include "v8datamodel/Selection.h"

namespace RBX
{
	// 005670f0: find over filteredSelections (+0x15c) then vector<ISelectionBase*>::erase 00459830
	void Selection::removeFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.erase(std::find(filteredSelections.begin(), filteredSelections.end(), fs));
	}
}

// The rest of the unit after the donor Selection.cpp. Other bodies have one owner each and are not repeated here:
// Selection()/~Selection() 00568180/00566f00 (SelectionLifetime.cpp), raiseAdded 00566ba0, addToSelection 00567420,
// clearSelection 005675d0, setSelection(Instance*) 00567770 (SelectionMutations.cpp), raiseRemoved 00566d50,
// removeFromSelection 00567c10 (SelectionRemove.cpp), onEvent 005682e0 (SelectionAncestorListener.cpp; it still needs
// the non-const Instance::getRootAncestor() 0042a5f0 in core v8tree/Instance.h), getSelection2 00566a80 and
// setSelection(shared_ptr<const Instances>) 00568330 (inline in v8datamodel/Selection.h), and sSelection 0082ec58
// (NativeClassNames.cpp).

// Dynamic initializers 007f3330 / 007f3360: both push security 1 (AnyCaller), not the donor NeedTrustedCaller (0).
static RBX::Reflection::BoundFuncDesc<RBX::Selection, boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >(void), 0> func_getSelection(&RBX::Selection::getSelection2, "Get", RBX::Reflection::FunctionDescriptor::AnyCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Selection, void(boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >), 1> func_setSelection(&RBX::Selection::setSelection, "Set", "selection", RBX::Reflection::FunctionDescriptor::AnyCaller);

namespace RBX
{
	// 00567180: vector<ISelectionBase*>::push_back 004213a0 on filteredSelections (+0x15c)
	void Selection::addFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.push_back(fs);
	}

	// 00567210
	void Selection::toggleSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
		std::vector<boost::shared_ptr<Instance> >::iterator found = std::find(sel->begin(), sel->end(), shared);
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
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Vector_const_iterator<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;
template class std::_Vector_iterator<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;
template class std::vector<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;
