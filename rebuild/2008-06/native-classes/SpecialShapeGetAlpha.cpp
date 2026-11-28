// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 native SpecialShape::getAlpha (inactive). Flags copied from SpecialShape.cpp (the SpecialShape unit). Its
// declaration `const float getAlpha() const;` is in v8datamodel/custommesh.h (the header its caller
// ViewNewPartMaterial.cpp uses), not yet in native-headers/v8datamodel/SpecialShape.h, so the body lives in this small
// unit on custommesh.h instead of SpecialShape.cpp (whose guarded SPECIALSHAPE_HEADER_DECLARES_GETALPHA copy was moved here).
#include "v8datamodel/custommesh.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 0059eca0 (registry placeholder func_0059eca0): donor custommesh.cpp getAlpha, the first body of the SpecialShape unit
	// (just before the FactoryProduct<SpecialShape> destructor 0059ece0). Parent +0x104, dynamic_cast to PartInstance
	// (??_R0 0092dd50), then PartInstance::alpha() = 1 - (1 - transparency +0x1e8) * alphaModifier +0x328 (the
	// part-embedded PartInstance layout).
	const float SpecialShape::getAlpha() const
	{
		Instance* parent = getParent();
		if (!parent)
			return 0.0f;

		if (PartInstance* part = dynamic_cast<PartInstance*>(parent))
			return part->alpha();

		return 0.0f;
	}
}
