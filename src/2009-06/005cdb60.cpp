// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
class Impl {
public:
	bool has(const char* name);
};
class Wrapper {
	char pad[0x1c];
	Impl* impl;
public:
	bool has(std::string name);
};
bool Wrapper::has(std::string name)
{
	return impl->has(name.c_str());
}
