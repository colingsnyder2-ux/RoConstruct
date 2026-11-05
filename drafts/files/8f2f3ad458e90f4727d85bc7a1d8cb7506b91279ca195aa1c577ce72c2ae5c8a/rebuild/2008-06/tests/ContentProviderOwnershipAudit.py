"""ContentProvider ownership audit wrapper (draft, inactive).

Delegates to audit_native_archive_consumers.py for ContentProvider.obj family.
Does not compile, link, or activate runtime selection. References are possible
edges, not extraction proof.
"""
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
if __name__ == "__main__":
    out = ROOT / "work/2008-06/shared-layouts/content-provider-ownership-migration.json"
    # Wrapper only documents the invocation; the real audit needs linked.lib.
    print("ContentProvider ownership audit: run audit_native_archive_consumers.py ContentProvider.obj after native-doc baseline")
