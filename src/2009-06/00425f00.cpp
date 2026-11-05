// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <utility>
struct Holder
{
    virtual ~Holder();
    virtual void type() const = 0;
    virtual Holder* clone() const = 0;
};
struct Any {
    Holder* content;
    Any(const Any& o) : content(o.content ? o.content->clone() : 0) {}
    ~Any() { delete content; }
    Any& swap(Any& r) { std::swap(content, r.content); return *this; }
    Any& operator=(Any r) { r.swap(*this); return *this; }
};
struct Element
{
    int first;
    Any second;
};
Element* __cdecl copy_backward(Element* first, Element* last, Element* result)
{
    while (first != last)
        *--result = *--last;
    return result;
}
