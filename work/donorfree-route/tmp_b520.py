ADDR="0054b520"
p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_%s.cpp"%ADDR
s=open(p).read()
# flags already /GS /EHs; ensure
s=s.replace("// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS",
            "// native-flags: /O2 /Ob2 /Oy /GF /GS /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS")
# struct TreeIter stays; add Local struct before TreeObj? Insert after TreeIter struct.
# Add Local struct with method before "struct TreeObj;"
s=s.replace("struct TreeObj;","struct Local_%s {\n    TreeIter* erase(TreeIter* ret, int whereCont, void* wherePtr);\n};\nstruct TreeObj;"%ADDR)
# function def replace
old_def="extern \"C\" TreeIter* __fastcall fn_%s(TreeObj* self, int unusedEdx, TreeIter* ret, int whereCont, void* wherePtr)"%ADDR
new_def="TreeIter* Local_%s::erase(TreeIter* ret, int whereCont, void* wherePtr)"%ADDR
s=s.replace(old_def,new_def)
# insert self assignment: after opening brace of function. Find the def line then next {
idx=s.index(new_def)
# find first "{" after idx
brace=s.index("{",idx)
s=s[:brace+1]+"\n    TreeObj* self = (TreeObj*)this;"+s[brace+1:]
# Now cast all fn_XXXX(self, 0, ...) calls to __thiscall dropping the 0.
import re
# generic: fn_HEX(self, 0, args...) -> cast. Need per-helper return type and stack arg count.
# We'll handle known helpers:
helpers = {
 "fn_0054cd10": ("int",2),   # (self,node) -> 1 stack arg? actually node is 1 stack arg
}
# Simpler: regex transform for any "fn_XXXXXXXX(self, 0" pattern.
# Pattern: (fn_[0-9a-f]{8})\(self, 0(, [^)]*(?:\)[^)]*)*)?\)
# We'll do iterative regex for calls with nested parens up to 2 levels.
def transform_call(s):
    # handle fn_XXXXXXXX(self, 0) -> fn_XXXXXXXX(self)  (0-stack helpers already 1-arg; but these have dummy, make 1-arg call)
    # Actually for helpers declared with dummy, call (self,0) sets edx=0. To avoid, if helper is 0-extra-stack (only self), convert to (self) only if declared 1-arg. But declared 2-arg. Can't drop without changing decl. Instead cast to __thiscall (self).
    # We'll cast any (self, 0) and (self, 0, ...) to __thiscall.
    import re
    # First handle two-arg tail: fn(self, 0, A, B, ...) complex. Use regex capturing the whole call up to matching close.
    # We'll repeatedly apply regex for fn_XXXX(self, 0 ...) 
    pattern = re.compile(r"(fn_[0-9a-f]{8})\(self, 0(\)|, .*)")
    # This won't handle nested. Let's do line-based replacements instead for known call lines.
    return s
# Instead, do targeted replacements for each helper name found in file with unusedEdx.
# Find helper decls with unusedEdx
for line in s.splitlines():
    m=__import__('re').match(r"\s*(\S+(?:\s+\S+)*)\s+__fastcall\s+(fn_[0-9a-f]{8})\([^)]*unusedEdx[^)]*\)", line)
# We'll parse decls manually:
import re
decl_re = re.compile(r"(\S+(?:\s*\*)?)\s+__fastcall\s+(fn_[0-9a-f]{8})\(([^)]*)\)")
# collect helpers with unusedEdx
helper_info={}
for m in decl_re.finditer(s):
    ret=m.group(1).strip()
    name=m.group(2)
    params=m.group(3)
    if "unusedEdx" in params:
        # count stack args: params after self,unusedEdx
        parts=[x.strip() for x in params.split(",")]
        # self and unusedEdx are first two
        stack_args=parts[2:]
        helper_info[name]=(ret, stack_args)
print("helpers with dummy:", helper_info)
# Now replace calls. For each helper, replace fn_NAME(self, 0, ...) and fn_NAME(self, 0)
for name,(ret,stack_args) in helper_info.items():
    # build cast type: ret(__thiscall*)(void* self, <stack arg types>)
    # map param type strings to types (strip names). Use the declared types.
    # stack arg type: remove trailing name. Heuristic: if param contains space, take all but last token; else the token.
    def type_of(p):
        toks=p.split()
        if len(toks)<=1: return p
        # if last token is identifier (no *), drop it
        if '*' not in toks[-1] and not toks[-1].endswith('*'):
            return ' '.join(toks[:-1])
        return p
    stack_types=[type_of(x) for x in stack_args]
    arglist=", ".join(["void*"]+stack_types)  # self is void*
    # Actually self type void*; keep
    cast="((%s(__thiscall*)(void*%s))%s)"%(ret, (", "+", ".join(stack_types)) if stack_types else "", name)
    # replace calls: name(self, 0) and name(self, 0, A, B, ...)
    # Simple cases first
    s=s.replace("%s(self, 0)"%name, "%s(self)"%cast.replace(name,"")+name if False else "%s(self)"%(cast))
    # The above is messy. Do cleaner:
# Redo cleanly:
s=open(p).read()
# re-apply flags/struct/def/self-insert already? We overwrote s from file, losing changes. Need re-apply. Instead, work on current file state (already modified partially? The previous script wrote? No, we did s=open; modified; but didn't write because we replaced s=open at end). 
# Let's just abort and do incremental.
print("abort")
PY