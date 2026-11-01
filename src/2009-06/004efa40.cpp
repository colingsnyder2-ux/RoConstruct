// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { namespace Stats {
struct Value { int lo; int hi; };
struct Priorities { Value system, high, medium, low; };
class Item {
public:
    Item* createChildItem(const char* name);
    void createBoundItem(const char* name, const Value& v);
    void addPriorities(const char* name, const Priorities& p);
};
void Item::addPriorities(const char* name, const Priorities& p)
{
    Item* item = createChildItem(name);
    item->createBoundItem("SYSTEM_PRIORITY", p.system);
    item->createBoundItem("HIGH_PRIORITY", p.high);
    item->createBoundItem("MEDIUM_PRIORITY", p.medium);
    item->createBoundItem("LOW_PRIORITY", p.low);
}
}}
