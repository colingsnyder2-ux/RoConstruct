// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_historyiteratorcopy_1d0e289ac2ce8df7.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
struct String;
extern void (__thiscall *string_construct)(String *, const char *);
extern void (__cdecl *invalid_parameter_noinfo)();

struct String {
    unsigned int proxy;
    char storage[16];
    unsigned int length;
    unsigned int capacity;

    String(const char *text);
    ~String();
};

inline String::String(const char *text) {
    string_construct(this, text);
}

struct Exception {
    virtual ~Exception();
    char *message;
    int owned;
};

struct RuntimeError : Exception {
    String text;
    RuntimeError(const String &);
    ~RuntimeError();
};

struct Change{void unplay();};
struct RestoreFlag{bool* flag;bool previous;RestoreFlag(bool& v):flag(&v),previous(v){v=true;}~RestoreFlag(){*flag=previous;}};
struct S{char padding[0x138];std::list<Change*> history;std::list<Change*>::iterator saved,current;bool playing,enabled;void unplay();};
void S::unplay(){if(playing)throw RuntimeError(String("ChangeHistoryService is currently playing"));if(!enabled)throw RuntimeError(String("ChangeHistoryService is disabled"));if(current==history.begin())throw RuntimeError(String("Attempt to unplay before the change history"));RestoreFlag restore(playing);(*current)->unplay();saved=current;--current;}
