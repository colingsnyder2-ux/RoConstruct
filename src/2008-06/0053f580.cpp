// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
struct Object;

struct Entry {
    void* value;
    void* control;
    Entry(Object*);
    ~Entry();
};

struct Container {
    char storage[32];
    void remove(const Entry&);
};

struct Reference {
    void* value;
    Reference(const Reference&);
    ~Reference();
    bool hasValue() const;
};

struct Provider {
    Reference getReference();
};

struct Owner {
    char padding[32];
    Provider provider;
};

struct Object {
    Owner* getOwner();
};

struct S {
    char padding[40];
    Container first;
    Container second;

    void accept(Reference);
    void detach(Object*);
    bool finish(Object*);
    void f(Object*);
};

#pragma optimize("", off)
void S::f(Object* object)
{
    {
        Entry entry(object);
        first.remove(entry);
    }
    {
        Entry entry(object);
        second.remove(entry);
    }

    Reference reference = object->getOwner()->provider.getReference();
    if (reference.hasValue()) {
        accept(reference);
        detach(object);
    } else {
        detach(object);
    }
    finish(object);
}
