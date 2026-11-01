// from server: 100% by colin
struct JointInstance {
    char pad[0x100];
    JointInstance(const JointInstance&);
    JointInstance& operator=(const JointInstance&);
    JointInstance(int);
};

extern "C" void __stdcall sub_005b1210(int);

JointInstance::JointInstance(int arg)
{
    sub_005b1210(arg);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x00) = 0x7b658c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x04) = 0x7b6584;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = 0x7b657c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14) = 0x7b656c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x2c) = 0x7b655c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x44) = 0x7b654c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x5c) = 0x7b653c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x74) = 0x7b652c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x8c) = 0x7b651c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xe8) = 0x7b6504;
}
