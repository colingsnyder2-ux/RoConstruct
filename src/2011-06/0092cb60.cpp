// from server: 89% by atomic.potato
struct String
{
    String& operator=(const String&);
    char data[24];
};

extern "C" String& assign_string(String*, const String*);

void copy_strings(String* begin, String* end, String* source)
{
    while (begin != end)
    {
        *begin = *source;
        begin->data[28] = source->data[28];
        begin = (String*)((char*)begin + 32);
    }
}
