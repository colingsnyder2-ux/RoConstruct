// from server: 100% by king_originala
extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct Failure {
    char data[40];
    Failure();
    ~Failure();
};

__declspec(noreturn) void __cdecl raiseFailure(const Failure&);

struct Dispatcher {
    void* reserved;
    void (__cdecl* invoke)(void*, char);
};

struct Function {
    Dispatcher* dispatcher;
    char padding[4];
    char storage[16];

    void operator()(char value);
};

__forceinline void Function::operator()(char value)
{
    if (!dispatcher)
        raiseFailure(Failure());

    dispatcher->invoke(storage, value);
}

struct Callable {
    char reserved[8];
    Function function;
};

struct Node {
    char reserved[24];
    Callable* callable;
};

struct Container {
    char reserved[20];
    Node* sentinel;
};

struct Owner {
    Container* container;
};

struct Iterator {
    char reserved[16];
    Owner* owner;
    Node* node;
    char padding[32];
    const char* value;
    bool* visited;

    bool equal(const Iterator&);
    void advance();
};

void* __stdcall process(void* result, Iterator first, Iterator last)
{
    if (!first.equal(last)) {
        void (__cdecl* const invalid)() = invalid_parameter_noinfo;

        do {
            if (!*first.visited) {
                if (!first.owner)
                    invalid();

                Container* container =
                    first.owner ? first.owner->container : 0;

                if (first.node == container->sentinel)
                    invalid();

                Function& function = first.node->callable->function;
                char value = *first.value;
                function(value);

                if (!*first.visited)
                    *first.visited = true;
            }

            first.advance();
        } while (!first.equal(last));
    }

    return result;
}
