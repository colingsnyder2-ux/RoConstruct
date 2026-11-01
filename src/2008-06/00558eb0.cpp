// from server: 100% by king_originala
extern "C" void (__cdecl *_invalid_parameter_noinfo)();
void __cdecl operator delete(void *) throw();

struct Object {
    virtual ~Object();
};

struct Storage;

struct Proxy {
    Storage *owner;
};

struct Iterator {
    Proxy *proxy;
    Object **position;

    Storage *container() const;
    bool operator==(const Iterator &) const;
    Object *operator*() const;
    Iterator &operator++();
};

struct Storage {
    Proxy *proxy;
    unsigned int reserved[2];
    Object **first;
    Object **last;
    Object **limit;

    Iterator begin();
    Iterator end();
    ~Storage();
};

__forceinline Storage *Iterator::container() const
{
    return proxy ? proxy->owner : 0;
}

__forceinline bool Iterator::operator==(const Iterator &other) const
{
    if (!proxy || proxy != other.proxy)
        _invalid_parameter_noinfo();
    return position == other.position;
}

__forceinline Object *Iterator::operator*() const
{
    if (!proxy)
        _invalid_parameter_noinfo();
    if (position >= container()->last)
        _invalid_parameter_noinfo();
    return *position;
}

__forceinline Iterator &Iterator::operator++()
{
    if (!proxy)
        _invalid_parameter_noinfo();
    if (position >= container()->last)
        _invalid_parameter_noinfo();
    ++position;
    return *this;
}

__forceinline Iterator Storage::begin()
{
    Object **p = first;
    if (p > last)
        _invalid_parameter_noinfo();
    Iterator result;
    result.proxy = proxy;
    result.position = p;
    return result;
}

__forceinline Iterator Storage::end()
{
    Object **p = last;
    if (first > p)
        _invalid_parameter_noinfo();
    Iterator result;
    result.proxy = proxy;
    result.position = p;
    return result;
}

__forceinline Storage::~Storage()
{
    if (first)
        operator delete(first);
    first = 0;
    last = 0;
    limit = 0;
    operator delete(proxy);
}

struct S {
    Storage storage;
    ~S();
};

S::~S()
{
    Iterator current = storage.begin();
    Iterator finish = storage.end();
    while (!(current == finish)) {
        delete *current;
        ++current;
    }
}
