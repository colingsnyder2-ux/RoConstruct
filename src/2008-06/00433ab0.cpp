// from server: 100% by king_originala
// from server: 82% by colin
typedef void* HANDLE;

extern "C" __declspec(dllimport) HANDLE __stdcall LoadBitmapA(HANDLE, const char*);
extern "C" HANDLE __stdcall FindResourceModule(const char*, const char*);

struct GdiObject
{
    HANDLE handle;

    GdiObject() : handle(0) {}
    virtual ~GdiObject() { release(); }

    int attach(HANDLE);
    void release();
};

struct Bitmap : GdiObject {};

struct Point { int x, y; Point(int a, int b) : x(a), y(b) {} };
extern "C" int __cdecl PrepareBitmap(Bitmap*, Point);

struct ImageManager
{
    void install(HANDLE, HANDLE, int);
};

struct ModuleState
{
    unsigned char padding[0x94];
    ImageManager** manager;
};

extern "C" ModuleState* __cdecl GetModuleState();

struct S
{
    void* vtable;
    HANDLE handle;

    int create(int, int, unsigned int, int, int);
    int f(unsigned short);
};

static __declspec(noinline) int createBitmap(S* self, unsigned short resource)
{
    if (!self->create(16, 16, 0x19, 0, 1))
        return 0;

    Bitmap bitmap;
    bitmap.attach(LoadBitmapA(
        FindResourceModule((const char*)(unsigned int)resource,
                           (const char*)2),
        (const char*)(unsigned int)resource));

    int value = PrepareBitmap(&bitmap, Point(0, 0));
    HANDLE imageList = self->handle;
    (*GetModuleState()->manager)->install(imageList, bitmap.handle, value);
    return 1;
}

int invoke(S* self, unsigned short resource) { return createBitmap(self, resource); }
