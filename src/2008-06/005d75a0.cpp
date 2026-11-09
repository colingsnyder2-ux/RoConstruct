// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_humanoid_head_helper_ad653ae437611735.cpp

// Candidate translation unit (score above; library headers required).
extern "C" {
    extern void (__thiscall *stringConstruct)(void*, const char*);
    extern void (__thiscall *stringDestroy)(void*);
}

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        stringConstruct(this, text);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        stringDestroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern char instanceType[];
extern char partInstanceType[];

extern "C" void* __cdecl dynamicCast(
    void*, long, void*, void*, int);

struct Instance {
    void* findChild(const std::string&);
};

void* getHead(Instance* instance)
{
    return instance ? dynamicCast(
        instance->findChild(std::string("Head")),
        0,
        instanceType,
        partInstanceType,
        0) : 0;
}
