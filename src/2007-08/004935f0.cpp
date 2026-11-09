// from server: 100% by auto
// roc 2007-08 004935f0  unit: RBX::Network::VPlayers::?$Notifier  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004935f0
//
// 004935f0  8b542404             mov edx, dword ptr [esp + 4]
// 004935f4  83ec08               sub esp, 8
// 004935f7  53                   push ebx
// 004935f8  8bd9                 mov ebx, ecx
// 004935fa  8b4308               mov eax, dword ptr [ebx + 8]
// 004935fd  b955555505           mov ecx, 0x5555555
// 00493602  2bc8                 sub ecx, eax
// 00493604  3bca                 cmp ecx, edx
// 00493606  7305                 jae 0x49360d
// 00493608  e8231b0100           call 0x4a5130
// 0049360d  8bc8                 mov ecx, eax
// 0049360f  d1e9                 shr ecx, 1
// 00493611  83f908               cmp ecx, 8
// 00493614  7305                 jae 0x49361b
// 00493616  b908000000           mov ecx, 8
// 0049361b  3bd1                 cmp edx, ecx
// 0049361d  55                   push ebp
// 0049361e  56                   push esi
// 0049361f  57                   push edi
// 00493620  7311                 jae 0x493633
// 00493622  be55555505           mov esi, 0x5555555
// 00493627  2bf1                 sub esi, ecx
// 00493629  3bc6                 cmp eax, esi
// 0049362b  7706                 ja 0x493633
// 0049362d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00493631  8bd1                 mov edx, ecx
// 00493633  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 00493636  03c2                 add eax, edx
// 00493638  6a00                 push 0
// 0049363a  50                   push eax
// 0049363b  e820c71100           call 0x5afd60
// 00493640  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00493643  89442418             mov dword ptr [esp + 0x18], eax
// 00493647  8d34ad00000000       lea esi, [ebp*4]
// 0049364e  8d3c06               lea edi, [esi + eax]
// 00493651  8b4308               mov eax, dword ptr [ebx + 8]
// 00493654  03c0                 add eax, eax
// 00493656  03c0                 add eax, eax
// 00493658  8d140e               lea edx, [esi + ecx]
// 0049365b  2bc2                 sub eax, edx
// 0049365d  03c1                 add eax, ecx
// 0049365f  83c408               add esp, 8
// 00493662  c1f802               sar eax, 2
// 00493665  8d048500000000       lea eax, [eax*4]
// 0049366c  8d0c38               lea ecx, [eax + edi]
// 0049366f  894c2414             mov dword ptr [esp + 0x14], ecx
// 00493673  7415                 je 0x49368a
// 00493675  50                   push eax
// 00493676  52                   push edx
// 00493677  50                   push eax
// 00493678  57                   push edi
// 00493679  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 0049367f  ffd7                 call edi
// 00493681  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00493685  83c410               add esp, 0x10
// 00493688  eb06                 jmp 0x493690
// 0049368a  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 00493690  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00493694  3be8                 cmp ebp, eax
// 00493696  7735                 ja 0x4936cd
// 00493698  8b4304               mov eax, dword ptr [ebx + 4]
// 0049369b  c1fe02               sar esi, 2
// 0049369e  8d14b500000000       lea edx, [esi*4]
// 004936a5  8d340a               lea esi, [edx + ecx]
// 004936a8  7409                 je 0x4936b3
// 004936aa  52                   push edx
// 004936ab  50                   push eax
// 004936ac  52                   push edx
// 004936ad  51                   push ecx
// 004936ae  ffd7                 call edi
// 004936b0  83c410               add esp, 0x10
// 004936b3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004936b7  2bcd                 sub ecx, ebp
// 004936b9  7406                 je 0x4936c1
// 004936bb  33c0                 xor eax, eax
// 004936bd  8bfe                 mov edi, esi
// 004936bf  f3ab                 rep stosd dword ptr es:[edi], eax
// 004936c1  85ed                 test ebp, ebp
// 004936c3  765a                 jbe 0x49371f
// 004936c5  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004936c9  8bcd                 mov ecx, ebp
// 004936cb  eb4e                 jmp 0x49371b
// 004936cd  8b5304               mov edx, dword ptr [ebx + 4]
// 004936d0  8d2c8500000000       lea ebp, [eax*4]
// 004936d7  8bc5                 mov eax, ebp
// 004936d9  c1f802               sar eax, 2
// 004936dc  740d                 je 0x4936eb
// 004936de  03c0                 add eax, eax
// 004936e0  03c0                 add eax, eax
// 004936e2  50                   push eax
// 004936e3  52                   push edx
// 004936e4  50                   push eax
// 004936e5  51                   push ecx
// 004936e6  ffd7                 call edi
// 004936e8  83c410               add esp, 0x10
// 004936eb  8b4304               mov eax, dword ptr [ebx + 4]
// 004936ee  8b542410             mov edx, dword ptr [esp + 0x10]
// 004936f2  8d0c28               lea ecx, [eax + ebp]
// 004936f5  2bf1                 sub esi, ecx
// 004936f7  03f0                 add esi, eax
// 004936f9  c1fe02               sar esi, 2
// 004936fc  8d04b500000000       lea eax, [esi*4]
// 00493703  8d3410               lea esi, [eax + edx]
// 00493706  7409                 je 0x493711
// 00493708  50                   push eax
// 00493709  51                   push ecx
// 0049370a  50                   push eax
// 0049370b  52                   push edx
// 0049370c  ffd7                 call edi
// 0049370e  83c410               add esp, 0x10
// 00493711  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00493715  85c9                 test ecx, ecx
// 00493717  7606                 jbe 0x49371f
// 00493719  8bfe                 mov edi, esi
// 0049371b  33c0                 xor eax, eax
// 0049371d  f3ab                 rep stosd dword ptr es:[edi], eax
// 0049371f  8b4304               mov eax, dword ptr [ebx + 4]
// 00493722  85c0                 test eax, eax
// 00493724  5f                   pop edi
// 00493725  5e                   pop esi
// 00493726  5d                   pop ebp
// 00493727  7409                 je 0x493732
// 00493729  50                   push eax
// 0049372a  e833c51900           call 0x62fc62
// 0049372f  83c404               add esp, 4
// 00493732  8b542404             mov edx, dword ptr [esp + 4]
// 00493736  8b442410             mov eax, dword ptr [esp + 0x10]
// 0049373a  014308               add dword ptr [ebx + 8], eax
// 0049373d  895304               mov dword ptr [ebx + 4], edx
// 00493740  5b                   pop ebx
// 00493741  83c408               add esp, 8
// 00493744  c20400               ret 4
// standard library deque<pod48> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod48>
struct E { int v[12]; };
#include <deque>
template class std::deque<E>;
