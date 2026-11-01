// from server: 100% by auto
// roc 2007-03 005c6430  unit: seg_005c0000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6430
//
// 005c6430  6a01                 push 1
// 005c6432  6a00                 push 0
// 005c6434  56                   push esi
// 005c6435  e8762fffff           call 0x5b93b0
// 005c643a  6a00                 push 0
// 005c643c  68ac497800           push 0x7849ac
// 005c6441  56                   push esi
// 005c6442  e8392cffff           call 0x5b9080
// 005c6447  6afe                 push -2
// 005c6449  56                   push esi
// 005c644a  e8c127ffff           call 0x5b8c10
// 005c644f  6afe                 push -2
// 005c6451  56                   push esi
// 005c6452  e8d931ffff           call 0x5b9630
// 005c6457  6afe                 push -2
// 005c6459  56                   push esi
// 005c645a  e80126ffff           call 0x5b8a60
// 005c645f  6afe                 push -2
// 005c6461  56                   push esi
// 005c6462  e8a927ffff           call 0x5b8c10
// 005c6467  6874567a00           push 0x7a5674
// 005c646c  6afe                 push -2
// 005c646e  56                   push esi
// 005c646f  e87c30ffff           call 0x5b94f0
// 005c6474  83c444               add esp, 0x44
// 005c6477  6afe                 push -2
// 005c6479  56                   push esi
// 005c647a  e8e125ffff           call 0x5b8a60
// 005c647f  83c408               add esp, 8
// 005c6482  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _createmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
