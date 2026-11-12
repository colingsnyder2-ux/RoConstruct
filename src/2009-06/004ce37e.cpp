// from server: 63% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Selection.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Selection.h"

#include "reflection/reflection.h"
#include "util/object.h"
#include "util/standardout.h"

#include <algorithm>

static RBX::Reflection::
	BoundFuncDesc<RBX::Selection, boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >(), 0>
		func_getSelection(
			&RBX::Selection::getSelection2, "Get", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller
		);
static RBX::Reflection::
	BoundFuncDesc<RBX::Selection, void(boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >), 1>
		func_setSelection(
			&RBX::Selection::setSelection, "Set", "selection", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller
		);

namespace RBX {

const char sSelection[] = "Selection";

// FUNCTION: WEBSERVICE 0x1005d240
// FUNCTION: ROBLOX 0x005672e0
void Selection::removeFilteredSelection(ISelectionBase* fs)
{
	filteredSelections.erase(std::find(filteredSelections.begin(), filteredSelections.end(), fs));
}

// FUNCTION: WEBSERVICE 0x1005d2c0
// FUNCTION: ROBLOX 0x00567360
void Selection::raiseAdded(boost::shared_ptr<Instance> instance)
{
	SelectionChanged event(instance, boost::shared_ptr<Instance>());

	for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end();
		 ++iter) {
		(*iter)->onSelectionChanged(event);
	}

	Notifier<Selection, SelectionChanged>::raise(event);
}

// FUNCTION: WEBSERVICE 0x1005d440
// FUNCTION: ROBLOX 0x005674e0
void Selection::raiseRemoved(boost::shared_ptr<Instance> source)
{
	SelectionChanged event(boost::shared_ptr<Instance>(), source);

	for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end();
		 ++iter) {
		(*iter)->onSelectionChanged(event);
	}

	Notifier<Selection, SelectionChanged>::raise(event);
}

// FUNCTION: WEBSERVICE 0x1005d5e0
// FUNCTION: ROBLOX 0x00567680
Selection::~Selection()
{
}

// FUNCTION: WEBSERVICE 0x1005d7d0
// FUNCTION: ROBLOX 0x00567870
void Selection::addFilteredSelection(ISelectionBase* fs)
{
	filteredSelections.push_back(fs);
}

// FUNCTION: WEBSERVICE 0x1005d8e0
// FUNCTION: ROBLOX 0x00567900
void Selection::toggleSelection(Instance* instance)
{
	boost::shared_ptr<Instance> shared = shared_from(instance);

	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
	std::vector<boost::shared_ptr<Instance> >::iterator iter = std::find(sel->begin(), sel->end(), shared);
	if (iter == sel->end()) {
		sel->push_back(shared);
		instance->Notifier<Instance, AncestorChanged>::addListener(this);
		raiseAdded(shared);
	}
	else {
		sel->erase(iter);
		instance->Notifier<Instance, AncestorChanged>::removeListener(this);
		raiseRemoved(shared);
	}
}

// FUNCTION: WEBSERVICE 0x1005dae0
// FUNCTION: ROBLOX 0x00567b00
void Selection::addToSelection(Instance* instance)
{
	boost::shared_ptr<Instance> shared = shared_from(instance);

	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
	std::vector<boost::shared_ptr<Instance> >::iterator iter = std::find(sel->begin(), sel->end(), shared);
	if (iter == sel->end()) {
		sel->push_back(shared);
		instance->Notifier<Instance, AncestorChanged>::addListener(this);
		raiseAdded(shared);
	}
}

// FUNCTION: WEBSERVICE 0x1005dc80
// FUNCTION: ROBLOX 0x00567ca0
void Selection::clearSelection()
{
	while (selection->size() > 0) {
		boost::shared_ptr<Instance> instance = selection->back();
		selection.write()->pop_back();
		instance->Notifier<Instance, AncestorChanged>::removeListener(this);
		raiseRemoved(instance);
	}
}

// FUNCTION: WEBSERVICE 0x1005dde0
// FUNCTION: ROBLOX 0x00567e00
void Selection::setSelection(Instance* instance)
{
	boost::shared_ptr<Instance> inst = shared_from(instance);

	while (selection->size() > 0) {
		boost::shared_ptr<Instance> item = selection->back();

		if (item == inst) {
			if (selection->size() == 1) {
				return;
			}

			boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
			sel->back() = sel->front();
			sel->front() = item;
		}
		else {
			selection.write()->pop_back();
			item->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(item);
		}
	}

	if (inst) {
		selection.write()->push_back(inst);
		instance->Notifier<Instance, AncestorChanged>::addListener(this);
		raiseAdded(inst);
	}
}

// FUNCTION: WEBSERVICE 0x1005e1f0
// FUNCTION: ROBLOX 0x00568210
void Selection::removeFromSelection(const Instance* instance)
{
	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();

	std::vector<boost::shared_ptr<Instance> >::iterator iter =
		std::find(sel->begin(), sel->end(), shared_from(instance));

	if (iter != sel->end()) {
		boost::shared_ptr<Instance> nonConst = *iter;

		sel->erase(iter);

		instance->Notifier<Instance, AncestorChanged>::removeListener(this);

		raiseRemoved(nonConst);
	}
}

// FUNCTION: WEBSERVICE 0x1005e720
// FUNCTION: ROBLOX 0x00568750
Selection::Selection() : selection(std::vector<boost::shared_ptr<Instance> >())
{
	setName("Selection");
}

// FUNCTION: WEBSERVICE 0x1005e870
// FUNCTION: ROBLOX 0x005688a0
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
