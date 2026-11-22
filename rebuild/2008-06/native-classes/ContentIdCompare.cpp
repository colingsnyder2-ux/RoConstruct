// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Inactive native 2008-06 recovery: the out-of-line RBX::ContentId comparison operator of the original ContentId /
// ContentProvider unit (0055bd10 ContentProvider::isUrl, 0055bd50 operator<, 0055bd60 operator!=, 0055bd80
// ContentId::fromAssets(const char*)). Flags copied from ContentIdAssets.cpp / ContentIdAssetsPath.cpp without their
// slingshot-load include variant (this unit needs only the donor util/ContentProvider.h declarations).
// util/ContentProvider.h declares 'bool operator!=(const ContentId&, const ContentId&)' out of line; callers
// 00642750 (GuiDrawImage, GuiDrawImageSize.cpp), 005bd360 (SoundChannel.cpp) and 005d11e0 (HopperBin TextureId
// setter, HopperBinSelect.cpp) call 0055bd60.
#include "util/ContentProvider.h"

namespace RBX {
// 0055bd50: ??MRBX@@YA_NABVContentId@0@0@Z (identity-registry decorated signature, 10 reference votes).
// Body is one 'jmp [0x80235c]', the MSVCP90 import std::operator<(const string&, const string&): same tail-jump
// shape as operator!= below (ContentId::id is the first member).
bool operator<(const ContentId& a, const ContentId& b)
{
	return a.toString() < b.toString();
}

// 0055bd60: ??9RBX@@YA_NABVContentId@0@0@Z (identity-registry decorated signature, 8 reference votes).
// Body is one 'jmp [0x8023d8]', the MSVCP90 import std::operator!=(const string&, const string&): ContentId::id is
// the first member, so toString() passes both references through unchanged and /O2 turns the call into a tail jump.
bool operator!=(const ContentId& a, const ContentId& b)
{
	return a.toString() != b.toString();
}
}
