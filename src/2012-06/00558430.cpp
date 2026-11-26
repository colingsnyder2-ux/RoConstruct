// from server: 100% by Xemicl
// roc 2012-06 00558430  unit: CrashReporter  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00558430
//
// 00558430  55                   push ebp
// 00558431  8bec                 mov ebp, esp
// 00558433  83ec08               sub esp, 8
// 00558436  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0055843d  8d450c               lea eax, [ebp + 0xc]
// 00558440  50                   push eax
// 00558441  e89af7ffff           call 0x557be0
// 00558446  83c404               add esp, 4
// 00558449  8945f8               mov dword ptr [ebp - 8], eax
// 0055844c  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0055844f  8b55f8               mov edx, dword ptr [ebp - 8]
// 00558452  8911                 mov dword ptr [ecx], edx
// 00558454  8b4508               mov eax, dword ptr [ebp + 8]
// 00558457  833800               cmp dword ptr [eax], 0
// 0055845a  7417                 je 0x558473
// 0055845c  b901000000           mov ecx, 1
// 00558461  85c9                 test ecx, ecx
// 00558463  740e                 je 0x558473
// 00558465  8b5508               mov edx, dword ptr [ebp + 8]
// 00558468  8b02                 mov eax, dword ptr [edx]
// 0055846a  50                   push eax
// 0055846b  e830c8edff           call 0x434ca0
// 00558470  83c404               add esp, 4
// 00558473  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00558476  83c901               or ecx, 1
// 00558479  894dfc               mov dword ptr [ebp - 4], ecx
// 0055847c  8b4508               mov eax, dword ptr [ebp + 8]
// 0055847f  8be5                 mov esp, ebp
// 00558481  5d                   pop ebp
// 00558482  c3                   ret 
// copied from an identical function in another client (function ?make@@YA?AV?$intrusive_ptr@UT@@@@UX@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /EHsc /MD
struct X { int a, b, c; };
struct T;
void intrusive_ptr_add_ref(T* p);
template<class U> class intrusive_ptr {
	U* px;
public:
	intrusive_ptr(U* p, bool add_ref = true) : px(p) { if (px != 0 && add_ref) intrusive_ptr_add_ref(px); }
	~intrusive_ptr();
};
T* create(const X& x);
intrusive_ptr<T> make(X x) { return intrusive_ptr<T>(create(x)); }