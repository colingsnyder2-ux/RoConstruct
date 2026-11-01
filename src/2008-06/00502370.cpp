// from server: 100% by king_originala
struct Item;
struct RenderDevice {
    void setTransform(const Item*);
    void setValue(double);
};

struct Drawable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void draw(RenderDevice*);
};

struct Item {
    char padding[0x34];
    Drawable* drawable;
    float value;
    void* data;
};

extern void finish(void*, RenderDevice*);

struct S {
    char padding[0x274];
    Item** items;
    int count;
    void draw(RenderDevice*);
};

void S::draw(RenderDevice* device)
{
    __declspec(align(64)) char scratch[64];

    for (int i = count - 1; i >= 0; --i) {
        Item* item = items[i];
        device->setTransform(item);
        device->setValue(item->value);
        item->drawable->draw(device);
        finish(item->data, device);
    }
}
