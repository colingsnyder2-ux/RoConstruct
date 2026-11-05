// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base
{
    unsigned char storage[32];

    Base(void*, std::string, void*);
    virtual ~Base();
};

struct DuplicateSelectionVerb : Base
{
    bool flag;

    DuplicateSelectionVerb(void*, void*, std::string);
    virtual ~DuplicateSelectionVerb();
};

DuplicateSelectionVerb::DuplicateSelectionVerb(
    void* first, void* second, std::string text)
    : Base(first, text, second)
{
    flag = false;
}
