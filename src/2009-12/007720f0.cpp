// from server: 26% by atomic.potato
struct VPlayerRemoteEventDesc {
    void* ctor(int, int);
    char pad[0x9c];
};

extern "C" void __stdcall sub_771530();
extern "C" void __stdcall sub_651910();
extern "C" void __stdcall sub_952c68();

int g_b90110;

void* VPlayerRemoteEventDesc::ctor(int a, int b)
{
    sub_771530();
    *(int*)((char*)this + 0x00) = 0x9e876c;
    *(int*)((char*)this + 0x04) = 0x9e8760;
    *(int*)((char*)this + 0x18) = 0x9e8754;
    *(int*)((char*)this + 0x1c) = 0x9e874c;
    *(int*)((char*)this + 0x94) = 0x9e873c;
    *(int*)((char*)this + 0x98) = 0x9e8724;
    *(int*)((char*)this + 0x20) = (int)sub_651910;
    g_b90110++;

    return this;
}
