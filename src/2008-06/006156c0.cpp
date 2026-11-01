// from server: 100% by king_originala
struct TypeInfo;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);
extern void (__thiscall *destroyString)(void*);

namespace std
{
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string
    {
        char storage[28];
    public:
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        destroyString(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct TypeInfo
{
    bool operator==(const TypeInfo&) const;
};

inline bool TypeInfo::operator==(const TypeInfo& other) const
{
    return typeEqual(this, other);
}

struct Object
{
    virtual ~Object();
};

struct Value : std::string
{
    char extra[4];
    Value(const std::string&);
};

struct Holder
{
    Object* value;
    Holder(const Value&);
    ~Holder();
    void swap(Holder& other);
};

inline Holder::~Holder()
{
    if (value)
        delete value;
}

inline void Holder::swap(Holder& other)
{
    if (&other != this)
    {
        Object* saved = other.value;
        other.value = value;
        value = saved;
    }
}

struct Descriptor
{
    unsigned int unused[2];
    TypeInfo* type;
};

extern TypeInfo stringType;
extern std::string __cdecl convert(const Holder&);
extern Descriptor* __cdecl valueDescriptor();

struct S
{
    Descriptor* descriptor;
    Holder holder;

    void finish();
    void f();
};

void S::f()
{
    if (stringType == *descriptor->type)
    {
        holder.swap(Holder(Value(convert(holder))));
        descriptor = valueDescriptor();
    }
    finish();
}
