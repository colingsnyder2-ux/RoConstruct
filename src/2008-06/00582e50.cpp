// from server: 100% by king_originala
struct Entry {
    char data[8];
};

struct Collection {
    char padding[0xC];
    Entry* begin;
    Entry* end;
};

struct Object {
    char padding[0x154];
    Collection* collection;
};

struct Handle {
    char padding[0xC];
    Object* get(int);
};

struct Reference {
    Object* get();
};

struct TrackCameraCommand {
    char padding[0x14];
    Handle handle;
    Reference* reference;
    bool isTracking();
};

bool TrackCameraCommand::isTracking()
{
    Collection* first = handle.get(1)->collection;
    if ((unsigned)(first->end - first->begin) <= 0)
        return false;

    Object* object = reference ? reference->get() : 0;
    Collection* second = object->collection;
    return (unsigned)(second->end - second->begin) == 1;
}
