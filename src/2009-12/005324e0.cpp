// from server: 60% by atomic.potato
struct String
{
    String(const String&);
};

struct Ray
{
    String f(const String&);
};

String Ray::f(const String& value)
{
    return String(value);
}
