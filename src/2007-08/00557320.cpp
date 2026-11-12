// from server: 70% by EspClaude
// from server: 51% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_claude_028251cef1f07129.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 ChatEnter helper: std::string-by-value wrapper (sibling of 005572b0) around a cdecl
// (const std::string&, const std::string&, int, std::string&) converter; codegen analog.
#ifndef _DLL
#define _DLL // the exe calls msvcp80 basic_string members through the IAT (/MD import)
#endif
#include <string>

void convertChatString(const std::string& text, const std::string& part, int flag, std::string& out);

std::string filterChatString(std::string text, std::string source)
{
	std::string result;
	convertChatString(text, std::string(source, 1, 1), 1, result);
	return result;
}
