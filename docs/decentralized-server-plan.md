# Distributed CPU mining and replicated coordination

Status: private cluster implementation available; see `decentralized-server-setup.md`.
Real local three-process tests verified quorum writes, concurrent coordinators,
GET/POST failover, lost SQLite projection replay, and an independently compiled
exact fixture. The detailed sections below describe the eventual design, including
features that are not implemented yet: two-validator signatures, public-worker
sandboxing, zero-local-compile AI mode, and provider-budget checkpoint migration.
Client 2009-12 remains excluded from jobs,
verification, propagation, credit, and reporting.

## Recommended shape

Start with distributed CPU work and the existing group server. Then replicate the
coordinator across three approved machines. Volunteers contribute computation;
approved validators decide what becomes a verified match. Replication removes a
single machine dependency, but does not make unknown peers trustworthy.

```
AI / deterministic miners -> candidate queue -> volunteer CPU workers
                                    |                 |
                                    v                 v
                           approved validators <- provisional results
                                    |
                           signed verification receipts
                                    |
                        replicated accepted-gain ledger
                                    |
                       scores / donors / daily leaderboard
```

## 1. Extract CPU work first

Add `roc cpu-worker`: advertise available compiler builds, OS, CPU slots, memory,
and cached artifacts. Default to one slot; users explicitly choose higher limits.
Workers pull jobs, heartbeat, compile in isolation, compare, upload results, and
release their lease. No AI keys, webhook credentials, coordinator tokens, or private
host paths go to these workers. CPU mining must be an explicit opt-in: existing
cloud workers currently promise an idle local PC.

Expose two independent settings: **AI mining** and **Contribute CPU mining**.
CPU contribution defaults off, with pause/resume and a CPU-slot limit. Turning it
off stops new CPU leases; finish the current bounded job, or offer an explicit stop
now action that cancels its process tree and requeues work. Persist the choice across
restarts. Advertise zero CPU slots while disabled; coordinators must not assign
compilation, propagation, configuration, or layout jobs to that node. AI-only mode
routes required compilation/comparison to opted-in CPU workers and validators. If
none are available, retain pending work rather than silently using that user's CPU.
Coordinator networking still uses a small amount of CPU; this switch controls the
heavy mining jobs. Manually launched local commands remain explicit user actions.

First supported jobs: source compilation and comparison; compiler/config variants;
propagation fan-out. Later add library cohorts and layout variants. Batch targets
only when they share a compiler/input manifest. Preserve every candidate, partial,
failure, and rejected hypothesis with provenance.

Job identity is SHA-256 over canonical JSON containing protocol version, source
hash, immutable include/library manifest, compiler bundle hash, exact flags,
client binary/data hashes, target addresses, and comparator version. Compilation
has its own key without target addresses, enabling one compilation to feed many
comparison jobs. Cache object artifacts by that key; validators independently
establish which cached artifacts actually correspond to the source.

Persist `queued -> leased -> reported -> validating -> accepted/rejected` states.
Each lease gets a monotonic generation plus a random nonce. Start with 120-second
leases and 20-second heartbeats; cap a compile at the existing 120-second timeout.
Retry failed delivery three times, then quarantine for review. A stale lease cannot
replace a later result. Deduplicate results and credit by job/receipt identity.

## 2. Acceptance and hostile workers

Remote scores and uploaded objects are provisional. An attacker can upload target
bytes with fabricated source; comparing that object alone does not prove recovery.
An approved validator must independently compile the exact submitted source and
compare against the pinned client, including relocations and initialized data under
the existing matching policy. Never execute recovered programs.

For the first pilot, the current group server performs this verification. In the
replicated phase, require matching signed receipts from two of three approved
validators before recording an exact. A partial score needs approved verification
before replacing the stored score. A receipt binds all input hashes, result,
validator identity, and protocol version. Receipt signers must be distinct approved
keys; two accounts created by one volunteer do not qualify.

Remove the current `/v1/submit` fallback that accepts a claimed score when a client
cannot be verified. Such submissions remain pending until a compatible validator
is available. Only accepted exacts become donors or leaderboard gains. Bind credits
to authenticated user keys, not a request's freely chosen username. Report model
names as declared metadata unless provider usage is independently evidenced.

Workers receive per-node credentials, narrowly scoped job/blob access, and quotas.
New volunteers: one concurrent lease, no validator role, no job creation or arbitrary
URL fetching. Sample 10% of remote non-exact outcomes for approved recomputation to
detect hidden wins and fabricated failures; increase sampling when discrepancies
appear. Audits and reputation help scheduling, but never replace exact verification.
Rate-limit enrollment, upload bytes, lease renewal, and job submissions. Quarantine
protocol violations immediately; review ordinary compiler/version disagreements.

Compile untrusted source inside a disposable VM or independently reviewed sandbox:
no network, no secrets, no host mounts, no administrator privileges; read-only pinned
compiler/libraries; isolated scratch disk; bounded processes, RAM, disk, and output.
Pilot limits: one compile slot, 4 GiB RAM, 2 GiB scratch, 1 MiB diagnostics, 32 MiB
result uploads. Oversized legitimate library jobs need an explicit larger profile.
Test path traversal, includes outside the manifest, archive bombs, compiler hangs,
and malicious object/parser inputs before admitting unknown workers. Sandbox the
validators too; signature verification does not make submitted source safe.

## 3. Replicate coordination

Prototype a three-node NATS JetStream cluster with three replicas for job streams,
consumer state, and accepted-event storage. Deploy across independent machines;
putting all replicas on one PC provides no machine-failure protection. A durable
queue needs explicit acknowledgments, redelivery, and bounded outstanding jobs.
Queue acknowledgment is not proof that a candidate is valid.

Use an elected coordinator with a generation/fencing token and conditional state
updates; an old leader cannot commit new leases after failover. Append signed
accepted-gain events to a replicated, retained ledger before publishing credit.
Local SQLite databases become rebuildable projections, not shared writable files.
Replay must enforce unique candidate/gain IDs and monotonic score improvement.
Replica consumers must reject events without required validator receipts.

Workers store at least three coordinator endpoints and reconnect automatically.
If the primary PC powers off, reachable coordinator replicas retain the queue and
scores. AI miners on other PCs reconnect and continue; an expired lease from the
offline PC can be reassigned to another compatible, opted-in AI worker. The dead
process itself cannot continue: only its persisted task/checkpoint can be resumed.
Persist prompts, candidate sources, attempt/refinement counters, and budget
reservations before dispatch, so failover preserves campaign limits and rejected
hypotheses. The backup must already have the required model access and artifacts.

Do not copy personal AI provider keys to volunteers. A backup worker uses its own
approved credentials, or a separately authorized credential service with bounded
per-job permissions. Track shared campaign costs/reservations in replicated state.
A provider call interrupted before its result was persisted may still be billed;
mark its billing state uncertain, retain its reservation, and allow retry only if
the global cap covers both possible charges. Missing credentials, CPU validators,
or coordinator quorum leave tasks pending. All PCs offline means no work can run.

Current RoConstruct has one group-server host: miners elsewhere may finish their
current local work during its outage, but cannot acquire new server leases or submit
until it returns. Automatic coordinator takeover is a deliverable of this plan, not
an existing feature.
Snapshots and artifacts are content-addressed and mirrored. Use versioned signed
membership/toolchain manifests with expiry and rollback protection; use an existing
update-security framework rather than inventing signature/update rules. Two of
three administrator keys approve validator enrollment, key rotation, and revocation.
Keep administrator root keys separate from online worker keys.

This design assumes approved coordinator operators are trusted. Raft replication
handles outages, not arbitrary malicious coordinators. Two compromised validators
can approve false results; a compromised coordinator can censor work. Stronger
Byzantine consensus is a separate project, not a property of this three-node pilot.
Losing quorum pauses acceptance rather than permitting conflicting credit.

## Implementation boundaries

- `roc/cpu_jobs.py`: manifests, hashing, persistent leases, cache keys, idempotency.
- `roc/cpu_worker.py`: capability registration, pull/heartbeat/result loop, sandbox.
- `roc/validator.py`: independent compilation, exact comparison, signed receipts.
- `roc/cluster.py`: replication adapters, fencing, membership, ledger replay.
- `/v2/cpu/register`, `/lease`, `/heartbeat`, `/result`: scoped worker protocol.
- `/v2/candidates` and `/v2/candidates/{id}`: enqueue/poll API; return pending until
  verification finishes. Keep bounded `/v1` compatibility during migration.
- Existing server and mining modules: dispatch expensive work; keep request handlers
  and DB transactions short. Existing daily reporting consumes accepted events.

## Pilot and scale gates

1. Capture current latency, CPU load, compiler throughput, and exact acceptance on
   a fixed 1,000-job corpus across allowed client/compiler builds. Include known
   exacts, partials, and rejected sources. Use no paid AI requests for this pilot.
2. Run two volunteer CPU machines and the existing trusted server in shadow mode:
   no remote result changes official scores. Require identical verified decisions,
   zero false exacts, and no lost jobs. Inject worker exits and duplicate submissions.
3. Enable one family/library cohort. Scale to five, then ten CPU machines only if
   authoritative throughput improves and status p95 remains below one second.
   Record verification CPU separately; double verification may erase speed gains.
4. Deploy three approved coordinators/validators. Kill a node and partition the
   network. Require service recovery within 60 seconds with a majority reachable,
   zero lost accepted gains, zero duplicate credit, and no minority-side acceptance.
5. Test forged scores/objects, Sybil signers, expired credentials, stale leases,
   manifest rollback, abusive uploads, and malicious source. All must fail closed.
   Verify CPU opt-out survives restart and receives zero heavy jobs; with no eligible
   CPU peers, AI-only jobs remain pending. Power off the original PC and require
   another ready AI miner to resume persisted work without resetting budgets or
   crediting a function twice. Simulate uncertain provider billing on failover.
6. Keep the single-server path available until a seven-day cohort run passes those
   checks. Preserve queues/artifacts on rollback; rebuild projections from the ledger.

If fewer than three independently operated machines are available, stop after
distributed CPU mining. It still offloads heavy work, but the coordinator remains
a single point of failure. No thousand-match payoff is assumed: measure throughput
and new verified exacts before expanding infrastructure.

## References

- [NATS JetStream](https://docs.nats.io/concepts/jetstream): persistence, delivery,
  and shared consumers.
- [JetStream clustering](https://docs.nats.io/learn/topologies/jetstream-in-a-cluster):
  three replicas, majority availability, placement, and failure domains.
- [The Update Framework specification](https://theupdateframework.io/spec/): signed,
  versioned metadata and update trust. Adopt its implementation/rules; do not treat
  it as a computational correctness verifier.
