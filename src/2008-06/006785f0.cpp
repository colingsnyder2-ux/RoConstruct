// from server: 100% by colin
struct RbxSceneManagerFactory {
    int count;
    char pad[4];
    struct Entry {
        int a, b, c, d, e;
    } entries[100];
    void addEntry(const Entry* e);
};

void RbxSceneManagerFactory::addEntry(const Entry* e) {
    int idx = count % 100;
    Entry* dst = &entries[idx];
    *dst = *e;
    count++;
}
