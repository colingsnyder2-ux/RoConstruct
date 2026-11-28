import re, sys
ADDR=sys.argv[1]
p="C:/Users/colin/RoConstruct/rebuild/2008-06/native-classes/AutoRecover_%s.cpp"%ADDR
s=open(p).read()
# flags
s=s.replace("// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS",
            "// native-flags: /O2 /Ob2 /Oy /GF /GS /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS")
# struct
s=s.replace("struct TreeObj;","struct Local_%s {\n    TreeIter* erase(TreeIter* ret, int whereCont, void* wherePtr);\n};\nstruct TreeObj;"%ADDR)
# def
old_def="extern \"C\" TreeIter* __fastcall fn_%s(TreeObj* self, int unusedEdx, TreeIter* ret, int whereCont, void* wherePtr)"%ADDR
new_def="TreeIter* Local_%s::erase(TreeIter* ret, int whereCont, void* wherePtr)"%ADDR
assert old_def in s
s=s.replace(old_def,new_def)
idx=s.index(new_def)
brace=s.index("{",idx)
s=s[:brace+1]+"\n    TreeObj* self = (TreeObj*)this;"+s[brace+1:]  # placeholder; will replace self->this
# Wait: keep self local? For frame, better remove. But casts reference self. Let's keep self local for correctness first, then optimize.
# Actually to match frame, better use this directly. But let's first get it compiling with self local, then refine.
# We'll keep self local (frame 0x68) but avoid xor via casts. Score may be lower but functional.
# Parse helper decls with unusedEdx
decl_re=re.compile(r"(\S+(?:\s*\*)?)\s+__fastcall\s+(fn_[0-9a-f]{8})\(([^)]*)\)")
helpers={}
for m in decl_re.finditer(s):
    ret=m.group(1).strip()
    name=m.group(2)
    params=m.group(3)
    if "unusedEdx" in params:
        parts=[x.strip() for x in params.split(",")]
        stack_args=parts[2:]
        helpers[name]=(ret,stack_args)
# function to type-of param
def type_of(p):
    toks=p.split()
    if len(toks)<=1: return p
    if '*' not in toks[-1] and not toks[-1].endswith('*'):
        return ' '.join(toks[:-1])
    return p
# Replace calls: for each helper, replace name(self, 0, A, B, ...) and name(self, 0)
for name,(ret,stack_args) in helpers.items():
    stack_types=[type_of(x) for x in stack_args]
    cast="((%s(__thiscall*)(void*%s))%s)"%(ret, (", "+", ".join(stack_types)) if stack_types else "", name)
    # replace simple (self, 0)
    s=s.replace("%s(self, 0)"%name, "%s(self)"%(cast))
    # replace (self, 0, X) single trailing arg (greedy up to closing paren at end of statement)
    # Use regex for name(self, 0, <expr>) where expr has no top-level comma ambiguity is hard.
    # We'll handle known patterns: name(self, 0, _Pnode), name(self, 0, _Fixnodeparent), name(self, 0, ret, whereCont, wherePtr)
    # Generic regex: name(self, 0, (.*)) followed by )  -- non-greedy
    import re as _re
    pat=_re.compile(_re.escape(name)+r"\(self, 0, (.+)\)")
    def repl(m):
        expr=m.group(1)
        return "%s(self, %s)"%(cast, expr)
    s=pat.sub(repl, s)
# Now replace self -> this in body (keep self local? we inserted self local; replace all self references including the local var name 'self' would break). 
# Instead keep self local and don't replace; casts already use self. self local stays (frame +4). Accept.
# But the self local is "TreeObj* self = (TreeObj*)this;" which we inserted. Good.
open(p,"w").write(s)
print("done", ADDR)
PY