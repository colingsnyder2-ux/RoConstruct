// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared-rtm roc_espeon_replaceangleimportcast4a016e70e72eb016.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<atlsimpstr.h>, <roc_espeon_mfcimportedstringcastfb14fe2507201232.cpp>)
#pragma include_alias("atlsimpstr.h", "roc_espeon_mfcimportedstringcastfb14fe2507201232.cpp")
#include <afxwin.h>
extern CString findText;
extern CString replaceText;
extern int searchFlags;
extern int searchDirection;
extern int searchMode;
extern int searchOption;

struct Control {
    int setSelection(int, int, int);
    int setReadOnly(int, int);
    int replaceSelection(const char*, int);
};

struct View;

typedef int (__thiscall *FallbackCall)(
    View*, const char*, int, int, int, int, int);
typedef int (__thiscall *SearchCall)(
    View*, const char*, int, int, int, int);

struct ViewTable {
    void* preceding[106];
    FallbackCall fallback;
    void* intermediate[2];
    SearchCall search;
};

struct View {
    ViewTable* table;
    char padding[84];
    Control control;

    void replaceAll(const char*, const char*, int, int, int);
};

void View::replaceAll(const char* find, const char* replacement,
                      int flags, int mode, int option)
{
    findText=find;
    replaceText=replacement;
    searchFlags = flags;
    searchMode = mode;
    searchDirection = 1;
    searchOption = option;

    CWaitCursor guard;

    control.setSelection(0, 0, 1);
    control.setReadOnly(1, 0);

    int found = 0;
    if (table->search(this, (LPCTSTR)findText, searchDirection,
                      flags, mode, option)) {
        found = 1;
        do {
            control.replaceSelection((LPCTSTR)replaceText, 1);
        } while (table->search(this, (LPCTSTR)findText,
                               searchDirection, flags, mode, option));
    }

    control.setReadOnly(0, 0);
    if (!found)
        table->fallback(this, (LPCTSTR)findText, searchDirection,
                        flags, mode, option, 1);
}