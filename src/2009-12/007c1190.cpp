// from server: 100% by atomic.potato
struct FilterStairs
{
    FilterStairs(int, int);
};

FilterStairs::FilterStairs(int a, int b)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0x10) = a;
    *(int*)((char*)this + 0xc) = 3;
    *(int*)((char*)this + 0x14) = b;
    *(int*)((char*)this + 0x18) = -1;
    *(int*)((char*)this + 0x1c) = -1;
}
