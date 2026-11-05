// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)

struct Reference {
    void* value;
    ~Reference();
};

struct Base {
    char storage[0x30];
    ~Base();
};

struct TextureProxy : Base {
    Reference first;
    char padding[0x0c];
    Reference second;
    Reference third;

    ~TextureProxy();
};

TextureProxy::~TextureProxy()
{
}
