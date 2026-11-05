// from server: 100% by king_originala
struct Resource {
    void release();
};

struct Base {
    virtual ~Base();
    char padding[232];
};

struct Frame : Base {
    Resource* resource;
    virtual ~Frame();
};

Frame::~Frame()
{
    if (resource)
        resource->release();
}
