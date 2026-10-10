# Investigations

Start with [worker guide](../AI_WORKER_GUIDE.md) and
[experiment memory](../EXPERIMENTS.md). The detailed
[matching findings log](matching-findings.md) retains positive and negative
address-level attempts. `roc repair` appends new findings here.

Local scratch lives in ignored `work/investigation/`: RakNet/RakPeer recipe
compilation probes, LTCG/real caller-context tests, compiler-cache diagnostics,
template RTTI analysis, old status checks and captured compiler output.
These scripts may contain absolute local paths or launch substantial work;
inspect before reuse. Their presence is not proof an experiment completed.

`local-inventory.json` records filenames, sizes and SHA-256 hashes of the scratch
snapshot at consolidation. It preserves provenance without publishing private
client binaries, source, settings or diagnostic contents. Original historical
reports are in [archive](../archive/README.md); ignored `work/` artifacts require
the original workspace and are not recoverable from a normal Git clone.
