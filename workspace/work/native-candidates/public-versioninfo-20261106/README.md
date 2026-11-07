# Inactive CVersionInfo candidate

Original path: `rebuild/2008-06/native-classes/CVersionInfo.cpp`. Public base: `76cede182885256cf1db4656f1ef8f3c239bd073`. Six byte/data checks match original in `work/2008-06/native-check-runs/20261106-225734-46db814d/results.json` (SHA-256 `444998152feae7d6a34c244ac99a6e3b9448123f7c97f48d701108e87f5c48d1`). Existing `CFileVersionInfo` provides overlapping original addresses in `p6/build_native_about.py`; app source also references `CVersionInfo`. Resolve provider ownership, call identity, ABI and selection before integration.
