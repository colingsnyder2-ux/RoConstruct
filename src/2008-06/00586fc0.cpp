// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_localscript_6338c0a25ca9c289.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct String {
    char storage[28];
};

struct Source {
    String text;
    unsigned long value;
};

typedef boost::shared_ptr<void> Shared;

extern bool __cdecl differs(const Source*, const Source*);
extern String& (__thiscall *assignString)(String*, const String&);

struct S {
    char padding[0x138];
    Source source;

    Shared update();
    void notify(const void*);
    void setSource(const Source&);
};

void S::setSource(const Source& input)
{
    Source* current = &source;
    if (differs(current, &input)) {
        assignString(&current->text, input.text);
        current->value = input.value;

        update();

        notify(reinterpret_cast<const void*>(0x975738));
    }
}
