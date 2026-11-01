// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Value
{
    char storage[0x34];
    Value(const Value&);
};

struct Holder
{
    Value* value;
    Holder(const Value&);
};

Holder::Holder(const Value& source)
{
    value = new Value(source);
}
