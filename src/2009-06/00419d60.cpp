// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
struct once_flag { long state; };
void call_once(once_flag& flag, void (*f)());
template<class T> class shared_ptr { public: T* px; void* pn; shared_ptr() : px(0), pn(0) {} shared_ptr(const shared_ptr&); ~shared_ptr(); };
}
class Item;
boost::shared_ptr<Item> createInstance();
static void initInstance();
static boost::once_flag flag;
boost::shared_ptr<Item> getInstance()
{
    boost::call_once(flag, &initInstance);
    return createInstance();
}
static void initInstance() { createInstance(); }
