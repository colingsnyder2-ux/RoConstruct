// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void __cdecl free(void*);
struct Base { void* p; ~Base() { free(p); } };
struct Mid : Base { void c() throw(); ~Mid() { c(); } };
struct D : Mid { void a(); void b(); ~D(); };
D::~D() { try { a(); b(); } catch (...) { } }
