// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were provided, so the layout below is a minimal stand-in.
// The primary vptr is at +0 and a secondary base with its own vptr sits at +0x74.
// The code at 0x45fef0 is the compiler-generated scalar deleting destructor, so it is
// produced from the user-declared virtual destructor, not written out by hand.

struct CRobloxDHtmlDialogBase0 {
    virtual void vf0() {}
    char pad[0x74 - 4];
};

struct CRobloxDHtmlDialogBase1 {
    virtual void vf1() {}
};

class CRobloxDHtmlDialog : public CRobloxDHtmlDialogBase0, public CRobloxDHtmlDialogBase1 {
public:
    CRobloxDHtmlDialog() {}
    virtual ~CRobloxDHtmlDialog(); // defined elsewhere (0x401050)
};

class CSaveToRobloxDialog : public CRobloxDHtmlDialog {
public:
    CSaveToRobloxDialog();
    virtual ~CSaveToRobloxDialog();
};

CSaveToRobloxDialog::CSaveToRobloxDialog() {}

CSaveToRobloxDialog::~CSaveToRobloxDialog() {}
