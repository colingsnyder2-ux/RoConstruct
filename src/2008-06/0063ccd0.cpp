// from server: 100% by king_originala
struct Value
{
    unsigned int words[6];
};

extern bool __cdecl func_0060a2f0(...);
extern char descriptor;

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

struct S
{
    void* tag;
    unsigned int reserved;
    unsigned char storage[sizeof(Value)];

    void f(const Value& value);
};

void S::f(const Value& value)
{
    if (!func_0060a2f0(&value))
    {
        new (storage) Value(value);
        tag = &descriptor;
    }
    else
    {
        tag = 0;
    }
}
