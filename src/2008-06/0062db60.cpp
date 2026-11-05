// from server: 100% by king_originala
struct PartInstance;

struct GetSetImpl
{
    static PartInstance* __cdecl get(PartInstance* p);
};

struct Array
{
    PartInstance** data;
    int count;
    int capacity;

    void resize(int size, int value);
    void append(PartInstance* const& value);
    PartInstance*& operator[](int index);
};

inline PartInstance*& Array::operator[](int index)
{
    return data[index];
}

struct Query
{
    void collect(void* first, PartInstance* second, Array* result);
};

struct Context
{
    char padding[0x84];
    Query* query;
};

struct Owner
{
    char padding[0x2e4];
    Context* context;
};

struct S
{
    char padding[0x130];
    Owner* owner;
    Array temporary;

    void f(void* first, PartInstance* second, Array* result);
};

void S::f(void* first, PartInstance* second, Array* result)
{
    if (owner)
    {
        Query* query = owner->context->query;
        temporary.resize(0, 0);
        query->collect(first, second, &temporary);
        for (int i = 0; i < temporary.count; ++i)
        {
            second = GetSetImpl::get(temporary[i]);
            result->append(second);
        }
    }
}
