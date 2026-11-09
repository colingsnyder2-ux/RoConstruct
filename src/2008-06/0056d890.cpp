// from server: 100% by colin
class type_info;
extern bool (__thiscall *type_equal)(const type_info*, const type_info&);

extern const type_info void_type;
extern const type_info color_type;
extern const type_info string_type;

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string {
    public:
        unsigned int allocator_storage;
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

        basic_string(const basic_string&);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        char* message;
        int owns_message;

    public:
        exception(const exception&);
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception {
        string text;

    public:
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

struct Color {
    float x, y, z;
};

struct Placeholder {
    virtual ~Placeholder();
    virtual const type_info& type() const;
};

struct Any {
    Placeholder* content;
    void assign(const Color&);
};

struct Name {
    unsigned int reserved;
    std::string text;
};

struct Descriptor {
    unsigned int reserved[2];
    const type_info* type;
    Name* name;
};

extern Color* __cdecl extract(Any*);
extern bool __cdecl convert(const Color*, Color*);
extern Descriptor* __cdecl color_descriptor();
extern void __cdecl finish(Any*);
extern std::string __cdecl format(const char*, ...);

struct S {
    Descriptor* descriptor;
    Any value;

    void f();
};

void S::f()
{
    bool (__thiscall *equal)(const type_info*, const type_info&) = type_equal;
    Any* p = &value;
    if (p) {
        const type_info& t = p->content ? p->content->type() : void_type;
        if (equal(&t, color_type)) {
            if (reinterpret_cast<char*>(p->content) + 4)
                return;
        }
    }

    Descriptor* d = descriptor;
    const type_info* dst = d->type;
    if (equal(&string_type, *dst)) {
        Color color;
        color.x = 0.0f;
        color.y = 0.0f;
        color.z = 0.0f;
        if (convert(extract(p), &color)) {
            p->assign(color);
            descriptor = color_descriptor();
            finish(p);
            return;
        }
    }

    Name* destination = color_descriptor()->name;
    const char* destination_name =
        destination->text.capacity >= 16 ?
        destination->text.storage.pointer :
        destination->text.storage.buffer;
    const std::string& source = descriptor->name->text;
    const char* source_name =
        source.capacity >= 16 ? source.storage.pointer : source.storage.buffer;

    throw std::runtime_error(
        format("Unable to cast %s to %s", source_name, destination_name));
}
