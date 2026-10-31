// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    shared_ptr& operator=(const shared_ptr& r) { px = r.px; pn = r.pn; return *this; }
    T* operator->() const { return px; }
    T* get() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
    void reset();
};
}
namespace RBX {
using boost::shared_ptr;
class GuiEvent;
class GuiResponse {
public:
    int response;
    int target;
    GuiResponse(int r, int t) : response(r), target(t) {}
    bool wasUsed() const { return response != 0; }
    static GuiResponse notUsed() { return GuiResponse(0, 0); }
};
class Instance {
public:
    typedef std::vector<shared_ptr<Instance> > Children;
    virtual ~Instance();
    char pad[0x48];
    const Children* children;
    char pad2[0x8c - 0x50];
    unsigned int numChildren() const;
    const Children* getChildren() const { return children; }
};
class IGuiTarget {
public:
    virtual GuiResponse process(const GuiEvent& event) = 0;
};
template <class T> shared_ptr<T> shared_from(T* r);
class GuiItem : public Instance, public IGuiTarget {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void onLoseFocus();
    shared_ptr<GuiItem> focus;
    void loseFocus() {
        if (focus) focus->onLoseFocus();
        focus.reset();
    }
    GuiResponse processNonFocus(const GuiEvent& event);
};
GuiResponse GuiItem::processNonFocus(const GuiEvent& event)
{
	for (unsigned int i = 0; i < numChildren(); ++i) {
		Instance* child = (*getChildren())[i].get();
		GuiItem* item = dynamic_cast<GuiItem*>(child);

		if (item != NULL && item != focus.get()) {
			GuiResponse itemResponse = item->process(event);

			if (itemResponse.wasUsed()) {
				loseFocus();
				focus = shared_from(item);
				focus->loseFocus();

				return itemResponse;
			}
		}
	}

	return GuiResponse::notUsed();
}
}
