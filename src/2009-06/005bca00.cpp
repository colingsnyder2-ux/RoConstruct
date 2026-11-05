// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct Item { int x; };
struct Holder;
void helper(Holder* h, Item* i, int a);
struct Holder {
    int a;
    Item item;
    void f(int v);
};
void Holder::f(int v)
{
    helper(this, &item, v);
}
