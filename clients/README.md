# Clients

Do not commit Roblox executables, DLLs, or game content here. They are proprietary.

`clients.json` is the shared registry: exe name, SHA-256, and the compiler that built it. Each contributor supplies their own copy:

```text
clients/<name>/RobloxApp_client.exe
```

`roc client list` checks your copy's hash. Work is only valid against the exact registered binary.

To start a new client: `roc client add <name> path\to\RobloxApp_client.exe`, then commit `clients.json`.
