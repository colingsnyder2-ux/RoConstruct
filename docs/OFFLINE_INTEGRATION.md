# Offline 2008-06 native integration (forks)

Native integration normally depends on the group server for its baseline
(`/v1/integration/base`), evidence and accepted-job history. When the server is
down or its published baseline is inconsistent, a fork can carry the whole
baseline in git and keep integrating locally.

## What lives in git

| File | Role |
| --- | --- |
| `rebuild/2008-06/patches/make_rbxgs_client.py` | generator; writes `rbxgs-client.json` |
| `rebuild/2008-06/patches/rbxgs-client.json` | generated base overlay (must equal the generator output) |
| `rebuild/2008-06/patches/native-promotions.json` | accepted promotion batches, replayed in order |
| `rebuild/2008-06/offline/evidence.json` | snapshot of the server's mined exact targets, linked addresses, native names |
| `rebuild/2008-06/offline/ledger.json` | accepted jobs and their gains (server snapshot + offline accepts) |

`/rebuild/` is ignored by `.gitignore`; add new files under it with `git add -f`.

## Workflow

```text
export ROC_INTEGRATION_OFFLINE=1
roc native-try targets                       # remaining eligible targets per native file
roc native-try evidence App/x/File.cpp       # target asm, mined proof, current diffs
roc native-try edit App/x/File.cpp           # editable copy under work/native-try/edit
roc native-try check App/x/File.cpp          # compile, prove gains, save the proposal
roc native-try accept --model MODEL          # linked preflight; on success append to native-promotions.json
git add rebuild/2008-06/patches/native-promotions.json && git add -f rebuild/2008-06/offline/ledger.json
```

With `ROC_INTEGRATION_OFFLINE=1`, `worker.Api` answers the read-only integration
endpoints from these files (`roc/integration_offline.py`); claim, submit and
credit endpoints are refused. The offline baseline revision is a hash of the
generator, overlay and promotions, so every commit is its own baseline.

`accept` runs the same `linked_preflight` the server runs (full linked build,
no lost bodies, native reference gate). Only an accepted receipt is recorded.
It grants no credit: a maintainer re-verifies the promotions on the server
(replay `native-promotions.json` entries after the server's accepted list) before
anything is credited.

`roc native-try snapshot` (online, without the variable) refreshes
`evidence.json` and the server part of `ledger.json`.
