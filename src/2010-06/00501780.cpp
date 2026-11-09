// from server: 61% by atomic.potato
struct ClientReplicator
{
    int value;
    short flags;
};

void f(void* destination, ClientReplicator* source);

void f(void* destination, ClientReplicator* source)
{
    int value = source->value;
    short flags = source->flags;
    *(int*)destination = value;
    *(short*)((char*)destination + 4) = flags;
}
