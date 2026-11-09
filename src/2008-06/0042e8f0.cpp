// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_captionthirdnative035b4b9d7643926e.cpp

// Candidate translation unit (score above; library headers required).
struct String;

extern bool (__thiscall *stringEmpty)(const String *);
extern String *(__thiscall *stringFromText)(String *, const char *);
extern String *(__thiscall *stringCopy)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);

struct String {
    void *data;

    __declspec(dllimport) String(const char *);
    __declspec(dllimport) String(const String &);
    __declspec(dllimport) ~String() throw();
    bool empty() const;
};

inline bool String::empty() const {
    return stringEmpty(this);
}

struct ProviderString : String { __declspec(dllimport) ~ProviderString() throw(); };
struct Provider {
    ProviderString getText();
};

struct S {
    char padding0[0xd8];
    String primary;
    String secondary;
    char padding1[0x7c];
    Provider *provider;

    String getText();
};

String S::getText() {
    return !secondary.empty() ? secondary :
           !primary.empty() ? primary :
           provider ? static_cast<const String&>(provider->getText()) : static_cast<const String&>(String(""));
}