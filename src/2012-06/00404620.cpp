// from server: 100% by auto
// roc 2012-06 00404620  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404620
//
// 00404620  f6055464e10001       test byte ptr [0xe16454], 1
// 00404627  755d                 jne 0x404686
// 00404629  830d5464e10001       or dword ptr [0xe16454], 1
// 00404630  b808000000           mov eax, 8
// 00404635  66a33864e100         mov word ptr [0xe16438], ax
// 0040463b  b908400000           mov ecx, 0x4008
// 00404640  ba13000000           mov edx, 0x13
// 00404645  b811000000           mov eax, 0x11
// 0040464a  c7053464e100f435b400 mov dword ptr [0xe16434], 0xb435f4
// 00404654  c7053c64e100f035b400 mov dword ptr [0xe1643c], 0xb435f0
// 0040465e  66890d4064e100       mov word ptr [0xe16440], cx
// 00404665  c7054464e100ec35b400 mov dword ptr [0xe16444], 0xb435ec
// 0040466f  6689154864e100       mov word ptr [0xe16448], dx
// 00404676  c7054c64e100e835b400 mov dword ptr [0xe1644c], 0xb435e8
// 00404680  66a35064e100         mov word ptr [0xe16450], ax
// 00404686  53                   push ebx
// 00404687  8b1da421b200         mov ebx, dword ptr [0xb221a4]
// 0040468d  56                   push esi
// 0040468e  57                   push edi
// 0040468f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00404693  33f6                 xor esi, esi
// 00404695  8b0cf53464e100       mov ecx, dword ptr [esi*8 + 0xe16434]
// 0040469c  51                   push ecx
// 0040469d  57                   push edi
// 0040469e  ffd3                 call ebx
// 004046a0  85c0                 test eax, eax
// 004046a2  740c                 je 0x4046b0
// 004046a4  46                   inc esi
// 004046a5  83fe04               cmp esi, 4
// 004046a8  72eb                 jb 0x404695
// 004046aa  5f                   pop edi
// 004046ab  5e                   pop esi
// 004046ac  33c0                 xor eax, eax
// 004046ae  5b                   pop ebx
// 004046af  c3                   ret 
// 004046b0  668b14f53864e100     mov dx, word ptr [esi*8 + 0xe16438]
// 004046b8  8b442414             mov eax, dword ptr [esp + 0x14]
// 004046bc  5f                   pop edi
// 004046bd  5e                   pop esi
// 004046be  668910               mov word ptr [eax], dx
// 004046c1  b801000000           mov eax, 1
// 004046c6  5b                   pop ebx
// 004046c7  c3                   ret 
// library atl-9.0/atl.cpp (function ?VTFromRegType@CRegParser@ATL@@KAHPBDAAG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
