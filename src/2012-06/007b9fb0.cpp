// from server: 90% by tajop
namespace RBX {
struct Block {
    char pad[0x9c];
    int* items;
    int count;
    int first() const;
};
int Block::first() const {
    if (count > 0) {
        return *items;
    }
    return 0;
}
}
