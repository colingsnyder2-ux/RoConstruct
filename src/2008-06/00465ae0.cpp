// from server: 100% by king_originala
extern "C" void *(__stdcall *LoadCursorA)(void *, const char *);
extern const char *__stdcall RegisterWindowClass(
    unsigned int, void *, void *, void *);

struct CreateInfo {
    char reserved[0x20];
    unsigned int style;
    const char *name;
    const char *className;
};

struct S {
    int BasePreCreateWindow(CreateInfo *);
    int PreCreateWindow(CreateInfo *);
};

int S::PreCreateWindow(CreateInfo *info)
{
    const char *className = RegisterWindowClass(
        8, LoadCursorA(0, (const char *)0x7f00), 0, 0);
    info->style |= 0x06000000;
    info->className = className;
    return BasePreCreateWindow(info);
}
