// from server: 92% by EspClaude
// from server: 57% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_claude_ca1c248e360318af.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog for 2007-08 00549a10 (returns std::string by hidden pointer, cdecl):
//   call 00408740 (cdecl, no args, returns a static object's address),
//   thiscall 005468d0 on it (hidden std::string return, ret 4),
//   if size() > 0: operator+=("\\GlobalSettings2.xml") through MSVCP80's IAT.
// The exe is /MD; the library preprocessing pass lacks it, so define _DLL to keep
// the std::basic_string<char> members dllimported as in the target.
#ifndef _DLL
#define _DLL
#endif
#include <string>

class RocAppFolders
{
public:
	std::string folder();			// 005468d0
};
RocAppFolders &rocAppFolders();		// 00408740

std::string rocGlobalSettingsPath()
{
	std::string path = rocAppFolders().folder();
	if (path.size() > 0)
		path += "\\GlobalSettings2.xml";
	return path;
}
