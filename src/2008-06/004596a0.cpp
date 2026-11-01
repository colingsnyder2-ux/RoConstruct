// from server: 100% by king_originala
extern char* func_0046a580();
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

struct Ref {
    void** vtable;
};

struct Rect {
    long left, top, right, bottom;
};

struct View;

struct Window {
    void** vtable;
    char padding0[28];
    void* handle;
    char padding1[212];
    void* owner;
    Ref* reference;
};

struct Factory {
    Window* create();
};

struct Data {
    char padding[148];
    Ref* reference;
};

struct View {
    char padding0[84];
    Data* data;
    char padding1[88];
    char owner[296];
    Window* window;

    void update();
    void setEnabled(unsigned char enabled, bool notify);
};

void View::setEnabled(unsigned char enabled, bool notify)
{
    if (enabled == static_cast<unsigned char>(window != 0))
        return;

    if (enabled) {
        Window* w = reinterpret_cast<Factory*>(func_0046a580())->create();
        window = w;
        Ref* r = data->reference;

        if (w->reference != r) {
            if (r)
                reinterpret_cast<unsigned long (__stdcall*)(Ref*)>(
                    r->vtable[1])(r);

            Ref* old = w->reference;
            if (old)
                reinterpret_cast<unsigned long (__stdcall*)(Ref*)>(
                    old->vtable[2])(old);

            w->reference = r;
        }

        window->owner = owner;
        Rect rect = { 0, 0, 0, 0 };

        if (!reinterpret_cast<int (__thiscall*)(Window*, const char*,
                const char*, unsigned long, const Rect&, View*,
                unsigned int, void*)>(window->vtable[23])(
                    window, 0, 0, 0x50000000UL, rect, this, 0x413, 0)) {
            window = 0;
            return;
        }

        if (notify)
            SendMessageA(window->handle, 0x364, 0, 0);
    } else {
        reinterpret_cast<int (__thiscall*)(Window*)>(
            window->vtable[26])(window);
        window = 0;
    }

    update();
}
