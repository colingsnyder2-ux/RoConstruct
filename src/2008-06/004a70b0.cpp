// from server: 100% by king_originala
extern void (__thiscall *stringConstruct)(void*, const char*);

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Alloc> class basic_string {
    char storage[28];
public:
    basic_string(const T*);
    ~basic_string();
};

template<class T, class Traits, class Alloc>
__forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
{
    stringConstruct(this, text);
}

typedef basic_string<char, char_traits<char>, allocator<char> > string;

class exception {
    const char* message;
    bool owned;
public:
    virtual ~exception();
    virtual const char* what() const;
};

class runtime_error : public exception {
    string message;
public:
    runtime_error(const string&);
    virtual ~runtime_error();
    virtual const char* what() const;
};
}

struct Data {
    const void* scope;
    unsigned int value;
};

struct BitStream {
    bool readBits(void*, int, bool);
};

struct Decoder {
    void read(BitStream*, Data*);
};

extern const void* __cdecl getLocalScope();

struct S {
    char padding[0xF54];
    Decoder decoder;
    void read(BitStream*, Data*);
};

void S::read(BitStream* stream, Data* data)
{
    decoder.read(stream, data);
    if (data->scope != getLocalScope()) {
        data->value = 0;
        if (!stream->readBits(&data->value, 24, true))
            throw std::runtime_error(
                std::string("BitStream >> RBX::Guid::Data failed"));
    } else {
        data->value = 0;
    }
}
