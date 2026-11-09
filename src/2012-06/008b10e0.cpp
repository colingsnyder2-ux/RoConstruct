// from server: 55% by tester
struct PluginMouse {
    char pad[0x134];
    PluginMouse();
};

extern "C" void __stdcall sub_8b1070();
extern "C" void __stdcall sub_b22654();
extern "C" void* __cdecl sub_67f480();

PluginMouse::PluginMouse()
{
    sub_8b1070();
    *(int*)((char*)this + 0) = 0xbe181c;
    *(int*)((char*)this + 4) = 0xbe1814;
    *(int*)((char*)this + 0x18) = 0xbe1808;
    *(int*)((char*)this + 0x1c) = 0xbe17fc;
    *(int*)((char*)this + 0xf0) = 0;
    *(int*)((char*)this + 0xf4) = 0;
    *(short*)((char*)this + 0xfa) = 0;
    *(short*)((char*)this + 0xf8) = 0;
    *(short*)((char*)this + 0xfc) = 0;
    *(short*)((char*)this + 0xfe) = 0;
    *(int*)((char*)this + 0x104) = 0;
    sub_b22654();
    *(void**)((char*)this + 0x128) = sub_67f480();
    *(int*)((char*)this + 0x12c) = 0;
    *(int*)((char*)this + 0x130) = 0;
    *(int*)((char*)this + 0xf0) = 0xe;
}
