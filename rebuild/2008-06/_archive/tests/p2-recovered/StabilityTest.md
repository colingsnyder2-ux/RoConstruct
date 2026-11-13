# P0 contact stability fixture

The existing local falling.rbxl is preserved verbatim as tests/fixtures/falling.rbxl.
It has an unanchored Brick initially atY20 and anchored Floor atY-5. Both use
the pinned model constructor's default dimensions. The diagnostic reads actual
model dimensions rather than assuming them: expected resting center is floorY
plus half the sum of floor and Brick heights (currently-3.8).

```powershell
.\roc.cmd rebuild 2008-06 player --no-notify
$player = (Resolve-Path rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe).Path
& $player --selftest
& $player --frames 240 C:\absolute\checkout\rebuild\2008-06\tests\fixtures\falling.rbxl
& $player --frames 600 --stability-test C:\absolute\checkout\rebuild\2008-06\tests\fixtures\falling.rbxl
```

Run direct processes with ROC_BUILD unset and fresh writable capture directories.
The canonical player module now uses the already-validated recovered player
configuration. player-local-diagnostic.json preserves the older config for the
owner's existing source/debug files. The explicit p2-recovered-player module is
an alias of the same output; do not build both concurrently.

The last half of a stability run must have at least120 steps. Every tail sample
must remain within0.01 stud of the geometry-derived resting center, with total
tail spread at most0.002 stud. The earlier working baseline's center-3.80274 is
about0.00274 below the ideal contact height; the tolerance accommodates that
solver contact margin while rejecting continued falling or notable jitter.
Floor Y, geometry-derived expected Y and anchored state are checked at every
step. Output contains every sample in stability_samples.csv and a gated summary
in stability_result.json; failure exits9. Six hundred1/60-second steps provide
a300-step / five-second stability window, not a real-time input test.

GetContactState is harness telemetry through genuine DataModel/Part APIs, not
an invented original ABI. The existing anchoring patch is retained and remains
a separately tracked native-recovery dependency. A passing owner-worktree run
does not prove P0 clean-worktree reproduction or the complete P5 physics gate.
