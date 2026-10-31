// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Item_005f9b20;
struct Holder_005f9b20 { int a; Item_005f9b20* item; };
class EnumDescriptor_005f9b20 {
public:
    bool isA(const Item_005f9b20* item) const;
    bool isA(const Holder_005f9b20* h) const;
};
bool EnumDescriptor_005f9b20::isA(const Holder_005f9b20* h) const
{
    const Item_005f9b20* item = h->item;
    return isA(item);
}
