// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
namespace RBX {
class Chunk;
class WeakBase {
public:
	WeakBase() {}
	virtual ~WeakBase() {}
};
template<class T> class RefPtr {
	T* p;
public:
	T* get() const { return p; }
};
template<class T> class WeakReferenceCountedPointer : public WeakBase {
	T* ptr;
public:
	WeakReferenceCountedPointer(const RefPtr<T>& other) : ptr(0) { assign(other.get()); }
	virtual ~WeakReferenceCountedPointer() {}
	void assign(T* p);
};
template class WeakReferenceCountedPointer<Chunk>;
}
