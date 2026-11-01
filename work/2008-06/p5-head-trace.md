# Head mesh trace

Original 004ef930 SpecialShape dispatch reads the seven-entry jump table at
004f02e0. Entry 0 is 004f011c, which calls 004ef430. The 100%-matched source
for 004ef430 is the HeadMesh single-variation cache factory in
`tools/rbxgs/Client/App/roc_espclaude_a0eb6c457c238b40.cpp`; 004f00fd / 004ee030
is entry 2, WedgeMesh. Do not trust the draft switch ordering without checking
the original jump table.

004ef430 constructs via 00500180, whose matched source is
`roc_espeon_headsurfaceminimuma98c5931c2e443a6.cpp`. That creates a level and
uses a builder initialized with 9 and min(size.x,size.z) * an original constant.
The builder constructor 004fdaf0 uses min(size.x,size.z) for both horizontal
axes. 00500180 calls 00500d30 to initialize the builder; trace its virtual
face methods and transforms, including texture coordinates, before integrating.
No head rendering or parity is claimed by this trace.
