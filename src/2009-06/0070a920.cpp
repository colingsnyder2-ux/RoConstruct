// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Item { char pad[0xb0]; double value; };
bool lessByValue(const Item* a, const Item* b)
{
    return a->value < b->value;
}
