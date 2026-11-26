// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00930f70  unit: RBX::CellFaceFacePair  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00930f70
//
// 00930f70  55                   push ebp
// 00930f71  8bec                 mov ebp, esp
// 00930f73  83ec24               sub esp, 0x24
// 00930f76  894ddc               mov dword ptr [ebp - 0x24], ecx
// 00930f79  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00930f7c  e87f6ef3ff           call 0x867e00
// 00930f81  50                   push eax
// 00930f82  8d45e4               lea eax, [ebp - 0x1c]
// 00930f85  50                   push eax
// 00930f86  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00930f89  e80208b9ff           call 0x4c1790
// 00930f8e  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00930f91  e86a6ef3ff           call 0x867e00
// 00930f96  50                   push eax
// 00930f97  8d4df0               lea ecx, [ebp - 0x10]
// 00930f9a  51                   push ecx
// 00930f9b  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00930f9e  e8ed07b9ff           call 0x4c1790
// 00930fa3  8d55f0               lea edx, [ebp - 0x10]
// 00930fa6  52                   push edx
// 00930fa7  8d45e4               lea eax, [ebp - 0x1c]
// 00930faa  50                   push eax
// 00930fab  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 00930fae  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00930fb1  e87ae80100           call 0x94f830
// 00930fb6  8945fc               mov dword ptr [ebp - 4], eax
// 00930fb9  837dfc00             cmp dword ptr [ebp - 4], 0
// 00930fbd  7c23                 jl 0x930fe2
// 00930fbf  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00930fc2  52                   push edx
// 00930fc3  8b4508               mov eax, dword ptr [ebp + 8]
// 00930fc6  50                   push eax
// 00930fc7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00930fca  51                   push ecx
// 00930fcb  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 00930fce  e84dfaffff           call 0x930a20
// 00930fd3  8945e0               mov dword ptr [ebp - 0x20], eax
// 00930fd6  8d55e0               lea edx, [ebp - 0x20]
// 00930fd9  52                   push edx
// 00930fda  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00930fdd  e89e82ffff           call 0x929280
// 00930fe2  8be5                 mov esp, ebp
// 00930fe4  5d                   pop ebp
// 00930fe5  c21000               ret 0x10

#pragma optimize("", off)

struct Vector3 {
    float x, y, z;
};

struct Vertex {
    const Vector3& getOffset() const;
};

struct Face {
    int findEdge(const Vector3& v0, const Vector3& v1) const;
};

struct CoordinateFrame {
    Vector3 pointToObjectSpace(const Vector3& v) const;
};

struct Connector;

struct ConnectorArray {
    void push_back(Connector* const& c);
};

struct CellFaceFacePair {
    char pad0[0x18];
    const Face* mainFace;
    Connector* newFaceEdgeConnector(int edgeId, const Vertex* v0, const Vertex* v1);
    void checkOneSideIntersection(const Vertex* v0, const Vertex* v1, const CoordinateFrame& otherInMe, ConnectorArray& newConnectors);
};

void CellFaceFacePair::checkOneSideIntersection(const Vertex* v0, const Vertex* v1, const CoordinateFrame& otherInMe, ConnectorArray& newConnectors)
{
    Vector3 v0InMe = otherInMe.pointToObjectSpace(v0->getOffset());
    Vector3 v1InMe = otherInMe.pointToObjectSpace(v1->getOffset());
    int edgeId = mainFace->findEdge(v0InMe, v1InMe);
    if (edgeId >= 0) {
        newConnectors.push_back(newFaceEdgeConnector(edgeId, v0, v1));
    }
}
