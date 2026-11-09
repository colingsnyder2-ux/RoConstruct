// from server: 100% by tester
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Value
{
    char data[0x24];
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
