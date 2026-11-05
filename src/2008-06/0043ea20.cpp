// from server: 100% by king_originala
struct Button;
typedef void (__thiscall *ButtonAction)(Button*, const char*, int, int);

struct Button {
    ButtonAction* table;
};

extern void* mainTable[];
extern void* secondaryTable[];
extern void* tertiaryTable[];
extern const char browseText[];
extern const char clearText[];

struct Base {
    void** table;
    char padding04[28];
    void** secondary;
    char padding24[160];
    Button* buttons;
    char paddingC8[68];
    void** tertiary;

    Base(const void*, const void*);
    ~Base();
    int getFlags();
    void setFlags(int);
};

struct S : Base {
    S(const void*, const void*);
};

S::S(const void* first, const void* second)
    : Base(first, second)
{
    table = mainTable;
    secondary = secondaryTable;
    tertiary = tertiaryTable;

    setFlags(getFlags() | 4);

    buttons->table[22](buttons, browseText, 0, 0xe101);
    buttons->table[22](buttons, clearText, 1, 0xe120);
}
