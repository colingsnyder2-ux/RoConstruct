// from server: 62% by atomic.potato
struct RECT_429900
{
    int left;
    int top;
    int right;
    int bottom;
};

extern "C" void __cdecl G1_func_00427f40(int, int, int, RECT_429900);

void func_00429900()
{
    RECT_429900 r = { 0, 0, 0x280, 0xc8 };
    G1_func_00427f40(3, 0xc0, 0, r);
}
