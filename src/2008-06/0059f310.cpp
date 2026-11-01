// from server: 100% by colin
// from server: 93% by king_originala
struct TypeInfo;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);
extern TypeInfo meshType;
extern void (__thiscall *copyString)(void*, const void*);
extern void (__thiscall *destroyString)(void*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string
    {
        char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const basic_string& other)
    {
        copyString(this, &other);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        destroyString(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct MeshId
{
    std::string value;
    unsigned int extra;
};

struct Type
{
    char padding[8];
    TypeInfo* info;
};

struct Holder
{
    virtual ~Holder();
    virtual void slot1() = 0;
    virtual Holder* clone() = 0;
};

inline Holder* cloneHolder(Holder* p)
{
    if (p)
        return p->clone();
    return 0;
}

extern const MeshId& __cdecl getMeshId(Holder* const*);

struct S;

struct Temporary
{
    Type* type;
    Holder* holder;

    Temporary(const S&);
    ~Temporary();
    const MeshId& convert();
};

struct S
{
    Type* type;
    Holder* holder;

    MeshId f();
};

inline Temporary::Temporary(const S& source)
    : type(source.type), holder(cloneHolder(source.holder))
{
}

inline Temporary::~Temporary()
{
    if (holder)
        delete holder;
}

MeshId S::f()
{
    const TypeInfo* t = type->info;
    if (typeEqual(&meshType, *t))
        return getMeshId(&holder);

    Temporary temporary(*this);
    return temporary.convert();
}
