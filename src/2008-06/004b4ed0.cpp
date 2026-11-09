// from server: 100% by king_originala
extern "C" {
    extern void (__cdecl *invalid_parameter_noinfo)();
}

struct Node;

struct Container {
    char padding[20];
    Node* sentinel;
};

struct CallbackTable {
    void* reserved;
    void (__cdecl *invoke)(void*);
};

struct Callback {
    CallbackTable* table;
    unsigned int reserved;
    char storage[16];
};

struct Value {
    char padding[8];
    Callback callback;
};

struct Node {
    char padding[24];
    Value* value;
};

struct Iterator {
    char prefix[16];
    Container** owner;
    Node* node;
    char padding[36];
    unsigned char* visited;

    bool equal(const Iterator*);
    void advance();
};

struct BadCall {
    char storage[40];
    BadCall();
    ~BadCall();
};

__declspec(noreturn) void __cdecl raise_bad_call(const BadCall&);

struct Result {
    Result() {}
};

Result __stdcall process(Iterator first, Iterator last)
{
    if (!first.equal(&last)) {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        do {
            if (!*first.visited) {
                if (!first.owner)
                    invalid();

                Container* container = first.owner ? *first.owner : 0;
                if (first.node == container->sentinel)
                    invalid();

                Callback* callback = &first.node->value->callback;
                if (!callback->table)
                    raise_bad_call(BadCall());

                callback->table->invoke(callback->storage);

                if (!*first.visited)
                    *first.visited = 1;
            }
            first.advance();
        } while (!first.equal(&last));
    }
    return Result();
}
