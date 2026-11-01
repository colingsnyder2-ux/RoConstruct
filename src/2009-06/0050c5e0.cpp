// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
	struct shared_count { void* pi_; shared_count() : pi_(0) {} ~shared_count(); };
	shared_ptr() : px(0), pn() {}
	void reset();
	T* px; shared_count pn;
};
}
namespace G3D {
template<class T> class Array {
public:
	T* data; int num; int numAllocated;
	Array() { num = 0; numAllocated = 0; data = 0; }
	~Array();
	void resize(int n, bool shrinkIfNecessary);
	void clear() { resize(0, false); }
};
}
namespace RBX {
class Thing;
struct Member30 { Member30(); char pad[0x30]; };
struct Member18 { Member18(); char pad[0x18]; };
class Holder2009 {
public:
	boost::shared_ptr<Thing> thing;
	struct Sub { Member30 a; Member18 b; } sub;
	G3D::Array<int> arr;
	Holder2009();
};
Holder2009::Holder2009()
{
	thing.reset();
	arr.clear();
}
}
