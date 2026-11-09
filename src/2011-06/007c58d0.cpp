// from server: 90% by atomic.potato
struct BallPolyContact
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    BallPolyContact(int, int, int*);
};

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void* __cdecl sub_74df10();
extern "C" void __cdecl sub_7f02b0();

BallPolyContact::BallPolyContact(int a, int b, int* c)
{
    sub_7f02b0();
    if (a & 1)
    {
        void* p = sub_74df10();
        EnterCriticalSection(p);
        v0 = *(int*)((char*)p + 0x18);
        *(int*)((char*)p + 0x18) = (int)this;
        LeaveCriticalSection(p);
    }
}
