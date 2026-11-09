// from server: 100% by colin
struct String;

typedef void (__thiscall *StringInit)(String*);
typedef void (__thiscall *StringDestroy)(String*);
typedef int (__thiscall *StringCompare)(const String*, const char*);
typedef const char* (__thiscall *StringData)(const String*);
typedef int (__cdecl *Atoi)(const char*);

extern StringInit stringInit;
extern StringDestroy stringDestroy;
extern StringCompare stringCompare;
extern StringData stringData;
extern Atoi atoi;
extern char propertyName[];
extern char emptyText[];

struct String
{
    void* data;
    String();
    __declspec(dllimport) void __thiscall destroyImport() throw();
    __declspec(nothrow) ~String();
    int compare(const char*) const;
    const char* text() const;
};

__forceinline String::String()
{
    stringInit(this);
}

__declspec(nothrow) __forceinline String::~String()
{
    this->destroyImport();
}

__forceinline int String::compare(const char* value) const
{
    return stringCompare(this, value);
}

__forceinline const char* String::text() const
{
    return stringData(this);
}

struct Dialog;
typedef void (__thiscall *DialogAction)(Dialog*);

struct DialogTable
{
    DialogAction preceding[88];
    DialogAction accept;
    DialogAction cancel;
};

struct Dialog
{
    DialogTable* table;
    void getProperty(const char*, unsigned long, String*, int);
    void handle(void*, long*);
};

void Dialog::handle(void*, long* result)
{
    *result = -1;
    String value;
    getProperty(propertyName, 0x800113EDUL, &value, 1);

    if (value.compare(emptyText) && atoi(value.text()) == 1)
        table->accept(this);
    else
        table->cancel(this);
}
