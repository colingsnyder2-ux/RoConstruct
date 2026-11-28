// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x0042c2b0 (CLuaHtmlView binder trampoline: the first argument is a struct whose first member is
// a function pointer; the call is forwarded unchanged and tail-jumps through the member); callee signature unknown.
struct BinderCall
{
    int (__cdecl *target)();
};
extern "C" int __cdecl fn_0042c2b0(BinderCall* call)
{
    return call->target();
}
