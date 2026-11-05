// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)

struct Handle {
    void* value;
    ~Handle();
    Handle& operator=(const Handle&);
};

Handle __cdecl makeHandle(void*, void*, void*);

struct TextureProxy {
    char padding[0x1c];
    char first[0x10];
    Handle handle;
    char second[0xc0];
    char third;

    void update();
};

void TextureProxy::update()
{
    handle = makeHandle(&third, second, first);
}
