// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 004e1560  unit: Ogre::RbxTextureCompositorSceneManager  size: 210 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e1560
//
// 004e1560  51                   push ecx
// 004e1561  53                   push ebx
// 004e1562  55                   push ebp
// 004e1563  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004e1567  56                   push esi
// 004e1568  8bd9                 mov ebx, ecx
// 004e156a  57                   push edi
// 004e156b  8b7b04               mov edi, dword ptr [ebx + 4]
// 004e156e  8b7704               mov esi, dword ptr [edi + 4]
// 004e1571  807e6900             cmp byte ptr [esi + 0x69], 0
// 004e1575  b001                 mov al, 1
// 004e1577  88442410             mov byte ptr [esp + 0x10], al
// 004e157b  7528                 jne 0x4e15a5
// 004e157d  8d4900               lea ecx, [ecx]
// 004e1580  8d460c               lea eax, [esi + 0xc]
// 004e1583  50                   push eax
// 004e1584  55                   push ebp
// 004e1585  8bfe                 mov edi, esi
// 004e1587  ff155026b200         call dword ptr [0xb22650]
// 004e158d  83c408               add esp, 8
// 004e1590  88442410             mov byte ptr [esp + 0x10], al
// 004e1594  84c0                 test al, al
// 004e1596  7404                 je 0x4e159c
// 004e1598  8b36                 mov esi, dword ptr [esi]
// 004e159a  eb03                 jmp 0x4e159f
// 004e159c  8b7608               mov esi, dword ptr [esi + 8]
// 004e159f  807e6900             cmp byte ptr [esi + 0x69], 0
// 004e15a3  74db                 je 0x4e1580
// 004e15a5  8bf7                 mov esi, edi
// 004e15a7  8974241c             mov dword ptr [esp + 0x1c], esi
// 004e15ab  84c0                 test al, al
// 004e15ad  7438                 je 0x4e15e7
// 004e15af  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004e15b2  3b39                 cmp edi, dword ptr [ecx]
// 004e15b4  7524                 jne 0x4e15da
// 004e15b6  55                   push ebp
// 004e15b7  57                   push edi
// 004e15b8  6a01                 push 1
// 004e15ba  8d542428             lea edx, [esp + 0x28]
// 004e15be  52                   push edx
// 004e15bf  8bcb                 mov ecx, ebx
// 004e15c1  e84afdffff           call 0x4e1310
// 004e15c6  8b08                 mov ecx, dword ptr [eax]
// 004e15c8  8b442418             mov eax, dword ptr [esp + 0x18]
// 004e15cc  5f                   pop edi
// 004e15cd  5e                   pop esi
// 004e15ce  5d                   pop ebp
// 004e15cf  8908                 mov dword ptr [eax], ecx
// 004e15d1  c6400401             mov byte ptr [eax + 4], 1
// 004e15d5  5b                   pop ebx
// 004e15d6  59                   pop ecx
// 004e15d7  c20800               ret 8
// 004e15da  8d4c241c             lea ecx, [esp + 0x1c]
// 004e15de  e89dc7ffff           call 0x4ddd80
// 004e15e3  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004e15e7  8d560c               lea edx, [esi + 0xc]
// 004e15ea  55                   push ebp
// 004e15eb  52                   push edx
// 004e15ec  ff155026b200         call dword ptr [0xb22650]
// 004e15f2  83c408               add esp, 8
// 004e15f5  84c0                 test al, al
// 004e15f7  7427                 je 0x4e1620
// 004e15f9  8b442410             mov eax, dword ptr [esp + 0x10]
// 004e15fd  55                   push ebp
// 004e15fe  57                   push edi
// 004e15ff  50                   push eax
// 004e1600  8d4c2428             lea ecx, [esp + 0x28]
// 004e1604  51                   push ecx
// 004e1605  8bcb                 mov ecx, ebx
// 004e1607  e804fdffff           call 0x4e1310
// 004e160c  8b10                 mov edx, dword ptr [eax]
// 004e160e  8b442418             mov eax, dword ptr [esp + 0x18]
// 004e1612  5f                   pop edi
// 004e1613  5e                   pop esi
// 004e1614  5d                   pop ebp
// 004e1615  8910                 mov dword ptr [eax], edx
// 004e1617  c6400401             mov byte ptr [eax + 4], 1
// 004e161b  5b                   pop ebx
// 004e161c  59                   pop ecx
// 004e161d  c20800               ret 8
// 004e1620  8b442418             mov eax, dword ptr [esp + 0x18]
// 004e1624  5f                   pop edi
// 004e1625  8930                 mov dword ptr [eax], esi
// 004e1627  5e                   pop esi
// 004e1628  5d                   pop ebp
// 004e1629  c6400400             mov byte ptr [eax + 4], 0
// 004e162d  5b                   pop ebx
// 004e162e  59                   pop ecx
// 004e162f  c20800               ret 8

#define _SECURE_SCL 0
#include <map>
#include <string>

struct Pad { char b[0x4]; };

struct StrLess4 {
    char state[1];
    bool operator()(const std::string& a, const std::string& b) const { return a < b; }
};
template class std::_Tree<std::_Tmap_traits<std::string, Pad, StrLess4,
    std::allocator<std::pair<const std::string, Pad> >, false> >;