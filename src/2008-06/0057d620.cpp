// from server: 100% by king_originala
struct Cam
{
    void setCameraType(int);
};

struct Provider
{
    virtual void v0();
    virtual Cam* getCamera();
};

struct Context
{
    char pad[0x288];
    Provider provider;
};

struct String
{
    int reserved;
    union
    {
        char buffer[16];
        char* pointer;
    } data;
    unsigned length;
    unsigned capacity;
};

struct Name
{
    int reserved;
    String text;
};

struct Result
{
    virtual void finish(int);
};

extern void __cdecl handle(int, int);

struct Command
{
    int reserved0;
    Name* name;
    int reserved8;
    Context* context;

    void execute(Result*);
};

void Command::execute(Result* result)
{
    context->provider.getCamera()->setCameraType(0);

    String* text = &name->text;
    const char* value = text->capacity >= 16
        ? text->data.pointer
        : text->data.buffer;

    handle(reinterpret_cast<int>(value), reinterpret_cast<int>(context));
    result->finish(1);
}
