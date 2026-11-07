# Tooling tests

This directory tests RoConstruct's tools and collaboration protocols. Native
binary/ABI/runtime checks live under `rebuild/2008-06/tests` and have different
input/toolchain requirements.

| Area | Existing test entry points |
| --- | --- |
| Source navigation | `test_source_catalog.py`, `test_source_view.py` |
| Draft lifecycle | `test_native_drafts.py`, `test_native_collaboration.py` |
| Publication and archives | `test_findings_workspace.py`, `test_findings_package_bytes.py` |
| Preservation | `test_fork_preservation.py`, `test_rebuild_package_sources.py` |
| Native proof runner | `test_native_check_runner.py`, `test_native_layout_evidence.py` |
| Integration | `test_integration.py`, `test_integration_local.py`, `test_integration_policy.py` |
| Hosting and ownership | `test_server_lease_queue.py`, `test_server_recovery.py` |
| Website | `test_site_progress.py`, `test_site_progress.js` |

Run focused tests for the changed behavior, for example:

```text
python -m pytest tests/test_source_catalog.py -q
```

Other tests may need pinned inputs or services. A test filename or passing tooling
test does not establish a native class swap. Do not delete an old check because
its filename is awkward: inspect CI, callers and its proof obligation first.
