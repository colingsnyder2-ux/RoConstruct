// from server: 100% by king_originala
struct Worker {
    int run(int);
};

struct State {
    int reserved;
    Worker* volatile worker;
};

struct Link {
    int reserved;
    int previous;
};

struct Context {
    int previous;
    Link* link;
    void* handle;
    int active;

    Context(void*);
};

extern "C" void* __stdcall get_context();
extern "C" State* __stdcall get_state();
extern "C" void __stdcall release_context(int, void*);

int __stdcall func(int)
{
    Context context(get_context());
    Worker* worker = get_state()->worker;
    int result = worker->run(0) ? 0 : (int)0x80004005u;

    if (context.link)
        context.link->previous = context.previous;

    if (context.active)
        release_context(0, context.handle);

    return result;
}
