// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT
// >>> native-status (generated) -- do not edit >>>
// SelectionMutations | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 0f3b89cb | roc native-status --write
#include "v8datamodel/Selection.h"
#include "util/Debug.h"
#include <algorithm>
namespace RBX {
	void Selection::raiseAdded(boost::shared_ptr<Instance> instance)
	{
		SelectionChanged event(instance, boost::shared_ptr<Instance>());

		for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
		{
			(*iter)->onSelectionChanged(event);
		}

		Notifier<Selection, SelectionChanged>::raise(event);
	}


	void Selection::addToSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);
		RBXASSERT(instance);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared);

		if (found == sel->end())
		{
			sel->push_back(shared);
			instance->Notifier<Instance, AncestorChanged>::addListener(this);
			raiseAdded(shared);
		}
	}
	

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

}
