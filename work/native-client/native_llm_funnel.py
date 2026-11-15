"""Where native_llm targets are lost: every queue method through each targets() filter (new-source included), so the
biggest unlock is visible.  Prints counts per first failing filter, split by size (<=2048 B vs larger).
  python work/native-client/native_llm_funnel.py"""
import collections
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import native_llm as n
from roc import match


def main():
    classes = json.loads(n.QUEUE.read_text())['classes']
    registry = json.loads(n.REGISTRY.read_text())
    native_exact = n.native_exact_addresses()
    shared = collections.Counter(m['addr'] for cl in classes for m in cl['methods'])
    drop = collections.Counter()
    for cl in classes:
        dest = None
        for m in cl['methods']:
            try:
                size = len(match.target('2008-06', m['addr'])[0])
            except Exception:
                size = 0
            band = 'small' if size <= 2048 else 'large'

            def lose(reason):
                drop[(reason, band)] += 1
            if cl['template'] or cl['owner'].startswith(('G3D::', 'std::', 'boost::')):
                lose('library/template class'); continue
            if dest is None:
                dest = n.destination_for(cl['owner'])[0] or ''
            if not dest:
                lose('multiple native destinations'); continue
            if m['addr'].lower() in native_exact:
                lose('already native exact'); continue
            if m['state'] != 'convert':
                lose('queue state=' + m['state']); continue
            headers = m.get('headers', cl.get('headers', []))
            if len(headers) != 1:
                lose('declared in %d headers' % min(len(headers), 2)); continue
            if shared[m['addr']] > 1:
                lose('ICF fold (shared body)'); continue
            identity = registry.get(m['addr'])
            if not identity or identity['placeholder'] or identity['name'] != m['symbol'] or identity.get('owner_class') != cl['owner']:
                lose('identity missing/placeholder'); continue
            analog = n.ROOT / 'src/2008-06' / (m['addr'] + '.cpp')
            packet = analog.read_text(errors='replace') if analog.is_file() else ''
            if not packet:
                lose('no analog source'); continue
            if '// from server: 100%' not in packet[:400]:
                lose('analog not 100% exact'); continue
            recipe = (match.directives(packet).get('lib') or '').split(' ')[0]
            if recipe and not recipe.startswith(('rbxgs', 'openrbx')):
                lose('vendor library lane'); continue
            text = (n.ROOT / headers[0]).read_text(errors='replace')
            name = m['declaration'].split('(')[0].split()[-1].rsplit('::', 1)[-1]
            if name not in text:
                lose('not declared in its header'); continue
            if re.search(r'\b%s\s*\([^;{}]*\)[^;{}]*\{' % re.escape(name), text):
                lose('header defines it inline'); continue
            lose('AVAILABLE')
    for band in ('small', 'large'):
        print('== %s (%s)' % (band, '<=2048 B' if band == 'small' else '>2048 B'))
        for (reason, b), count in sorted(drop.items(), key=lambda kv: -kv[1]):
            if b == band:
                print('  %6d  %s' % (count, reason))


if __name__ == '__main__':
    main()
