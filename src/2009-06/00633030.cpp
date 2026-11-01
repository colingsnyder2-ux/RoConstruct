// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Name { std::string name; };
struct Node {
    unsigned int reserved;
    Name* value;
    Node* next;
};
std::string __cdecl format(const char* pattern, ...);
void __cdecl writeString(void* destination, const char* text);
int __cdecl convert(Node** source, void* destination)
{
    Node* node = *source;
    std::string text = format("Enum.%s.%s", node->next->value->name.c_str(), node->value->name.c_str());
    writeString(destination, text.c_str());
    return 1;
}
