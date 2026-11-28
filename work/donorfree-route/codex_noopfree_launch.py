import os, subprocess, sys
env=dict(os.environ, QT_TAG='CodexZ3')
raise SystemExit(subprocess.call([sys.executable, 'codex_noopfree_variant.py', '0'], env=env))
