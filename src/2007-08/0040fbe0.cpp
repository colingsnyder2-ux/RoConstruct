// from server: 82% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: ogre-1.7.0 roc_claude_35765e1ccb24507a.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _DLL
#define _DLL // /MD: the exe calls msvcp80 basic_string members through the IAT
#endif
// 2007-08: std::_Uninit_fill_n for a 0x24-byte element {std::string; 2 dwords at 0x1c/0x20}
// (element size from 'add esi, 0x24'; string copy ctor through the msvcp80 IAT; dword copies at 0x1c/0x20).
#include <string>
#include <vector>
struct NameRule
{
	std::string pattern;
	int value1;
	int value2;
};
template class std::vector<NameRule>;
