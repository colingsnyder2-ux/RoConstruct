// from server: 100% by colin
extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);

struct CXTColorSelectorCtrl {
    char pad[0x20];
    void* field_20;
    char pad2[0x78 - 0x24];
    int field_78;
    void SetColor(void* color);
};

void CXTColorSelectorCtrl::SetColor(void* color)
{
    int value;
    if (color == 0) {
        value = -1;
    } else {
        value = *(int*)((char*)color + 4);
    }
    field_78 = value;
    InvalidateRect(field_20, 0, 0);
}
