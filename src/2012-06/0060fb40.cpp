// from server: 46% by Intel
struct SphereBuilder {
    int process(int a1, void* a2, void* a3);
};

extern "C" int __cdecl sub_60FAE0(int, int, int, int);
extern "C" int __cdecl sub_60F030(int, int, int, int);
extern "C" int __cdecl sub_60F060(int, int, int, int);
extern "C" int __cdecl sub_60FB10(int, int, int, int);
extern "C" int __cdecl sub_60F860(int, int, int, int);
extern "C" int __cdecl sub_60F890(int, int, int, int);

int SphereBuilder::process(int a1, void* a2, void* a3) {
    if (a1 > 5)
        return 0;

    int v4 = *reinterpret_cast<int*>(reinterpret_cast<char*>(a3) + 4);

    switch (a1) {
    case 0:
        return sub_60FAE0(reinterpret_cast<int>(a2), v4, v4, 0x60FA40);
    case 1:
        return sub_60F030(reinterpret_cast<int>(a2), v4, v4, 0x60FA40);
    case 2:
        return sub_60F060(reinterpret_cast<int>(a2), v4, v4, 0x60FA40);
    case 3:
        return sub_60FB10(reinterpret_cast<int>(a2), v4, v4, 0x60FA40);
    case 4:
        return sub_60F860(reinterpret_cast<int>(a2), v4, v4, 0x60FA40);
    case 5:
        return sub_60F890(reinterpret_cast<int>(a2), v4, v4, 0x60FA40);
    }
    return 0;
}
