// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT
#include "v8datamodel/Selection.h"
#include "util/Debug.h"
#include <algorithm>
namespace RBX {
	void Selection::raiseRemoved(boost::shared_ptr<Instance> source)
	{
		SelectionChanged event(boost::shared_ptr<Instance>(), source);

		for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
		{
			(*iter)->onSelectionChanged(event);
		}

		Notifier<Selection, SelectionChanged>::raise(event);
	}


	void Selection::removeFromSelection(const Instance* instance)
	{
		RBXASSERT(instance);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared_from(instance));

		if (found != sel->end())
		{
			boost::shared_ptr<Instance> nonConst = *found;

			sel->erase(found);
			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(nonConst);
		}
	}

}
