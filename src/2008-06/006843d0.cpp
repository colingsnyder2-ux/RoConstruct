// from server: 100% by king_originala
extern "C" void __cdecl sub_6832B0();

struct OgreTwoDManager {
    char pad[8];
    char byte8;
    char byte9;
    void method(int, int, int);
};

void OgreTwoDManager::method(int a, int b, int c)
{
    if (byte9 == 0)
        return;
    if ((char)a != byte8)
        return;
    sub_6832B0();
}
