// from server: 59% by atomic.potato
struct String
{
    String(const String&);
};

struct Creator
{
    Creator* f(String*, const String&);
};

Creator* Creator::f(String* result, const String& value)
{
    result->String::String(value);
    return this;
}
