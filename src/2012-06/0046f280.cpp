// from server: 100% by Xemicl
// copied from an identical function in another client (function ?wrapper@ns_ROCX000000@@YAHXZ)

namespace ns_ROCX000000 {
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
}
