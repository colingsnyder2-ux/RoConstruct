// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 8-byte element sorted by its float at offset 4 (ascending insertion sort,
// the std::sort small-range case). The first field is an opaque payload.
struct SortElem8 {
    int payload;
    float key;
};

extern "C" void fn_0067cb30(SortElem8* first, SortElem8* last)
{
    if (first == last)
        return;
    for (SortElem8* it = first + 1; it != last; ++it) {
        SortElem8 val = *it;
        if (val.key < first->key) {
            // shift the whole prefix up by one and put val at the front
            for (SortElem8* p = it; p != first; --p)
                *p = *(p - 1);
            *first = val;
        } else {
            // unguarded linear insert
            SortElem8* hole = it;
            while (val.key < (hole - 1)->key) {
                *hole = *(hole - 1);
                --hole;
            }
            *hole = val;
        }
    }
}
