// from server: 70% by atomic.potato
struct PartInstance {
    void *pad[90];
    void *field;
    unsigned char f();
};

unsigned char PartInstance::f()
{
    return ((unsigned char *)field)[0x102] == 0;
}
