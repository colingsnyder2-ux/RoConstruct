// from server: 47% by atomic.potato
struct BasicString
{
    BasicString(const BasicString&);
};

struct S
{
    S* f(const BasicString&);
};

S* S::f(const BasicString& value)
{
    BasicString* target = reinterpret_cast<BasicString*>(reinterpret_cast<char*>(this) - 176);
    BasicString result(value);
    *target = result;
    return this;
}
