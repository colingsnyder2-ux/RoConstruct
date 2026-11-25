// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: boost::multi_index::detail::ordered_index_node_impl::decrement over nodes whose
// word 0 is parent pointer | color bit (0=red, 1=black), word 1 is left, word 2 is right.

extern "C" void fn_004c6710(unsigned int*& x)
{
    if ((x[0] & 1u) == 0 && (unsigned int*)(((unsigned int*)(x[0] & ~1u))[0] & ~1u) == x) {
        x = (unsigned int*)x[2];
    } else if (x[1]) {
        unsigned int* y = (unsigned int*)x[1];
        while (y[2]) y = (unsigned int*)y[2];
        x = y;
    } else {
        unsigned int* y = (unsigned int*)(x[0] & ~1u);
        while (x == (unsigned int*)y[1]) {
            x = y;
            y = (unsigned int*)(y[0] & ~1u);
        }
        x = y;
    }
}
