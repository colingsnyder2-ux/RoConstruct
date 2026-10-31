// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct Elem;
struct Holder;
void initHolder(Holder* self, const Holder& other);
struct Holder {
    Elem* data;
    Holder(const Holder& other);
};
Holder::Holder(const Holder& other)
{
    initHolder(this, other);
}
