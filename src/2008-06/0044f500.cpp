// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_publishideliteral21970d0d89d3ee76.cpp

// Candidate translation unit (score above; library headers required).



struct Text;
typedef void (__thiscall *TextDestructor)(Text *);
typedef int (__thiscall *TextValue)(const Text *);

extern TextDestructor destroy_text;
extern TextValue text_value;

struct Text
{
    void *data;
    __declspec(dllimport) ~Text() throw();
    int value() const;
};

inline int Text::value() const
{
    return text_value(this);
}

struct BaseText { void* data; __declspec(dllimport) ~BaseText() throw(); };
extern BaseText __cdecl make_text();
extern Text __cdecl append_text(const BaseText &, const char *);

struct Primary
{
    virtual void primary();
    char padding[112];
};

struct Secondary
{
    virtual void secondary();
};

struct Base : Primary, Secondary
{
    Base(int, int, int);
};

struct CPublishAsPlaceDialog : Base
{
    CPublishAsPlaceDialog(int, int);
    virtual void primary();
    virtual void secondary();
};

CPublishAsPlaceDialog::CPublishAsPlaceDialog(int first, int second)
    : Base(first, append_text(make_text(), "/IDE/Upload.aspx").value(), second)
{
}