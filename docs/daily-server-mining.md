# Daily Server Mining

The GUI's **Server Mining** page ranks people by new server-verified exact functions,
shows each person's models, and lists totals by model, mining command, and client.
Choose a date or refresh to fetch the group server's current tally.

`roc daily-stats --date 2026-10-11 --server http://127.0.0.1:8765` prints the same report.
Use `--db work/server.db` for local database access or `--output PATH` to choose the
report directory. With no date, it uses today in `America/New_York`.

The server saves JSON and CSV under `reports/daily/` beside its database every minute.
After midnight Eastern time it finalizes the prior day. On startup it fills missing
reports for days present in the new ledger, including days missed during downtime.
CSV contains the credited functions; JSON includes rankings and those raw rows.

Set the leaderboard webhook in the user-local secrets store under
`ROCONSTRUCT_LEADERBOARD_WEBHOOK` (or use the environment variable). The server posts
the prior day's rankings after midnight Eastern time, including models used and
Server Mining command totals. A `.discord-sent` file prevents repeat sends across
restarts. Failed sends retry on the next reporting cycle. A crash between delivery
and saving the marker can cause a duplicate message. Webhook URLs never enter Git.

Credit requires server verification, an improvement from below 100 to 100, and a
unique client/address for that day. Repeated submissions cannot add credit. Partial
improvements and unverifiable submissions stay in the ledger but do not count as
exact gains. Client 2009-12 is excluded. Commands identify themselves via the
submission's `model` field, for example `roc propagation`; these appear under
**Server Mining**. Model names are recorded as submitted.

Old database events lack model and verification evidence. Reports show these as
historical unattributed exact events, excluded from verified totals. They cannot be
reconstructed reliably from the existing event table. Cost/request counts are not
reported because submissions do not carry reliable provider billing data.

Updated server and dashboard processes must be restarted to enable the new endpoints
and gain ledger. Existing mining jobs can continue until a convenient restart.
Install/update via `roc install` to include the `tzdata` dependency on Windows.
