// from server: 44% by tester
struct ArcHandles {
    void __cdecl setAxes(int value);
};

void ArcHandles::setAxes(int value)
{
    if (value != 4) {
        *(int*)this = 0xdf5938;
        *(char*)((char*)this + 4) = 0;
        *(char*)((char*)this + 5) = 0;
    } else {
        extern void func_008d8f10();
        func_008d8f10();
    }
}
