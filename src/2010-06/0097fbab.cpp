// from server: 100% by auto
// roc 2010-06 0097fbab  unit: CSpinButtonCtrl  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0097fbab
//
// 0097fbab  6850157400           push 0x741550
// 0097fbb0  6a1a                 push 0x1a
// 0097fbb2  6a1c                 push 0x1c
// 0097fbb4  8d851cfdffff         lea eax, [ebp - 0x2e4]
// 0097fbba  50                   push eax
// 0097fbbb  e81e8fe2ff           call 0x7a8ade
// 0097fbc0  c3                   ret 
// standard library list<ptr> (function __unwindfunclet$?sort@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ$1)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
