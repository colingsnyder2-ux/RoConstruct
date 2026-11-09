// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Name { public: static const Name& declare(const char*); };
struct Guid { static void generateGUID(std::string&); };
static const Name* localScope;
void initLocalScope()
{
    std::string guid;
    Guid::generateGUID(guid);
    localScope = &Name::declare(guid.c_str());
}
}
