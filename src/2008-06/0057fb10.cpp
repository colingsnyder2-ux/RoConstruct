// from server: 100% by EspClaude
// roc 2008-06 0057fb10  unit: RBX::VModelInstance::?$FilteredSelection  size: 136 bytes
extern "C" {
    extern void (__cdecl *invalid_parameter_noinfo)();
}

struct Node;

struct Entry {
    Node* object;
    void* control;
};

struct Children {
    char reserved[12];
    Entry* first;
    Entry* last;
    unsigned int size() const { return (unsigned int)(last - first); }
    Entry& operator[](unsigned int i)
    {
        if (i >= size())
            invalid_parameter_noinfo();
        return first[i];
    }
};

struct Node {
    char reserved[0x108];
    Children* children;

    unsigned int numChildren() const { return children ? children->size() : 0; }
    Node* getChild(unsigned int i) { return (*children)[i].object; }
    void finish();
    void reset(int);
};

struct Listener {
    void invoke(Node**);
};

struct Selection {
    Listener* listener;
    unsigned char* changed;

    void process(Node** object);
};

void Selection::process(Node** object)
{
    if ((*object)->numChildren() > 0) {
        for (unsigned int i = 0; i < (*object)->numChildren(); ++i) {
            Node* child = (*object)->getChild(i);
            listener->invoke(&child);
        }
        (*object)->finish();
        (*object)->reset(0);
        *changed = 1;
    }
}
