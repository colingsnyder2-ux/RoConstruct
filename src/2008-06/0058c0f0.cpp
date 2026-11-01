// from server: 100% by king_originala
struct List;

struct Proxy {
    List* list;
};

struct Node {
    Node* next;
    Node* previous;
};

struct Iterator {
    Proxy* owner;
    Node* node;
};

struct List {
    Proxy* volatile proxy;
    unsigned char padding[16];
    Node* head;
    unsigned int size;

    Iterator erase(Iterator first, Iterator last);
};

extern "C" {
    extern void (__cdecl* invalid_parameter_noinfo)();
}

struct S {
    unsigned char padding[0x138];
    List history;
    Iterator current;
    Iterator previous;
    unsigned char reserved;
    bool enabled;

    void trim();
    void update();
};

void S::update()
{
    if (enabled) {
        Proxy* owner = current.owner;
        Proxy* expected = history.proxy;
        Node* end = history.head;
        void (__cdecl* invalid)() = invalid_parameter_noinfo;
        List* list = &history;

        if (!owner || owner != expected)
            invalid();

        if (current.node != end) {
            Iterator last;
            last.node = list->head;
            last.owner = list->proxy;
            list->erase(current, last);

            Iterator position;
            position.node = *reinterpret_cast<Node* volatile*>(&list->head);
            position.owner = list->proxy;
            current = position;

            Node* node = list->head;
            Proxy* proxy = list->proxy;

            if (!proxy)
                invalid();

            node = node->previous;

            List* container = proxy ? proxy->list : 0;
            if (node == container->head)
                invalid();

            Iterator before;
            before.owner = proxy;
            before.node = node;
            previous = before;
        }

        while (history.size > 10)
            trim();
    }
}
