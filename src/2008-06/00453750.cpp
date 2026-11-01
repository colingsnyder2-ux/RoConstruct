// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long use_count;
    volatile long weak_count;
};

struct Object;
struct Shared {
    Object* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->use_count;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->use_count) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak_count) == 0)
                p->destroy();
        }
    }
}

struct Text {
    unsigned char data[28];
    Text();
    ~Text();
    const char* c_str() const;
};

extern void (__thiscall* text_construct)(Text*);
extern void (__thiscall* text_destroy)(Text*);
extern const char* (__thiscall* text_data)(const Text*);

inline Text::Text()
{
    text_construct(this);
}

inline Text::~Text()
{
    text_destroy(this);
}

inline const char* Text::c_str() const
{
    return text_data(this);
}

struct Message {
    void* data;
    Message();
    __declspec(nothrow) ~Message();
    const char* text() const;

    __declspec(dllimport) void __thiscall destroyImport() throw();
};

extern void (__thiscall* message_construct)(Message*);
extern void (__thiscall* message_destroy)(Message*);
extern const char* (__thiscall* message_data)(const Message*);
extern void (__cdecl* format_message)(Message*, unsigned int, const char*);

inline Message::Message()
{
    message_construct(this);
}

inline Message::~Message()
{
    destroyImport();
}

inline const char* Message::text() const
{
    return message_data(this);
}

struct Worker {
    bool query(Text*, int);
};

struct Object {
    Worker* worker();
};

struct Provider {
    Shared acquire();
};

struct Guard {
    unsigned char data[12];
    Guard(Shared);
    ~Guard();
};

struct Receiver;
typedef void (__thiscall* MessageSetter)(Receiver*, const char*);

struct ReceiverTable {
    void (__thiscall* set_result)(Receiver*, int);
    void (__thiscall* reserved1)(Receiver*);
    void (__thiscall* reserved2)(Receiver*);
    MessageSetter set_message;
};

struct Receiver {
    ReceiverTable* table;
};

struct CRobloxDoc {
    unsigned char padding[148];
    Provider* provider;
    void f(Receiver*);
};

void CRobloxDoc::f(Receiver* receiver)
{
    Shared shared = provider->acquire();
    Guard guard(shared);
    Worker* worker = shared.object->worker();
    Text text;
    receiver->table->set_result(receiver, worker->query(&text, 0));
    Message message;
    format_message(&message, 130, text.c_str());
    MessageSetter* setter = &receiver->table->set_message;
    const char* value = message.text();
    (*setter)(receiver, value);
}
