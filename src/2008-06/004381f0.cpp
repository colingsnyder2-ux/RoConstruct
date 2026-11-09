// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_brickcolorimports_771dab872f364cbb.cpp

// Candidate translation unit (score above; library headers required).
struct String {
    char* data;

    __declspec(dllimport) String(const char*);
    __declspec(dllimport) String(const String&);
    __declspec(dllimport) ~String() throw();
    __declspec(dllimport) int Compare(const char*) const;
};

extern int __cdecl ConvertColor(String);

struct Item;

typedef void (__thiscall *SetColorFunction)(Item*, int);

struct ItemTable {
    void* reserved[57];
    SetColorFunction setColor;
};

struct Item {
    ItemTable* table;
    char padding[0x108];
    int color;

    void SetValue(String);
    void Update(String);
};

void Item::Update(String value)
{
    if (value.Compare("") != 0) {
        table->setColor(this, ConvertColor(value));
    } else {
        color = -1;
        SetValue(String(""));
    }
}
