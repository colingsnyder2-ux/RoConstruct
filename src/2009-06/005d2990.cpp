// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>
struct CRITICAL_SECTION { void* a; long b, c; void* d, *e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct pool_type {
    CRITICAL_SECTION mtx;
    void* first;
    static pool_type& instance();
};
extern long g_count;
namespace boost { template<class T> class shared_ptr { public: T* px; void* pn; shared_ptr(const shared_ptr&); ~shared_ptr(); }; }
namespace RBX {
class XmlElement {
public:
    XmlElement* next;
    struct ChildList {
        XmlElement* first;
        XmlElement* last;
        void append(XmlElement* child)
        {
            if (last == 0)
                first = child;
            else
                last->next = child;
            last = child;
        }
    } children;
    ~XmlElement();
    static void operator delete(void* p)
    {
        pool_type& pt = pool_type::instance();
        EnterCriticalSection(&pt.mtx);
        *(void**)p = pt.first;
        pt.first = p;
        LeaveCriticalSection(&pt.mtx);
        InterlockedDecrement(&g_count);
    }
    void addChild(XmlElement* child) { children.append(child); }
};
XmlElement* newRootElement();
class Instance;
boost::shared_ptr<Instance> readInstance(XmlElement* root);
class Instance {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual XmlElement* writeXml();
    boost::shared_ptr<Instance> clone();
};
boost::shared_ptr<Instance> Instance::clone()
{
    XmlElement* root = newRootElement();
    root->addChild(writeXml());
    std::auto_ptr<XmlElement> holder(root);
    return readInstance(root);
}
}
