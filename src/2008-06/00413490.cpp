// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
struct Action {
    void (__thiscall **table)(Action*, int);
};
struct Context {
    Action* find(std::string);
};
struct CutVerb {
    char padding[8];
    Context* context;
    void execute(int);
    void finish(int);
};
void CutVerb::execute(int argument) {
    Action* action = context->find(std::string("Copy"));
    action->table[4](action, argument);
    finish(argument);
}
