// from server: 100% by Yeetserama
// hypothesis: 0042efb0 is the TEX twin of exact 0042eee0 (VAR).
// Only the format literal differs; reuse the verified codegen analog.
// copied from an identical function in another client (function ?func_42ed20@ns_ROCX000003@@YGXPAUOutput@1@@Z)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
struct String {
    char storage[28];
    ~String();
    const char *c_str() const;
};

struct Text {
    char storage[4];
    Text();
    __declspec(dllimport) ~Text() throw();
    const char *c_str() const;
};

extern void (__thiscall *destroyString)(String *);
extern const char *(__thiscall *stringData)(const String *);
extern void (__thiscall *constructText)(Text *);
extern void (__thiscall *destroyText)(Text *);
extern const char *(__thiscall *textData)(const Text *);
extern void (__cdecl *formatText)(Text *, const char *, ...);

inline String::~String()
{
    destroyString(this);
}

inline const char *String::c_str() const
{
    return stringData(this);
}

inline Text::Text()
{
    constructText(this);
}

inline const char *Text::c_str() const
{
    return textData(this);
}

extern unsigned int count;
extern String __cdecl formatCount(unsigned int);

struct Output;

struct OutputTable {
    char reserved[12];
    void (__thiscall *write)(Output *, const char *);
};

struct Output {
    OutputTable *table;
};

void __stdcall func_42ed20(Output *output)
{
    String value = formatCount(count);
    Text text;
    formatText(&text, "TEX %s", value.c_str());
    OutputTable *t = output->table;
    t->write(output, text.c_str());
}
}
