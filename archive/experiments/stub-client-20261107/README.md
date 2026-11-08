# Inactive stub-client experiment

Preserved from untracked local files on 2026-11-07. Original paths:

- `rebuild/2008-06/p6/NativeClientStub.cpp`
- `rebuild/2008-06/p6/build_native_client.py`

This archive is outside the canonical workspace and public native provider trees.
Nothing here is a verified provider, approved build profile or runtime result.
The builder generates an empty CRobloxDoc::initializeCommands and adds dummy
Workspace load/cleanup, document handlers and subsystem results. The inspected
build log ended with 113 unresolved externals; its playable-client comment was
not supported by that log. Original scripts were not run.

Tracked Python/CMD/BAT/JSON/Markdown caller search found the stub referenced by
the experimental builder only. The normal build_client profile has not been
replaced with this builder. Existing diagnostic binaries have not been fully
traced or authorized for execution.

On 2026-11-07 the local originals were moved into the inactive candidate
`work/native-candidates/stub-client-quarantine-20261107/` after acquiring file
leases, checking for active processes and maintained callers, and verifying
that both files matched the archived copies byte for byte. The local
`quarantine.json` records original paths and hashes. The archived copies above
remain the durable, tracked evidence. This does not establish runtime safety.
