// from server: 100% by king_originala
typedef unsigned short WORD;
typedef unsigned int UINT;

extern "C" {
extern void* (__stdcall *FindResourceA)(void*, const char*, const char*);
extern void* (__stdcall *LoadResource)(void*, void*);
extern void* (__stdcall *LockResource)(void*);
extern int (__stdcall *FreeResource)(void*);
}

extern void* __stdcall FindResourceModule(const char*, const char*);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);

struct Controls
{
    void Clear();
};

struct ToolbarResource
{
    WORD version;
    WORD width;
    WORD height;
    WORD count;
};

static __declspec(noinline) WORD* Items(ToolbarResource* data)
{
    return (WORD*)(data + 1);
}

struct Size
{
    int cx;
    int cy;
    Size(int, int);
};

inline Size::Size(int x, int y)
{
    cx = x;
    cy = y;
}

struct Images
{
    int Load(UINT, UINT*, int, Size, int);
};

struct CommandBar
{
    char padding0[0xfc];
    Controls* controls;
    char padding1[0x0c];
    Size dimensions;

    int SetButtons(UINT*, int);
    Images* GetImages();
    int LoadToolbar(UINT, int);
};

int CommandBar::LoadToolbar(UINT id, int loadImages)
{
    UINT resourceId = (WORD)id;
    controls->Clear();

    if (!resourceId)
        return 0;

    void* module = FindResourceModule((const char*)resourceId,
                                     (const char*)241);
    if (!module)
        return 0;

    void* resource = FindResourceA(module, (const char*)resourceId,
                                  (const char*)241);
    if (!resource)
        return 0;

    void* handle = LoadResource(module, resource);
    if (!handle)
        return 0;

    ToolbarResource* data = (ToolbarResource*)LockResource(handle);
    if (!data)
        return 0;

    UINT* buttons = new UINT[data->count];
    int i = 0;
    if ((WORD)i < data->count)
    {
        WORD* items = Items(data);
        do
        {
            buttons[i] = items[i];
            ++i;
        } while (i < data->count);
    }

    int result = SetButtons(buttons, data->count);

    if (loadImages)
    {
        Images* images = GetImages();
        if (!images->Load(id, buttons, data->count,
                          Size(data->width, data->height), 0))
            result = 0;

        if (data->width != 16)
            dimensions = Size(data->width, data->height);
    }

    delete[] buttons;
    FreeResource(handle);
    return result;
}
