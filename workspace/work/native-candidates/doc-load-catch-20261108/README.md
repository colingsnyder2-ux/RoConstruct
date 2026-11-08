# Document string-load provider diagnostic

Inactive evidence against cac7d50d19761c3a015d490c4e6d6c3837795f66. The indexed function is 385 bytes, while its object includes the adjacent catch continuation for 459 bytes. Comparison against the original PE across all 459 bytes passed relocation-masked code and referenced data checks; 10 reviewed binding groups and three imports matched. This explains the shorter-index comparison, but does not prove complete call identity, EH metadata, callee ABI or runtime.

Adding the same saved object to the prior non-forced isolated link reduced unresolved symbols from 102 to 101 without introducing new symbols or duplicates. The link still fails; no executable was run. The shell retains P6 glue and the FileSystem ownership fix is diagnostic-only. No class-swap or server-credit claim is made.
