// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct IUnknown;
class CObj;
template<class T> struct __declspec(novtable) IA { IA() { static_cast<T*>(this)->z = 0; } virtual void a() = 0; };
struct __declspec(novtable) IB { virtual void b() = 0; };
template<class T, unsigned long dw> class IObjectSafetyRobloxImpl {
public:
	IObjectSafetyRobloxImpl() { m_dwCurrentSafety = 0; }
	virtual long __stdcall GetInterfaceSafetyOptions(const void*, unsigned long*, unsigned long*);
	unsigned long m_dwCurrentSafety;
};
struct ComHolder { int a; IUnknown* p; ComHolder() : p(0) {} ~ComHolder(); };
namespace boost {
namespace detail { class shared_count { public: void* pi_; shared_count() : pi_(0) {} ~shared_count(); }; }
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; shared_ptr() : px(0) {} };
}
class COleDataSource { public: COleDataSource(); virtual ~COleDataSource(); char pad[0x40]; };
class PartDataSource : public COleDataSource { public: PartDataSource() {} };
class A; class B;
class __declspec(novtable) CObj : public IA<CObj>, public IB, public IObjectSafetyRobloxImpl<CObj,1> {
public:
	CObj();
	ComHolder h;
	int z;
	boost::shared_ptr<A> s1;
	boost::shared_ptr<B> s2;
	PartDataSource ds;
};
CObj::CObj() {}
