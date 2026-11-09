// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
struct Entry { void* key; void* value; };
struct S {
    char pad[0x60];
    std::vector<Entry> entries;
    void* find();
};
void* S::find()
{
    void* result = 0;
    for (unsigned int i = 0; i < 0x2000; ++i) {
        if (result)
            break;
        result = entries[i].value;
    }
    return result;
}
