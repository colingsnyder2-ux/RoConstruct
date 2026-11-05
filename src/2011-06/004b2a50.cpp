// from server: 65% by atomic.potato
struct Player {
    char pad0[0x68];
    int* begin;
    int* end;
    int getIndex(int);
};

extern "C" int* __stdcall sub_4abcf0(int*);

int Player::getIndex(int idx)
{
    int* p = sub_4abcf0(&idx);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
