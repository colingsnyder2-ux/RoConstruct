// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)

struct Node;
struct Object;
struct State;

struct Handle {
    void* value;
    Handle(int);
    Handle(const Handle&);
    ~Handle();
    Object* get();
};

struct Iterator {
    unsigned int data[2];
    bool operator!=(const Iterator&) const;
    Node* operator*() const;
    Iterator& operator++();
};

struct Collection {
    Iterator begin();
    Iterator end();
    void clear();
};

struct Object {
    char padding[0xf0];
    Collection collection;
};

struct State {
    int get();
};

struct NodeData {
    char padding[0x20];
    State state;
};

struct Node {
    NodeData* get(Handle*);
};

extern int nodeCount;

struct Manager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void destroy(Node*, bool);
    void flush(Node*);
    void remove(Handle*);
    void process(Handle);
};

void Manager::process(Handle object)
{
    Iterator first = object.get()->collection.begin();
    Iterator last = object.get()->collection.end();

    while (first != last) {
        Node* node = *first;
        {
            Handle handle(0);
            node->get(&handle)->state.get();
        }
        --nodeCount;
        flush(node);
        destroy(node, true);
        ++first;
    }

    {
        Handle handle(object);
        remove(&handle);
    }

    object.get()->collection.clear();
}
