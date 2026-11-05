// from server: 100% by auto
// roc 2007-03 00531630  unit: seg_00530000  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00531630
//
// 00531630  8b5104               mov edx, dword ptr [ecx + 4]
// 00531633  8b4204               mov eax, dword ptr [edx + 4]
// 00531636  83ec10               sub esp, 0x10
// 00531639  80781500             cmp byte ptr [eax + 0x15], 0
// 0053163d  53                   push ebx
// 0053163e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00531642  56                   push esi
// 00531643  57                   push edi
// 00531644  7516                 jne 0x53165c
// 00531646  8b33                 mov esi, dword ptr [ebx]
// 00531648  39700c               cmp dword ptr [eax + 0xc], esi
// 0053164b  7305                 jae 0x531652
// 0053164d  8b4008               mov eax, dword ptr [eax + 8]
// 00531650  eb04                 jmp 0x531656
// 00531652  8bd0                 mov edx, eax
// 00531654  8b00                 mov eax, dword ptr [eax]
// 00531656  80781500             cmp byte ptr [eax + 0x15], 0
// 0053165a  74ec                 je 0x531648
// 0053165c  3b5104               cmp edx, dword ptr [ecx + 4]
// 0053165f  8bfa                 mov edi, edx
// 00531661  8bf1                 mov esi, ecx
// 00531663  7407                 je 0x53166c
// 00531665  8b03                 mov eax, dword ptr [ebx]
// 00531667  3b420c               cmp eax, dword ptr [edx + 0xc]
// 0053166a  7321                 jae 0x53168d
// 0053166c  8b13                 mov edx, dword ptr [ebx]
// 0053166e  8d44240c             lea eax, [esp + 0xc]
// 00531672  50                   push eax
// 00531673  57                   push edi
// 00531674  89542414             mov dword ptr [esp + 0x14], edx
// 00531678  56                   push esi
// 00531679  8d542420             lea edx, [esp + 0x20]
// 0053167d  52                   push edx
// 0053167e  c644242000           mov byte ptr [esp + 0x20], 0
// 00531683  e858faffff           call 0x5310e0
// 00531688  8b30                 mov esi, dword ptr [eax]
// 0053168a  8b7804               mov edi, dword ptr [eax + 4]
// 0053168d  85f6                 test esi, esi
// 0053168f  8b1d44e97700         mov ebx, dword ptr [0x77e944]
// 00531695  7502                 jne 0x531699
// 00531697  ffd3                 call ebx
// 00531699  3b7e04               cmp edi, dword ptr [esi + 4]
// 0053169c  7502                 jne 0x5316a0
// 0053169e  ffd3                 call ebx
// 005316a0  8d4710               lea eax, [edi + 0x10]
// 005316a3  5f                   pop edi
// 005316a4  5e                   pop esi
// 005316a5  5b                   pop ebx
// 005316a6  83c410               add esp, 0x10
// 005316a9  c20400               ret 4
// standard library map_ptr<char> (function ??A?$map@PAUK@@DU?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@D@std@@@3@@std@@QAEAADABQAUK@@@Z)

// stl: map_ptr<char>
typedef char E;
#include <map>
struct K; template class std::map<K*, E>;
