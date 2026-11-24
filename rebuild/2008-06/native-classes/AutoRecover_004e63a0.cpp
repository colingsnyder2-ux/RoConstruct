// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: boost::function-style manager(in, out, op): op 0 = clone 16 bytes, 1 = no-op, else = get-type query.
// INFERRED: 0x941678 is the type_info of the stored functor type.
extern "C" char fn_data_00941678[];

extern "C" void fn_004e63a0(void* in, void* out, int op)
{
    if (op == 0) {
        if (out) {
            unsigned* s = (unsigned*)in;
            unsigned* d = (unsigned*)out;
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            d[3] = s[3];
        }
    } else if (op != 1) {
        const std::type_info** slot = (const std::type_info**)out;
        const std::type_info& ti = *(const std::type_info*)fn_data_00941678;
        *slot = (**slot == ti) ? (const std::type_info*)in : (const std::type_info*)0;
    }
}
