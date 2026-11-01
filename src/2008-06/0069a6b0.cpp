// from server: 100% by king_originala
extern "C" void (__cdecl *invalidParameter)();

struct Node {
    Node *left;
    Node *parent;
    Node *right;
    unsigned char key;
    unsigned char padding[3];
    void *value;
};

struct Container {
    unsigned char padding[24];
    Node *head;
};

struct Iterator {
    Container **owner;
    Node *current;
    Container **endOwner;
    Node *end;

    void increment();
};

struct Queue;
extern Iterator *(__thiscall *getIterator)(Queue *, Iterator *);

struct String;
extern String *shadowInvocation;
extern String *blankInvocation;

struct Scene {
    typedef Queue *(__thiscall *GetQueue)(Scene *);
    typedef bool (__thiscall *QueueStarted)(Scene *, unsigned char);
    typedef void (__thiscall *RenderGroup)(Scene *, void *, bool);

    struct Table {
        void *padding0[134];
        GetQueue getQueue;
        void *padding1[7];
        QueueStarted queueStarted;
        void *padding2[84];
        RenderGroup renderGroup;
    };

    Table *table;
    unsigned char padding[0x8a50];
    int stage;

    bool started(unsigned char, const String &);
    bool ended(unsigned char, const String &);
    void render();
};

void Scene::render()
{
    Iterator i;
    getIterator(table->getQueue(this), &i);
    void (__cdecl *invalid)() = invalidParameter;

    for (;;) {
        if (!i.owner || i.owner != i.endOwner)
            invalid();

        if (i.current == i.end)
            break;

        if (!i.owner)
            invalid();

        Container *container = i.owner ? *i.owner : 0;
        if (i.current == container->head)
            invalid();

        Node *node = i.current;
        unsigned char key = node->key;
        Container **owner = i.owner;
        i.increment();

        if (!owner)
            invalid();

        container = owner ? *owner : 0;
        if (node == container->head)
            invalid();

        void *group = node->value;
        if (!table->queueStarted(this, key))
            continue;

        do {
            if (started(key, *(stage == 1 ? shadowInvocation : blankInvocation)))
                break;

            table->renderGroup(this, group, true);
        } while (ended(key, *(stage == 1 ? shadowInvocation : blankInvocation)));
    }
}
