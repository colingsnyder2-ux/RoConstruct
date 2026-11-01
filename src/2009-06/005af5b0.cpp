// from server: 100% by EspClaude
// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma optimize("", off)
#pragma strict_gs_check(on)

struct String;
extern void (__thiscall *assignString)(String*, const String&);

struct String {
    unsigned char data[28];
};

struct Base {
    virtual ~Base();
    unsigned char reserved0[8];
    String name;
    unsigned char reserved1[8];
    Base();
};

struct IteratorBase {
    unsigned int link;
    IteratorBase();
    ~IteratorBase();
};

struct Reference {
    void* value;
    Reference();
    ~Reference();
};

struct EmptyState {
    unsigned char data[12];
    EmptyState();
};

struct Holder {
    void* a;
    void* b;
    Holder();
    ~Holder();
};

struct TexturePtr {
    void* object;
    void* control;
    __declspec(dllimport) TexturePtr();
    __declspec(dllimport) ~TexturePtr();
};

struct TextureProxy : Base {
    IteratorBase iterator;
    bool flag;
    void* owner;
    bool option;
    bool option2;
    Reference first;
    Reference second;
    EmptyState state;
    Holder holder;
    TexturePtr texture;

    TextureProxy(void*, const String&, bool);
    virtual ~TextureProxy();
};

TextureProxy::TextureProxy(void* p, const String& s, bool b)
    : Base(),
      iterator(),
      flag(false),
      owner(p),
      option(b),
      option2(false),
      first(),
      second(),
      state(),
      holder(),
      texture()
{
    assignString(&name, s);
}
