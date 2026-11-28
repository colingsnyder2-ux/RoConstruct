import os, subprocess, sys
env=dict(os.environ, QT_TAG='CodexZ1')
raise SystemExit(subprocess.call([sys.executable, 'codex_zero_variant.py', '0'], env=env))
