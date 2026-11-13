# Selective OpenRBX trial

This is an isolated trial, not a canonical engine swap. Keep source, layout, call-binding and provider review separate from byte-match and runtime results.

The trial-only glue override removes two empty settings stubs so the real selected GlobalSettings methods remain the providers. All other glue bodies remain unchanged.

Freeze the last successfully verified trial into a new directory:

```powershell
python rebuild/2008-06/openrbx-selective/snapshot_baseline.py work/openrbx-selective-codex/baseline-N
```

Refresh the historical opportunity ranking:

```powershell
python rebuild/2008-06/openrbx-selective/rank_remaining.py work/openrbx-selective-codex/baseline-N --output work/openrbx-selective-codex/ranking.json
```

Compile each candidate once using the rbxgs recipe and a separate overlay:

```powershell
python rebuild/2008-06/openrbx-selective/compile_candidates.py PATH-TO-SOURCES
```

Then scan the compiled objects against the baseline:

```powershell
python rebuild/2008-06/openrbx-selective/scan_candidates.py work/openrbx-selective-codex/baseline-N PATH-TO-OBJECTS --output work/openrbx-selective-codex/candidates.json
```

The score is an archive-object address inventory, not a count of functions present in the executable. See force-audit.json for executable-map evidence. The scan checks masked code and resolvable data, known symbol identity, existing definitions and exclusions. Its output is a lead, not a call-binding, layout, provider or runtime proof. Review donor source and target evidence, extract selected bodies, and add explicit symbol/address mappings to `run_trial.py`.

Build and verify the batch:

```powershell
python rebuild/2008-06/openrbx-selective/run_batch.py work/openrbx-selective-codex/baseline-N
```

The runner prevents overlapping runs, rejects global or per-object ownership losses, requires a gain, forces the selected symbols into smoke and M2/M4a/M5 executables, and verifies their selected providers in isolated link maps. It saves a hash-bound receipt at `rebuild/2008-06/out/RbxgsAppOpenRBXSelective/batch-verification.json`. Freeze a fresh baseline only after this succeeds.

Add `--fast` for diagnostic compile/link/smoke only. Fast mode skips scoring and milestones, overwrites the trial report, and cannot prove a gain. Run the full command afterwards. No scheduler or notifications are created.
