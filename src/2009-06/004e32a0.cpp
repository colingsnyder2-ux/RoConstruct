// from server: 100% by why2
struct Replicator {
    void* field0;
    void* field4;
    void set();
};

void Replicator::set() {
    *(void**)field0 = field4;
}
