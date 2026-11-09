// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
#include <string>
namespace boost {
template<class T> inline void checked_delete(T* x) { typedef char type_must_be_complete[sizeof(T) ? 1 : -1]; (void)sizeof(type_must_be_complete); delete x; }
template<class T> class scoped_ptr {
	T* ptr;
	typedef scoped_ptr<T> this_type;
public:
	explicit scoped_ptr(T* p = 0) : ptr(p) {}
	~scoped_ptr() { boost::checked_delete(ptr); }
	void reset(T* p = 0) { this_type(p).swap(*this); }
	void swap(scoped_ptr& b) { T* tmp = b.ptr; b.ptr = ptr; ptr = tmp; }
	T* get() const { return ptr; }
	bool operator!() const { return ptr == 0; }
};
}
namespace RBX { namespace RenderNew {
class TextureProxy;
typedef std::map<std::string, TextureProxy*> Cache;
class TextureProxy {
public:
	static boost::scoped_ptr<Cache> cache;
	static void initCache();
};
void TextureProxy::initCache()
{
	if (!cache)
		cache.reset(new Cache());
}
} }
