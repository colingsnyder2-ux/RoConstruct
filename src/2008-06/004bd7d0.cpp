// from server: 100% by auto
// roc 2008-06 004bd7d0  unit: ProfiledRakPeer  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd7d0
//
// 004bd7d0  56                   push esi
// 004bd7d1  8bf1                 mov esi, ecx
// 004bd7d3  8b86dc080000         mov eax, dword ptr [esi + 0x8dc]
// 004bd7d9  8b4808               mov ecx, dword ptr [eax + 8]
// 004bd7dc  3b8ee0080000         cmp ecx, dword ptr [esi + 0x8e0]
// 004bd7e2  7411                 je 0x4bd7f5
// 004bd7e4  8b96dc080000         mov edx, dword ptr [esi + 0x8dc]
// 004bd7ea  8b4208               mov eax, dword ptr [edx + 8]
// 004bd7ed  8a4804               mov cl, byte ptr [eax + 4]
// 004bd7f0  80f901               cmp cl, 1
// 004bd7f3  752a                 jne 0x4bd81f
// 004bd7f5  8b96dc080000         mov edx, dword ptr [esi + 0x8dc]
// 004bd7fb  57                   push edi
// 004bd7fc  8b7a08               mov edi, dword ptr [edx + 8]
// 004bd7ff  6a0c                 push 0xc
// 004bd801  e81a311e00           call 0x6a0920
// 004bd806  8b8edc080000         mov ecx, dword ptr [esi + 0x8dc]
// 004bd80c  894108               mov dword ptr [ecx + 8], eax
// 004bd80f  8b96dc080000         mov edx, dword ptr [esi + 0x8dc]
// 004bd815  8b4208               mov eax, dword ptr [edx + 8]
// 004bd818  83c404               add esp, 4
// 004bd81b  897808               mov dword ptr [eax + 8], edi
// 004bd81e  5f                   pop edi
// 004bd81f  8b86dc080000         mov eax, dword ptr [esi + 0x8dc]
// 004bd825  8b4808               mov ecx, dword ptr [eax + 8]
// 004bd828  8b542408             mov edx, dword ptr [esp + 8]
// 004bd82c  898edc080000         mov dword ptr [esi + 0x8dc], ecx
// 004bd832  8910                 mov dword ptr [eax], edx
// 004bd834  8b86e4080000         mov eax, dword ptr [esi + 0x8e4]
// 004bd83a  ff86ec080000         inc dword ptr [esi + 0x8ec]
// 004bd840  c6400401             mov byte ptr [eax + 4], 1
// 004bd844  8b8ee4080000         mov ecx, dword ptr [esi + 0x8e4]
// 004bd84a  8b5108               mov edx, dword ptr [ecx + 8]
// 004bd84d  8996e4080000         mov dword ptr [esi + 0x8e4], edx
// 004bd853  5e                   pop esi
// 004bd854  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?AddPacketToProducer@RakPeer@@IAEXPAUPacket@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
