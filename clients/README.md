# Clients

Do not commit Roblox executables, DLLs, or game content here. They are proprietary.

`clients.json` is the shared registry: exe name, SHA-256, and the compiler that built it. `sources.json` says where the binaries come from: a `clients.zip` bundle (URL, size, SHA-256) and, per client, Google Drive file ids as a fallback.

`roc client fetch <name>` downloads what that client needs and verifies it. Every command that works on a client (`analyze`, `next`, `claim`) fetches it first if it's missing, so you never have to place files by hand. Nothing is committed: `.gitignore` keeps `clients/*` out of the repo except these two json files and this README.

Manual copies still work. Drop them where they belong and `roc client verify` checks the hash and that the binary isn't modified (PE checksum). Work is only valid against the exact registered binary:

```text
clients/<name>/<exe from clients.json>
```

Managing sources:

```text
roc client fetch <name>|all              fetch and verify
roc client-sources <drive folder>        index a public Drive folder into the fallback
roc client-sources --bundle <zip>        point the manifest at a different clients.zip
roc client-sources --dry-run             show what a Drive index would find, write nothing
```

To start a new client: `roc client add <name> path\to\RobloxApp.exe`, then commit `clients.json` and `sources.json`.
