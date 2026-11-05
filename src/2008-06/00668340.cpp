// from server: 100% by king_originala
struct Item
{
    char reserved[12];
    void* first;
    void* second;
};

struct Result
{
    unsigned long data[3];
};

struct Entry
{
    void* key;
    Item* value;
};

struct FirstContainer
{
    char reserved[32];
    Result insert(Item* const&);
};

struct SecondContainer
{
    Result insert(const Entry&);
};

struct S
{
    char reserved[16];
    FirstContainer first;
    SecondContainer second;

    void f(Item*);
};

void S::f(Item* item)
{
    Item* value = item;
    first.insert(value);

    void* key = item->first;
    if (key)
    {
        Entry entry;
        entry.key = key;
        entry.value = item;
        second.insert(entry);
    }

    key = item->second;
    if (key)
    {
        Entry entry;
        entry.key = key;
        entry.value = item;
        second.insert(entry);
    }
}
