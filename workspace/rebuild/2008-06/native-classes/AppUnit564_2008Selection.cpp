// 2008-06 native RBX::Selection rows of the application range 00564000..00570000 (inactive), against the native
// v8datamodel/Selection.h (read-only; its layout is proven by tests/NativeSelectionLayout.cpp: size 0x174,
// selection +0x154, filteredSelections +0x15c).
// >>> native-status (generated) -- do not edit >>>
// AppUnit564_2008Selection | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src f6211821 | roc native-status --write
#include "v8datamodel/Selection.h"

namespace RBX
{
	// 005670f0: find over filteredSelections (+0x15c) then vector<ISelectionBase*>::erase 00459830
	void Selection::removeFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.erase(std::find(filteredSelections.begin(), filteredSelections.end(), fs));
	}
}

#ifdef NATIVE_APPUNIT564_PENDING
// Pending-build-only (generated v8datamodel/Selection.h copy, proposal): the 2008 class name is a const char array
// (RTTI .?AV?$FactoryProduct@VSelection@RBX@@VInstance@2@$1?sSelection@2@3QBDB@RBX@@, string 0082ec58), and the
// class declares its constructor 00568180, destructor 00566f00, onEvent 005682e0, raiseAdded/raiseRemoved
// 00566ba0 / 00566d50, toggleSelection 00567210, addFilteredSelection 00567180, getSelection2 00566a80 and
// setSelection(shared_ptr<const Instances>) 00568330. Bodies after the donor Selection.cpp. onEvent 005682e0 is
// declared but not built: it calls the non-const Instance::getRootAncestor() 0042a5f0, which the native
// v8tree/Instance.h does not declare (proposal).
namespace RBX
{
	const char sSelection[] = "Selection";

	// Template members the shared headers only declare (same definitions as Team.cpp / DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
}

// Dynamic initializers 007f3330 / 007f3360.
static RBX::Reflection::BoundFuncDesc<RBX::Selection, boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >(void), 0> func_getSelection(&RBX::Selection::getSelection2, "Get", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Selection, void(boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >), 1> func_setSelection(&RBX::Selection::setSelection, "Set", "selection", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

namespace RBX
{
	Selection::Selection()
		: selection(std::vector<boost::shared_ptr<Instance> >())
	{
		setName("Selection");
	}

	Selection::~Selection()
	{
	}

	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Selection::getSelection2()
	{
		return selection.read();
	}

	void Selection::addFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.push_back(fs);
	}

	void Selection::raiseAdded(boost::shared_ptr<Instance> instance)
	{
		SelectionChanged event(instance, boost::shared_ptr<Instance>());
		for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
			(*iter)->onSelectionChanged(event);
		Notifier<Selection, SelectionChanged>::raise(event);
	}

	void Selection::raiseRemoved(boost::shared_ptr<Instance> source)
	{
		SelectionChanged event(boost::shared_ptr<Instance>(), source);
		for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
			(*iter)->onSelectionChanged(event);
		Notifier<Selection, SelectionChanged>::raise(event);
	}

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

	void Selection::addToSelection(Instance* instance)
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
	}

	void Selection::removeFromSelection(const Instance* instance)
	{
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
		std::vector<boost::shared_ptr<Instance> >::iterator found = std::find(sel->begin(), sel->end(), shared_from(instance));
		if (found != sel->end())
		{
			boost::shared_ptr<Instance> nonConst = *found;
			sel->erase(found);
			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(nonConst);
		}
	}

	// 005675d0: the loop test is size() > 0 (sar 3; test; jbe), not the donor's empty() (test 0xfffffff8)
	void Selection::clearSelection()
	{
		while (selection->size() > 0)
		{
			boost::shared_ptr<Instance> instance = selection->back();
			selection.write()->pop_back();
			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(instance);
		}
	}

	// 00567770
	void Selection::setSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> inst = shared_from(instance);
		while (selection->size() > 0)
		{
			boost::shared_ptr<Instance> item = selection->back();
			if (item == inst)
			{
				if (selection->size() == 1)
					return;
				boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
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

	void Selection::setSelection(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > value)
	{
		setSelection(value->begin(), value->end());
	}
}
#endif

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Vector_const_iterator<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;
template class std::_Vector_iterator<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;
template class std::vector<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;
