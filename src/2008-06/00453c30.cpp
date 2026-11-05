// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_unit_10b9dcc0d5db3c98.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <string>
#include <sstream>
#include <memory>
#include <intrin.h>
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);
typedef long LRESULT;
class CWnd;

template<class E> struct ImpStr : std::basic_string<E> {
    __declspec(noinline) const E* c_str() const { return std::basic_string<E>::c_str(); }
    __declspec(noinline) ImpStr& operator=(const std::basic_string<E>& r) { std::basic_string<E>::operator=(r); return *this; }
};
extern template struct __declspec(dllimport) ImpStr<char>;
static inline const char* cstr(const std::string& x) { return static_cast<const ImpStr<char>&>(x).c_str(); }

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    __forceinline void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    __forceinline shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
    T* get() const { return px; }
};

struct CStringRef {
    char* m_pszData;
    __declspec(dllimport) operator const char*() const throw();
    __declspec(dllimport) ~CStringRef() throw();
};

namespace RBX {
class StandardOut {
public:
    static shared_ptr<StandardOut> __cdecl singleton();
    void print(int type, const char* format, ...);
};
class ContentId {
public:
    ContentId(const std::string& id);
private:
    std::string id;
    const void* mimeTypePtr;
};
class ContentProvider {
public:
    static bool __cdecl isUrl(const std::string& s);
    std::auto_ptr<std::istream> getContent(ContentId ticket);
};
class DataModel { public: ContentProvider* contentProvider(); };
inline ContentProvider* contentProvider(DataModel* dm) { return dm ? dm->contentProvider() : 0; }
void __cdecl copyStream(std::istream&, std::ostream&, int);
struct Lock { Lock(shared_ptr<DataModel> dm); ~Lock(); int a, b, c; };
class ScriptContext { public: void executeInNewThread(int identity, const char* script, const char* name); };
class ScriptHost { public: ScriptContext* getScriptContext(); };
class ScriptSource { public: shared_ptr<ScriptHost> get(); };
}

struct Window {
    char pad[0x20]; void* handle; CWnd* SetFocus();
    int InsertString(int nIndex, const char* item) { return (int)SendMessageA(handle, 0x181, nIndex, (long)item); }
    int GetCount() const { return (int)SendMessageA(handle, 0x18b, 0, 0); }
    void SetSel(int start, int end) { SendMessageA(handle, 0xb1, start, end); }
};
typedef int (__thiscall *FindEntry)(void*, int, const char*);
struct SearchObject { FindEntry* table; };
typedef void (__thiscall *EnableEntry)(void*, int);
struct ComboControl {
    EnableEntry* table;
    char pad[0xfc - 4];
    int type;
    int getType() const { return type; }
    char pad2[0x178 - 0x100];
    Window* list;
    char gap[8];
    Window* edit;
    CStringRef getText();
    SearchObject* getList();
    void removeItem(int);
};
struct ControlNotify { char hdr[0xc]; ComboControl* control; };

struct DataModelRef : shared_ptr<RBX::DataModel> {};
class CRobloxDoc {
public:
    char pad[0x94];
    RBX::ScriptSource* scripts;
    DataModelRef getDataModel();
    void OnExecute(ControlNotify* notify, LRESULT* result);
};

void CRobloxDoc::OnExecute(ControlNotify* notify, LRESULT* result)
{
    ComboControl* combo = notify->control;
    if (combo->getType() != 5)
        return;

    std::string script(combo->getText());

    const char* text = static_cast<const ImpStr<char>&>(script).c_str();
    SearchObject* object = combo->getList();
    if (object->table[133](object, -1, text) == -1) {
        combo->list->InsertString(0, static_cast<const ImpStr<char>&>(script).c_str());
        if (combo->list->GetCount() > 10)
            combo->removeItem(combo->list->GetCount() - 1);
    }

    combo->table[26](combo, 0);

    RBX::StandardOut::singleton()->print(0, "> %s", static_cast<const ImpStr<char>&>(script).c_str());

    try {
        if (RBX::ContentProvider::isUrl(script)) {
            std::auto_ptr<std::istream> stream(RBX::contentProvider(getDataModel().get())->getContent(RBX::ContentId(script)));
            std::ostringstream buffer;
            RBX::copyStream(*stream, buffer, 4096);
            static_cast<ImpStr<char>&>(script) = buffer.str();
        }
        RBX::Lock lock(getDataModel());
        scripts->get()->getScriptContext()->executeInNewThread(3, static_cast<const ImpStr<char>&>(script).c_str(), "Cmd");
    } catch (...) {
    }

    combo->table[26](combo, 1);
    Window* edit = combo->edit;
    SendMessageA(edit->handle, 0xb1, 0, -1);
    SendMessageA(edit->handle, 0xb7, 0, 0);
    combo->edit->SetFocus();
    *result = 1;
}
