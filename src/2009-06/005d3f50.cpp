// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public: shared_ptr() : px(0), pn() {}
    T* get() const { return px; } T* operator->() const { return px; }
public:
    T* px;
    detail::shared_count pn;
};
}
namespace boost {
template<class T> class weak_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr<T> lock() const;
};
}
namespace G3D {
class Vector3 {
public:
	float x, y, z;
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
};
}
namespace RBX {
class Instance;
struct SelectionChanged {
	SelectionChanged(boost::shared_ptr<Instance> added, boost::shared_ptr<Instance> removed);
	~SelectionChanged();
	boost::shared_ptr<Instance> addedItem, removedItem;
};
class ISelectionBase { public: virtual void onSelectionChanged(const SelectionChanged& event) = 0; };
class SelNotifier { public: void raise(const SelectionChanged& event) const; };
class Selection {
public:
	char pad[0x94];
	std::vector<ISelectionBase*> filteredSelections;
	char pad2[0xcc - 0xac];
	SelNotifier notifier;
	void raiseAdded(boost::shared_ptr<Instance> instance);
};
void Selection::raiseAdded(boost::shared_ptr<Instance> instance)
{
	SelectionChanged event(instance, boost::shared_ptr<Instance>());
	for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
	{
		(*iter)->onSelectionChanged(event);
	}
	notifier.raise(event);
}
}
