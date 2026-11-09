// from server: 47% by atomic.potato
// roc 2012-06 0092fcb0  unit: RBX::CellEdgeEdgePair  size: 49 bytes
//
// 0092fcb0  837c240400           cmp dword ptr [esp + 4], 0
// 0092fcb5  7515                 jne 0x92fccc
// 0092fcb7  8b4104               mov eax, dword ptr [ecx + 4]
// 0092fcba  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 0092fcc0  50                   push eax
// 0092fcc1  e89a78baff           call 0x4d7560
// 0092fcc6  83c404               add esp, 4
// 0092fcc9  c20400               ret 4
// 0092fccc  8b4908               mov ecx, dword ptr [ecx + 8]
// 0092fccf  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 0092fcd5  50                   push eax
// 0092fcd6  e88578baff           call 0x4d7560
// 0092fcdb  83c404               add esp, 4
// 0092fcde  c20400               ret 4
// library ogre-1.7.0 OgreMeshSerializerImpl.cpp (function ??$serialize@VMeshHeader@@@OgreMeshSerializerImpl@Ogre@@QAEXPAU MeshHeader@@@Z)

extern "C" int __stdcall _4d7560(int);

struct S {
    int f(int);
};

int S::f(int param) {
    if (param == 0) {
        int v1 = *(int*)(this + 4);
        int v2 = *(int*)(v1 + 0x104);
        _4d7560(v2);
    } else {
        int v3 = *(int*)(this + 4);
        int v4 = *(int*)(v3 + 0x104);
        _4d7560(v4);
    }
    return 0;
}
