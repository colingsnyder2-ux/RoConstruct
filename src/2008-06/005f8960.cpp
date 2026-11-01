// from server: 100% by colin
extern void *ios_base_table;
extern void *basic_ios_table;

namespace std {
template<class C> struct char_traits;
template<class C, class T> struct basic_streambuf;

struct __declspec(novtable) ios_base {
    ios_base();
    virtual ~ios_base();
};

template<class C, class T>
struct __declspec(novtable) basic_ios : ios_base {
    basic_ios();
    virtual ~basic_ios();
};

template<class C, class T>
struct basic_istream : virtual basic_ios<C, T> {
    int count;
    __declspec(dllimport) basic_istream(basic_streambuf<C, T> *, bool);
    virtual ~basic_istream();
};

inline ios_base::ios_base()
{
    *reinterpret_cast<void *volatile *>(this) = ios_base_table;
}

template<class C, class T>
inline basic_ios<C, T>::basic_ios()
{
    *reinterpret_cast<void *volatile *>(this) = basic_ios_table;
}
}

typedef std::basic_istream<char, std::char_traits<char> > IStream;

struct State {
    char reserved[28];
    void *owner;
};

struct ChainStorage {
    State *volatile state;
    unsigned int spare;
    ChainStorage();
    ~ChainStorage();
};

struct StorageBase {
    ChainStorage *volatile storage;
    StorageBase();
};

inline StorageBase::StorageBase() : storage(0) {}

struct ChainBase : StorageBase {
    ChainBase();
    virtual ~ChainBase();
};

inline ChainBase::ChainBase() {}

struct S : ChainBase, IStream {
    ChainStorage chain;
    S();
    virtual ~S();
};

S::S() : IStream(0, false)
{
    storage = &chain;
    chain.state->owner = this;
}
