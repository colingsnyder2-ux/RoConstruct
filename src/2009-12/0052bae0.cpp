// from server: 92% by atomic.potato
struct Instance;
struct ServerReplicator;

extern "C" int __stdcall sub_007f4aaa(
    void *, Instance *, void *, void *, void *);

struct Instance {};
struct ServerReplicator {};

int __stdcall f(Instance *instance)
{
    return sub_007f4aaa(0, instance, (void *)0x00affe40,
        (void *)0x00b1bdfc, 0) != 0;
}
