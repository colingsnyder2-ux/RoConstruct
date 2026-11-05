// from server: 100% by king_originala
struct Frame {
    float data[12];
    Frame();
};

struct Instance {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void setFrame(const Frame&);

    char padding[0x198];
    void* resource;
    void update();
};

struct Flag {
    bool value;
};

struct Collection {
    char data[0x44];
    void update(Flag);
};

struct Renderable;

struct Bucket {
    void onAdded(Renderable*);
};

struct Workspace {
    char padding0[0x19c];
    void* resource;
    char padding1[0x1a4];
    Collection collection;
    Bucket bucket;

    void setInsertPoint(int);
    void added(int);
};

extern "C" void* __cdecl castObject(
    void*, int, const void*, const void*, int);
extern "C" void __cdecl releaseResource(void*);

void Workspace::added(int value)
{
    setInsertPoint(value);

    Flag flag;
    flag.value = false;
    collection.update(flag);

    Renderable* renderable = static_cast<Renderable*>(
        castObject(reinterpret_cast<void*>(value), 0,
                   reinterpret_cast<const void*>(0x92907c),
                   reinterpret_cast<const void*>(0x939f70), 0));
    if (renderable)
        bucket.onAdded(renderable);

    Instance* instance = static_cast<Instance*>(
        castObject(reinterpret_cast<void*>(value), 0,
                   reinterpret_cast<const void*>(0x92907c),
                   reinterpret_cast<const void*>(0x947f1c), 0));
    if (instance && instance->resource) {
        instance->setFrame(Frame());
        instance->update();

        if (resource) {
            void* old = *reinterpret_cast<void* volatile*>(&resource);
            resource = 0;
            if (old)
                releaseResource(old);
        }
    }
}
