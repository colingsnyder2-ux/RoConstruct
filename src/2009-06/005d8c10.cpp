// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
static inline bool isHttp(const std::string& s) { return s.find("http://") == 0 || s.find("https://") == 0; }
static inline bool isAsset(const std::string& s) {  }
bool isUrl(const std::string& s)
{
if (isHttp(s)) return true; bool r = s.find("rbxasset://") == 0; return r;
}
