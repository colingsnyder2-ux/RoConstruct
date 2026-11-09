// from server: 70% by atomic.potato
struct S
{
    char data[0x1f8];
    S& f(const S& value);
};

extern "C" S& __stdcall basic_string_copy(S* destination, const S* source);

S& S::f(const S& value)
{
    basic_string_copy(reinterpret_cast<S*>(reinterpret_cast<char*>(this) + 0x1f8), &value);
    return const_cast<S&>(value);
}
