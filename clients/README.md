# Clients

Do not commit Roblox executables, DLLs, or game content here. They are proprietary.

`clients.json` is the shared registry: exe name, SHA-256, and the compiler that built it. `sources.json` says where the binaries come from.

## Clients download themselves

You do not have to supply any files. Every command that touches a client fetches it first if it isn't already on disk and verified — `analyze`, `next`, `claim`, one-click links, and the worker all do this. Click **Start helping** on a client you don't have and it downloads itself before starting.

Google Drive is the source, so you only pull the one client you asked for rather than a 75 MB archive of every build. A month folder on Drive holds several different builds, so RoConstruct downloads the exe, hashes it against `clients.json`, and fetches the rest of that build only once it matches. A `clients.zip` bundle is the fallback when Drive is unreachable. Either way nothing is used until its SHA-256 matches the registry, so a truncated or wrong build is rejected rather than decompiled.

To fetch without waiting for a command to want it:

```text
roc client-fetch <name>|all              fetch and verify now
```

Nothing is committed. `.gitignore` keeps `clients/*` out of the repo except `clients.json`, `sources.json`, and this README.

## Supplying your own copy

Also fine. Drop it in place and `roc client verify` checks the hash and that the binary isn't modified (PE checksum). Work is only valid against the exact registered binary:

```text
clients/<name>/<exe from clients.json>
```

## Managing sources

```text
roc client-sources <drive folder>        index a public Drive folder
roc client-sources --bundle <zip>        point the manifest at a different clients.zip
roc client-sources --dry-run             show what a Drive index would find, write nothing
roc client remove <name>                 unregister a client
roc client remove <name> --purge         unregister and delete its local copies
```

`--purge` deletes `clients/<name>/` and `work/<name>/`, so it is re-downloaded and re-analyzed next time. To start a new client: `roc client add <name> path\to\RobloxApp.exe`, then commit `clients.json` and `sources.json`.

Known gap: `2012-06` is missing `RenderSystem_Direct3D9.dll`, which Drive does not serve anonymously. The client verifies and analyzes correctly; the file is only needed to actually run the game.
