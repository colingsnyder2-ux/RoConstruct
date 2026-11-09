// from server: 100% by tajop
struct Manager
{
    int pad0;
    void (*destroy)(void*);
};

struct Functor
{
    int head;
    char tag[4];
    Manager* manager;
    char buffer[0x3c];

    ~Functor()
    {
        if (manager)
            manager->destroy(buffer);
    }
};

struct Container
{
    void* node;
    void insert(void* key, void* where, void* value);
};

extern void* buyNode();
extern void* endNode();
extern void* keyOf(Functor* item);

struct Scale9FrameData
{
    char pad0[0x1c];
    Container items;

    void init(Functor first, Functor second);
};

void Scale9FrameData::init(Functor first, Functor second)
{
    items.node = buyNode();
    void* where = endNode();
    items.insert(keyOf(&first), where, first.tag);
    where = endNode();
    items.insert(keyOf(&second), where, second.tag);
}
