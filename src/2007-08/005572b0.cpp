// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// 2007-08: std::string-by-value wrapper around a cdecl (const std::string&, std::string&) converter.
#include <string>
void convertChatString(const std::string& in, std::string& out);
std::string filterChatString(std::string text)
{
	std::string result;
	convertChatString(text, result);
	return result;
}
