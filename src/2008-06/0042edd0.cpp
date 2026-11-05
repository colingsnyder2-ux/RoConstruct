// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_wrappercleanup_feb62d084056a8f7.cpp

// Candidate translation unit (score above; library headers required).
struct String {
    char storage[28];
    ~String() throw();
    const char *c_str() const;
};

struct Format {
    char storage[4];
    Format();
    __declspec(dllimport) ~Format() throw();
    const char *text() const;
};

extern void (__thiscall *string_destroy)(String *);
extern const char *(__thiscall *string_c_str)(const String *);
extern void (__thiscall *format_construct)(Format *);
extern void (__thiscall *format_destroy)(Format *);
extern const char *(__thiscall *format_text)(const Format *);
extern void (__cdecl *format_print)(Format *, const char *, ...);

String::~String() throw()
{
    string_destroy(this);
}

const char *String::c_str() const
{
    return string_c_str(this);
}

Format::Format()
{
    format_construct(this);
}

const char *Format::text() const
{
    return format_text(this);
}

extern unsigned int texture_count;
extern String __cdecl sub_5a6bc0(unsigned int);

struct Target;
typedef void (__thiscall *TargetMethod)(Target *, const char *);

struct Target {
    TargetMethod *vtable;
};

struct CWrapperView {
    void func_42edd0(Target *);
};

void CWrapperView::func_42edd0(Target *target)
{
    String value = sub_5a6bc0(texture_count);
    Format output;
    format_print(&output, "TEX %s", value.c_str());
    TargetMethod *table = target->vtable;
    const char *text = output.text();
    table[3](target, text);
}
