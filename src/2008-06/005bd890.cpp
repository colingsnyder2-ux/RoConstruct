// from server: 100% by king_originala
struct Channel;
struct Instance;
struct Change;

struct Link {
    unsigned long value;
    void remove(Link*);
};

struct Control {
    unsigned long reserved[2];
    long count;
};

struct Shared {
    Control* object;
    void* owner;
    void clear();
};

struct Instance {
    bool contains(Instance*);
    Channel* oldChannel();
    Channel* newChannel();
    Instance* root();
};

struct Change {
    Channel* subject;
    Instance* oldParent;
    Instance* newParent;
};

struct Channel {
    char reserved0[0x130];
    Link link;
    Shared shared;
    void* resource;
    char reserved1[0x24];
    unsigned char active;
    unsigned char flags;
    char reserved2[2];
    int count;
    void* part;

    void update(Change*);
    void baseUpdate(Change*);
    void stop();
    void refresh();
    void prepare();
    void notify(void*);
    void finish();
};

extern Instance* __cdecl lookup(Instance*);
extern void* __stdcall releaseResource(void*, int);
extern void __cdecl disposeResource(void*);
extern void* __cdecl checkedCast(void*, int, const void*, const void*, int);
extern const char instanceType;
extern const char partType;

void Channel::update(Change* change)
{
    Instance* oldNode = lookup(change->oldParent);
    Instance* newNode = lookup(change->newParent);
    Link* ownLink = this ? &link : 0;

    if (oldNode) {
        Channel* channel = oldNode->oldChannel();
        if (channel)
            channel->link.remove(ownLink);

        if (flags & 2)
            stop();

        if (resource) {
            disposeResource(releaseResource(resource, 0));
            resource = 0;
        }

        if (shared.object) {
            --shared.object->count;
            shared.clear();
        }
    }

    baseUpdate(change);

    if (change->subject == this) {
        part = checkedCast(change->newParent, 0, &instanceType, &partType, 0);
        refresh();
    }

    if (newNode) {
        Channel* channel = newNode->newChannel();
        if (channel && channel->shared.object) {
            flags &= 0xfb;
            prepare();
            refresh();
            if (count > 0)
                notify(this);
        }
    }

    if (oldNode) {
        Instance* oldRoot = oldNode->root();
        if (oldRoot &&
            (change->oldParent == oldRoot || change->oldParent->contains(oldRoot))) {
            if (newNode) {
                Instance* newRoot = newNode->root();
                if (newRoot &&
                    (change->newParent == newRoot ||
                     change->newParent->contains(newRoot)))
                    return;
            }

            if (active)
                notify(change->oldParent);
            finish();
        }
    }
}
