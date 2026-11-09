// from server: 61% by atomic.potato
struct BasicString {
    char pad0[28];
};

struct S_func_0065f060 {
    char pad0[172];
    BasicString m_string;
    BasicString* f(BasicString* value);
};

BasicString* S_func_0065f060::f(BasicString* value)
{
    BasicString* (__thiscall *basic_string_copy)(BasicString*, const BasicString*) =
        0;
    basic_string_copy(value, &m_string);
    value->pad0[28] = m_string.pad0[28];
    return value;
}
