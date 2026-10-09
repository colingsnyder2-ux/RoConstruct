#!/usr/bin/env sh
# RoConstruct setup for Linux. The Windows counterpart is install.cmd.
#
# It installs only what a contributor needs: the two pip packages (in a private
# venv under tools/venv), the exact MSVC compiler bundles (unpacked with
# Wine/msitools/cabextract, not installed), and then reports. No Ollama, no
# Docker, no model, no client.
set -e
cd "$(dirname "$0")"

PYTHON="${PYTHON:-python3}"
VENV="$PWD/tools/venv"

echo "RoConstruct setup (Linux)"
echo

if ! "$PYTHON" -c 'import sys; raise SystemExit(0 if sys.version_info >= (3, 12) else 1)'; then
    echo "Python 3.12 or newer is required (found: $("$PYTHON" --version 2>&1))."
    exit 1
fi

if ! command -v "${ROC_WINE:-wine}" >/dev/null 2>&1; then
    echo "Wine is required: it runs the exact 2005/2008 cl.exe compilers."
    echo "  Arch:          sudo pacman -S wine"
    echo "  Debian/Ubuntu: sudo apt install wine wine32"
    echo "  Fedora:        sudo dnf install wine"
    exit 1
fi

if ! command -v cabextract >/dev/null 2>&1 && ! command -v 7z >/dev/null 2>&1; then
    echo "cabextract or 7z is required to unpack the compiler archives."
    echo "  Arch:          sudo pacman -S cabextract"
    echo "  Debian/Ubuntu: sudo apt install cabextract"
    exit 1
fi

# A private venv, not `pip install --user`: most distributions now refuse
# user-level pip installs into the system Python (PEP 668), and this also keeps
# pefile/capstone out of anything else on the machine.
if [ ! -x "$VENV/bin/python" ]; then
    echo "Creating the Python venv in tools/venv..."
    if ! "$PYTHON" -m venv "$VENV"; then
        echo "Could not create a venv. On Debian/Ubuntu: sudo apt install python3-venv"
        exit 1
    fi
fi

echo "Checking Python packages (pefile, capstone)..."
if ! "$VENV/bin/python" -m pip install -q --disable-pip-version-check pefile capstone; then
    echo "pip failed. Check your internet connection and run this again."
    exit 1
fi

# `roc install` prints the download size and time before it starts, and resumes
# interrupted downloads. Declining a compiler is not a failed install: doctor
# reports what is still missing below.
"$VENV/bin/python" roc.py install || true

echo
echo "Checking everything is in place..."
"$VENV/bin/python" roc.py doctor || true

echo
echo "------------------------------------------------------------------"
echo " Setup complete. No Ollama, no Docker, no GPU required."
echo
echo " Next:  ./roc.sh launch          start a worker (cloud models need a key)"
echo "        ./roc.sh provider setup  save a cloud model key"
echo "        ./roc.sh local-ai        opt-in local model (Ollama)"
echo "        ./roc.sh doctor          diagnose this install"
echo "------------------------------------------------------------------"
