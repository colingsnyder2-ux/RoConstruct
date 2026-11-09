// from server: 74% by tajop
extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct bad_function_call {
    char data[0x28];
    bad_function_call();
};

__declspec(noreturn) void throw_exception(const bad_function_call& e);

struct Mutex {
    void* handle;
    bool flag;
    void lock();
    void unlock();
};

struct Function {
    void* manager;
    void* functor;
    void (*invoker)(void* functor, void* a0);
    void operator()(void* a0) const
    {
        if (!manager)
            throw_exception(bad_function_call());
        invoker(functor, a0);
    }
};

struct FuncVec {
    int alloc;
    Function** first;
    Function** last;
    Function** end;
    Function*& operator[](unsigned i)
    {
        if (!first || i >= (unsigned)(last - first))
            _invalid_parameter_noinfo();
        return first[i];
    }
};

struct ArgVec {
    int alloc;
    void** first;
    void** last;
    void** end;
    unsigned size() const;
    void*& operator[](unsigned i)
    {
        if (!first || i >= (unsigned)(last - first))
            _invalid_parameter_noinfo();
        return first[i];
    }
};

struct Registry {
    Mutex mutex;
    FuncVec funcs;
};

extern Registry* g_registry;

void invokeAll(ArgVec* v)
{
    for (unsigned i = 0; i < v->size(); ++i) {
        Mutex* m = &g_registry->mutex;
        m->lock();
        void*& a = (*v)[i];
        (*g_registry->funcs[i])(a);
        (*v)[i] = 0;
        m->unlock();
    }
}
