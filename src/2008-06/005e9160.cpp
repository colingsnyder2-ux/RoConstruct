// from server: 100% by tester
struct Owner {
    int forward();
};

int Owner::forward()
{
    int* ptr = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x88);
    int* vtable = *reinterpret_cast<int**>(ptr);
    int func = vtable[6];
    return reinterpret_cast<int(__thiscall*)(int*)>(func)(ptr);
}
