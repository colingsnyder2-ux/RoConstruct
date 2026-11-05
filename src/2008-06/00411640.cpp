// from server: 100% by king_originala
extern "C" {
    extern void* (__stdcall *CreateSolidBrush)(unsigned long color);
    extern long (__stdcall *SendMessageA)(void* window, unsigned int message,
                                         unsigned int wparam, long lparam);
}

struct Handle {
    void* reserved;
    void* handle;
    void Attach(void* value);
};

struct PaintManager {
    char padding[0xf8];
    Handle font;
};

extern PaintManager* paintManager;
extern void* resource;
void __cdecl InitializePaintManager(int);

struct CBrush {
    char padding0[0x20];
    void* window;
    char padding1[0x70];
    Handle brush;

    int BaseInitialize(void* argument);
    void SetResource(void* value);
    int Initialize(void* argument);
};

int CBrush::Initialize(void* argument)
{
    brush.Attach(CreateSolidBrush(0x404040));

    int result = BaseInitialize(argument);
    if (result == -1)
        return result;

    if (!paintManager)
        InitializePaintManager(0);

    Handle* font = &paintManager->font;
    void* fontHandle = font;
    if (font)
        fontHandle = font->handle;

    SendMessageA(window, 0x30, (unsigned int)fontHandle, 1);
    SetResource(resource);
    return 0;
}
