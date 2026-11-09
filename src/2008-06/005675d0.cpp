// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_selection_native_family_ad678e9424f0efdf.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
namespace RBX { class Instance; template<typename Class> boost::shared_ptr<Class> shared_from(Class*); template<> boost::shared_ptr<Instance> shared_from<Instance>(Instance*); template<> boost::shared_ptr<const Instance> shared_from<const Instance>(const Instance*); }
#include <v8datamodel/Selection.h>
namespace RBX {
	void Selection::toggleSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = (*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154)).write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared);

		if (found == sel->end())
		{
			sel->push_back(shared);
			((const Notifier<Instance, AncestorChanged>*)((const char*)instance+0xa4))->addListener((Listener<Instance, AncestorChanged>*)((char*)this+0x150));
			raiseAdded(shared);
		}
		else
		{
			sel->erase(found);
			((const Notifier<Instance, AncestorChanged>*)((const char*)instance+0xa4))->removeListener((Listener<Instance, AncestorChanged>*)((char*)this+0x150));
			raiseRemoved(shared);
		}
	}

	void Selection::addToSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);
		RBXASSERT(instance);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = (*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154)).write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared);

		if (found == sel->end())
		{
			sel->push_back(shared);
			((const Notifier<Instance, AncestorChanged>*)((const char*)instance+0xa4))->addListener((Listener<Instance, AncestorChanged>*)((char*)this+0x150));
			raiseAdded(shared);
		}
	}
	
	void Selection::removeFromSelection(const Instance* instance)
	{
		RBXASSERT(instance);

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = (*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154)).write();

		std::vector<boost::shared_ptr<Instance>>::iterator found = std::find(sel->begin(), sel->end(), shared_from(instance));

		if (found != sel->end())
		{
			boost::shared_ptr<Instance> nonConst = *found;

			sel->erase(found);
			((const Notifier<Instance, AncestorChanged>*)((const char*)instance+0xa4))->removeListener((Listener<Instance, AncestorChanged>*)((char*)this+0x150));
			raiseRemoved(nonConst);
		}
	}

	void Selection::clearSelection()
	{
		while ((*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154))->size() > 0)
		{
			boost::shared_ptr<Instance> instance = (*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154))->back();
			(*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154)).write()->pop_back();

			((const Notifier<Instance, AncestorChanged>*)((const char*)instance.get()+0xa4))->removeListener((Listener<Instance, AncestorChanged>*)((char*)this+0x150));
			raiseRemoved(instance);
		}
	}

	void Selection::setSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> inst = shared_from(instance);
		
		while ((*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154))->size() > 0)
		{
			boost::shared_ptr<Instance> item = (*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154))->back();

			if (item == inst)
			{
				if ((*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154))->size() == 1)
					return;

				boost::shared_ptr<std::vector<boost::shared_ptr<Instance>>> sel = (*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154)).write();
				sel->back() = sel->front();
				sel->front() = item;
			}
			else
			{
				(*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154)).write()->pop_back();
				((const Notifier<Instance, AncestorChanged>*)((const char*)item.get()+0xa4))->removeListener((Listener<Instance, AncestorChanged>*)((char*)this+0x150));
				raiseRemoved(item);
			}
		}

		if (inst)
		{
			(*(CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((char*)this+0x154)).write()->push_back(inst);
			((const Notifier<Instance, AncestorChanged>*)((const char*)instance+0xa4))->addListener((Listener<Instance, AncestorChanged>*)((char*)this+0x150));
			raiseAdded(inst);
		}
	}


}
