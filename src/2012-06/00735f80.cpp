// from server: 46% by atomic.potato
struct String
{
    String(const String&);
};

struct ImageLabel
{
    int f(String&);
};

String::String(const String&)
{
}

int ImageLabel::f(String& value)
{
    String* target = reinterpret_cast<String*>(reinterpret_cast<char*>(this) + 4);
    target->~String();
    target = new String(value);
    return reinterpret_cast<int>(this);
}
