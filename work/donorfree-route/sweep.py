"""python sweep.py: one crash-and-continue pass over the milestone script cases (no relink). Each case runs once through
scripttest (-script); a crashing case is re-run under the Frida fault probe (auto/peekfault.py) to record the faulting
module/pc and the code-range stack. Writes auto/sweep_report.json; prints one line per case."""
import json, os, re, subprocess, sys
from pathlib import Path
H = Path(__file__).parent
sys.path.insert(0, str(H))
sys.argv = sys.argv[:1]
import scripttest as st
CASES = {
    'part_parent': 'local o = Instance.new("Part") o.Parent = workspace',
    'part_props': 'local o = Instance.new("Part") o.Parent = workspace o.Size = Vector3.new(4,2,4) o.Position = Vector3.new(0,10,0) o.Anchored = true o.BrickColor = BrickColor.new("Bright red")',
    'model_seat': 'local m = Instance.new("Model") m.Parent = workspace local s = Instance.new("Seat") s.Parent = m',
    'spawn_decal': 'local s = Instance.new("SpawnLocation") s.Parent = workspace local d = Instance.new("Decal") d.Parent = s',
    'sound': 'local s = Instance.new("Sound") s.Parent = workspace',
    'explosion': 'local e = Instance.new("Explosion") e.Position = Vector3.new(0,5,0) e.Parent = workspace',
    'remove_clone': 'local o = Instance.new("Part") o.Parent = workspace local c = o:Clone() c.Parent = workspace o:Remove()',
    'changed_event': 'local v = Instance.new("IntValue") v.Parent = workspace v.Changed:connect(function() end) v.Value = 3',
    'humanoid': 'local m = Instance.new("Model") m.Parent = workspace local h = Instance.new("Humanoid") h.Parent = m',
}
rep = {}
for name, lua in CASES.items():
    r = st.run(st.EXE, lua + '\nlocal v = Instance.new("StringValue") v.Name = "R1 pass=1 fail=" v.Parent = workspace', wait=14)
    crash = r.get('_exit')
    passed = r.get('_workspace', 0) > 0 and r.get('R1', {}).get('pass') == 1 and not r['R1']['fail']
    row = {'result': crash if crash else 'ok' if passed else 'missing result', 'raw': r}
    if crash:
        (H / 'auto/one.lua').write_text(lua)
        p = subprocess.run([sys.executable, str(H / 'auto/peekfault.py')], capture_output=True, text=True, cwd=str(H))
        row['fault'] = [l for l in p.stdout.splitlines() if l.startswith(('pc ', 'stack '))]
    rep[name] = row
    print('%-14s %s %s' % (name, row['result'], (row.get('fault') or [''])[0][:150]), flush=True)
(H / 'auto/sweep_report.json').write_text(json.dumps(rep, indent=1))
