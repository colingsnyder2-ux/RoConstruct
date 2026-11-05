// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
std::string contentPath(const char* text);
namespace RBX {
static __declspec(noinline) std::string safeChatPath()
{
    return contentPath("Fonts\\safechat.xml");
}
void use(const char* path);
void loadSafeChat()
{
    std::string path = safeChatPath();
    use(path.c_str());
}
}
