// from server: 100% by colin
struct World {
    int pad0[0x2b];
    int* items;
    int count;
    void removeItem(int, int);
    void clear();
};

void World::clear() {
    int i = 0;
    if (count > 0) {
        do {
            removeItem(items[i], 0);
            ++i;
        } while (i < count);
    }
}
