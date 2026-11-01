// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class C, class T, class A>
    class basic_string {
    public:
        unsigned char allocator_storage;
        union {
            C buffer[16];
            C* pointer;
        } storage;
        unsigned length;
        unsigned capacity;

        __declspec(dllimport) ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Command;
struct Owner;

struct CommandMap {
    Command** lookup(Owner* const& key);
};

struct Owner {
    unsigned reserved;
    CommandMap commands;
};

extern "C" void* __cdecl intern_name(const char* name, int length);

struct Command {
    unsigned reserved;
    void* name;
    Owner* owner;

    Command(Owner* source, String text);
};

Command::Command(Owner* source, String text)
{
    const char* characters = text.storage.pointer;
    if (text.capacity < 16)
        characters = text.storage.buffer;

    void* interned = intern_name(characters, -1);
    name = interned;
    owner = source;
    *owner->commands.lookup((Owner*)interned) = this;
}
