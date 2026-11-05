// from server: 33% by atomic.potato
extern "C" int __cdecl sub_75F700();
extern "C" void __cdecl sub_7F4929(int);

struct S {
    char pad[0x14];
};

int __cdecl sub_75F790()
{
    if (!(*(unsigned char*)0xB97A44 & 1)) {
        *(unsigned int*)0xB97A44 |= 1;
        sub_75F700();
        *(unsigned int*)0xB97A30 = 0x9E7354;
        sub_7F4929(0x9898B0);
    }
    return 0xB97A30;
}
