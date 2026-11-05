// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern void (__thiscall *string_construct)(void*, const char*);
extern void (__thiscall *string_destroy)(void*);

struct String
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    String(const char*);
    ~String();
    const char* c_str() const;
};

inline String::String(const char* text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

inline const char* String::c_str() const
{
    return capacity >= 16 ? pointer : buffer;
}

struct Exception
{
    char storage[40];
    Exception(const String&);
};

extern void* exception_type;
extern "C" __declspec(noreturn) void __stdcall raise_exception(void*, void*);

struct BitStream
{
    char storage[276];
    BitStream();
    ~BitStream();
};

extern void __cdecl write_byte(BitStream*, int);
extern void __cdecl write_integer(BitStream*, int);
extern void __cdecl write_string(BitStream*, const String*);

struct Player
{
    char storage[8];
    String* name;
    int identifier;
    void prepare();
};

struct ReferenceCount
{
    unsigned int reserved;
    volatile long count;
};

struct PlayerPointer
{
    Player* pointer;
    ReferenceCount* reference;
    PlayerPointer(const PlayerPointer&);
};

inline PlayerPointer::PlayerPointer(const PlayerPointer& other)
    : pointer(other.pointer), reference(other.reference)
{
    if (reference)
    {
        volatile long* counter = reinterpret_cast<volatile long*>(reference);
        ++counter;
        _InterlockedExchangeAdd(counter, 1);
    }
}

struct Event
{
    char storage[72];
    Event(const char*, PlayerPointer);
    Event(const Event&);
    ~Event();
};

struct Signal
{
    char storage[112];
    void invoke(Event);
};

struct Connection;
struct ConnectionTable
{
    void* entries[13];
    void (__thiscall *send)(Connection*, BitStream*, int, int, int,
                           unsigned int, unsigned int, int);
};

struct Connection
{
    ConnectionTable* table;
};

extern unsigned int destination_low;
extern unsigned int destination_high;

struct S
{
    char storage[304];
    Signal signal;
    PlayerPointer local;
    Connection* connection;

    void f(String text);
};

void S::f(String text)
{
    if (!local.pointer)
    {
        String message("No local Player to chat from");
        Exception error(message);
        raise_exception(&error, &exception_type);
    }

    BitStream stream;
    write_byte(&stream, 81);

    Player* player = local.pointer;
    player->prepare();
    String* name = reinterpret_cast<String*>(
        reinterpret_cast<char*>(player->name) + 4);
    int identifier = player->identifier;

    write_string(&stream, name);
    write_integer(&stream, identifier);
    write_string(&stream, &text);

    connection->table->send(connection, &stream, 1, 2, 2,
                            destination_low, destination_high, 1);

    Event event(text.c_str(), local);
    signal.invoke(event);
}
