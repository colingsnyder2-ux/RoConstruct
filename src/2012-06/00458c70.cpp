// from server: 56% by atomic.potato
struct XItem
{
    int f();
};

extern "C" void * __cdecl make_object(void *);
extern "C" int __cdecl query_object(void *);
extern "C" void __cdecl release_object(void *);

int XItem::f()
{
    void *object = make_object(&object);
    int result = query_object(object);
    release_object(&object);
    return result;
}
