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
struct Link {
    int reserved;
    int previous;
};

extern "C" void* __stdcall get_context();
extern void __stdcall release_context(int, void*);

struct Context {
    int previous;
    Link* link;
    void* handle;
    int active;

    Context(void*);
    ~Context();
};



struct Service {
    void run(std::string, int);
};

extern Service* service;


__forceinline Context::~Context()
{
    if (link)
        link->previous = previous;
    if (active)
        release_context(0, handle);
}

void __cdecl func(const char* text)
{
    Context context(get_context());
    service->run(std::string(text), 0);
}
