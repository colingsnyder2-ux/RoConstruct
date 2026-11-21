#!/bin/sh
# qd.sh SRC FAMILY ADDR SYMPREFIX  : quick compile SRC with FAMILY's flags (QC_I = extra include dirs ';'-separated) and diff ADDR vs the symbol
python work/native-client/qc.py "$1" "$2" 2>&1 | grep -E "error|exit" | cut -c1-250
./roc.cmd native-asm 2008-06 "$3" --obj C:/Users/colin/AppData/Local/Temp/qc/q.obj --sym "$4" 2>&1 | python -c "import sys;t=sys.stdin.read().split('\n');print('\n'.join(l[-150:] if len(l)>150 else l for l in t[:70]))"
