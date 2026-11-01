// from server: 100% by king_originala
namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string
    {
        unsigned char allocator_storage[4];
        union
        {
            T buffer[16];
            T *pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T *);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern void (__thiscall *string_constructor)(std::string *, const char *);

namespace std
{
    template<>
    __forceinline basic_string<char, char_traits<char>, allocator<char> >::basic_string(const char *text)
    {
        string_constructor(this, text);
    }
}

struct ScriptState;

struct ThreadStorage
{
    ScriptState *sub_5a7570();
    void sub_5a76b0(ScriptState *);
    void sub_5a6ff0(ScriptState *);
};

extern "C" ThreadStorage *__cdecl sub_42bbb0();
extern "C" int *__cdecl sub_493760();
extern "C" int __cdecl sub_622400(ScriptState *, int);
extern "C" void __cdecl sub_5ac610(ScriptState *);

struct StateGuard
{
    ScriptState *previous;
    StateGuard(ScriptState *);
    ~StateGuard();
};

__forceinline StateGuard::~StateGuard()
{
    ThreadStorage *storage = sub_42bbb0();
    ScriptState *current = storage->sub_5a7570();
    if (current != previous)
    {
        storage->sub_5a76b0(previous);
        if (current)
            storage->sub_5a6ff0(current);
    }
}

struct ScriptError
{
    unsigned char data[40];
    ScriptError(const std::string &);
    ScriptError(const ScriptError &);
    ~ScriptError();
};

struct Scheduler
{
    void sub_6217d0(ScriptState *);
};

struct StateHeader
{
    unsigned char padding[8];
    unsigned char suspended;
};

struct S
{
    unsigned char padding0[0x1a8];
    Scheduler *scheduler;
    unsigned char padding1[0x1c];
    void *volatile timeout;

    int sub_5ae0d0(ScriptState *, int);
};

int S::sub_5ae0d0(ScriptState *state, int arguments)
{
    int result;
    {
        StateGuard guard(state);
        if (timeout && *sub_493760() == 2)
        {
            std::string message("Game script timout");
            throw ScriptError(message);
        }
        result = sub_622400(state, arguments);
    }

    switch (result)
    {
    case 0:
        return 0;
    case 1:
        {
            StateHeader *header = state
                ? reinterpret_cast<StateHeader *>(
                    reinterpret_cast<char *>(state) - 12)
                : 0;
            if (!header->suspended)
                scheduler->sub_6217d0(state);
            return 1;
        }
    default:
        sub_5ac610(state);
        return 2;
    }
}
