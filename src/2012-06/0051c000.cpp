// from server: 100% by Xemicl
// roc 2012-06 0051c000  unit: Ogre::istreamDataStream  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051c000
//
// 0051c000  8bc1                 mov eax, ecx
// 0051c002  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0051c006  8b11                 mov edx, dword ptr [ecx]
// 0051c008  8910                 mov dword ptr [eax], edx
// 0051c00a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0051c00d  894804               mov dword ptr [eax + 4], ecx
// 0051c010  85c9                 test ecx, ecx
// 0051c012  740c                 je 0x51c020
// 0051c014  83c108               add ecx, 8
// 0051c017  ba01000000           mov edx, 1
// 0051c01c  f00fc111             lock xadd dword ptr [ecx], edx
// 0051c020  c20800               ret 8
// copied from an identical function in another client (function ??$?0UX@@@?$weak_ptr@UX@@@@QAE@ABU?$shared_ptr@UX@@@@UDummy@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
struct Base { virtual void dispose(); long use; long weak; };
struct Dummy {};
template<class T> struct shared_ptr { T* px; Base* pi; };
template<class T> struct weak_ptr { T* px; Base* pi;
  template<class Y> weak_ptr(const shared_ptr<Y>& r, Dummy = Dummy()) : px(r.px), pi(r.pi) { if (pi) _InterlockedIncrement(&pi->weak); } };
struct X {};
template weak_ptr<X>::weak_ptr(const shared_ptr<X>&, Dummy);