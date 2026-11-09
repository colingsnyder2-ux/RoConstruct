// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_captionemptyfallback4ba4fd27241a52ef.cpp

// Candidate translation unit (score above; library headers required).

struct Str;
extern bool (__thiscall* str_empty)(const Str*);
extern Str* (__thiscall* str_text)(Str*, const char*);
extern Str* (__thiscall* str_copy)(Str*, const Str*) throw();
extern void (__thiscall* str_destroy)(Str*) throw();

struct Str {
    char* data;
    __declspec(dllimport) Str(const char*);
    __declspec(dllimport) Str(const Str&);
    __declspec(dllimport) ~Str() throw();
    bool empty() const;
};

inline bool Str::empty() const
{
    return str_empty(this);
}

struct ParentStr : Str { __declspec(dllimport) ~ParentStr() throw(); };
struct X {
    ParentStr copy();
};

struct S {
    char padding[0xec];
    Str caption;
    char padding2[0x6c];
    X* parent;
    Str getCaption();
};

Str S::getCaption()
{
    return !caption.empty()
        ? caption
        : (parent ? static_cast<const Str&>(parent->copy()) : static_cast<const Str&>(Str("")));
}