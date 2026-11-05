// from server: 29% by atomic.potato
struct VGuiObject {
    char pad[0x34];
    int field34;
};

struct EventDesc {
    int method(int, int);
};

int EventDesc::method(int a, int b)
{
    VGuiObject* obj = (VGuiObject*)this;
    if (a != 0) {
        return ((EventDesc*)((char*)obj->field34 + (a - 0x1c)))->method(0, b);
    }
    return ((EventDesc*)((char*)obj->field34 + 0))->method(0, b);
}
