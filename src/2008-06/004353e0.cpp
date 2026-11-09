// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_declaration_43798f06cec7c1c4.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Item {
    char padding[0x130];
    unsigned char enabled;
    unsigned char requiresFirst;
    unsigned char requiresSecond;
};

struct Settings {
    char padding[0x130];
    unsigned char first;
    unsigned char second;
};

struct String { __declspec(dllimport) const char* c_str() const; };



struct Text {
    char padding[4];
    String value;
};

struct Argument {
    int unused;
    boost::shared_ptr<Text> text;
    int identifier;
};

struct Service {
    Item* __thiscall lookup(Argument*);
};

typedef boost::shared_ptr<Service> Shared;

Shared __cdecl getService();
Settings* __cdecl getSettings();

struct CDeclarationView {
    char padding[0xa8];
    unsigned char acceptAll;
    char alignment[3];
    int identifier;

    void __thiscall f(Argument*);
    void* __thiscall insert(int, const char*, int, int, int, int, int,
                           unsigned long, unsigned long);
    void __thiscall configure(void*, int, int, int, int, int, int, Argument*);
    void __thiscall finish(void*, Item*);
};

void CDeclarationView::f(Argument* argument)
{
    if (!acceptAll && argument->identifier != identifier)
        return;

    Item* item = getService().get()->lookup(argument);

    if (item) {
        Settings* settings = getSettings();
        if (item->requiresFirst && !settings->first)
            return;
        if (item->requiresSecond && !settings->second)
            return;
        if (!item->enabled)
            return;
    }

    const char* text = argument->text->value.c_str();
    void* entry = insert(0x23, text, 8, 8, 0, 0, 0,
                         0xffff0000UL, 0xffff0002UL);
    configure(entry, 4, 0, 0, 0, 0, 0, argument);
    finish(entry, item);
}
