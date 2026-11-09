// from server: 100% by king_originala
// from server: 98% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_unit_b6f0c9701eb28399.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Vector4.h"
#include "G3D/Array.h"
#include "G3D/Table.h"

extern "C" __declspec(noinline) void roc_g3d_table_vector4_array_int_set(
    G3D::Table<G3D::Vector4, G3D::Array<int> >& table,
    const G3D::Vector4& key,
    const G3D::Array<int>& value) {
    table.set(key, value);
}
