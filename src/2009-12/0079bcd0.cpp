// from server: 100% by auto
// roc 2009-12 0079bcd0  unit: seg_00790000  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079bcd0
//
// 0079bcd0  56                   push esi
// 0079bcd1  8b742408             mov esi, dword ptr [esp + 8]
// 0079bcd5  6a05                 push 5
// 0079bcd7  6a01                 push 1
// 0079bcd9  56                   push esi
// 0079bcda  e811eafeff           call 0x78a6f0
// 0079bcdf  6a06                 push 6
// 0079bce1  6a02                 push 2
// 0079bce3  56                   push esi
// 0079bce4  e807eafeff           call 0x78a6f0
// 0079bce9  56                   push esi
// 0079bcea  e851d0feff           call 0x788d40
// 0079bcef  6a01                 push 1
// 0079bcf1  56                   push esi
// 0079bcf2  e839dafeff           call 0x789730
// 0079bcf7  83c424               add esp, 0x24
// 0079bcfa  85c0                 test eax, eax
// 0079bcfc  744a                 je 0x79bd48
// 0079bcfe  8bff                 mov edi, edi
// 0079bd00  6a02                 push 2
// 0079bd02  56                   push esi
// 0079bd03  e858ccfeff           call 0x788960
// 0079bd08  6afd                 push -3
// 0079bd0a  56                   push esi
// 0079bd0b  e850ccfeff           call 0x788960
// 0079bd10  6afd                 push -3
// 0079bd12  56                   push esi
// 0079bd13  e848ccfeff           call 0x788960
// 0079bd18  6a01                 push 1
// 0079bd1a  6a02                 push 2
// 0079bd1c  56                   push esi
// 0079bd1d  e89ed7feff           call 0x7894c0
// 0079bd22  6aff                 push -1
// 0079bd24  56                   push esi
// 0079bd25  e866ccfeff           call 0x788990
// 0079bd2a  83c42c               add esp, 0x2c
// 0079bd2d  85c0                 test eax, eax
// 0079bd2f  751b                 jne 0x79bd4c
// 0079bd31  6afd                 push -3
// 0079bd33  56                   push esi
// 0079bd34  e877cafeff           call 0x7887b0
// 0079bd39  6a01                 push 1
// 0079bd3b  56                   push esi
// 0079bd3c  e8efd9feff           call 0x789730
// 0079bd41  83c410               add esp, 0x10
// 0079bd44  85c0                 test eax, eax
// 0079bd46  75b8                 jne 0x79bd00
// 0079bd48  33c0                 xor eax, eax
// 0079bd4a  5e                   pop esi
// 0079bd4b  c3                   ret 
// 0079bd4c  b801000000           mov eax, 1
// 0079bd51  5e                   pop esi
// 0079bd52  c3                   ret 
// library lua-5.1/ltablib.c (function _foreach)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltablib.c
