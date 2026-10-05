"""Unit-check the mechanical repair passes in isolation (no compiler, no LLM).

Each transform exists to kill one measured MSVC error class. When a fixup run
looks flat it is usually because a transform silently became a no-op, so each
one gets a direct assertion here.
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import rebuild as R  # noqa: E402

if not os.path.exists(R.OPAQUE_HEADER):
    print("NOTE: %s missing -- run: python scripts\\re\\opaque.py build"
          % R.OPAQUE_HEADER)

fails = []


def check(name, got, want_sub):
    ok = want_sub in got
    print("  %-22s %s" % (name, "PASS" if ok else "FAIL"))
    if not ok:
        print("      want substring: %r" % want_sub)
        print("      got: %r" % got[:300])
        fails.append(name)


print("=== fix_voidp_assignments (C2440: void* -> T*)")
src = ("/* SEH_GLOBALS_MARKER */\n"
       "extern void *ExceptionList;\n"
       "void f(void) {\n"
       "    uint8_t local_10;\n"
       "    local_10 = ExceptionList;\n"
       "    ExceptionList = &local_10;\n"
       "}\n")
out = R.fix_voidp_assignments(src)
# whitespace inside decltype(...) is irrelevant to the compiler
flat = " ".join(out.split())
check("read into typed dest", flat,
      "local_10 = decltype( local_10)(ExceptionList);")
check("write from typed src", out, "ExceptionList = &local_10;")

print("=== declare_namespaces (C2653) -- covered in detail below")

print("=== add_base_types (C4430 / C2065)")
src = "void f(void){ byte b = 1; dword d = 2; undefined4 u = 3; }"
out = R.add_base_types(src)
check("byte typedef", out, "typedef unsigned char  byte;")
check("dword typedef", out, "typedef unsigned int   dword;")
check("undefined4 typedef", out, "typedef unsigned int   undefined4;")

print("=== fix_thiscall (C3865)")
src = "void __thiscall Foo(int *this_, int a) { this_ += 4; }"
out = R.fix_thiscall(src)
if "__thiscall" in out:
    print("  %-22s FAIL" % "convention stripped")
    fails.append("thiscall still present")
else:
    print("  %-22s PASS" % "convention stripped")
check("body preserved", out, "this_ += 4;")

print("=== strip_win32_decls (C2377 CRITICAL_SECTION)")
src = ("/* WINDOWS_H_MARKER */\n#include <windows.h>\n"
       "typedef struct { long x; } CRITICAL_SECTION;\n"
       "void f(void){ CRITICAL_SECTION cs; }\n")
out = R.strip_win32_decls(src)
if "typedef struct { long x; } CRITICAL_SECTION;" in out:
    print("  %-22s FAIL" % "model CRITICAL_SECTION stripped")
    fails.append("win32 CRITICAL_SECTION")
else:
    print("  %-22s PASS" % "model CRITICAL_SECTION")

print("=== add_opaque_universe (C2440 class pointers)")
src = "void f(void){ StringInterface *p; *(uint32_t*)p = 1; }"
out = R.add_opaque_universe(src)
check("StringInterface aliased", out, "typedef void StringInterface;")

print("=== add_seh_globals")
src = "void f(void){ ExceptionList = 0; }"
out = R.add_seh_globals(src)
check("ExceptionList void*", out, "extern void *ExceptionList;")

print("=== fix_missing_semis (C2146) -- ladder-gated, never in prepare()")
src = ("void f(void) {\n"
       "    int a = 1 int b = 2;\n"
       "}\n")
out = R.fix_missing_semis(src)
check("merged statement split", out, "int a = 1;")

# the regression that dropped us from 30% to 0%: this pass must NOT touch
# declarations, or `typedef unsigned char byte;` becomes `... char; byte;`
src2 = "typedef unsigned char byte;\ntypedef unsigned int dword;\n"
out2 = R.fix_missing_semis(src2)
check("typedef untouched", out2, "typedef unsigned char byte;")
if "unsigned char; byte" in out2:
    print("      typedef was mangled")
    fails.append("fix_missing_semis mangles typedefs")

# and it must not run from prepare() at all
prepared = R.prepare("void f(void){ int a = 1 int b = 2; }")
if "int a = 1 int b" in prepared:
    print("  %-22s PASS" % "not applied in prepare")
else:
    print("  %-22s FAIL" % "not applied in prepare")
    fails.append("fix_missing_semis runs in prepare")

print("=== declare_namespaces: qualified members (C2653 / C2039 / C2869)")
src = "void f(void){ RBX::MouseCommand *m; Ogre::Root *r; }"
out = R.declare_namespaces(src)
check("RBX opened", out, "namespace RBX {")
check("member aliased", out, "typedef void MouseCommand;")
check("Ogre opened", out, "namespace Ogre {")
# a namespace the model already opens must NOT be redeclared
src2 = "namespace RBX {\n  typedef void Thing;\n}\nvoid f(){ RBX::Thing *t; }"
out2 = R.declare_namespaces(src2)
if out2.count("namespace RBX") == 1:
    print("  %-22s PASS" % "no duplicate namespace")
else:
    print("  %-22s FAIL" % "no duplicate namespace")
    fails.append("declare_namespaces duplicates")

print("=== alias_unknown_types (C4430 / C2182)")
# StringInterface is in the generated universe -> must NOT be re-aliased
src = ("extern ThrowInfo s_DAT_1037a970;\n"
       "extern StringInterface *already_ok;\n"
       "void f(ThrowInfo *t){ (void)t; }\n")
out = R.alias_unknown_types(src)
check("ThrowInfo aliased", out, "typedef void ThrowInfo;")
flat = " ".join(out.split())
check("void object became pointer", flat,
      "extern void *s_DAT_1037a970;")
check("universe type untouched", out, "extern StringInterface *already_ok;")
# regression: must not alias a fragment of a DAT_ variable name
if "typedef void T_1037;" in out:
    print("      mangled a DAT_ name into a type")
    fails.append("alias_unknown_types greedy")

print("=== fix_trailing_struct_semi (C1004)")
src = "struct Foo {\n    uint32_t a;\n}\n\nvoid f(void){}\n"
out = R.fix_trailing_struct_semi(src)
check("semicolon added", out, "uint32_t a;\n};")
src2 = "struct Bar {\n    uint32_t a;\n};\n"
check("already-terminated kept",
      R.fix_trailing_struct_semi(src2), "};")

print("=== unqualify_externs (C2039 on qualified file-scope decls)")
src = ("extern RBX_RTTI_Type_Descriptor RBX::Instance::RTTI_Type_Descriptor;\n"
       "extern void *RBX::ContentId::RTTI_Type_Descriptor;\n")
out = R.unqualify_externs(src)
if "::" in out:
    print("  %-22s FAIL" % "qualified decl removed")
    print("      got: %r" % out[:200])
    fails.append("unqualify_externs")
else:
    print("  %-22s PASS" % "qualified decl removed")
check("unqualified decl survives", R.unqualify_externs(
    "extern void plain_symbol;\n"), "extern void plain_symbol;")

print("=== strip_asm (C2400)")
src = "void f(void){ __asm { mov ecx, 0xffffffff } int x = 1; }"
out = R.strip_asm(src)
if "__asm" in out:
    print("  %-22s FAIL" % "asm removed")
    fails.append("strip_asm")
else:
    print("  %-22s PASS" % "asm removed")
check("body kept", out, "int x = 1;")

print("=== namespace vs struct collision (C2869)")
src = "typedef struct RBX {\n  struct RBX *Instance;\n} RBX;\nvoid f(){ RBX::Instance *i; }"
out = R.declare_namespaces(src)
if "namespace RBX" in out:
    print("  %-22s FAIL" % "no namespace when RBX is a struct")
    fails.append("namespace/struct collision")
else:
    print("  %-22s PASS" % "no namespace when RBX is a struct")

print()
print("FAILURES: %d %s" % (len(fails), fails if fails else ""))
sys.exit(1 if fails else 0)
