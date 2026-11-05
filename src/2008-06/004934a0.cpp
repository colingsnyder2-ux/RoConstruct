// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_signalfloatargumentc6ada45f4e7a0231.cpp

// Candidate translation unit (score above; library headers required).


extern "C" {
    extern void (__cdecl * const _invalid_parameter_noinfo)();
}

struct Failure {
    unsigned char storage[40];
    Failure();
    ~Failure();
};

__declspec(noreturn) void __cdecl raise_failure(const Failure&);

struct CallableTable {
    void* unused;
    void (__cdecl *invoke)(void*, float);
};

struct Callable {
    CallableTable* table;
    unsigned char unused[4];
    unsigned char data[1];
};

struct Value {
    unsigned char prefix[8];
    Callable callable;
};

struct Node {
    unsigned char prefix[24];
    Value* value;
};

struct Container {
    unsigned char prefix[20];
    Node* end;
};

struct Iterator {
    unsigned char prefix[16];
    Container** owner;
    Node* node;
    unsigned char unused[32];
    float* argument;
    unsigned char* invoked;

    bool equal(const Iterator&);
    void advance();
};

struct Result {
    Result() {}
};

Result __stdcall apply(Iterator first, Iterator last)
{
    if (!first.equal(last)) {
        void (__cdecl *invalid)() = _invalid_parameter_noinfo;
        do {
            if (!*first.invoked) {
                if (!first.owner)
                    invalid();

                Container* container = first.owner ? *first.owner : 0;
                if (first.node == container->end)
                    invalid();

                Callable* callable = &first.node->value->callable;
                float argument = *first.argument;

                if (!callable->table)
                    raise_failure(Failure());

                callable->table->invoke(callable->data, argument);
                if (!*first.invoked)
                    *first.invoked = 1;
            }
            first.advance();
        } while (!first.equal(last));
    }
    return Result();
}