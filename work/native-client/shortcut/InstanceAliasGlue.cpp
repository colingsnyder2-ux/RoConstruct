// Shortcut glue (owner-authorized): the engine-ABI Instance members are emitted with the access-specific mangling of the 2007 headers
// (protected ctors IAE, protected virtual dtor MAE) while 2008 callers reference the public/UAE names (analog code, factory products).
// Same object, different decoration: alias the callers' names to the engine definitions.
#pragma comment(linker, "/alternatename:??0Instance@RBX@@QAE@XZ=??0Instance@RBX@@IAE@XZ")
#pragma comment(linker, "/alternatename:??0Instance@RBX@@QAE@PBD@Z=??0Instance@RBX@@IAE@PBD@Z")
#pragma comment(linker, "/alternatename:??1Instance@RBX@@UAE@XZ=??1Instance@RBX@@MAE@XZ")
