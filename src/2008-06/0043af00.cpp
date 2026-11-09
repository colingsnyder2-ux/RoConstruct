// from server: 100% by colin
struct String {
    const char* c_str() const;
};

extern const char* (__thiscall *string_c_str)(const String*);

inline const char* String::c_str() const
{
    return string_c_str(this);
}

struct TextData
{
    char padding[4];
    String text;
};

struct Record
{
    virtual void slot0();
    virtual bool value();
    TextData* data;
};

struct PrimaryInterface
{
    virtual ~PrimaryInterface();
    char padding[0x1c];
};

struct SecondaryInterface
{
    virtual ~SecondaryInterface();
    char padding[0xd8];
    int flag;
    char tail[0x18];
};

struct PropertyItem : PrimaryInterface, SecondaryInterface
{
    PropertyItem(const char*, int, int);
    virtual ~PropertyItem();
    void OnValueChanged(int);
};

struct ItemInterface
{
    ItemInterface(Record*, int);
    virtual ~ItemInterface();
    char padding[0x1c];
};

struct XItem : PropertyItem, ItemInterface
{
    Record* record;

    XItem(Record*, int);
    virtual ~XItem();
};

static TextData* dataOf(Record* source)
{
    return source->data;
}

XItem::XItem(Record* source, int argument)
    : PropertyItem(dataOf(source)->text.c_str(), 0, 0),
      ItemInterface(source, argument),
      record(source)
{
    flag = 1;
    OnValueChanged(source->value());
}
