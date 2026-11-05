// from server: 100% by Intel
struct Block
{
    int getSize();
};

int Block::getSize()
{
    return (*(int*)((char*)this + 8) - *(int*)((char*)this + 4)) >> 2;
}
