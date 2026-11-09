// from server: 100% by auto
// roc 2009-12 0079f8d0  unit: seg_00790000  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f8d0
//
// 0079f8d0  68eed8ffff           push 0xffffd8ee
// 0079f8d5  56                   push esi
// 0079f8d6  e88590feff           call 0x788960
// 0079f8db  6870b79e00           push 0x9eb770
// 0079f8e0  68eed8ffff           push 0xffffd8ee
// 0079f8e5  56                   push esi
// 0079f8e6  e84599feff           call 0x789230
// 0079f8eb  6890b39e00           push 0x9eb390
// 0079f8f0  6870b79e00           push 0x9eb770
// 0079f8f5  56                   push esi
// 0079f8f6  e825b2feff           call 0x78ab20
// 0079f8fb  6a07                 push 7
// 0079f8fd  6868b79e00           push 0x9eb768
// 0079f902  56                   push esi
// 0079f903  e89894feff           call 0x788da0
// 0079f908  685cb79e00           push 0x9eb75c
// 0079f90d  68eed8ffff           push 0xffffd8ee
// 0079f912  56                   push esi
// 0079f913  e81899feff           call 0x789230
// 0079f918  6a00                 push 0
// 0079f91a  6840ef7900           push 0x79ef40
// 0079f91f  56                   push esi
// 0079f920  e88b95feff           call 0x788eb0
// 0079f925  83c444               add esp, 0x44
// 0079f928  6a01                 push 1
// 0079f92a  6880ef7900           push 0x79ef80
// 0079f92f  56                   push esi
// 0079f930  e87b95feff           call 0x788eb0
// 0079f935  6854b79e00           push 0x9eb754
// 0079f93a  6afe                 push -2
// 0079f93c  56                   push esi
// 0079f93d  e8ee98feff           call 0x789230
// 0079f942  6a00                 push 0
// 0079f944  68c0ee7900           push 0x79eec0
// 0079f949  56                   push esi
// 0079f94a  e86195feff           call 0x788eb0
// 0079f94f  6a01                 push 1
// 0079f951  6800ef7900           push 0x79ef00
// 0079f956  56                   push esi
// 0079f957  e85495feff           call 0x788eb0
// 0079f95c  684cb79e00           push 0x9eb74c
// 0079f961  6afe                 push -2
// 0079f963  56                   push esi
// 0079f964  e8c798feff           call 0x789230
// 0079f969  6a01                 push 1
// 0079f96b  6a00                 push 0
// 0079f96d  56                   push esi
// 0079f96e  e85d97feff           call 0x7890d0
// 0079f973  83c448               add esp, 0x48
// 0079f976  6aff                 push -1
// 0079f978  56                   push esi
// 0079f979  e8e28ffeff           call 0x788960
// 0079f97e  6afe                 push -2
// 0079f980  56                   push esi
// 0079f981  e8fa99feff           call 0x789380
// 0079f986  6a02                 push 2
// 0079f988  6848b79e00           push 0x9eb748
// 0079f98d  56                   push esi
// 0079f98e  e80d94feff           call 0x788da0
// 0079f993  68489e9e00           push 0x9e9e48
// 0079f998  6afe                 push -2
// 0079f99a  56                   push esi
// 0079f99b  e89098feff           call 0x789230
// 0079f9a0  6a01                 push 1
// 0079f9a2  68a0f47900           push 0x79f4a0
// 0079f9a7  56                   push esi
// 0079f9a8  e80395feff           call 0x788eb0
// 0079f9ad  683cb79e00           push 0x9eb73c
// 0079f9b2  68eed8ffff           push 0xffffd8ee
// 0079f9b7  56                   push esi
// 0079f9b8  e87398feff           call 0x789230
// 0079f9bd  83c440               add esp, 0x40
// 0079f9c0  c3                   ret 
// library lua-5.1/lbaselib.c (function _base_open)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
