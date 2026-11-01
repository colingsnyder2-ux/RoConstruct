// from server: 100% by colin
struct String {
    unsigned char unused;
};

extern const char* (__thiscall *string_c_str)(const String*);

struct ItemData {
    unsigned char padding[4];
    String text;
};

struct Item {
    unsigned char padding[4];
    ItemData* data;
};

struct CMemberTreeView {
    void* insertItem(unsigned int, const char*, int, int, unsigned int,
                     unsigned int, unsigned int, void*, void*);
    void setItem(void*, unsigned int, const char*, int, int,
                 unsigned int, unsigned int, Item*);
    void addItem(Item*);
};

void CMemberTreeView::addItem(Item* item)
{
    ItemData* data = item->data;
    const char* text = string_c_str(&data->text);
    void* handle = insertItem(35, text, 10, 10, 0, 0, 0,
                              (void*)0xffff0000, (void*)0xffff0002);
    setItem(handle, 4, 0, 0, 0, 0, 0, item);
}
