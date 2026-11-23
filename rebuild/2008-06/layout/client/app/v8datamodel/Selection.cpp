// =============================================================================
// Selection.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Selection.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Selection.h"

namespace RBX
{
	void Selection::removeFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.erase(std::find(filteredSelections.begin(), filteredSelections.end(), fs));
	}
}

static RBX::Reflection::BoundFuncDesc<RBX::Selection, boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >(void), 0> func_getSelection(
	&RBX::Selection::getSelection2,
	"Get",
	RBX::Reflection::FunctionDescriptor::AnyCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Selection, void(boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >), 1> func_setSelection(
	&RBX::Selection::setSelection,
	"Set",
	"selection",
	RBX::Reflection::FunctionDescriptor::AnyCaller);

namespace RBX
{
	void Selection::addFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.push_back(fs);
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
}

template class std::_Vector_const_iterator<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;
template class std::_Vector_iterator<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;
template class std::vector<RBX::ISelectionBase *,std::allocator<RBX::ISelectionBase *> >;

#include <algorithm>

namespace RBX
{
	bool Selection::isSelected(const Instance* instance) const
	{
		return std::find(selection->begin(), selection->end(), shared_from(instance)) != selection->end();
	}
}

#ifdef NATIVE_SELECTION_ROOT_ANCESTOR_PENDING
namespace RBX
{
void Selection::onEvent(const Instance* source, AncestorChanged event) {
	if (source->getRootAncestor() != this->getRootAncestor()) removeFromSelection(source);
}
}
#endif

namespace RBX
{

boost::shared_ptr<Instance> Selection::back() const
{
	return selection->size() > 0 ? selection->back() : boost::shared_ptr<Instance>();
}

}

boost::shared_ptr<RBX::Instance> RBX::Selection::front() const
{
	return selection->size() > 0 ? *selection->begin() : boost::shared_ptr<Instance>();
}

typedef std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator SelectionIterator;

SelectionIterator RBX::Selection::begin() const
{
	return selection->begin();
}

SelectionIterator RBX::Selection::end() const
{
	return selection->end();
}

namespace RBX
{
Selection::~Selection()
{
}
}
