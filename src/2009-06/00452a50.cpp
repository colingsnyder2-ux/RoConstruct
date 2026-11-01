// from server: 96% by EspClaude
// true extent: 0x24b bytes (server extent 0x227 cuts the catch funclet)

// from server: 97% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
#include <memory>
#include <exception>

template <class T> class bstr {
public:
    __declspec(noinline) bstr() { _Mysize = 0; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) bstr& operator=(const bstr& r) { _Mysize = r._Mysize; return *this; }
    __declspec(noinline) bstr& operator=(const T* r) { _Mysize = 0; return *this; }
    __declspec(noinline) const T* c_str() const { return _Buf; }
    __declspec(noinline) unsigned int size() const { return _Mysize; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> string_;
__declspec(dllimport) bool operator==(const string_&, const char*);

namespace boost {
struct lock_error { lock_error(); };
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
    void reset();
    T* get() const { return px; }
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

}

template <class T> class bios {
public:
    __declspec(noinline) bios() { x = 0; }
    __declspec(noinline) virtual ~bios() { x = 0; }
    int x;
    char pad[0x40];
};
template <class T> class bostr : virtual public bios<T> {
public:
    __declspec(noinline) explicit bostr(int mode) { y = mode; }
    __declspec(noinline) virtual ~bostr() { y = 0; }
    __declspec(noinline) bostr& flush() { return *this; }
    __declspec(noinline) bstr<T> str() const { return bstr<T>(); }
    int y;
    char pad[0x30];
};
extern template class __declspec(dllimport) bios<char>;
extern template class __declspec(dllimport) bostr<char>;
typedef bostr<char> ostringstream_;

template <class T> class CStringT_ {
public:
    __declspec(noinline) CStringT_() { m_pszData = 0; }
    __declspec(noinline) ~CStringT_() throw() { m_pszData = 0; }
    __declspec(noinline) operator const T*() const { return m_pszData; }
    __declspec(noinline) int LoadString(unsigned int nID) { return 0; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT_<char>;
typedef CStringT_<char> CString;
class CWnd;
class CFileDialog {
public:
    CFileDialog(int bOpenFileDialog, const char* lpszDefExt = 0, const char* lpszFileName = 0,
                unsigned long dwFlags = 6, const char* lpszFilter = 0, CWnd* pParentWnd = 0,
                unsigned long dwSize = 0, int bVistaStyle = 1);
    virtual ~CFileDialog();
    virtual int DoModal();
    CString GetPathName() const;
    char data[0x1dc];
};
int ShowMessageBox(const char* lpszText, unsigned int nType = 0, unsigned int nIDHelp = 0);

namespace RBX {
class Tuple { public: Tuple(); ~Tuple(); char data[0x18]; };
class ScriptContext {
public:
    std::auto_ptr<Tuple> executeInNewThread(int identity, const char* script, const char* name, const Tuple& args);
};
class ServiceProvider {
public:
    virtual ~ServiceProvider();
    template<class T> T* create() const;
};
class DataModel : public ServiceProvider {};
class ReadRequest {
public:
    ReadRequest(boost::shared_ptr<DataModel> dm, bool flag);
    ~ReadRequest();
    void* a;
};
namespace LDraw2Lua {
class LDrawParser {
public:
    explicit LDrawParser(const char* fileName);
    ~LDrawParser();
    void writeLua(bostr<char>& stream);
    char data[0x20];
};
}
}

class CRobloxView { public: boost::shared_ptr<RBX::DataModel> getDataModel(); };

class CRobloxDoc {
public:
    virtual ~CRobloxDoc();
    char pad[0x98];
    CRobloxView* view;
    boost::shared_ptr<RBX::DataModel> getDataModel();
    void OnInsertLDraw();
};

void CRobloxDoc::OnInsertLDraw()
{
    CString filter;
    filter.LoadString(0xd3);
    CFileDialog dlg(1, "ldr", 0, 6, filter, 0, 0, 1);
    if (dlg.DoModal() == 1) {
        RBX::LDraw2Lua::LDrawParser parser(dlg.GetPathName());
        ostringstream_ stream(2);
        parser.writeLua(stream);
        stream.flush();
        try {
            RBX::ReadRequest request(view->getDataModel(), true);
            RBX::Tuple args;
            string_ script = stream.str();
            getDataModel()->create<RBX::ScriptContext>()->executeInNewThread(1, script.c_str(), "LDraw", args);
        } catch (std::exception& e) {
            ShowMessageBox(e.what(), 0x10);
        }
    }
}
