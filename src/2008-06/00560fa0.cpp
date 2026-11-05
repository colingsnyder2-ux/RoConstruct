// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_fb5f53f9882dbe52.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
#include <vector>
namespace RBX {
class Name { public: static const Name& getNullName(); };
class ContentId
{
	std::string id;
	const Name* mimeTypePtr;
public:
	ContentId() : id(), mimeTypePtr(&Name::getNullName()) {}
};
class ContentList
{
public:
	ContentId id;
	std::vector<int> items;
	ContentList();
};
ContentList::ContentList() {}
}
