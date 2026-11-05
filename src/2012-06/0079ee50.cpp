// from server: 58% by Intel
// roc 2012-06 0079ee50  unit: RBX::Humanoid  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0079ee50
//
// 0079ee50  83c180               add ecx, -0x80
// 0079ee53  8d8124020000         lea eax, [ecx + 0x224]
// 0079ee59  50                   push eax
// 0079ee5a  6a00                 push 0
// 0079ee5c  e87f7cffff           call 0x796ae0
// 0079ee61  85c0                 test eax, eax
// 0079ee63  740e                 je 0x79ee73
// 0079ee65  8b8898010000         mov ecx, dword ptr [eax + 0x198]
// 0079ee6b  8b8108010000         mov eax, dword ptr [ecx + 0x108]
// 0079ee71  eb02                 jmp 0x79ee75
// 0079ee73  33c0                 xor eax, eax
// 0079ee75  85c0                 test eax, eax
// 0079ee77  7404                 je 0x79ee7d
// 0079ee79  8b4030               mov eax, dword ptr [eax + 0x30]
// 0079ee7c  c3                   ret
// 0079ee7d  33c0                 xor eax, eax
// 0079ee7f  c3                   ret
// library rbxgs humanoid/Humanoid.cpp (function ??MSystemAddress@@QBE_NABU0@@Z)





struct Humanoid {
    int getSomething();
};

extern "C" int __stdcall sub_796AE0(int* a1, int a2);

int Humanoid::getSomething() {
    int* v1 = reinterpret_cast<int*>(reinterpret_cast<char*>(this) - 0x80);
    int* v2 = reinterpret_cast<int*>(reinterpret_cast<char*>(v1) + 0x224);
    int v3 = sub_796AE0(v2, 0);
    if (!v3)
        return 0;
    int v4 = *reinterpret_cast<int*>(reinterpret_cast<char*>(v3) + 0x198);
    int v5 = *reinterpret_cast<int*>(reinterpret_cast<char*>(v4) + 0x108);
    if (!v5)
        return 0;
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(v5) + 0x30);
}
