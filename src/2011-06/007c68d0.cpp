// from server: 45% by atomic.potato
// roc 2011-06 007c68d0  unit: RBX::EdgeEdgePair  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c68d0
//
// 007c68d0  837c240400           cmp dword ptr [esp + 4], 0
// 007c68d5  7515                 jne 0x7c68ec
// 007c68d7  8b4104               mov eax, dword ptr [ecx + 4]
// 007c68da  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 007c68e0  50                   push eax
// 007c68e1  e84adad2ff           call 0x4f4330
// 007c68e6  83c404               add esp, 4
// 007c68e9  c20400               ret 4
// 007c68ec  8b4908               mov ecx, dword ptr [ecx + 8]
// 007c68ef  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 007c68f5  50                   push eax
// 007c68f6  e835dad2ff           call 0x4f4330
// 007c68fb  83c404               add esp, 4
// 007c68fe  c20400               ret 4
// library rbxgs-net Replicator.cpp

extern "C" int __stdcall _004f4330(int);

struct RBX_EdgeEdgePair {
    int f(int);
};

int RBX_EdgeEdgePair::f(int param) {
    if (param != 0) {
        goto label1;
    }
    int temp = *(int*)(this + 4);
    temp = *(int*)(temp + 0x104);
    _004f4330(temp);
    return 0;
label1:
    int temp_this = *(int*)(this + 8);
    int temp2 = *(int*)(temp_this + 0x104);
    _004f4330(temp2);
    return 0;
}
