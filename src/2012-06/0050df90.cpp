// from server: 33% by atomic.potato
struct RbxSpatialHashedSceneNode {
    char pad0[0x34];
    char field34[0x48];
    char pad7c[0x10];
    char field8c[0x1c];
    char fielda8[0x4];
    void _findVisibleObjects();
};

extern "C" int __stdcall sub_972290(int, int);
extern "C" void __stdcall sub_829e70();
extern "C" void __stdcall sub_50d7b0();
extern "C" void __stdcall sub_81cf90();
extern "C" void __stdcall sub_983270(int, int, int, int);
extern "C" void __stdcall sub_50c500();

extern unsigned char byte_e580b3;
extern int dword_e5809c;

void RbxSpatialHashedSceneNode::_findVisibleObjects()
{
    if (byte_e580b3 != 0 && *(int*)((char*)this + 0x74) != 0) {
        int fn = dword_e5809c;
        if (fn != 0) {
            if (((char(__stdcall*)(int,int,int))fn)(0x59, 0xb6c360, 0xb6c440) != 0)
                goto skip;
        }
        sub_972290(byte_e580b3, 0xb6c3c0);
    }
skip:
    sub_829e70();
    sub_50d7b0();
    sub_81cf90();
    sub_983270((int)((char*)this + 0x34), 0x10, 4, 0x5047b0);
    sub_50c500();
}
