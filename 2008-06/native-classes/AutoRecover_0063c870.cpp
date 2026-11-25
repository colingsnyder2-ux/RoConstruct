// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct Local_0063c870 { int a, b, c, d, e; };
struct Local_0063c870_arg { int pad[4]; };
// INFERRED: bind_t built from pmf (3 dwords), empty placeholder, object ptr
extern "C" Local_0063c870* fn_0063c870(Local_0063c870* out, int a, int b, int c, int d)
{
    Local_0063c870_arg tmp;
    out->a = a;
    out->b = b;
    out->c = c;
    out->d = tmp.pad[3];
    out->e = d;
    return out;
}
