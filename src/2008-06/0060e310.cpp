// from server: 100% by king_originala
void __cdecl alignedFree(void*);

struct Array {
    void* data;
    int count;
    int capacity;

    Array();
    ~Array();
};

inline Array::Array()
{
    count = 0;
    capacity = 0;
    data = 0;
}

inline Array::~Array()
{
    alignedFree(data);
}

void __cdecl gather(void*, Array*);
void __cdecl process(Array*, void*, void*);

struct Contact {
    char padding[8];
    char state[32];
    void* value;

    void update(void*);
};

void Contact::update(void* argument)
{
    Array temporary;
    gather(state, &temporary);
    process(&temporary, argument, value);
}
