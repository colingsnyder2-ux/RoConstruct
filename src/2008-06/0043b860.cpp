// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct String {
    const char* c_str() const;
};

extern const char* (__thiscall* const string_c_str)(const String*);

inline const char* String::c_str() const
{
    return string_c_str(this);
}

struct Name {
    int unused;
    String text;
};

inline const char* NameText(const Name* n, const Name*) { return n->text.c_str(); }

struct Source {
    virtual void reserved();
    virtual unsigned char value();
    Name* name;
};

struct First {
    virtual ~First();
    char padding[0x1c];
};

struct Second {
    virtual ~Second();
    char padding[0xd8];
    int flag;
    char tail[0xc];
};

struct Base : First, Second {
    Base(const char*, int, int);
    ~Base();
    void OnValueChanged(int);
};

struct Link {
    virtual ~Link();
    char padding[0x1c];
    Link(Source*, int);
};

struct Item : Base, Link {
    Source* source;
    Item(Source*, int);
    virtual ~Item();
};

Item::Item(Source* input, int option)
    : Base(NameText(input->name, input->name), 0, 0),
      Link(input, option),
      source(input)
{
    flag = 1;
    OnValueChanged(input->value());
}