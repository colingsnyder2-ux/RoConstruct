// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: boost::multi_index::detail::ordered_index_node_impl::increment over nodes whose
// word 0 is parent pointer | color bit, word 1 is left, word 2 is right.

extern "C" void fn_004c66c0(unsigned int*& x)
{
    if (x[2]) {
        x = (unsigned int*)x[2];
        while (x[1]) x = (unsigned int*)x[1];
    } else {
        unsigned int* y = (unsigned int*)(x[0] & ~1u);
        while (x == (unsigned int*)y[2]) {
            x = y;
            y = (unsigned int*)(y[0] & ~1u);
        }
        if ((unsigned int*)x[2] != y) x = y;
    }
}
