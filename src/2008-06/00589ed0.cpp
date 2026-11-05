// from server: 100% by king_originala
namespace std {
template<class T> struct char_traits;
template<class T> class allocator {};

template<class C, class T = char_traits<C>, class A = allocator<C> >
class basic_string {
    A alloc;
    union {
        C buffer[16];
        C* pointer;
    } storage;
    unsigned length;
    unsigned capacity;
public:
    basic_string();
    ~basic_string();
};
}

typedef std::basic_string<char> String;

extern void (__thiscall *stringConstructor)(String*);
extern void (__thiscall *stringDestructor)(String*);
extern "C" void (__cdecl * const _invalid_parameter_noinfo)();

namespace std {
template<class C, class T, class A>
inline basic_string<C, T, A>::basic_string() {
    stringConstructor(this);
}

template<class C, class T, class A>
inline basic_string<C, T, A>::~basic_string() {
    stringDestructor(this);
}
}

struct Object {
    virtual void destroy(unsigned);
};

struct Holder {
    Object* pointer;

    Holder(const String&);
    ~Holder();
    void swap(Object*&);
};

inline Holder::~Holder() {
    if (pointer)
        pointer->destroy(1);
}

inline void Holder::swap(Object*& other) {
    if (&pointer != &other) {
        Object* saved = pointer;
        pointer = other;
        other = saved;
    }
}

struct Value {
    void* type;
    Object* object;
    void assign(const bool&);
};

struct Values {
    unsigned reserved[3];
    Value* first;
    Value* last;
    Value* limit;

    Values(unsigned);
    ~Values();
    Value& at(unsigned);
};

inline Value& Values::at(unsigned index) {
    if (static_cast<unsigned>(last - first) <= index)
        _invalid_parameter_noinfo();
    return first[index];
}

struct Result {
    Result(const Values&);
    ~Result();
};

extern void* __cdecl stringType();

struct S {
    char padding[0x165];
    bool enabled;

    bool query(String&, int);
    Result f();
};

Result S::f() {
    String text;
    if (enabled && query(text, 0)) {
        Values values(2);
        void (__cdecl *invalid)() = _invalid_parameter_noinfo;
        bool flag = true;
        if (static_cast<unsigned>(values.last - values.first) <= 0)
            invalid();
        values.first[0].assign(flag);

        if (static_cast<unsigned>(values.last - values.first) <= 1)
            invalid();
        Value& value = values.first[1];
        value.type = stringType();
        Object*& destination = value.object;
        Holder(text).swap(destination);
        return Result(values);
    } else {
        Values values(1);
        bool flag = false;
        values.at(0).assign(flag);
        return Result(values);
    }
}
