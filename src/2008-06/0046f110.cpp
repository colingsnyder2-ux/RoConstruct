// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string();
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
typedef unsigned int size_t;




extern std::string __cdecl makeString(const char *);
void *__cdecl operator new(size_t);
void __cdecl operator delete(void *);

struct Resource
{
    virtual ~Resource();
    char storage[120];
    Resource(std::string);
};

extern Resource *current;

struct Command
{
    void *table;
    std::string text;
    Command(const char *);
};

Command::Command(const char *value)
    : table((void *)0x81cb74), text(value)
{
    if (!current)
    {
        Resource *replacement =
            new Resource(makeString((const char *)0x81cb78));
        if (replacement != current && current)
            delete current;
        current = replacement;
    }
}
