// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class C, class T, class A>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const C*);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern void (__thiscall *stringConstruct)(std::string*, const char*);
extern void (__thiscall *stringDestroy)(std::string*);

namespace std {
    template<class C, class T, class A>
    inline basic_string<C, T, A>::basic_string(const C* text)
    {
        stringConstruct(this, text);
    }

    template<class C, class T, class A>
    inline basic_string<C, T, A>::~basic_string()
    {
        stringDestroy(this);
    }
}

extern bool ignoreFailure;
extern bool (__cdecl *failureHandler)(
    const char*, const std::string&, const char*, int, bool*, bool);

extern void __cdecl beginFailure();
extern void __cdecl endFailure();
extern void (__stdcall *exitFunction)(int);

struct S {
    void* const* vtable;
    void* entries;
    int count;

    void runMainLoop();
    void step();
};

void S::runMainLoop()
{
    typedef bool (__thiscall *RequiresMainLoop)(S*);

    if (!ignoreFailure &&
        reinterpret_cast<RequiresMainLoop>(vtable[33])(this)) {
        beginFailure();

        if (failureHandler &&
            failureHandler(
                "requiresMainLoop() == false",
                std::string("This GWindow implementation failed to overwrite runMainLoop even though it requires a main loop."),
                "d:\\Roblox\\Releases\\2008.06.17\\Client\\Rendering\\g3d\\include\\GLG3D/GWindow.h",
                521, &ignoreFailure, true)) {
            exitFunction(-1);
        }

        endFailure();
    }

    while (count > 0)
        step();
}
