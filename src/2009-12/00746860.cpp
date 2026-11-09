// from server: 100% by tester
struct RBX_ForceField {
    void construct();
};

extern "C" void __stdcall sub_637B00();

void RBX_ForceField::construct()
{
    *(int*)((char*)this + 0) = 0x9e397c;
    *(int*)((char*)this + 4) = 0x9e3970;
    *(int*)((char*)this + 0x18) = 0x9e3964;
    *(int*)((char*)this + 0x1c) = 0x9e395c;
    sub_637B00();
}
