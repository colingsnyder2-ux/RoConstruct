# 2008 native integration findings

`accepted-integrations.json` preserves the server's accepted overlay history. `native-credit.json` records server-awarded native credit.

`integration-jobs.json` includes pending and rejected proposals; those are not accepted integrations. `working-tree/` contains reproducible build tooling, specs, glue and overlays as currently on disk; unsubmitted edits may be present. Acceptance comes only from the server ledger. `inventory.json` records source counts and file hashes.

Recovered exact and partial functions live at `/src/<client>/`. The complete native rebuild is published at `/2008-06/`, including source and build artifacts. Private configuration and credentials remain excluded.
