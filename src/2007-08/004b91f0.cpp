// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
#include <string.h>
struct RakPeer {
    char pad[0x898];
    int field_898;
    int field_89c;
    int field_8a0;
    int field_8a4;
    int field_8a8;
    int field_8ac;
    int field_8b0;
    int field_8b4;
    int field_8b8;
    int field_8bc;
    int field_8c0;
    void func_4b91f0();
};

extern "C" int __cdecl sub_4ca340();
extern "C" int __cdecl sub_4b7f70();

void RakPeer::func_4b91f0()
{
    memcpy(&field_8b0, &field_89c, 20);
    for (int i = 0; i < 0x14; i += 4)
        *(int*)((char*)this + i + 0x89c) = sub_4ca340();
    field_898 = sub_4b7f70() + 0x2710;
}
