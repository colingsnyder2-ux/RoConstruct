// from server: 100% by EspClaude
// from server: 54% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs roc_claude_be243a3cb1a58165.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DataModel.h"
#include "v8tree/Instance.h"
#include "reflection/property.h"

namespace RBX
{
	// Owner object: target reads the DataModel pointer at +0x188.
	struct PropertyGridOwner
	{
		char pad[0x188];
		DataModel* dataModel;
	};

	// Property grid item: target reads the owner at +0x128 and the descriptor at +0x12c.
	class PropertyGridItemBoolBinding
	{
		char pad[0x128];
		PropertyGridOwner* owner;
		const Reflection::TypedPropertyDescriptor<bool>* descriptor;
	public:
		bool getValue(Instance* instance);
		void setValue(Instance* instance, const bool& value);
	};

	bool PropertyGridItemBoolBinding::getValue(Instance* instance)
	{
		DataModel::Lock lock(owner->dataModel);
		return descriptor->getValue(instance);
	}

	void PropertyGridItemBoolBinding::setValue(Instance* instance, const bool& value)
	{
		DataModel::Lock lock(owner->dataModel);
		descriptor->setValue(instance, value);
	}
}
