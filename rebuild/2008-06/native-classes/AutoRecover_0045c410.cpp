// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: 0x009329e0 is the type_info object of the stored functor type
// (boost::function-style functor manager for a trivially copyable 8-byte functor).
extern "C" const std::type_info g_typeinfo_009329e0;

// INFERRED: arguments are (in, out, op) with op: 0 = clone, 1 = move/no-op,
// 2 = check type (in holds a type_info*), 3 = get type.
extern "C" void fn_0045c410(void** in, void** out, int op)
{
    if (op == 3)
    {
        *(const std::type_info**)out = &g_typeinfo_009329e0;
        return;
    }
    if (op == 0)
    {
        if (out)
        {
            out[0] = in[0];
            out[1] = in[1];
        }
        return;
    }
    if (op == 1)
        return;

    const std::type_info* t = (const std::type_info*)in[0];
    if (*t == g_typeinfo_009329e0)
        in[0] = out;
    else
        in[0] = 0;
}
