// from server: 100% by auto
// roc 2009-06 0084ebeb  unit: CSpinButtonCtrl  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0084ebeb
//
// 0084ebeb  68a01e6700           push 0x671ea0
// 0084ebf0  6a1a                 push 0x1a
// 0084ebf2  6a1c                 push 0x1c
// 0084ebf4  8d851cfdffff         lea eax, [ebp - 0x2e4]
// 0084ebfa  50                   push eax
// 0084ebfb  e876afecff           call 0x719b76
// 0084ec00  c3                   ret 
// standard library list<ptr> (function __unwindfunclet$?sort@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ$1)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
