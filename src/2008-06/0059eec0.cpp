// from server: 100% by king_originala
extern void *(__thiscall *copyString)(void *, const void *);

struct StringValue
{
    char text[28];
    int value;

    StringValue(const StringValue &source);
};

inline StringValue::StringValue(const StringValue &source)
{
    copyString(text, source.text);
    value = source.value;
}

struct Base
{
    virtual ~Base();
};

struct S : Base
{
    StringValue data;

    S(const StringValue &source);
    virtual ~S();
};

S::S(const StringValue &source) : data(source)
{
}
