// from server: 100% by EspClaude
// from server: 69% by colin
// roc 2008-06 00442140  unit: TextureItem  size: 295 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442140
//
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <vector>
struct Elem { int x; };
struct Value : std::vector<Elem> {
    Value() {}
    Value(const Value&);
    ~Value();
};

Value& lookup(std::map<unsigned int, Value>& m, const unsigned int& k)
{
    return m[k];
}
