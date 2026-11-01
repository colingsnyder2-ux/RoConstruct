// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
class mutex {
public:
	class scoped_lock {
	public:
		scoped_lock(mutex& m);
		~scoped_lock();
		int pad;
	};
};
template<class T> class scoped_ptr {
public:
	T* px;
	void reset(T* p = 0) { T* old = px; px = p; delete old; }
	T* get() const { return px; }
	typedef T* scoped_ptr::*unspecified_bool_type;
	operator unspecified_bool_type() const { return px == 0 ? 0 : &scoped_ptr::px; }
	bool operator!() const { return px == 0; }
};
}
namespace RBX { namespace Network {
class Item2009 { public: Item2009(); ~Item2009(); char pad[0x34]; };
extern boost::mutex sync2009;
class Holder2009 {
public:
	boost::scoped_ptr<Item2009> item;
	Item2009* get();
};
Item2009* Holder2009::get()
{
	if (!item) {
		boost::mutex::scoped_lock lock(sync2009);
		if (!item)
			item.reset(new Item2009());
	}
	return item.get();
}
}}
