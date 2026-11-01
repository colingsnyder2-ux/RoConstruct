// from server: 100% by colin
struct Sub {
    char pad[0x30];
    int field30;
};

extern "C" Sub* __cdecl func_0057adb0(void* p);

struct Humanoid {
    char pad[0x104];
    int getField30();
};

int Humanoid::getField30()
{
    Sub* s = func_0057adb0((char*)this - 0x104);
    return s->field30;
}
