// from server: 83% by atomic.potato
struct FriendStatusEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int);
};

extern "C" int* __cdecl sub_4b3c60(int);

int FriendStatusEnumDesc::lookup(int value)
{
    int* p = sub_4b3c60(value);
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
