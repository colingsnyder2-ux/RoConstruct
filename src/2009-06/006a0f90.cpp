// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace RBX {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	long use_count_;
	long weak_count_;
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct WeakRef {
	void* px;
	sp_counted_base* pi_;
	~WeakRef() { if (pi_ != 0) pi_->weak_release(); }
};
class A0 { public: virtual void a0(); char pad[0x10]; };
class A1 { public: virtual void a1(); };
class A2 { public: virtual ~A2(); void* d; };
class A3 { public: virtual void a3(); char pad[8]; };
class Instance : public A0, public A1, public A2, public A3 {
public:
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
class FactoryProduct : public Instance {
public:
	virtual ~FactoryProduct() {}
};
class __declspec(novtable) Described : public FactoryProduct {};
class __declspec(novtable) DescribedCreatable : public Described {};
class TouchTransmitter : public DescribedCreatable {
	WeakRef other;
public:
	~TouchTransmitter();
};
TouchTransmitter::~TouchTransmitter()
{
}
}
