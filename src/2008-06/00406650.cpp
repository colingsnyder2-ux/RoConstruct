// from server: 100% by tester
struct VCContent_CComAggObject
{
    void Init();
};

void VCContent_CComAggObject::Init()
{
    *(unsigned short*)((char*)this + 0x1226) = 0;
    *(int*)((char*)this + 0x1228) = -1;
    *(int*)((char*)this + 0x122c) = 0;
    *(int*)((char*)this + 0x1230) = 0;
    *(int*)((char*)this + 0x1234) = 0;
    *(int*)((char*)this + 0x123c) = 0;
    *(int*)((char*)this + 0x1238) = 0;
    *(int*)((char*)this + 0x1240) = 0;
    *(char*)this = 0;
    *(char*)((char*)this + 0x21) = 0;
    *(char*)((char*)this + 0x122) = 0;
    *(char*)((char*)this + 0x1a3) = 0;
    *(char*)((char*)this + 0x224) = 0;
    *(char*)((char*)this + 0xa25) = 0;
}
