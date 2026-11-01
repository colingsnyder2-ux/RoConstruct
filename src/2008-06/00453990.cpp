// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Model;

struct Pair {
    Model* object;
    Control* control;
    Pair(const Pair&);
    ~Pair();
};

Pair::Pair(const Pair& other) : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

Pair::~Pair()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Guard {
    unsigned char storage[12];
    Guard(Pair);
    ~Guard();
};

struct String;
extern void (__thiscall *string_construct)(String*);
extern void (__thiscall *string_destroy)(String*);
extern const char* (__thiscall *string_c_str)(const String*);

struct String {
    unsigned char storage[28];
    String();
    ~String();
    const char* c_str() const;
};

String::String()
{
    string_construct(this);
}

String::~String()
{
    string_destroy(this);
}

const char* String::c_str() const
{
    return string_c_str(this);
}

struct Text;
extern void (__thiscall *text_construct)(Text*);
extern void (__thiscall *text_destroy)(Text*);
extern const char* (__thiscall *text_data)(const Text*);
extern void (__cdecl *format_text)(Text*, unsigned int, const char*);

struct Text {
    void* storage;
    Text();
    __declspec(nothrow) ~Text();
    operator const char*() const;

    __declspec(dllimport) void __thiscall destroyImport() throw();
};

Text::Text()
{
    text_construct(this);
}

__declspec(nothrow) Text::~Text()
{
    destroyImport();
}

Text::operator const char*() const
{
    return text_data(this);
}

struct Command {
    virtual void enable(int) = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void setText(const char*) = 0;
};

typedef void (__thiscall *SetTextFunction)(Command*, const char*);

struct Controller {
    bool query(String*, int);
};

struct Model {
    Controller* controller();
};

struct Source {
    Pair get();
};

struct Document {
    unsigned char padding[148];
    Source* source;
    void update(Command*);
};

void Document::update(Command* command)
{
    Pair model = source->get();
    Guard guard(model);
    Controller* controller = model.object->controller();
    String message;
    command->enable(controller->query(&message, 0));
    Text text;
    format_text(&text, 0x83, message.c_str());
    SetTextFunction* slot =
        *reinterpret_cast<SetTextFunction**>(command) + 3;
    const char* value = text;
    (*slot)(command, value);
}
