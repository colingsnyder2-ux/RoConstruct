// from server: 100% by king_originala
struct Result {
    char padding[0x34];
    int value;
};

extern "C" void __cdecl sub_6A1250();
extern "C" Result* __cdecl sub_6A0926();

int __cdecl wrapper()
{
    sub_6A1250();
    return sub_6A0926()->value;
}
