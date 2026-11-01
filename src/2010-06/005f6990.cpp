// from server: 100% by atomic.potato
struct LocalBackpackTool {
    void construct();
};

extern "C" void __stdcall sub_40F8E0();

void LocalBackpackTool::construct()
{
    *(int*)((char*)this + 0x00) = 0xa2f964;
    *(int*)((char*)this + 0x04) = 0xa2f95c;
    *(int*)((char*)this + 0x18) = 0xa2f950;
    *(int*)((char*)this + 0x1c) = 0xa2f944;
    *(int*)((char*)this + 0x94) = 0xa2f93c;
    sub_40F8E0();
}
