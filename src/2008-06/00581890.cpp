// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Iterator
{
    void* owner;
    void** position;
};

struct Function
{
    void (__cdecl *callback)(void*, void*);
    void* context;
    Function();
};

Function __cdecl apply(Iterator, Iterator, Function);
void __cdecl callback(void*, void*);
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct Selection
{
    char padding[0x13c];
    void* owner;
    char reserved[8];
    void** begin;
    void** end;

    int contains(void*);
};

struct Ref
{
    Selection* get();
};

struct S
{
    char padding[0x20];
    Ref* reference;

    void execute(void*);
};

void S::execute(void* argument)
{
    Selection* selection = reference ? reference->get() : 0;
    void* context = selection->contains(argument) ? argument : 0;

    Iterator last;
    last.position = selection->end;
    if (selection->begin > selection->end)
        _invalid_parameter_noinfo();

    Iterator first;
    first.position = selection->begin;
    last.owner = selection->owner;
    if (first.position > selection->end)
        _invalid_parameter_noinfo();
    first.owner = selection->owner;

    struct CallbackData
    {
        void (__cdecl *callback)(void*, void*);
        void* context;
    };

    CallbackData function = { callback, context };
    apply(first, last, *reinterpret_cast<Function*>(&function));
}
