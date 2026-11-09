// from server: 100% by Intel
struct Block {
    int getCount();
};

int Block::getCount() {
    return (*(int*)((char*)this + 8) - *(int*)((char*)this + 4)) >> 5;
}
