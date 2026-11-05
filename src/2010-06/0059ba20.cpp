// from server: 49% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Selection.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Selection.h"

#include "util/object.h"
#include "util/standardout.h"

#include <algorithm>

namespace RBX {

const char sSelection[] = "Selection";

// FUNCTION: WEBSERVICE 0x1005d440
void Selection::raiseRemoved(boost::shared_ptr<Instance> item)
{
	SelectionChanged event(boost::shared_ptr<Instance>(), item);

	for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end();
		 ++iter) {
		(*iter)->VTable0x00(event);
	}

	Notifier<Selection, SelectionChanged>::raise(event);
}

// FUNCTION: WEBSERVICE 0x1005d5e0
Selection::~Selection()
{
}

// STUB: WEBSERVICE 0x1005e1f0
void Selection::removeFromSelection(const Instance* instance)
{
	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > items = selection.write();

	std::vector<boost::shared_ptr<Instance> >::iterator iter =
		std::find(items->begin(), items->end(), shared_from(instance));

	if (iter != items->end()) {
		boost::shared_ptr<Instance> removedItem = *iter;

		items->erase(iter);

		instance->Notifier<Instance, AncestorChanged>::removeListener(this);

		raiseRemoved(removedItem);
	}
}

// FUNCTION: WEBSERVICE 0x1005e870
void Selection::onEvent(const Instance* source, AncestorChanged event)
{
	const Instance* sourceRoot = source->getParent() != NULL ? source->getParent()->getRootAncestor() : source;

	if (sourceRoot != getRootAncestor()) {
		removeFromSelection(source);
	}
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Selection, RBX::Instance, RBX::sSelection>;
template class RBX::Reflection::
	Described<RBX::Selection, RBX::sSelection, RBX::FactoryProduct<RBX::Selection, RBX::Instance, RBX::sSelection> >;
template class RBX::DescribedCreatable<RBX::Selection, RBX::Instance, RBX::sSelection>;
