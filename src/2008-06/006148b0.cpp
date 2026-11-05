// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern int generation;

struct Body;

struct Link {
    int reserved;
    Body* owner;
};

struct Owned {
    char storage[0xB4];
    Owned(Body*);
    ~Owned();
};

struct Body {
    char reserved0[0x10];
    Body* root;
    Body* parent;
    int reserved18;
    Body** children;
    int childCount;
    char reserved24[8];
    Owned* owned;
    int reserved30;
    Link* link;
    char reserved38[0x58];
    int generationId;

    void setParent(Body*);
    void removeChild(Body*);
    void addChild(Body*);
    Body* calcRoot();
    void setRoot(Body*);
};

__declspec(noinline) void Body::setRoot(Body*newRoot){root=newRoot;for(int i=0;i<childCount;++i)children[i]->setRoot(newRoot);}

void Body::setParent(Body* value)
{
    if (parent == value)
        return;

    if (link) {
        link->owner = 0;
        link = 0;
    }

    if (parent)
        parent->removeChild(this);
    else {
        delete owned;
        owned = 0;
    }

    parent = value;
    if (value)
        value->addChild(this);
    else
        owned = new Owned(this);

    Body* newRoot = parent ? parent->calcRoot() : this;

    int id = ++generation;
    if (id == 0x7FFFFFFF) {
        id = 1;
        generation = id;
    }

    newRoot->generationId = id;
    unsigned int i = 0;
    root = newRoot;
    if (childCount > 0) {
        do {
            children[i]->setRoot(newRoot);
            ++i;
        } while ((int)i < childCount);
    }
}

