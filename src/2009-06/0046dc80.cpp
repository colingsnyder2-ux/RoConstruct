// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
struct IUnknown { virtual long __stdcall QueryInterface(const void*, void**) = 0; virtual unsigned long __stdcall AddRef() = 0; virtual unsigned long __stdcall Release() = 0; };
class CObj;
template<class T> struct __declspec(novtable) IA { IA() { static_cast<T*>(this)->z = 0; } virtual void a() = 0; };
struct __declspec(novtable) IB { virtual void b() = 0; };
template<class T, unsigned long dw> class IObjectSafetyRobloxImpl {
public:
	IObjectSafetyRobloxImpl() { m_dwCurrentSafety = 0; }
	virtual long __stdcall GetInterfaceSafetyOptions(const void*, unsigned long*, unsigned long*);
	unsigned long m_dwCurrentSafety;
};
struct ComHolder { int a; IUnknown* p; ComHolder() : p(0) {} ~ComHolder() { IUnknown* q = p; if (q) q->Release(); } };
class COleDataSource { public: COleDataSource(); virtual ~COleDataSource(); char pad[0x40]; };
class PartDataSource : public COleDataSource { public: PartDataSource() {} };
class A; class B;
class __declspec(novtable) CObj : public IA<CObj>, public IB, public IObjectSafetyRobloxImpl<CObj,1> {
public:
	~CObj();
	ComHolder h;
	int z;
	boost::shared_ptr<A> s1;
	boost::shared_ptr<B> s2;
	PartDataSource ds;
};
CObj::~CObj() {}
