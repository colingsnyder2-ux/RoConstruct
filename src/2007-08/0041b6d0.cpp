// from server: 100% by auto
// roc 2007-08 0041b6d0  unit: VDHTMLWindow::?$SignalDesc  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041b6d0
//
// 0041b6d0  8b542404             mov edx, dword ptr [esp + 4]
// 0041b6d4  83ec08               sub esp, 8
// 0041b6d7  53                   push ebx
// 0041b6d8  8bd9                 mov ebx, ecx
// 0041b6da  8b4308               mov eax, dword ptr [ebx + 8]
// 0041b6dd  b949922409           mov ecx, 0x9249249
// 0041b6e2  2bc8                 sub ecx, eax
// 0041b6e4  3bca                 cmp ecx, edx
// 0041b6e6  7305                 jae 0x41b6ed
// 0041b6e8  e8439a0800           call 0x4a5130
// 0041b6ed  8bc8                 mov ecx, eax
// 0041b6ef  d1e9                 shr ecx, 1
// 0041b6f1  83f908               cmp ecx, 8
// 0041b6f4  7305                 jae 0x41b6fb
// 0041b6f6  b908000000           mov ecx, 8
// 0041b6fb  3bd1                 cmp edx, ecx
// 0041b6fd  55                   push ebp
// 0041b6fe  56                   push esi
// 0041b6ff  57                   push edi
// 0041b700  7311                 jae 0x41b713
// 0041b702  be49922409           mov esi, 0x9249249
// 0041b707  2bf1                 sub esi, ecx
// 0041b709  3bc6                 cmp eax, esi
// 0041b70b  7706                 ja 0x41b713
// 0041b70d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0041b711  8bd1                 mov edx, ecx
// 0041b713  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 0041b716  03c2                 add eax, edx
// 0041b718  6a00                 push 0
// 0041b71a  50                   push eax
// 0041b71b  e840461900           call 0x5afd60
// 0041b720  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0041b723  89442418             mov dword ptr [esp + 0x18], eax
// 0041b727  8d34ad00000000       lea esi, [ebp*4]
// 0041b72e  8d3c06               lea edi, [esi + eax]
// 0041b731  8b4308               mov eax, dword ptr [ebx + 8]
// 0041b734  03c0                 add eax, eax
// 0041b736  03c0                 add eax, eax
// 0041b738  8d140e               lea edx, [esi + ecx]
// 0041b73b  2bc2                 sub eax, edx
// 0041b73d  03c1                 add eax, ecx
// 0041b73f  83c408               add esp, 8
// 0041b742  c1f802               sar eax, 2
// 0041b745  8d048500000000       lea eax, [eax*4]
// 0041b74c  8d0c38               lea ecx, [eax + edi]
// 0041b74f  894c2414             mov dword ptr [esp + 0x14], ecx
// 0041b753  7415                 je 0x41b76a
// 0041b755  50                   push eax
// 0041b756  52                   push edx
// 0041b757  50                   push eax
// 0041b758  57                   push edi
// 0041b759  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 0041b75f  ffd7                 call edi
// 0041b761  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0041b765  83c410               add esp, 0x10
// 0041b768  eb06                 jmp 0x41b770
// 0041b76a  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 0041b770  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041b774  3be8                 cmp ebp, eax
// 0041b776  7735                 ja 0x41b7ad
// 0041b778  8b4304               mov eax, dword ptr [ebx + 4]
// 0041b77b  c1fe02               sar esi, 2
// 0041b77e  8d14b500000000       lea edx, [esi*4]
// 0041b785  8d340a               lea esi, [edx + ecx]
// 0041b788  7409                 je 0x41b793
// 0041b78a  52                   push edx
// 0041b78b  50                   push eax
// 0041b78c  52                   push edx
// 0041b78d  51                   push ecx
// 0041b78e  ffd7                 call edi
// 0041b790  83c410               add esp, 0x10
// 0041b793  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041b797  2bcd                 sub ecx, ebp
// 0041b799  7406                 je 0x41b7a1
// 0041b79b  33c0                 xor eax, eax
// 0041b79d  8bfe                 mov edi, esi
// 0041b79f  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041b7a1  85ed                 test ebp, ebp
// 0041b7a3  765a                 jbe 0x41b7ff
// 0041b7a5  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0041b7a9  8bcd                 mov ecx, ebp
// 0041b7ab  eb4e                 jmp 0x41b7fb
// 0041b7ad  8b5304               mov edx, dword ptr [ebx + 4]
// 0041b7b0  8d2c8500000000       lea ebp, [eax*4]
// 0041b7b7  8bc5                 mov eax, ebp
// 0041b7b9  c1f802               sar eax, 2
// 0041b7bc  740d                 je 0x41b7cb
// 0041b7be  03c0                 add eax, eax
// 0041b7c0  03c0                 add eax, eax
// 0041b7c2  50                   push eax
// 0041b7c3  52                   push edx
// 0041b7c4  50                   push eax
// 0041b7c5  51                   push ecx
// 0041b7c6  ffd7                 call edi
// 0041b7c8  83c410               add esp, 0x10
// 0041b7cb  8b4304               mov eax, dword ptr [ebx + 4]
// 0041b7ce  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b7d2  8d0c28               lea ecx, [eax + ebp]
// 0041b7d5  2bf1                 sub esi, ecx
// 0041b7d7  03f0                 add esi, eax
// 0041b7d9  c1fe02               sar esi, 2
// 0041b7dc  8d04b500000000       lea eax, [esi*4]
// 0041b7e3  8d3410               lea esi, [eax + edx]
// 0041b7e6  7409                 je 0x41b7f1
// 0041b7e8  50                   push eax
// 0041b7e9  51                   push ecx
// 0041b7ea  50                   push eax
// 0041b7eb  52                   push edx
// 0041b7ec  ffd7                 call edi
// 0041b7ee  83c410               add esp, 0x10
// 0041b7f1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041b7f5  85c9                 test ecx, ecx
// 0041b7f7  7606                 jbe 0x41b7ff
// 0041b7f9  8bfe                 mov edi, esi
// 0041b7fb  33c0                 xor eax, eax
// 0041b7fd  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041b7ff  8b4304               mov eax, dword ptr [ebx + 4]
// 0041b802  85c0                 test eax, eax
// 0041b804  5f                   pop edi
// 0041b805  5e                   pop esi
// 0041b806  5d                   pop ebp
// 0041b807  7409                 je 0x41b812
// 0041b809  50                   push eax
// 0041b80a  e853442100           call 0x62fc62
// 0041b80f  83c404               add esp, 4
// 0041b812  8b542404             mov edx, dword ptr [esp + 4]
// 0041b816  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041b81a  014308               add dword ptr [ebx + 8], eax
// 0041b81d  895304               mov dword ptr [ebx + 4], edx
// 0041b820  5b                   pop ebx
// 0041b821  83c408               add esp, 8
// 0041b824  c20400               ret 4
// standard library deque<string> (function ?_Growmap@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXI@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
