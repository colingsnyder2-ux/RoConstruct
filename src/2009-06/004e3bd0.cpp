// from server: 100% by why2
struct Replicator {
    char pad[0x2bcc];
    void* field_2bcc;
    void* get();
};

void* Replicator::get()
{
    void* p = field_2bcc;
    if (p)
        return *(void**)((char*)p + 0xdc);
    return 0;
}
