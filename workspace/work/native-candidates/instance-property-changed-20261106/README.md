# Inactive Instance property notification provider

Original mapping: `Instance::raisePropertyChanged` 0040db00, notifier dispatch
0040a530, listener exception handler 0040a1c0. Source preserves the existing real
Instance/Property/PropertyChanged classes; Property and PropertyChanged are each
eight bytes. Instance receives only the already recovered static Changed signal
declaration, adding no instance field. Scoped headers retain the complete canonical
headers and inline their real two-pointer property/event copies.

The old 200-byte listener handler inlined string access. This profile uses the
existing imported `c_str` header and a const exception catch; the resulting 197-byte
handler matches original code/data, and its 13-node EH graph passes. The 160-byte
notification method and 143-byte dispatcher remain byte/data matches in that same
object. The changed source was compiled once after each changed input; saved objects
were reused for subsequent graph checks.

This is an inactive proposal, not selected by the current client build. Do not link
it together with the older NativeInstancePropertyChangedWorker provider. Shared
header reconciliation, indirect callback/signal ABI, descriptor initialization,
StandardOut ownership/ABI, final selection and P5/P6/runtime gates remain required.
RunService's wider graph now resolves the real Name storage, notification helpers,
StandardOut lifetime and Boost mutex imports, but stops at thread_resource_error's
constructor (00568430). No runtime or server credit.

Source provenance: existing canonical tests/NativeInstancePropertyChangedWorker.cpp,
canonical property/Instance headers, and the existing runservice-events and
std-noinline-string profiles. All profiles are scoped; shared headers are untouched.
