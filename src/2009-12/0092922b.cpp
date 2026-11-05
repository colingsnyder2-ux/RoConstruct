// roc 2009-12 0092922b  unit: CSpinButtonCtrl  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0092922b
//
// 0092922b  68203d7200           push 0x723d20
// 00929230  6a1a                 push 0x1a
// 00929232  6a1c                 push 0x1c
// 00929234  8d851cfdffff         lea eax, [ebp - 0x2e4]
// 0092923a  50                   push eax
// 0092923b  e864b7ecff           call 0x7f49a4
// 00929240  c3                   ret 
// standard library list<ptr> (function __unwindfunclet$?sort@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ$1)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
