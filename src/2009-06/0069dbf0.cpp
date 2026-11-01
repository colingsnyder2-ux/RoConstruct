// from server: 96% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
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
extern const char sGeometry[];
class DescribedGeometry : public Instance {
public:
	DescribedGeometry(const char* name);
};
class __declspec(novtable) Inner2009 : public DescribedGeometry {
public:
	Inner2009(const char* n) : DescribedGeometry(n), value(0) {}
	void* value;
};
template<class T> class Array {
public:
	T* data;
	int num;
	int numAllocated;
	void resize(int n);
	void init(int n, int a) {
		num = 0;
		numAllocated = 0;
		data = 0;
		if (a > 0) resize(n); else data = 0;
	}
	Array() { init(0, 0); }
	~Array();
};
class Geometry : public Inner2009 {
public:
	Array<int> items;
	Geometry();
	virtual const char* getClassName() const;
};
Geometry::Geometry() : Inner2009(sGeometry) {}
}
