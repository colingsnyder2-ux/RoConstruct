# FileSystem provider ownership diagnostic

Inactive evidence against ea3315adce77d0282fa9459620cba22c252ba4d9. The diagnostic link initially had two definitions of FileSystem::getCacheDirectory: the native FileSystem object and glue_content_provider.obj in RbxgsApp linked.lib. In a private archive copy, the glue member was removed; a rebuilt glue object omitted only that function and retained getContent. The native FileSystem source then supplied the cache function. The original archive and sources remain preserved.

All 313 retained functions matched the original archive member in code, named relocations and referenced data. Non-COMDAT data and normalized SEH symbol identities also matched. Compile include hashes were captured after compilation and then guarded; this does not independently prove unchanged inputs during compilation.

Three fresh native objects matched original code/data for Workspace load, InsertObject action, and FileSystem user-app-data access; a separate saved-object analysis also matched FileSystem cache-directory code/data. Original direct/indirect call identity, ABI, exception behavior, final executable selection and runtime remain unproven. Fail-closed proof is incomplete.

The isolated, non-forced link improved unresolved symbols from 107 to 104, introduced none, and eliminated the duplicate. It still fails; no executable was run. The shell retains P6 glue. No class-swap or server-credit claim is made.
