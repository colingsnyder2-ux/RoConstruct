# Inactive RunService candidate

Original path: `rebuild/2008-06/native-classes/RunService.cpp`. Public and workspace base: `76cede182885256cf1db4656f1ef8f3c239bd073`.

`removeRunView` 00555830 matches original code/data and reviewed direct-call bindings in `work/2008-06/native-check-runs/20261106-225357-ea497c99/analysis-25f9833e.json` (SHA-256 `a476f4ab67614bf3b0a16fd2f0d172a4a1b76f15189b02d0609680b3832c7ea6`). The called `runViewValid` provider at 005555e0 has not been integrated or ABI-proven. `RunService-valid.cpp` is a first hypothesis: 230/239 bytes, 74%, first divergence offset 24, run `20261106-225901-3482ccbf`. Retain both candidates inactive until provider, EH, dependency regression and selection/runtime gates are proven.

Update: both `removeRunView` and `runViewValid` are now integrated as inactive source in commit `3151ad550d4d98cb082eac6dc9274677befbfc01`. The second hypothesis, original call bindings, EH graphs, layout and existing-method regressions are recorded in `work/2008-06/shared-layouts/public-runservice-reconciliation.json`. Linked selection and runtime gates remain open. The earlier hypothesis remains historical.
