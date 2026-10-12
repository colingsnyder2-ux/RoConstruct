# Private distributed server

Implemented: standalone trusted server, optional three-node quorum log, HTTP worker
failover, shared CPU jobs, default-off CPU contribution, automatic trusted
recompilation, monotonic scores, durable retry receipts, and SQLite replay.

This is a permissioned cluster. Colin is the initial trusted operator; a second
person gets only a worker credential unless Colin separately approves that person
as a coordinator. Contributor count does not change voting membership.

## One PC, or two people sharing CPU

From the repo, with Python 3.12 installed:

```powershell
py -3.12 roc.py cluster setup --nodes 127.0.0.1 --db <offline-backup.db>
py -3.12 roc.py cluster start --config work/cluster/node-1/node.json
```

Setup installs only the cluster dependency, downloads the pinned NATS broker,
checks its release SHA-256, and generates private config plus start launchers.
Default port is 8766; the existing server on 8765 is untouched. Setup imports an
**offline SQLite backup** once. For a fresh project without a server DB, omit `--db`
to seed locally analyzed allowed clients. An existing server requires `--db` to
preserve its scores; setup refuses to snapshot a busy live DB. Never
pass a live database file as `--db`. Restart resumes an interrupted import from the
same backup; changing that backup is refused. Donor client 2009-12 is filtered out.

For another PC, use your private LAN/VPN address instead of 127.0.0.1 in setup.
Give each CPU contributor their own invite file, plus the normal worker
repo/install and allowed client/compiler assets. The initial `cpu-worker.json` is
for one contributor. To add another:

```powershell
py -3.12 roc.py cluster invite --config work/cluster/node-1/node.json --name helper2 --output work/helper2-cpu.json
py -3.12 roc.py cluster revoke --config work/cluster/node-1/node.json --name helper2
```

Send `helper2-cpu.json` privately; that person uses it as `--config` below. Their
credential is bound to their worker identity and permits one outstanding lease.
Revocation disables future requests and requeues that person's current lease.
CPU credentials cannot enqueue jobs, submit mining scores, read sources, or become
coordinators. Give an AI miner `ai-worker.json` separately when authorized.
Keep `node.json` and `nats.conf`
private: those hold coordinator credentials. Run the normal `roc install` and
client analysis on a fresh contributor first. Both PCs must use the same registry
and matcher revision; mismatches fail closed.

Contributor commands:

```powershell
py -3.12 roc.py cpu-worker --config work/cluster/cpu-worker.json --enable
py -3.12 roc.py cpu-worker --config work/cluster/cpu-worker.json --disable
```

Enable persists. Disable persists and stops new leases after the current bounded
job completes. CPU slots are one per process. AI workers are independent; this
switch controls additional CPU mining, while normal AI workers retain their
existing local compile/compare steps. Ctrl+C stops the process; an abandoned lease
expires and requeues. No contributor receives provider keys or coordinator tokens.

A solo trusted coordinator works with zero contributors, or any number of approved
contributors. Turning that sole coordinator off stops service until it restarts.
Another approved PC can host a standalone deployment from an offline backup, but
this is manual recovery, not automatic two-host failover.

## Three approved coordinators: automatic failover

Use three distinct private addresses, preferably on independent always-on PCs:

```powershell
py -3.12 roc.py cluster setup --nodes 100.64.1.10,100.64.1.11,100.64.1.12 --db work/backups/server.db
```

Copy only the matching `node-N` directory to each approved host's
`work/cluster/node-N`. On each host, from its own checkout:

```powershell
py -3.12 roc.py cluster start --config work/cluster/node-N/node.json
```

First node bootstraps; all nodes replay and start automatically. On a new host the
broker downloads if the original executable path is unavailable. Do not run two
copies of the same node identity. For Linux, replace `py -3.12` with `python3.12`.
Linux compiler verification still requires the project's existing Wine setup.

Private network ports: HTTP 8766, NATS clients 4222, NATS routes 6222. Permit them
only between approved hosts/contributors through the private network. This first
version uses authenticated HTTP/NATS without transport TLS: never expose these
ports to the public Internet. Public volunteer execution needs sandboxing first.

AI miners use the comma-separated URLs from `ai-worker.json` and its worker token:

```powershell
py -3.12 roc.py worker --server http://100.64.1.10:8766,http://100.64.1.11:8766,http://100.64.1.12:8766 --token <worker_token> --user NAME
```

One voting host can die; two surviving nodes continue. Two unavailable voting
hosts stop writes. A third lightweight always-on witness is needed for safe
automatic failover between two main PCs; this version uses a third full log replica
as that witness. A witness without compilers helps quorum but cannot verify source:
at least one surviving coordinator needs the exact client/compiler installation.

An already-running miner switches endpoints, retaining request IDs. Mining API
POST failover refuses non-cluster endpoints. A miner on a powered-off PC stops;
another ready miner takes its expired function lease. The provider API call itself
does not migrate. Backup AI miners need their own authorized provider key and
budget configuration. Global AI spend reservations/checkpoint continuation remain
future work; do not launch duplicate paid sessions assuming a shared budget exists.

## Send actual CPU work

Create a JSON file with `client`, `addrs`, `source`, `user`, and `model`:

```json
{
  "client": "2008-06",
  "addrs": ["00401040"],
  "source": "<a real candidate C++ source>",
  "user": "colin",
  "model": "roc propagation"
}
```

The address above is a tested fixture, not a promised new gain. Use real unresolved
targets and candidate sources. One source compiles once per batch, then compares
against up to 1000 addresses. Same manifest enqueues once. Results/source/failures
and trusted verdicts remain in `cpu_jobs`; raw reported scores never enter progress.
Each contributor also writes `<config-name>.attempts.jsonl` beside its config,
including candidate inputs and observed scores/errors before delivery. Result
delivery uses a stable receipt ID, including in solo mode.

```powershell
py -3.12 roc.py cluster enqueue --config work/cluster/node-1/node.json --job work/candidate-job.json
py -3.12 roc.py cluster status --config work/cluster/node-1/node.json
```

Enabled CPU workers pull the job. Coordinators automatically recompile reported
sources before accepting improvements. Disable that validator loop with
`"validate_queue": false` in a node's private config, then restart it. Explicit
validation remains available with `cluster validate --config ... --id JOB_ID`.
Nodes missing the correct compiler refuse verification instead of trusting scores.
Matches include the existing relocation and initialized-data checks. Exact stored
sources never regress. Only a locally improved, trusted-verified score gets credit.

This implementation has one trusted coordinator verification per accepted result;
two independent signed validators are planned. It protects against forged worker
scores, replayed requests and stale leases, not a compromised trusted coordinator
or malicious compiler input exploiting an unsandboxed compiler. Admit trusted
contributors only. It never executes recovered programs.

The old publisher/Discord scheduler is not automatically started by cluster mode.
The existing live server remains authoritative until an operator deliberately
migrates miners, publishing and reporting to this cluster. Test fixture exacts are
isolated and are **zero new campaign gains**.

## Dashboard and terminal controls

Windows hosting setup URI: `roconstruct://server`. After `roc link install`,
clicking it opens the dashboard directly on **Servers**, with a hosting guide.
It does not download dependencies, start a server, import a DB, or enable CPU
contribution. Links accept no credentials or commands. Hosting setup is separate
from `roconstruct://work?...`, which opens the AI worker flow.

The guide distinguishes a server (shared queue and trusted verification), a CPU
helper (optional compilation for an existing server), and commands on this PC.
Use **Host Server** at the top of the page to open setup. Under **Advanced
hosting options**, **Copy setup link for another PC** shares the setup entry point. A CPU helper still
needs its own private invite file; a server needs its own approved node config.

Open `roc gui`, then **Servers**. Save private node/contributor JSON configs
under `work/` (setup does this automatically). Select the coordinator. The page
shows jobs, owner, contributing PC/PID, current function, completed comparisons,
compiler/flags, trusted scores, exact/partial gains, and connection freshness.
Worker-reported progress is informational; only trusted verification adds gains.
Contributor credentials see only their own assigned jobs, without source/keys.

**Start CPU worker** explicitly enables the selected local contributor. Pause
finishes the current job and stops taking new leases; resume allows new leases.
CPU off finishes the current job and exits the contributor. CPU on permits
contribution; a stopped worker still needs Start. Admin controls apply to remote
contributors too. Queued jobs can be paused/resumed independently. These controls
do not disable required coordinator verification or AI workers' existing local
compiler steps. CPU opt-out covers optional shared CPU mining.

ROC commands started from the dashboard or a terminal also appear here, including
function/unit, flags, owner/PC and targets inspected. Pause/CPU off apply at the
next target/compiler call, after active compilation. Some analysis/library phases
have coarse checkpoints; they cannot stop midway through a compiler call.
Already-running commands from older code need a new start to emit telemetry.
Inspection counts are not gains; unknown total/percentage remains unknown.

```powershell
py -3.12 roc.py cluster status --config work/cluster/node-1/node.json --watch
py -3.12 roc.py cluster cpu-pause --config work/cluster/node-1/node.json --name cpu-1
py -3.12 roc.py cluster cpu-resume --config work/cluster/node-1/node.json --name cpu-1
py -3.12 roc.py cluster cpu-off --config work/cluster/node-1/node.json --name cpu-1
py -3.12 roc.py cluster cpu-on --config work/cluster/node-1/node.json --name cpu-1
py -3.12 roc.py tasks
py -3.12 roc.py tasks pause --id TASK_ID
py -3.12 roc.py tasks resume --id TASK_ID
py -3.12 roc.py tasks stop --id TASK_ID
```

HTTP 503/network timeout can mean an uncertain publication: a pending log entry
may commit when quorum returns. Retry the **same request ID and body**. The API
client preserves the ID within its retry loop; CPU results use stable job/nonce
receipts. Never interpret a timeout as proof that the write did not happen.

## Verification

```powershell
py -3.12 -m unittest discover -s tests -p test_cluster.py -v
$env:ROC_CLUSTER_LIVE='1'
$env:ROC_NATS_SERVER='<path to checked nats-server.exe>'
py -3.12 -m unittest discover -s tests -p test_cluster_live.py -v
```

The live test starts real NATS brokers and Python servers on isolated ports/DBs;
rechecks archived 2008-06:00401040 with the real compiler; verifies solo automatic
validation, forged/stale result rejection, CPU opt-out, authentication, concurrent
CAS writes, GET/POST failover, duplicate credit prevention, lost DB replay, minority
write rejection and recovery. It kills only processes it started and retains logs
under `work/cluster-test-*`. Real multi-PC power/network tests and seven-day soak
remain deployment checks. Local three-process tests cannot prove host-level uptime.

Windows pilot on 2026-10-11 passed: real solo and three-broker tests, two separate
contributor processes, trusted recompilation of archived exacts, and live dashboard
Start/Pause/Resume/CPU off. A Windows status-reader lock found by the UI pilot is
covered by atomic-write retries; telemetry cannot terminate a matching job.
The full offline import preserved 196,968 allowed functions and 262,390 events,
with canonical row hashes checked against the backup. These are restored records,
not new gains. Live campaign server and miners were kept on their existing port.

Consensus/log behavior follows [JetStream clustering](https://docs.nats.io/learn/topologies/jetstream-in-a-cluster)
and [expected-sequence publication](https://docs.nats.io/nats-concepts/jetstream/headers).
