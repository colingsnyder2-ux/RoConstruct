# Hosting and maintenance

## Group server

`roc host` runs the server with a public tunnel and hourly publishing, and restarts it 30
seconds after any exit. To restart (after recipe, matcher or function-table changes),
stop only its python child; never start a second server on port 8765.
`roc server --startup` starts `roc host` at login. Back up `work/server.db`.

Public address: install [Tailscale](https://tailscale.com), run
`tailscale funnel --bg 8765`, then `roc config --public-server https://PC.TAILNET.ts.net`.
Without one, `--tunnel` uses a temporary Cloudflare address; the site and workers follow it.

The server re-verifies every submission with the real compiler and exe, so scores cannot be
faked. It also stores shared agent memory (`/v1/agent-memory`): sanitized attempts from every
PC, marked `server_confirmed` only when a source hash matches a verified score event.

## Publishing

Each hourly check (with `--publish`):

1. commits only website data (`docs/data`, `progress.json`, `history.json`,
   `source-links.json`) to this repo, never other staged files;
2. exports all stored sources and portable evidence to
   [RoConstruct-findings](https://github.com/colingsnyder2-ux/RoConstruct-findings):
   `src/`, `agent-memory/` (lessons, shared attempts, context), `reports/` (historical
   research reports), and that repo's README and workflow. It reads them from the local
   checkout at `local/findings/`. A findings push rebuilds its release ZIPs.

Unchanged output makes no commit. A lock (`work/publish.lock`, byte-range locked, never
deleted) prevents concurrent publishes.

## Rebuild progress

`roc rebuild CLIENT progress` summarizes `rebuild/<client>/out/*/report.json` and
`closure.json` into `docs/rebuild-progress.json`. The site shows this under each
client as simple progress bars: modules reporting, modules linked, byte-exact
functions, unresolved symbols, temporary stubs and runtime milestones.

`--no-notify` disables the Discord webhook for that run. Otherwise the webhook is
sent only when the summary changes, with a 5-minute minimum interval and a
10-message hourly cap. Webhook failures never block progress generation.

## Discord and daily stats

`--discord-webhook URL` (or `ROCONSTRUCT_DISCORD_WEBHOOK`) logs mined functions.
Digests split each batch into one message per client, with a six-hour mining rate.
Player Mining receives contributor matching, automatic matching and native integration digests.
The Models field shows the submitted AI model; deterministic tools retain their honest `roc ...`
labels. Each mining digest shows contributor totals and verified score-gain points. Integration
digests show combined points and native integrated counts. Each unique native credit adds one
leaderboard point; already-mined code gets no duplicate mining score event. `ROCONSTRUCT_PLAYER_MINES_WEBHOOK` / `player_mines_webhook` can name
the shared destination explicitly; the existing Discord webhook setting remains supported.
The old server-mines webhook is no longer a mining notification destination.
The daily Discord leaderboard is removed. Local daily audit reports remain.
Credit needs server verification, an improvement from below 100 to
100, and a unique client/address per day; 2009-12 is excluded. Commands report under
the automatic-tool audit group by their `model` field; this does not select a separate webhook. Reports (JSON + CSV) are saved under
`reports/daily/` beside the database; `roc daily-stats [--date D] [--db work/server.db]`
prints one.

## Private cluster and CPU sharing

Optional and permissioned: one trusted coordinator, or three for automatic failover.

```text
roc cluster setup --nodes 127.0.0.1 --db OFFLINE-BACKUP.db     one PC (port 8766)
roc cluster start --config work/cluster/node-1/node.json
roc cluster setup --nodes A,B,C --db work/backups/server.db    three coordinators
roc cluster invite|revoke --config ... --name helper2          CPU contributor credentials
roc cpu-worker --config cpu-worker.json --enable|--disable     contributor switch (off by default)
roc cluster enqueue|status|validate --config ...               CPU jobs
roc tasks [pause|resume|stop --id ID]                          local command controls
```

Never pass a live database as `--db`. Keep `node.json` and `nats.conf` private; ports
8766/4222/6222 are for private networks only (no transport TLS yet). Contributors can only
compile assigned jobs; coordinators recompile every reported improvement. One of three
voting hosts may fail. The existing live server stays authoritative until an operator
migrates to the cluster. Tests: `tests/test_cluster.py`; real brokers with
`ROC_CLUSTER_LIVE=1` and `ROC_NATS_SERVER` set, `tests/test_cluster_live.py`.

## Clients

`roc client add NAME PATH\RobloxApp.exe` records hash, build date and compiler, then
analyzes it; commit `clients/clients.json` and `clients/sources.json` and restart the server.
`roc client-sources FOLDER` indexes a public Drive folder; `roc client remove NAME --purge`
unregisters and deletes local copies. Known gap: 2012-06 lacks `RenderSystem_Direct3D9.dll`
on Drive (only needed to run the game).

## Packages

`py -3.12 packaging/build.py [worker|local-ai|server]` builds zips into `local/packages/`.
Worker: the cloud worker, compilers and essential agent docs. Local AI: the same plus
Ollama/Docker extras on request. Server: adds the maintainer modules (`server`, `cluster`,
`reports`, `progress`). Each build stages the package and
imports every module before zipping; a helper module missing from `WORKER_MODULES` fails
the build. Maintainer commands typed in a worker install say so instead of crashing.

## After 100%

Native promotion claims, batch uploads, independent rebuild verification and
separate credit are documented in [INTEGRATION.md](INTEGRATION.md). Use
`roc integrate --count 4`; several classes can share one verification job.

Match data sections, relink a byte-identical exe, name types and functions, swap
third-party code for real source (Ogre, G3D, Lua, RakNet, Boost; open replacements for
MFC, Codejock, FMOD), then port (WebAssembly, Linux, macOS).
