// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<class T> class scoped_ptr {
    T* ptr;
public:
    explicit scoped_ptr(T* p = 0) : ptr(p) {}
    ~scoped_ptr();
};
}
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	virtual ~Instance();
	void setName(const std::string& name);
	char ipad[0x8c - 0x2c];
};
class DescribedCD : public Instance {
public:
	DescribedCD();
	~DescribedCD();
};
class __declspec(novtable) SecondCD {
public:
	SecondCD() : a(-1), b(-1), c(0) {}
	virtual ~SecondCD();
	int a, b, c;
};
class ClickHelper;
class ClickDetector : public DescribedCD, public SecondCD {
public:
	ClickDetector();
	int x9c;
	float maxActivationDistance;
	int xa4;
	boost::scoped_ptr<ClickHelper> helper;
};
ClickDetector::ClickDetector()
	: x9c(0), maxActivationDistance(32.0f)
{
	setName("ClickDetector");
}
}
