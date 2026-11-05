// from server: 34% by atomic.potato
struct Elem {
    char pad[0x20];
    int key;
};

struct Arr {
    char pad[0x20];
    Elem* data;
};

extern "C" void __fastcall sub_7007B0(Elem* dst, Elem* src);

void __fastcall sub_72BD20(Arr* arr, int unused, int count, int value) {
    int i = (count - 1) / 2;
    int saved = 0;
    while (i >= 0) {
        Elem* child = (Elem*)((char*)arr + 0x20 + i * 0x28);
        if (child->key <= value) break;
        Elem* parent = (Elem*)((char*)arr + 0x20 + count * 0x28);
        sub_7007B0(parent, child);
        parent->key = child->key;
        count = i;
        i = (i - 1) / 2;
    }
    Elem* slot = (Elem*)((char*)arr + 0x20 + count * 0x28);
    sub_7007B0(slot, (Elem*)&saved);
    slot->key = value;
}
