// from server: 34% by atomic.potato
struct BasicString
{
    BasicString(const BasicString&);
};

struct S
{
    void f(BasicString&);
};

void S::f(BasicString& value)
{
    BasicString* destination = (BasicString*)((char*)this + 4);
    BasicString copy(value);
    destination[7] = copy;
}
