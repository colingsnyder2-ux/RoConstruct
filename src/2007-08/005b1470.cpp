// from server: 100% by colin
struct JointInstance {
    char pad[0x100];
    JointInstance* construct(int);
};

extern "C" void __stdcall sub_005b1210(int);

JointInstance* JointInstance::construct(int arg)
{
    sub_005b1210(arg);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x00) = 0x7b64bc;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x04) = 0x7b64b4;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = 0x7b64ac;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14) = 0x7b649c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x2c) = 0x7b648c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x44) = 0x7b647c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x5c) = 0x7b646c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x74) = 0x7b645c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x8c) = 0x7b644c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xe8) = 0x7b6434;
    return this;
}
