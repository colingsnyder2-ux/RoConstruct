// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct PropertyGridItem {
    char padding[0x128];

    void OnAddChildItem();
    PropertyGridItem* AddChildItem(PropertyGridItem*);
};

struct ComponentItem : PropertyGridItem {
    char data[0x18];

    ComponentItem(void*, void*, int);
};

struct Vector3Item : PropertyGridItem {
    void* first;
    void* second;
    ComponentItem* children[3];

    void OnAddChildItem();
};

void Vector3Item::OnAddChildItem()
{
    PropertyGridItem::OnAddChildItem();
    for (int i = 0; i < 3; ++i) {
        children[i] = new ComponentItem(second, first, i);
        AddChildItem(children[i]);
    }
}
