# Client samples

Do not commit Roblox executables, DLLs, or game content here. They are proprietary and redistribution needs permission from their owner.

RoConstruct detects locally supplied samples in these slots:

```text
clients/
  2007M/RobloxApp_client.exe
  2008M/RobloxApp_client.exe
  2010L/RobloxApp_client.exe
```

Only use files you are authorized to possess and analyze. Tracked source contains no client binaries.

The public repo also contains no 2008 database. Keep both files outside Git, then point RoConstruct at their folder with `ROCONSTRUCT_DATA_ROOT`. For 2008M, folder must contain `rbx2008m.db` and `bin\RobloxApp_client.exe`.
