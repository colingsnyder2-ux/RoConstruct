// from server: 100% by king_originala
extern void (__thiscall *streambuf_constructor)(void*);

namespace std {
    template<class C> struct char_traits;

    template<class C, class T> class __declspec(novtable) basic_streambuf {
    protected:
        basic_streambuf();
    public:
        virtual ~basic_streambuf();
    private:
        char storage[56];
    };

    template<class C, class T>
    inline basic_streambuf<C, T>::basic_streambuf()
    {
        streambuf_constructor(this);
    }
}

struct BufferBase : std::basic_streambuf<char, std::char_traits<char> > {
    char flag;
    char padding[7];
    char mode;
    char alignment[3];
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;

    BufferBase();
};

inline BufferBase::BufferBase()
    : flag(0),
      mode(0),
      field48(0),
      field4c(0),
      field50(0),
      field54(0),
      field58(16)
{
}

struct S : BufferBase {
    S(void** source, int second, int third);
    void initialize(void** source, int second, int third);
};

S::S(void** source, int second, int third)
{
    source = static_cast<void**>(*source);
    initialize(reinterpret_cast<void**>(&source), second, third);
}
