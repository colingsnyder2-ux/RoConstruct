# Inactive StandardOut lifetime provider

Original mapping: singleton 00569620 (173 bytes), destructor 00569590 (144 bytes),
scalar deleting destructor 005696d0 (30 bytes). All three match original code/data
in the same object. sizeof(StandardOut) remains 0x30, checked during compilation.
The complete original SDK header is retained in a scoped profile; removing only
its redundant explicit destructor declaration lets the compiler emit the real
implicit virtual destructor without the donor object's extra vptr store.

This alternate lifetime source is inactive and must not coexist with another
definition of these methods. It does not replace or select the current App archive.
The wider RunService EH audit uses its lifetime object, genuine existing App
standardout.obj for print, and Boost mutex.obj as explicit providers. It advances
to the missing boost::thread_resource_error constructor at 00568430. Full provider
ownership, all direct/indirect callee ABI and EH closure, header compatibility,
linked selection and relevant P5/P6/runtime proofs remain required. No runtime
activation or server credit is claimed. No diagnostic binary was executed.

Provenance: tools/rbxgs/Client/App/include/util/standardout.h and the real singleton
and constructor in tools/rbxgs/Client/App/util/standardout.cpp; existing imported
string profile. No fabricated fields, address patches or stubs.
