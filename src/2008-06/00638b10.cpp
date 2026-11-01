// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct ExceptionObject
{
    unsigned long words[10];
    ExceptionObject();
    ~ExceptionObject();
};

extern __declspec(noreturn) void __cdecl raise_exception(const void *);

struct FunctionManager
{
    void *reserved;
    void (__cdecl *invoke)(void *, double);
};

struct Callable
{
    FunctionManager *manager;
    unsigned long unused;
    unsigned long storage[2];

    void operator()(double value);
};

inline void Callable::operator()(double value)
{
    if (!manager)
        (raise_exception(&ExceptionObject()), __assume(0));
    manager->invoke(storage, value);
}

struct FunctionObject
{
    unsigned long reserved[2];
    Callable callable;
};

struct Node
{
    unsigned long reserved[6];
    FunctionObject *function;
};

struct Owner
{
    unsigned long reserved[5];
    Node *end;
};

struct Iterator
{
    unsigned long reserved[4];
    Owner **owner;
    Node *node;
    unsigned long unused[8];
    double *value;
    bool *done;

    bool equal(const Iterator &other);
    void advance();
};

void *__stdcall process(void *result, Iterator first, Iterator last)
{
    if (!first.equal(last))
    {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        do
        {
            if (!*first.done)
            {
                if (!first.owner)
                    invalid();

                Owner *owner = first.owner ? *first.owner : 0;
                if (first.node == owner->end)
                    invalid();

                Callable *callable = &first.node->function->callable;
                (*callable)(*first.value);

                if (!*first.done)
                    *first.done = true;
            }

            first.advance();
        } while (!first.equal(last));
    }

    return result;
}
