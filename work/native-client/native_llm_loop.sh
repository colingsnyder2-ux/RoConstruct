#!/bin/sh
# Back-to-back native_llm dashboard runs (each loads the current harness code).  Stop: touch work/native-client/native-llm/STOP
cd "$(dirname "$0")/../.." || exit 1
T="$1"; PORT="${2:-8791}"; JOBS="${JOBS:-16}"; LIMIT="${LIMIT:-64}"; STOP=work/native-client/native-llm/STOP
rm -f "$STOP"
while [ ! -f "$STOP" ]; do
  ID=$(curl -s -H "X-ROC-Token: $T" -H "Content-Type: application/json" \
    -d "{\"kind\":\"native_llm\",\"jobs\":$JOBS,\"limit\":$LIMIT,\"max_size\":2048,\"tries\":2,\"nim\":0,\"free\":0,\"retry_older_than\":3,\"new_source\":true,\"pick\":\"claude\"}" \
    "http://127.0.0.1:$PORT/api/start" | python -c "import sys,json;print(json.load(sys.stdin).get('id',''))")
  [ -n "$ID" ] || { echo "start failed"; exit 1; }
  echo "run $ID $(date +%H:%M)"
  until curl -s -H "X-ROC-Token: $T" "http://127.0.0.1:$PORT/api/log?id=$ID" | grep -q '"event": "state", "message": "\(Completed\|Failed\|Stopped\|Killed\|Cancelled\)'; do sleep 30; done
  curl -s -H "X-ROC-Token: $T" "http://127.0.0.1:$PORT/api/log?id=$ID" | grep -o '"message": "exact [0-9]*/[0-9]* ([0-9]* B)"' | tail -1
  # A run with no targets left ends fast: stop instead of spinning.
  curl -s -H "X-ROC-Token: $T" "http://127.0.0.1:$PORT/api/log?id=$ID" | grep -q '"message": "0 targets' && { echo "no targets"; exit 0; }
  # Retry-only pool: pause between runs (SLEEP seconds) instead of re-proving old drafts back to back.
  [ "${SLEEP:-0}" -gt 0 ] && sleep "$SLEEP"
done
echo stopped
