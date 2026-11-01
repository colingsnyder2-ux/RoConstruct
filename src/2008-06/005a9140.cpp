// from server: 100% by king_originala
typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Alloc>
class basic_string {
    char storage[28];
public:
    basic_string(const T*);
    ~basic_string();
};

template<class T, class Traits, class Alloc>
__forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
{
    constructString(this, text);
}

typedef basic_string<char, char_traits<char>, allocator<char> > string;

class exception {
    char* message;
    int ownsMessage;
public:
    virtual ~exception();
};

class runtime_error : public exception {
    string message;
public:
    runtime_error(const string&);
    virtual ~runtime_error();
};
}

struct State;

struct ThreadRef {
    char storage[24];
    State* thread;
    unsigned int tail;

    ThreadRef(State*);
    ~ThreadRef();
};

struct Scheduler {
    void delay(State*, double);
};

struct Context {
    char storage[0x1a8];
    Scheduler* scheduler;
};

extern "C" {
int __cdecl gettop(State*);
double __cdecl tonumber(State*, int);
State* __cdecl newthread(State*);
void __cdecl pushvalue(State*, int);
void __cdecl xmove(State*, State*, int);
void __cdecl pushinteger(State*, int);
void __cdecl gettable(State*, int);
Context* __cdecl touserdata(State*, int);
void __cdecl settop(State*, int);
}

int __cdecl delayFunction(State* state)
{
    if (gettop(state) < 2)
        throw std::runtime_error(
            std::string("delay function requires 2 arguments"));

    double seconds = tonumber(state, 1);
    ThreadRef reference(newthread(state));
    pushvalue(state, 2);
    xmove(state, reference.thread, 1);
    State* thread = reference.thread;
    pushinteger(state, 67);
    gettable(state, -10002);
    Context* context = touserdata(state, -1);
    settop(state, -2);
    context->scheduler->delay(thread, seconds);
    settop(state, -2);
    return 0;
}
