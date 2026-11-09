// from server: 100% by Yeetserama
// from server: 100% by Espeon
// from server: 91% by colin
struct CXTPPropertyGridItem {
    char reserved00[0x1c];
    void* items[3];

    void setValue(void* value);
};

struct Vector3Item : CXTPPropertyGridItem {
    void setValue(void* value);
};

void Vector3Item::setValue(void* value)
{
    CXTPPropertyGridItem::setValue(value);
    for (int i = 0; i < 3; ++i) {
        if (items[i] != 0) {
            void** vtable = *(void***)((char*)items[i] + 0x100);
            ((void (__thiscall*)(void*, void*))vtable[0])((char*)items[i] + 0x100, value);
        }
    }
}

