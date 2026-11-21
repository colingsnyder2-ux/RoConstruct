// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// RBX::stringHash 00669f60 (?stringHash@RBX@@YAIABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z,
// registry name; declared in native gui/ScoreHud.h). Callers: renderFFALeaderboard 0065556e and the ChatLine
// constructor 0065061e (colour index of a player name). It lies next to its only callee 00669f10 (placeholder
// sub_00669f10, body in Inferred_00669f10.cpp: seed 0xf8c9, multiplier 0x5c6b7, i.e. the RS string hash).
#include <string>

namespace RBX
{
	// 00669f10: declared exactly as Inferred_00669f10.cpp defines it (placeholder name from the identity tier).
	void sub_00669f10(unsigned int* hash, const unsigned char* data, unsigned int length);

	unsigned int stringHash(const std::string&);

	// 00669f60. Target: hash local zeroed, then (&hash, c_str() [_Myres >= 0x10 selects _Ptr], size()) pushed
	// to the cdecl 00669f10; returns the local.
	unsigned int stringHash(const std::string& s)
	{
		unsigned int length = s.size();
		const unsigned char* data = reinterpret_cast<const unsigned char*>(s.c_str());
		unsigned int hash = 0;
		sub_00669f10(&hash, data, length);
		return hash;
	}
}
