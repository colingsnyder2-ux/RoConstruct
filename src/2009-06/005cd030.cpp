// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
struct once_flag { long state; };
void call_once(once_flag& flag, void (*f)());
template<class T> class scoped_ptr { public: T* px; scoped_ptr() : px(0) {} ~scoped_ptr(); };
}
class Item;
static boost::scoped_ptr<Item>& instance() { static boost::scoped_ptr<Item> sp; return sp; }
static void initInstance() { instance(); }
static boost::once_flag flag;
boost::scoped_ptr<Item>& getInstance()
{
    boost::call_once(flag, &initInstance);
    return instance();
}
