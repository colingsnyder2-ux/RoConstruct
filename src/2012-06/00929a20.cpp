// from server: 100% by tajop
struct BallPolyContact
{
    int value0;
    int value4;
    int value8;
    int valueC;
    int value10;
    int value14;
    BallPolyContact(int, int, int *);
    BallPolyContact *destroy(char);
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);
extern "C" void *__cdecl sub_82B600();
extern "C" void __cdecl sub_965240();

BallPolyContact *BallPolyContact::destroy(char flag)
{
    sub_965240();
    if (flag & 1)
    {
        void *p = sub_82B600();
        EnterCriticalSection(p);
        value0 = *(int *)((char *)p + 0x18);
        *(int *)((char *)p + 0x18) = (int)this;
        LeaveCriticalSection(p);
    }
    return this;
}
