# Native class source

This directory is reconstructed production source.  Each `.cpp` must contain
only bodies that independently compile to the original 2008-06 client bytes.
Keep source grouped by original owning class or cohesive template family.

Promotion path:

1. Experiment in `../tests/Native*Trial.cpp`.
2. Prove target bytes, relocations, constructor and destructor layout where
   applicable.
3. Move the minimal exact body into one owner here.
4. Add it to a selected native build only after provider ABI is proven.

Never place scaffolding, guessed fields, donor implementation, hard-coded
addresses, or test `main` code here.  An exact body is not automatically safe
to select into a running client; selection remains owned by the build manifest.

Useful commands:

```powershell
.\roc.cmd native-asm 2008-06 0044fe00 --obj out\native-layouts\Check.obj --sym ?copyDocument@
python ..\tests\check_native_class.py C:\path\to\source.cpp range=0044f200-00455d40
```
