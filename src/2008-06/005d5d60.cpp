// from server: 100% by colin
extern "C" int __cdecl sub_6A17C6(int, int, int, int, int);

struct RBX_Teams {
    bool teamExists(int color);
};

bool RBX_Teams::teamExists(int color) {
    int result = sub_6A17C6(color, 0, 0x92907c, 0x9457ec, 0);
    return result != 0;
}
