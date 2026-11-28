"""python auto_dashboard.py: render work/donorfree-route/auto/results.json (autorecover.py output) as auto/dashboard.html
(auto-refreshing every 20 s). Open the file in a browser."""
import html, json
from pathlib import Path

A = Path(__file__).parent / 'auto'
rows = json.load(open(A / 'results.json')) if (A / 'results.json').exists() else []
tr = []
for r in rows:
    ok = r.get('compile')
    st = 'compiled' if ok else 'failed'
    detail = r.get('exact_check') or r.get('last_errors') or r.get('error') or ''
    tr.append('<tr class="%s"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td><pre>%s</pre></td><td><a href="packet_%s.md">packet</a></td></tr>' % (
        st, r['addr'], html.escape(r.get('name', '')[:70]), st, r.get('tries', ''), html.escape(detail[:600]), r['addr']))
page = '''<!doctype html><meta charset="utf-8"><meta http-equiv="refresh" content="20"><title>Auto recovery</title>
<style>body{font:14px system-ui;margin:20px;background:#111;color:#ddd}table{border-collapse:collapse;width:100%%}td,th{border:1px solid #333;padding:4px 8px;vertical-align:top}
tr.compiled td:nth-child(3){color:#6c6}tr.failed td:nth-child(3){color:#e66}pre{margin:0;white-space:pre-wrap;font-size:12px}a{color:#8af}</style>
<h2>autorecover.py results (%d targets, %d compiled)</h2>
<table><tr><th>addr</th><th>function</th><th>status</th><th>tries</th><th>exact_check / errors</th><th>packet</th></tr>%s</table>''' % (
    len(rows), sum(1 for r in rows if r.get('compile')), '\n'.join(tr))
(A / 'dashboard.html').write_text(page, encoding='utf-8')
print(A / 'dashboard.html')
