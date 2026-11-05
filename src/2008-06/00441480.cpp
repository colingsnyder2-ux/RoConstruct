// from server: 66% by king_originala
struct String;

extern void (__thiscall *CopyString)(String*, const String&);
extern void (__thiscall *DestroyString)(String*);

struct String
{
    char* data;
    String(const String&);
    ~String() throw();
};

__forceinline String::String(const String& value)
{
    CopyString(this, value);
}

__forceinline String::~String() throw()
{
    DestroyString(this);
}

struct Item
{
    typedef int (__thiscall *Getter)(Item*);
    Getter* table;

    void SetValue(String value);
    void Apply(const int& value);
    void Change(String value);
};

void Item::Change(String value)
{
    SetValue(value);
    int result = table[57](this);
    Apply(result);
}
