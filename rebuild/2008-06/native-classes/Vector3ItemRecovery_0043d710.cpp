// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/mfc-noinline-pcxstr
// 2008-06 native Vector3Item editor row (draft recovery; inactive until proved).
// 0043d710: OnAfterEdit (primary vftable slot) - parse the edited text into the vector.
// 0043d790: update (Item vftable slot 0) - forward to the three component rows.
#include "PropertyGridItems2008.h"
#include "util/Utilities.h"

void Vector3Item::update(RBX::SelectionGroup* group)
{
    Vector3ItemBase::update(group);
    for (int i = 0; i < 3; ++i)
        if (components[i])
            components[i]->update(group);
}

BOOL Vector3Item::OnAfterEdit(CString& strValue)
{
    G3D::Vector3 value(0.0f, 0.0f, 0.0f);
    std::string text(strValue);
    return RBX::StringConverter<G3D::Vector3>::convertToValue(text, value);
}
