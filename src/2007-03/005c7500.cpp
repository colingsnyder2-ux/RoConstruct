// from server: 100% by auto
// roc 2007-03 005c7500  unit: seg_005c0000  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c7500
//
// 005c7500  68eed8ffff           push 0xffffd8ee
// 005c7505  56                   push esi
// 005c7506  e80517ffff           call 0x5b8c10
// 005c750b  68f0a57b00           push 0x7ba5f0
// 005c7510  68eed8ffff           push 0xffffd8ee
// 005c7515  56                   push esi
// 005c7516  e8d51fffff           call 0x5b94f0
// 005c751b  6828a27b00           push 0x7ba228
// 005c7520  68f0a57b00           push 0x7ba5f0
// 005c7525  56                   push esi
// 005c7526  e84534ffff           call 0x5ba970
// 005c752b  6a07                 push 7
// 005c752d  68e8a57b00           push 0x7ba5e8
// 005c7532  56                   push esi
// 005c7533  e8481bffff           call 0x5b9080
// 005c7538  68dca57b00           push 0x7ba5dc
// 005c753d  68eed8ffff           push 0xffffd8ee
// 005c7542  56                   push esi
// 005c7543  e8a81fffff           call 0x5b94f0
// 005c7548  6a00                 push 0
// 005c754a  68906b5c00           push 0x5c6b90
// 005c754f  56                   push esi
// 005c7550  e83b1cffff           call 0x5b9190
// 005c7555  83c444               add esp, 0x44
// 005c7558  6a01                 push 1
// 005c755a  68e06b5c00           push 0x5c6be0
// 005c755f  56                   push esi
// 005c7560  e82b1cffff           call 0x5b9190
// 005c7565  68d4a57b00           push 0x7ba5d4
// 005c756a  6afe                 push -2
// 005c756c  56                   push esi
// 005c756d  e87e1fffff           call 0x5b94f0
// 005c7572  6a00                 push 0
// 005c7574  68106b5c00           push 0x5c6b10
// 005c7579  56                   push esi
// 005c757a  e8111cffff           call 0x5b9190
// 005c757f  6a01                 push 1
// 005c7581  68506b5c00           push 0x5c6b50
// 005c7586  56                   push esi
// 005c7587  e8041cffff           call 0x5b9190
// 005c758c  68cca57b00           push 0x7ba5cc
// 005c7591  6afe                 push -2
// 005c7593  56                   push esi
// 005c7594  e8571fffff           call 0x5b94f0
// 005c7599  6a01                 push 1
// 005c759b  6a00                 push 0
// 005c759d  56                   push esi
// 005c759e  e80d1effff           call 0x5b93b0
// 005c75a3  83c448               add esp, 0x48
// 005c75a6  6aff                 push -1
// 005c75a8  56                   push esi
// 005c75a9  e86216ffff           call 0x5b8c10
// 005c75ae  6afe                 push -2
// 005c75b0  56                   push esi
// 005c75b1  e87a20ffff           call 0x5b9630
// 005c75b6  6a02                 push 2
// 005c75b8  68c8a57b00           push 0x7ba5c8
// 005c75bd  56                   push esi
// 005c75be  e8bd1affff           call 0x5b9080
// 005c75c3  6858927b00           push 0x7b9258
// 005c75c8  6afe                 push -2
// 005c75ca  56                   push esi
// 005c75cb  e8201fffff           call 0x5b94f0
// 005c75d0  6a01                 push 1
// 005c75d2  68f0705c00           push 0x5c70f0
// 005c75d7  56                   push esi
// 005c75d8  e8b31bffff           call 0x5b9190
// 005c75dd  68bca57b00           push 0x7ba5bc
// 005c75e2  68eed8ffff           push 0xffffd8ee
// 005c75e7  56                   push esi
// 005c75e8  e8031fffff           call 0x5b94f0
// 005c75ed  83c440               add esp, 0x40
// 005c75f0  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _base_open)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
