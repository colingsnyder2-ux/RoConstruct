// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Resource {
    virtual ~Resource();
    volatile long references;
    void release();
};

struct View {
    char padding[0x44];
    bool active;
    Resource *resource;

    void reset(bool dispose);
};

void View::reset(bool dispose)
{
    active = false;
    if (dispose && resource) {
        if (InterlockedDecrement(&resource->references) == 0) {
            resource->release();
            if (resource)
                delete resource;
        }
        resource = 0;
    }
}
