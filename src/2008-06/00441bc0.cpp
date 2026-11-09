// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_soundimportconversion_764afbe1fa502256.cpp

// Candidate translation unit (score above; library headers required).
#include <fstream>


struct Text;
struct String;
struct FileStorage;

extern void (__thiscall *textConstruct)(Text *);
extern void (__thiscall *textDestroy)(Text *) throw();
extern void (__thiscall *textLoad)(Text *, int);
extern const char *(__thiscall *textConvert)(Text *, int, int, int);
extern const char *(__thiscall *textChars)(Text *);
extern FileStorage *(__thiscall *fileConstruct)(FileStorage *, const char *);
extern void (__thiscall *stringCopy)(String *, const String *);
extern void (__thiscall *stringDestroy)(String *);

struct Text {
    unsigned char data[4];
    Text();
    ~Text() throw();
    __declspec(dllimport) operator const char*() const;
    void load(int);
    const char *convert(int, int, int);
};

struct FilterText {
    unsigned char data[4];
    FilterText() { textConstruct((Text *)this); }
    __declspec(dllimport) ~FilterText() throw();
    void load(int id) { textLoad((Text *)this, id); }
    const char *convert(int a, int b, int c) { return textConvert((Text *)this, a, b, c); }
};

struct String {
    unsigned char data[28];
    String(const String &);
    ~String();
};

typedef std::ifstream InputFile;

struct RawPayload {
    String text;
    int value;
};

struct Payload {
    String text;
    int value;
    Payload(const RawPayload &);
};

struct DialogStorage {
    unsigned char data[468];
    DialogStorage(int, const char *, const char *, unsigned int, const char *);
};

struct Dialog {
    unsigned char padding[12];
    DialogStorage storage;
    Dialog(int, const char *, const char *, unsigned int, const char *);
    ~Dialog();
    int run();
    Text filename();
};

struct Related {
    void prepare();
};

struct Owner {
    unsigned char padding[0x198];
    Related *related;
};

struct SoundItem {
    unsigned char padding[0x128];
    Owner *owner;
    void accept(const Payload &);
    void f();
};

extern const char *__cdecl makeType(const char *, int);
extern RawPayload __cdecl readFile(const InputFile &, const char *);

inline Text::Text() {
    textConstruct(this);
}

inline Text::~Text() throw() {
    textDestroy(this);
}

inline void Text::load(int id) {
    textLoad(this, id);
}

inline const char *Text::convert(int a, int b, int c) {
    return textConvert(this, a, b, c);
}

inline String::String(const String &other) {
    stringCopy(this, &other);
}

inline String::~String() {
    stringDestroy(this);
}

inline Payload::Payload(const RawPayload &other)
    : text(other.text), value(other.value) {
}

inline Dialog::Dialog(int a, const char *b, const char *c,
                      unsigned int d, const char *e)
    : storage(a, b, c, d, e) {
}

void SoundItem::f() {
    FilterText filter;
    filter.load(0x86);
    Dialog dialog(1, 0, 0, 0, filter.convert(0, 0, 1));
    if (dialog.run() == 1) {
        if (owner->related)
            owner->related->prepare();

        Payload result(
            readFile(
                InputFile(dialog.filename(), 0x21, 0x40),
                makeType("audio/x-wav", -1)));
        accept(result);
    }
}