#!/bin/sh
# prove_retry.sh SOURCE [prove args]: prove.py caches an "inputs changed during compile" failure (a peer wrote a file in
# native-classes / native-headers while cl ran: the include-search snapshot covers both directories), so the next call reuses
# the failed row. Retry with a toggled trailing comment until the ledger row is not that failure.
src="$1"; shift
fam="prove-$(basename "$src" .cpp)"
for i in 1 2 3 4 5 6; do
  out=$(python work/native-client/prove.py "$src" "$@" 2>&1 | tail -1)
  if python -c "import json,sys; sys.exit(0 if any(e.get('error')=='inputs changed during compile; rerun' for e in json.load(open('work/native-client/prove-out/$fam/ledger.json')).values()) else 1)"; then
    if tail -n1 "$src" | grep -q '^// retry$'; then sed -i '$d' "$src"; else echo "// retry" >> "$src"; fi
  else
    tail -n1 "$src" | grep -q '^// retry$' && sed -i '$d' "$src"
    echo "$out"; exit 0
  fi
done
echo "gave up: $out"
