// from server: 100% by colin
struct String {
    const char *c_str() const;
};

extern const char *(__thiscall *string_c_str)(const String *);

inline const char *String::c_str() const {
    return string_c_str(this);
}

struct PropertyData {
    unsigned long reserved;
    String text;
};

struct Property {
    virtual ~Property();
    virtual bool getValue();
    PropertyData *data;
};

inline const char *NameText(const PropertyData *n, const PropertyData *) { return n->text.c_str(); }

struct Primary {
    virtual ~Primary();
    char padding[0x1c];
};

struct Secondary {
    virtual ~Secondary();
};

struct GridItem : Primary, Secondary {
    char padding[0xd8];
    int flag;
    char tail[0x0c];

    GridItem(const char *, int, int);
    virtual ~GridItem();
    void SetValue(int);
};

struct Item {
    virtual ~Item();
    char padding[0x1c];

    Item(Property *, int);
};

struct EnumItem : GridItem, Item {
    Property *property;

    EnumItem(Property *, int);
    virtual ~EnumItem();
};

EnumItem::EnumItem(Property *value, int argument)
    : GridItem(NameText(value->data, value->data), 0, 0),
      Item(value, argument)
{
    flag = 1;
    property = value;
    SetValue(value->getValue());
}
