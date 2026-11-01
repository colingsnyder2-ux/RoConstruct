// from server: 100% by king_originala
extern char instanceType;
extern char backpackItemType;

extern "C" void* __cdecl runtimeCast(
    void*, long, void*, void*, int);

struct SharedPointer
{
    void* object;
    void* control;
    ~SharedPointer();
};

struct Receiver
{
    void accept(void*);
};

struct LocalBackpack
{
    void func_005fd330(int, SharedPointer, int, int);
};

void LocalBackpack::func_005fd330(
    int, SharedPointer value, int, int)
{
    void* item = runtimeCast(
        value.object, 0, &instanceType, &backpackItemType, 0);

    if (item)
        reinterpret_cast<Receiver*>(
            reinterpret_cast<char*>(this) - 0x170)->accept(item);
}
