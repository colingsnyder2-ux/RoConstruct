// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)
#pragma strict_gs_check(on)

struct Node;
struct Owner;

struct Handle {
    void* value;
    Handle(const Handle&);
    ~Handle();
    bool valid() const;
};

struct HandleSource {
    Handle get();
};

struct Owner {
    char padding[32];
    HandleSource source;
};

struct Node {
    Owner* getOwner();
};

struct Key {
    void* value;
    void* control;
    Key(Node*);
    ~Key();
};

struct InsertResult {
    void* first;
    void* second;
    bool inserted;
};

struct Container {
    char storage[32];
    unsigned int erase(const Key&);
    InsertResult insert(const Key&);
};

struct S {
    char padding[40];
    Container active;
    Container inactive;

    void activate(Node*);
    void deactivate(Node*);
    void process(Handle);
    void f(Node*, bool);
};

void S::f(Node* node, bool enabled)
{
    if (enabled) {
        bool erased;
        {
            Key key(node);
            erased = inactive.erase(key) == 1;
        }
        if (erased) {
            Key key(node);
            InsertResult result = active.insert(key);
        }
        activate(node);
        return;
    }

    {
        bool erased;
        {
            Key key(node);
            erased = active.erase(key) == 1;
        }
        if (erased) {
            Key key(node);
            InsertResult result = inactive.insert(key);
        }
    }

    Handle handle = node->getOwner()->source.get();
    if (handle.valid())
        process(handle);
    deactivate(node);
}
