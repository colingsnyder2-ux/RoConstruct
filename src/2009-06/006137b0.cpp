// from server: 100% by why2
struct RBX_Script {
    char pad[0x94];
    int field_0x94;
    int isRunning();
};

extern "C" int __cdecl sub_5d1000();

int RBX_Script::isRunning() {
    if (field_0x94 == 2)
        return 0;
    return sub_5d1000();
}
