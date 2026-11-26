// from server: 100% by Xemicl
// roc 2012-06 005add20  unit: RBX::Network::ErrorCompPhysicsSender  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005add20
//
// 005add20  8b442404             mov eax, dword ptr [esp + 4]
// 005add24  85c0                 test eax, eax
// 005add26  740e                 je 0x5add36
// 005add28  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005add2c  8b11                 mov edx, dword ptr [ecx]
// 005add2e  83c070               add eax, 0x70
// 005add31  8910                 mov dword ptr [eax], edx
// 005add33  8901                 mov dword ptr [ecx], eax
// 005add35  c3                   ret 
// 005add36  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005add3a  8b11                 mov edx, dword ptr [ecx]
// 005add3c  33c0                 xor eax, eax
// 005add3e  8910                 mov dword ptr [eax], edx
// 005add40  8901                 mov dword ptr [ecx], eax
// 005add42  c3                   ret 
// copied from an identical function in another client (function ?insert@@YAXPAUJob@@PAPAULink@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Pad { char pad[0x70]; };
struct Link { Link* next; };
struct Job : Pad, Link { };
void insert(Job* job, Link** list)
{
    Link* l = job;
    l->next = *list;
    *list = l;
}