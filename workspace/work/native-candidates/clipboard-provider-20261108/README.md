# Clipboard and Workspace selection provider diagnostic

Inactive evidence against 7905bf0f464a075916f3ae5584d8936d0f1b77f1. Two fresh canonical sources produced four original relocation-masked code/data matches. The prior ClipboardActions object introduced an unresolved collectSelection dependency; the Workspace selection provider supplies it. Fail-closed analysis remains incomplete because reviewed direct-call bindings were not supplied; indirect calls, ABI, exception behavior, final selection, runtime and server credit remain unproven.

Adding both objects to the prior non-forced isolated link reduced unresolved symbols from 104 to 102 with zero introduced symbols and duplicate definitions. The link still fails. No executable was run. The shell retains P6 glue; the FileSystem ownership change exists only in the diagnostic archive. Objects remain local; hashes and inputs are recorded.
