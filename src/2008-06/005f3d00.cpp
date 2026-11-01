// from server: 100% by king_originala
typedef void (__thiscall *StreambufConstructor)(void*);
extern StreambufConstructor streambufConstructor;

namespace std {
    template<class T> struct char_traits;

    template<class T, class Traits> class basic_streambuf {
    protected:
        basic_streambuf();
    public:
        ~basic_streambuf();
    private:
        char storage[56];
    };

    template<class T, class Traits>
    inline basic_streambuf<T, Traits>::basic_streambuf()
    {
        streambufConstructor(reinterpret_cast<char*>(this) - 4);
    }
}

struct Device {
    int value;
};

struct Buffer : std::basic_streambuf<char, std::char_traits<char> > {
    unsigned char state;
    unsigned char padding[3];
    Device device;
    unsigned char engaged;
    unsigned char padding2[3];
    char* first;
    char* last;
    char* current;
    char* limit;
    int capacity;

    Buffer();
};

inline Buffer::Buffer()
    : state(0),
      engaged(0),
      first(0),
      last(0),
      current(0),
      limit(0),
      capacity(16)
{
}

struct S : Buffer {
    S(const Device& source, int mode, int size);
    virtual ~S();
    void open(const Device& source, int mode, int size);
};

S::S(const Device& source, int mode, int size)
{
    open(Device(source), mode, size);
}
