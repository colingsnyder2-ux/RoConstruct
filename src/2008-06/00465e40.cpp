// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>

template <class T> class bstr {
public:
    __declspec(noinline) bstr() { _Mysize = 0; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) bstr& operator=(const bstr& r) { _Mysize = r._Mysize; return *this; }
    __declspec(noinline) bstr& operator=(const T* r) { _Mysize = 0; return *this; }
    __declspec(noinline) const T* c_str() const { return _Buf; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> string_;
__declspec(dllimport) bool operator!=(const string_&, const string_&);
__declspec(dllimport) bool operator!=(const string_&, const char*);
__declspec(dllimport) bool operator==(const string_&, const char*);

class CString {
public:
    __declspec(dllimport) CString();
    __declspec(dllimport) ~CString() throw();
    __declspec(dllimport) operator const char*() const;
    __declspec(dllimport) void __cdecl Format(unsigned int nFormatID, ...);
    char* m_pszData;
};

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
    void reset();
    T* get() const { return px; }
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

}

namespace RBX {
namespace Reflection { class ClassDescriptor { public: void* vptr; string_ name; }; }
class Described { public: virtual ~Described(); virtual const Reflection::ClassDescriptor* getDescriptor() const; };
struct PadI0 { virtual ~PadI0(); char pad0[0xc]; };
class Instance : public PadI0, public Described {
public:
    char pad1[0x110 - 0x14];
    string_ name;
};
struct PadS { char pad[0x154]; };
class Selection : public PadS {
public:
    std::vector<boost::shared_ptr<Instance> >* children;
};
class DataModel;
class ReadRequest {
public:
    ReadRequest(boost::shared_ptr<DataModel> dm);
    ~ReadRequest();
    void* a; void* b; void* c;
};
}

class CSelectionCaptionBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void SetCaption(const char* text, int flags = 0);
};

class CSelectionCaption : public CSelectionCaptionBase {
public:
    char pad0[0x1c];
    void* m_hWnd;
    char pad1[0x1b8 - 0x24];
    boost::shared_ptr<RBX::DataModel> dataModel;
    boost::shared_ptr<RBX::Selection> selection;
    void UpdateCaption();
};

void CSelectionCaption::UpdateCaption()
{
    if (!m_hWnd)
        return;
    CString caption;
    string_ name;
    if (selection) {
        RBX::ReadRequest request(dataModel);
        std::vector<boost::shared_ptr<RBX::Instance> >::iterator it = selection->children->begin();
        if (it != selection->children->end()) {
            name = (*it)->name;
            const RBX::Reflection::ClassDescriptor* desc = (*it)->getDescriptor();
            while (++it != selection->children->end()) {
                if ((*it)->name != name) {
                    name = "";
                    if (!desc)
                        break;
                }
                if ((*it)->getDescriptor() != desc) {
                    desc = 0;
                    if (name == "")
                        break;
                }
            }
            if (desc) {
                if (name != "") {
                    if (selection->children->size() > 1) {
                        const char* className = desc->name.c_str();
                        caption.Format(0xb5, className, name.c_str(), (int)selection->children->size());
                    } else {
                        const char* className = desc->name.c_str();
                        caption.Format(0xb4, className, name.c_str());
                    }
                } else
                    caption.Format(0xb6, desc->name.c_str(), (int)selection->children->size());
            } else
                caption.Format(0xb7, (int)selection->children->size());
        }
    }
    SetCaption(caption);
}
