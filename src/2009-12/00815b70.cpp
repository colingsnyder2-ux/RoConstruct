// from server: 100% by auto
// roc 2009-12 00815b70  unit: CXTPCommandBar  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00815b70
//
// 00815b70  56                   push esi
// 00815b71  8bf1                 mov esi, ecx
// 00815b73  85f6                 test esi, esi
// 00815b75  7518                 jne 0x815b8f
// 00815b77  68b0647f00           push 0x7f64b0
// 00815b7c  b9d0bab900           mov ecx, 0xb9bad0
// 00815b81  e8b6081100           call 0x92643c
// 00815b86  85c0                 test eax, eax
// 00815b88  752d                 jne 0x815bb7
// 00815b8a  e87ddffdff           call 0x7f3b0c
// 00815b8f  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 00815b95  85c0                 test eax, eax
// 00815b97  751e                 jne 0x815bb7
// 00815b99  68b0647f00           push 0x7f64b0
// 00815b9e  b9d0bab900           mov ecx, 0xb9bad0
// 00815ba3  e894081100           call 0x92643c
// 00815ba8  85c0                 test eax, eax
// 00815baa  7505                 jne 0x815bb1
// 00815bac  e85bdffdff           call 0x7f3b0c
// 00815bb1  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 00815bb7  5e                   pop esi
// 00815bb8  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetMouseManager@CXTPCommandBars@@QBEPAVCXTPMouseManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
