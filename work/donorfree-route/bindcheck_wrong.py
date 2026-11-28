"""Static audit of auto/bindcheck.json 'wrong' (WRONG/PROVEN misbindings) against CODEX_RESULTS.txt,
GEMINI_RESULTS.txt, shared-layouts/*.json, and linkexp/qt.map.
Emits verified NAME=TARGET aliases (only where TARGET is a real defined non-stub symbol in qt.map)
to work/donorfree-route/aliases_gemini.txt (grow-only) and prints a full summary.
python bindcheck_wrong.py"""
import json
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
OUT_ALIAS = H / 'aliases_gemini.txt'
OUT_REPORT = ROOT / 'work/native-client/mass-tools/bindcheck_wrong_report.json'


def load_real_map_symbols():
    real = set()
    mp = H / 'linkexp/qt.map'
    if mp.is_file():
        for l in mp.read_text(errors='replace').splitlines():
            p = l.split()
            if len(p) >= 4 and ':' in p[0] and 'stubs.obj' not in p[-1].lower():
                real.add(p[1])
    return real


def load_exact_results():
    exact = {}
    for list_path in (ROOT / 'work/native-client/CODEX_RESULTS.txt', ROOT / 'work/native-client/GEMINI_RESULTS.txt'):
        if not list_path.is_file():
            continue
        for line in list_path.read_text(encoding='utf-8').splitlines():
            rp = line.strip()
            if not rp or not (ROOT / rp).is_file():
                continue
            data = json.loads((ROOT / rp).read_text(encoding='utf-8'))
            units = data if isinstance(data, list) else data.get('results', [])
            for u in units:
                src = Path(u.get('source', '')).name
                for c in u.get('checks', []):
                    if c.get('status') == 'exact' and not c.get('data_errors'):
                        va = c['addr'].lower()
                        exact[va] = {'source': src, 'symbol': c.get('symbol') or c.get('requested_symbol'), 'results': rp}
    return exact


def load_shared_layouts(target_vas):
    hits = {}
    sl = ROOT / 'work/2008-06/shared-layouts'
    for p in sl.glob('*.json'):
        try:
            d = json.loads(p.read_text(errors='ignore'))
        except Exception:
            continue
        def walk(o):
            if isinstance(o, dict):
                addr = o.get('address') or o.get('addr')
                sym = o.get('symbol')
                if isinstance(addr, str) and isinstance(sym, str):
                    a = addr.lower().removeprefix('0x').zfill(8)
                    if a in target_vas and a not in hits:
                        hits[a] = {'receipt': p.name, 'symbol': sym}
                for v in o.values():
                    walk(v)
            elif isinstance(o, list):
                for v in o:
                    walk(v)
        walk(d)
    return hits


def merge_aliases(new_pairs):
    existing = {}
    if OUT_ALIAS.is_file():
        for l in OUT_ALIAS.read_text(encoding='utf-8').splitlines():
            l = l.strip()
            if l and not l.startswith('#') and '=' in l:
                k, v = [x.strip() for x in l.split('=', 1)]
                existing[k] = v
    added = 0
    for k, v in new_pairs.items():
        if k not in existing:
            existing[k] = v
            added += 1
    OUT_ALIAS.write_text(''.join(f'{k}={v}\n' for k, v in sorted(existing.items())), encoding='utf-8')
    return added, len(existing)


def main():
    bc = json.loads((H / 'auto/bindcheck.json').read_text(encoding='utf-8'))
    wrong = bc.get('wrong', [])
    target_vas = {w[1].lower() for w in wrong if len(w) >= 4}
    real_syms = load_real_map_symbols()
    exact = load_exact_results()
    sl = load_shared_layouts(target_vas)

    resolved_exact, resolved_sl, unresolved = [], [], []
    new_aliases = {}
    for w in wrong:
        sym, va, obj, reason = w[0], w[1].lower(), w[2], w[3]
        entry = {'symbol': sym, 'va': va, 'current_obj': obj, 'reason': reason}
        if va in exact:
            nsym = exact[va]['symbol']
            entry['exact_native'] = exact[va]
            entry['target_in_map'] = nsym in real_syms
            resolved_exact.append(entry)
            if nsym and nsym != sym and nsym in real_syms:
                new_aliases[sym] = nsym
        elif va in sl:
            nsym = sl[va]['symbol']
            entry['shared_layout'] = sl[va]
            entry['target_in_map'] = nsym in real_syms
            resolved_sl.append(entry)
            if nsym and nsym != sym and nsym in real_syms:
                new_aliases[sym] = nsym
        else:
            unresolved.append(entry)

    added, total_aliases = merge_aliases(new_aliases)
    OUT_REPORT.parent.mkdir(parents=True, exist_ok=True)
    OUT_REPORT.write_text(json.dumps({
        'total_wrong': len(wrong),
        'exact_in_results': len(resolved_exact),
        'exact_in_shared_layouts': len(resolved_sl),
        'unresolved': len(unresolved),
        'verified_aliases_added': added,
        'verified_aliases_total': total_aliases,
        'resolved_exact': resolved_exact,
        'resolved_shared_layouts': resolved_sl,
        'unresolved_all': unresolved,
    }, indent=2) + '\n', encoding='utf-8')
    print('bindcheck_wrong: total=%d exact_results=%d shared_layouts=%d unresolved=%d aliases_added=%d total_aliases=%d' % (
        len(wrong), len(resolved_exact), len(resolved_sl), len(unresolved), added, total_aliases))


if __name__ == '__main__':
    main()
