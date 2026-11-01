// from server: 100% by colin
struct Text {
    const char* c_str() const;
};

extern const char* (__thiscall* text_c_str)(const Text*);

inline const char* Text::c_str() const
{
    return text_c_str(this);
}

struct TextOwner {
    int padding;
    Text text;
};

struct Source {
    virtual ~Source();
    virtual bool value();
    TextOwner* text;
};

inline const char *NameText(const TextOwner *n, const TextOwner *) { return n->text.c_str(); }

struct Primary {
    virtual ~Primary();
    char padding[0x1c];
};

struct Secondary {
    virtual ~Secondary();
    char padding[0xd8];
    int state;
    char tail[0x14];
};

struct ItemBase : Primary, Secondary {
    ItemBase(const char*, int, int);
    virtual ~ItemBase();
    void OnValueChanged(int);
};

struct Attachment {
    Attachment(Source*, int);
    virtual ~Attachment();
    char padding[0x1c];
};

struct Item : ItemBase, Attachment {
    Item(Source*, int);
    virtual ~Item();
    Source* source;
};

Item::Item(Source* object, int argument)
    : ItemBase(NameText(object->text, object->text), 0, 0),
      Attachment(object, argument)
{
    state = 1;
    source = object;
    OnValueChanged(object->value());
}
