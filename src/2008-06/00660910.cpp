// from server: 100% by king_originala
struct String {
    unsigned char padding[5];
    unsigned char flags;
};

struct Local {
    String* name;
    int start;
    int end;
};

struct Prototype {
    unsigned char padding0[5];
    unsigned char flags;
    unsigned char padding1[18];
    Local* locals;
    unsigned char padding2[28];
    int capacity;
};

struct FunctionState {
    Prototype* prototype;
    unsigned char padding[44];
    short localCount;
};

struct Parser {
    unsigned char padding[48];
    FunctionState* function;
    void* state;
};

extern "C" void* __cdecl growVector(
    void*, void*, int*, int, int, const char*);
extern "C" void __cdecl barrier(void*, Prototype*, String*);

int __cdecl registerLocal(Parser* parser, String* name)
{
    FunctionState* function = parser->function;
    Prototype* prototype = function->prototype;
    int oldCapacity = prototype->capacity;

    if (function->localCount + 1 > prototype->capacity)
        prototype->locals = (Local*)growVector(
            parser->state, prototype->locals, &prototype->capacity,
            12, 32767, "too many local variables");

    while (oldCapacity < prototype->capacity) {
        prototype->locals[oldCapacity].name = 0;
        ++oldCapacity;
    }

    prototype->locals[function->localCount].name = name;

    if ((name->flags & 3) && (prototype->flags & 4))
        barrier(parser->state, prototype, name);

    return function->localCount++;
}
