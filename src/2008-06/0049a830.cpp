// from server: 100% by king_originala
struct String {
    char storage[28];
};

extern String& (__thiscall *assign_string)(String*, const String&);

struct Node {
    Node* next;
};

struct Iterator {
    void* owner;
    Node* node;
};

struct S;

struct Tree {
    void* owner;
    char padding[16];
    Node* head;

    void clear();
    void copy_range(Iterator destination, Iterator first,
                    Iterator last, const S* source);
};

struct S {
    unsigned int first;
    unsigned int second;
    String text;
    Tree tree;

    S& operator=(const S& source);
};

S& S::operator=(const S& source)
{
    first = source.first;
    second = source.second;
    assign_string(&text, source.text);

    const Tree* input = &source.tree;
    Tree* destination = &tree;

    if (destination != input) {
        Node* head = input->head;
        void* owner = input->owner;

        Iterator begin;
        begin.owner = owner;
        begin.node = head->next;

        destination->clear();

        Iterator end;
        end.owner = owner;
        end.node = head;

        Iterator position;
        position.node = destination->head->next;
        position.owner = destination->owner;

        destination->copy_range(position, begin, end, &source);
    }

    return *this;
}
