// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../native-donor-2007
// Inactive native 2008-06 property-grid rows: ContentItem<T> constructors, Vector3Item::OnAfterEdit and update.
#include <afxwin.h>
#include <afxdlgs.h>
#include <string>
#include "PropertyGridItems2008.h"

// NEEDS-DECL: template<class T> struct RBX::StringConverter { static bool convertToValue(const std::string&, T&); };

// 0043e840 / 0043ea20: constructors of the ContentItem<T> template, instantiated explicitly.
template ContentItem<RBX::Soundscape::SoundId>::ContentItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>* property, CPropGrid* grid);
template ContentItem<RBX::TextureId>::ContentItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>* property, CPropGrid* grid);

// 0043d710
BOOL Vector3Item::OnAfterEdit(CString& strValue)
{
    G3D::Vector3 v(0.0f, 0.0f, 0.0f);
    std::string text((LPCSTR)strValue);
    return RBX::StringConverter<G3D::Vector3>::convertToValue(text, v);
}

// 0043d790
void Vector3Item::update(RBX::SelectionGroup* group)
{
    Vector3ItemBase::update(group);
    for (int i = 0; i < 3; ++i) {
        if (components[i] != 0)
            components[i]->update(group);
    }
}
