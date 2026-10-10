#!/usr/bin/env sh
# RoConstruct launcher for Linux. Windows uses roc.cmd.
#   ./roc.sh launch      start a worker
#   ./roc.sh doctor      check what is missing
#   ./roc.sh --help      every command
#
# Prefers the private venv install.sh created; falls back to system Python.
DIR="$(cd "$(dirname "$0")" && pwd)"
if [ -x "$DIR/tools/venv/bin/python" ]; then
    exec "$DIR/tools/venv/bin/python" "$DIR/roc.py" "$@"
fi
exec "${PYTHON:-python3}" "$DIR/roc.py" "$@"