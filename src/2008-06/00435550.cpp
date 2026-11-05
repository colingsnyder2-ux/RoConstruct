// from server: 100% by colin
struct String;

extern String& (__thiscall *append_text)(String*, const char*);
extern String& (__thiscall *append_string)(String*, const String&);
extern const char* (__thiscall *string_data)(const String*);
extern void (__thiscall *destroy_string)(String*);

struct String
{
    unsigned char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroy_string(this);
}

struct Node
{
    int unused;
    String text;
};

struct Link
{
    int unused;
    Node* node;
};

struct Slot
{
    Link* value;
    String render() const;
};

struct Entry
{
    Node* first;
    Link* second;
    Slot third;
};

extern const char separator[];
extern const char suffix[];
extern const char middle[];

void func_00435550(int* count, String* output, const Entry* entry)
{
    if (*count > 0)
        append_text(output, separator);

    {
        const Node* n = entry->second->node;
        append_text(output, string_data(&n->text));
    }
    append_text(output, middle);
    {
        const Node* f = entry->first;
        append_text(output, string_data(&f->text));
    }

    {
        const Link* v = entry->third.value;
        if (v == entry->second)
        {
            append_text(output, suffix);
            append_string(output, entry->third.render());
        }
    }

    ++*count;
}
