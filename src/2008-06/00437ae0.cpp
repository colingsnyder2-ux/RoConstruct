// from server: 100% by colin
struct String;
typedef const String& (__thiscall *PrepareProc)(String*, int, int);
typedef void (__thiscall *DestroyProc)(String*);
typedef void (__thiscall *AssignProc)(void*, const String*);

extern PrepareProc prepareString;
extern DestroyProc destroyString;
extern AssignProc assignString;
extern char primaryTable[];
extern char secondaryTable[];

struct String
{
    void* data;
    String(const String&);
    __declspec(dllimport) ~String() throw();
};



String __cdecl makeValue(int);

struct Binding
{
    char data[100];
};

struct Base
{
    Base(const String&);
    ~Base();
    void setValue(String);

    void* primaryTable;
    char reserved04[28];
    void* secondaryTable;
    char reserved24[104];
    int type;
    char reserved90[20];
    String value;
    Binding binding;
};

struct S : Base
{
    int color;
    S(String caption, int colorValue);
};

S::S(String caption, int colorValue)
    : Base(prepareString(&caption, colorValue, 0))
{
    primaryTable = ::primaryTable;
    secondaryTable = ::secondaryTable;
    type = 4;
    color = colorValue;
    setValue(makeValue(colorValue));
    assignString(&binding, &value);
}
