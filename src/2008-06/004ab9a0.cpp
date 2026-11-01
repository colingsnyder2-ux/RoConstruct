// from server: 100% by tester
struct Replicator {
    char pad[0x2c70];
    void* field_2bcc;
    void* get();
};

void* Replicator::get()
{
    void* p = field_2bcc;
    if (p)
        return *(void**)((char*)p + 0x1a0);
    return 0;
}
