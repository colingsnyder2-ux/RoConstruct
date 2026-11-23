// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target is a free cdecl function that takes two checked vector
// iterators and a third value by value, and returns an iterator by value
// (hidden return pointer at [ebp+8]). It looks like an STL algorithm wrapper
// of the form "first = _Checked_assign_from_base(first, f(_Checked_base(first),
// _Checked_base(last), val))".
// The mangled callee names are truncated in the disassembly, so they use the
// fn_<address> convention.
// The disassembly's "add esp, 4" after each _Checked_base call suggests a
// calling convention this declaration does not reproduce exactly.

struct VecIter {
    int proxy;
    int ptr;
};

extern "C" int fn_005534c0(VecIter* it, int extra);
extern "C" int fn_005468c0(VecIter* dst, int* src);
extern "C" int fn_00546880(int a1);

extern "C" VecIter fn_00545d40(VecIter first, VecIter last, int val)
{
    int base = fn_005534c0(&last, val);
    int base2 = fn_005534c0(&first, base);
    int res = fn_00546880(base2);
    fn_005468c0(&first, &res);

    VecIter out;
    out.proxy = first.proxy;
    out.ptr = first.ptr;
    return out;
}
