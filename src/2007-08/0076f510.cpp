// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
// roc-lib: ogre-1.6.4 roc_claude_688423dbce7610bd.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 dynamic initializer in seg_00760000 (codegen analog): new of an 8-byte object (push 8),
// pointer stored to a global, registered through a thiscall on a global, then a cdecl
// (void*, T*, T*) call and the atexit-style tail call shared by the neighbouring initializers.
struct Obj8_0076f510 { Obj8_0076f510(); int a; int b; };
struct Reg_0076f510 { void add(Obj8_0076f510*); };
extern Reg_0076f510 g_reg_0076f510;
extern Obj8_0076f510* g_ptr_0076f510;
extern int g_arg_0076f510;
extern int g_tail_0076f510;
void call3_0076f510(void*, Obj8_0076f510*, Obj8_0076f510*);
extern "C" void tail_fn_0076f510(void*);
void func_0076f510()
{
	Obj8_0076f510* p = new Obj8_0076f510;
	g_ptr_0076f510 = p;
	g_reg_0076f510.add(p);
	call3_0076f510(&g_arg_0076f510, p, p);
	tail_fn_0076f510(&g_tail_0076f510);
}
