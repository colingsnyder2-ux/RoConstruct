// from server: 100% by tajop
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);

struct Inner {
    char pad[0x28];
    void** items;
    int count;
};

struct Holder {
    char pad[4];
    Inner* inner;
};

struct Outer {
    char pad0[0xa8];
    void* field_a8;
    char pad1[0x104 - 0xa8 - 4];
    void* field_104;
    Holder* sub_6768c0(void* p);
    void method();
};

void Outer::method()
{
    SendMessageA(field_a8, 0x184, 0, 0);
    void* r = (void*)SendMessageA(field_104, 0x188, 0, 0);
    if (r == (void*)-1)
        return;
    void* r2 = (void*)SendMessageA(field_104, 0x199, (unsigned int)r, 0);
    Holder* h = sub_6768c0(r2);
    if (h == 0)
        return;
    for (int i = 0; i < h->inner->count; i++) {
        Inner* in = h->inner;
        void* item;
        if (i >= 0 && i < in->count)
            item = in->items[i];
        else
            item = 0;
        void* r3 = (void*)SendMessageA(field_a8, 0x18b, 0, 0);
        SendMessageA(field_a8, 0x181, (unsigned int)r3, (long)item);
    }
}
