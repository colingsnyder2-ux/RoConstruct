// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0043dff0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "PropertyGridItems2008.h"
#include "SelectionGroup.h"

void ScriptItem::update(RBX::SelectionGroup* selection)
{
	if (selection == 0)
		_invalid_parameter_noinfo();
	for (std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator c = classes.begin(), ce = classes.end(); c != ce; ++c)
	{
		const RBX::Reflection::ClassDescriptor* key = *c;
		RBX::SelectionGroup::iterator selected = selection->find(key);
		size_t n = selected != selection->end() ? selected->second.size() : 0;
		if (n > 0)
		{
			SetHidden(0);
			return;
		}
	}
	SetHidden(1);
}
