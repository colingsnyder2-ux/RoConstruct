// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

namespace std {
template<class E> struct char_traits;
template<class T> class allocator;
template<class E, class Tr, class A> class basic_string {
public:
    __declspec(noinline) int compare(const E*) const { return 0; }
    char storage[28];
};
extern template class __declspec(dllimport) basic_string<char, char_traits<char>, allocator<char> >;
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

namespace RBX {
class Name {
public:
    unsigned int id;
    std::string name;
    bool operator==(const char* s) const { return name.compare(s) == 0; }
};

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
    T* get() const { return px; }
};

class Head { public: virtual void h(); char pad[12]; };
class Product {
public:
    virtual ~Product();
    virtual const Name& getClassName() const = 0;
};
class Instance : public Head, public Product {
};

class Notifier {
public:
    void addListener(void* l);
};
class Players : public Instance {
public:
    char pad2[0x150 - 0x14];
    Notifier notifier;
};

class ChildAdded {
public:
    shared_ptr<Instance> child;
};
}

using namespace RBX;

class CWndBase { public: virtual ~CWndBase(); char pad[0x1c]; void* m_hWnd; char pad2[0xa4 - 0x24]; };
template<class S, class E> class Listener {
public:
    virtual void onEvent(const S* source, E event) = 0;
};
class PlayersChanged {};

class CRobloxView : public CWndBase, public Listener<Instance, ChildAdded>, public Listener<Players, PlayersChanged> {
public:
    virtual void onEvent(const Instance* source, ChildAdded event);
    virtual void onEvent(const Players* source, PlayersChanged event);
};

void CRobloxView::onEvent(const Instance* source, ChildAdded event)
{
    if (event.child->getClassName() == "NetworkClient")
        PostMessageA(m_hWnd, 0x46C, 0, 0);
    if (event.child->getClassName() == "NetworkClient" || event.child->getClassName() == "Players")
        PostMessageA(m_hWnd, 0x46B, 0, 0);
    if (event.child->getClassName() == "Players") {
        Listener<Players, PlayersChanged>* listener = this;
        Players* players = static_cast<Players*>(event.child.get());
        if (players)
            players->notifier.addListener(listener);
    }
}
