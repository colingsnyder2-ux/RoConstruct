// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load
// Inactive native 2008-06 recovery: RBX::ContentId::fromAssets(const std::string&) from the original ContentId unit
// (0055bae0 isAsset, 0055bb50 isHttp, 0055bd80 fromAssets(const char*), 0055c500 this overload). Flags and include
// path copied from ContentIdAssets.cpp, which holds the const char* overload.
// The donor util/ContentProvider.h (reached through util/NativeContentProvider.h) keeps isAsset/isHttp inline, but the
// binary has them out of line in this unit (0055bae0 / 0055bb50, identity-registry decorated names).
// Following the slingshot-load/util/ContentProvider.h macro pattern, this unit turns the donor inline bodies into
// declarations (the inline text survives under a unit-local name only) and defines the members below.
// INFERRED: out-of-line placement from the binary (addresses beside fromAssets 0055bd80 in the ContentId unit).
#define isAsset isAsset() const; bool unitInlineIsAsset
#define isHttp isHttp() const; bool unitInlineIsHttp
#include "util/NativeContentProvider.h"
#undef isAsset
#undef isHttp

namespace RBX {
// 0055bae0: ?isAsset@ContentId@RBX@@QBE_NXZ; substr(0, 11) (MSVCP90 import) == "rbxasset://" (0082da68).
bool ContentId::isAsset() const {
 return id.substr(0, 11) == "rbxasset://";
}

// 0055bb50: ?isHttp@ContentId@RBX@@QBE_NXZ; substr(0, 4) == "http".
bool ContentId::isHttp() const {
 return id.substr(0, 4) == "http";
}

// 0055c500: ?fromAssets@ContentId@RBX@@SA?AV12@ABV?$basic_string@...@Z (identity-registry decorated signature);
// inline c_str() (_Myres +0x18 >= 0x10 picks the heap pointer +4, else the buffer +4), then the const char*
// overload 0055bd80 with the hidden return slot. Caller: HopperBin::setLegacyTextureName 005d13d0.
ContentId ContentId::fromAssets(const std::string& filePath) {
 return fromAssets(filePath.c_str());
}
}
