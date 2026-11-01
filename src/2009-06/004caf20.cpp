// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
	struct sp_counted_base {
		virtual ~sp_counted_base() {}
		virtual void dispose() = 0;
		long use_count_;
		long weak_count_;
		void add_ref_copy() { _InterlockedIncrement(&use_count_); }
		void release();
	};
	class shared_count {
	public:
		shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
		~shared_count();
		shared_count& operator=(const shared_count& r);
		sp_counted_base* pi_;
	};
	template<class T> class shared_ptr {
	public:
		T* get() const { return px; }
		T* px;
		shared_count pn;
	};
}
namespace RBX {
class Selection;
class Holder { public: char pad[0x8c]; boost::shared_ptr<Selection> selection; };
class Owner {
public:
	char pad[0xac];
	boost::shared_ptr<Selection> cached;
	static Holder* findHolder(Owner* o);
	boost::shared_ptr<Selection> getSelection();
};
boost::shared_ptr<Selection> Owner::getSelection()
{
	if (!cached.get())
		cached = findHolder(this)->selection;
	return cached;
}
}
