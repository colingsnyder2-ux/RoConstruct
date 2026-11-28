import os, subprocess, sys
env=dict(os.environ, QT_TAG='CodexZ2')
raise SystemExit(subprocess.call([sys.executable, 'codex_cache_variant.py', '0'], env=env))
