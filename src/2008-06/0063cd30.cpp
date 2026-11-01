// from server: 100% by king_originala
inline void* operator new(unsigned int, void* p) { return p; }

struct Value {
    unsigned int data[6];
};

extern "C" bool __cdecl func_0060a2f0(const Value&);
extern unsigned char table_00849d08;

struct S {
    void* table;
    unsigned int reserved;
    Value value;

    void set(const Value&);
};

void S::set(const Value& source)
{
    if (!func_0060a2f0(source)) {
        new (&value) Value(source);
        table = &table_00849d08;
    } else {
        table = 0;
    }
}
