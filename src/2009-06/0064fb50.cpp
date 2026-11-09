// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
namespace boost {
template<class T> class scoped_ptr {
    T* ptr;
public:
    explicit scoped_ptr(T* p = 0) : ptr(p) {}
    ~scoped_ptr() { delete ptr; }
};
}
namespace RBX {
template<class T> class Countable {
public:
    static long count;
    Countable() { InterlockedIncrement(&count); }
    ~Countable() { InterlockedDecrement(&count); }
};
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
class DescribedX : public Instance {
public:
	DescribedX();
	virtual ~DescribedX() {}
};
class __declspec(novtable) SecondX {
public:
	virtual ~SecondX();
	int a, b, c;
};
class ThirdX {
public:
	virtual ~ThirdX();
	char tpad[0x1c];
};
class Helper { public: ~Helper(); };
class Explosion : public DescribedX, public SecondX, public ThirdX {
public:
	Explosion();
	virtual ~Explosion();
	Countable<Explosion> counter;
	boost::scoped_ptr<Helper> helper;
};
Explosion::~Explosion()
{
}
}
