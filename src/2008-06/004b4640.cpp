// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> inline void checked_delete(T* x) { typedef char type_must_be_complete[sizeof(T) ? 1 : -1]; (void)sizeof(type_must_be_complete); delete x; }
template<class T> class scoped_ptr {
    T* px;
    scoped_ptr(scoped_ptr const&);
    scoped_ptr& operator=(scoped_ptr const&);
    typedef scoped_ptr<T> this_type;
public:
    explicit scoped_ptr(T* p = 0) : px(p) {}
    ~scoped_ptr() { boost::checked_delete(px); }
    void reset(T* p = 0) { this_type(p).swap(*this); }
    T* operator->() const { return px; }
    T* get() const { return px; }
    void swap(scoped_ptr& b) { T* tmp = b.px; b.px = px; px = tmp; }
};
}
namespace RBX {
namespace Reflection { class ClassDescriptor; }
struct S0 { virtual ~S0(); char p[0xc]; };
struct S10 { virtual ~S10(); };
struct S14 { virtual ~S14(); int a; const Reflection::ClassDescriptor* descriptor; };
struct S20 { virtual ~S20(); };
struct S24 { virtual ~S24(); char p[0x1c]; };
struct S44 { virtual ~S44(); char p[0x1c]; };
struct S64 { virtual ~S64(); char p[0x1c]; };
struct S84 { virtual ~S84(); char p[0x1c]; };
struct Sa4 { virtual ~Sa4(); char p[0x1c]; };
struct Sc4 { virtual ~Sc4(); char p[0x68]; };
class Instance : public S0, public S10, public S14, public S20, public S24, public S44, public S64, public S84, public Sa4, public Sc4 {
public:
    Instance();
    virtual ~Instance();
};
namespace Reflection {
template<class C> class __declspec(novtable) Described : public Instance {
public:
    static const ClassDescriptor& classDescriptor();
    __forceinline Described() { descriptor = &classDescriptor(); }
};
}
class RunService; class Heartbeat;
template<class S, class E> class __declspec(novtable) Listener {
public:
    virtual void onEvent(const S* source, E event) = 0;
};
namespace Profiling {
class ThreadProfiler {
public:
    ThreadProfiler(const char* name);
    char data[0xc048];
};
}
}
class PluginInterface {
public:
    PluginInterface();
    virtual ~PluginInterface();
};
class RakPeerInterface {
public:
    virtual ~RakPeerInterface();
#define V(n) virtual void v##n();
    V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)V(20)
    V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)V(40)
    V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)
    virtual void AttachPlugin(PluginInterface* plugin);
};
class RakPeer : public RakPeerInterface {
public:
    RakPeer();
    virtual ~RakPeer();
    char data[0x904];
};
class ProfiledRakPeer : public RakPeer {
    RBX::Profiling::ThreadProfiler* profiler;
    int extra;
public:
    ProfiledRakPeer(RBX::Profiling::ThreadProfiler* p) : profiler(p) {}
};
namespace RBX { namespace Network {
extern const char* const sPeer;
class Peer : public Reflection::Described<Peer>, public PluginInterface, public Listener<RunService, Heartbeat>
{
    boost::scoped_ptr<int> logger;
    boost::scoped_ptr<Profiling::ThreadProfiler> profilePacketsThread;
protected:
    boost::scoped_ptr<RakPeer> rakPeer;
public:
    Peer();
    virtual ~Peer();
    virtual void onEvent(const RunService* source, Heartbeat event);
};
Peer::Peer()
    : profilePacketsThread(new Profiling::ThreadProfiler("Packets Thread"))
{
    rakPeer.reset(new ProfiledRakPeer(profilePacketsThread.get()));
    rakPeer->AttachPlugin(this);
}
}}
