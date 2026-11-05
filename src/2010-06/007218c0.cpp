// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
struct Inner { char pad[7]; char m_flag; };
struct Outer { Inner* m_inner; };
struct Tool { void* pad; };
__declspec(noinline) static Outer* doIt(Tool* t, int b) { return (Outer*)((char*)t + b * 4); }
void func(Tool* a, int b, char v) { doIt(a, b)->m_inner->m_flag = v; }
