// from server: 100% by auto
// roc 2008-06 0065aee0  unit: RBX::BallBallContact  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065aee0
//
// 0065aee0  53                   push ebx
// 0065aee1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0065aee5  55                   push ebp
// 0065aee6  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0065aeec  56                   push esi
// 0065aeed  57                   push edi
// 0065aeee  8bf9                 mov edi, ecx
// 0065aef0  c70300000000         mov dword ptr [ebx], 0
// 0065aef6  85ff                 test edi, edi
// 0065aef8  740e                 je 0x65af08
// 0065aefa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065aefe  39470c               cmp dword ptr [edi + 0xc], eax
// 0065af01  7705                 ja 0x65af08
// 0065af03  3b4710               cmp eax, dword ptr [edi + 0x10]
// 0065af06  7606                 jbe 0x65af0e
// 0065af08  ffd5                 call ebp
// 0065af0a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065af0e  8b742424             mov esi, dword ptr [esp + 0x24]
// 0065af12  8b0f                 mov ecx, dword ptr [edi]
// 0065af14  890b                 mov dword ptr [ebx], ecx
// 0065af16  894304               mov dword ptr [ebx + 4], eax
// 0065af19  39770c               cmp dword ptr [edi + 0xc], esi
// 0065af1c  7705                 ja 0x65af23
// 0065af1e  3b7710               cmp esi, dword ptr [edi + 0x10]
// 0065af21  7606                 jbe 0x65af29
// 0065af23  ffd5                 call ebp
// 0065af25  8b742424             mov esi, dword ptr [esp + 0x24]
// 0065af29  8b03                 mov eax, dword ptr [ebx]
// 0065af2b  8b0f                 mov ecx, dword ptr [edi]
// 0065af2d  85c0                 test eax, eax
// 0065af2f  7404                 je 0x65af35
// 0065af31  3bc1                 cmp eax, ecx
// 0065af33  7402                 je 0x65af37
// 0065af35  ffd5                 call ebp
// 0065af37  8b5304               mov edx, dword ptr [ebx + 4]
// 0065af3a  3bd6                 cmp edx, esi
// 0065af3c  742b                 je 0x65af69
// 0065af3e  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0065af41  8bc1                 mov eax, ecx
// 0065af43  2bc6                 sub eax, esi
// 0065af45  c1f803               sar eax, 3
// 0065af48  8d2cc2               lea ebp, [edx + eax*8]
// 0065af4b  8bc6                 mov eax, esi
// 0065af4d  3bf1                 cmp esi, ecx
// 0065af4f  7415                 je 0x65af66
// 0065af51  2bd6                 sub edx, esi
// 0065af53  8b30                 mov esi, dword ptr [eax]
// 0065af55  893402               mov dword ptr [edx + eax], esi
// 0065af58  8b7004               mov esi, dword ptr [eax + 4]
// 0065af5b  89740204             mov dword ptr [edx + eax + 4], esi
// 0065af5f  83c008               add eax, 8
// 0065af62  3bc1                 cmp eax, ecx
// 0065af64  75ed                 jne 0x65af53
// 0065af66  896f10               mov dword ptr [edi + 0x10], ebp
// 0065af69  5f                   pop edi
// 0065af6a  5e                   pop esi
// 0065af6b  5d                   pop ebp
// 0065af6c  8bc3                 mov eax, ebx
// 0065af6e  5b                   pop ebx
// 0065af6f  c21400               ret 0x14
// standard library vector<pod8> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
