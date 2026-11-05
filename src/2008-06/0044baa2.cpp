// from server: 52% by king_originala
struct Object;

struct VTable {
    void (__thiscall *destroy)(Object *, unsigned int);
    void *unused04[25];
    void *(__thiscall *first)(Object *);
    Object *(__thiscall *next)(Object *, void **);
    void *unused70[2];
    int (__thiscall *newDocument)(Object *);
    void *unused7C[2];
    void (__thiscall *close)(Object *);
    void *unused88;
    void (__thiscall *attach)(Object *, Object *);
    void *unused90[2];
    int (__thiscall *initialize)(Object *);
};

struct Object {
    VTable *vtable;
};

struct View : Object {
    char unused04[28];
    void *window;
};

namespace std {
    template<class T> struct char_traits;
    template<class T> struct allocator;
    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        basic_string(const T *);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Exception {
    char storage[36];
    Exception(const std::string &);
    ~Exception();
};

extern "C" int __stdcall message(unsigned int, unsigned int, unsigned int);
extern "C" void __stdcall raiseException(void *, void *);
extern "C" long __stdcall SendMessageA(void *, unsigned int, unsigned int, long);
extern void __cdecl activate(int, Object *);

extern Object *activeDocument;
extern Object *temporaryObject;
extern char exceptionType;

struct Module : Object {
    char unused04[140];
    Object *document;
    Object *run();
};

Object *Module::run()
{
    message(0xF104, 0, ~0U);

    Object *previous = document;
    if (previous)
        previous->vtable->close(previous);

    raiseException(0, 0);

    if (!vtable->initialize(this)) {
        std::string text("CDocument::OnNewDocument returned FALSE");
        Exception error(text);
        raiseException(&error, &exceptionType);
    }

    vtable->attach(this, document);

    if (!document->vtable->newDocument(document)) {
        std::string text("User cancelled");
        Exception error(text);
        raiseException(&error, &exceptionType);
    }

    if (activeDocument == document)
        activate(1, activeDocument);

    void *position = document->vtable->first(document);
    while (position) {
        View *view = static_cast<View *>(
            document->vtable->next(document, &position));

        Object *old = temporaryObject;
        temporaryObject = 0;
        if (old)
            old->vtable->destroy(old, 1);

        SendMessageA(view->window, 0x364, 0, 0);
    }

    return document;
}
