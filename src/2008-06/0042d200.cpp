// from server: 100% by king_originala
extern "C" void* __cdecl get_type();
void* __cdecl operator new(unsigned int);
extern unsigned int holder_table[];

struct Holder {
    void* table;
    float value;
    Holder(const float& v);
};

inline Holder::Holder(const float& v)
{
    table = holder_table;
    value = v;
}

struct S {
    void* type;
    Holder* holder;
    S(const float& value);
};

S::S(const float& value)
{
    type = get_type();
    holder = new Holder(value);
}
