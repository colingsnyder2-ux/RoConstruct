# Clients

Do not commit Roblox executables, DLLs, or game content here. They are proprietary.

`clients.json` is the shared registry: exe name, SHA-256, and the compiler that built it. Each contributor supplies their own copy:

```text
clients/<name>/<exe from clients.json>
```

`roc client verify` checks your copy's hash and that it isn't modified (PE checksum). Work is only valid against the exact registered binary.

To start a new client: `roc client add <name> path\to\RobloxApp.exe`, then commit `clients.json`.
