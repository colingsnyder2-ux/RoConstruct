"""Emit bounded compiler-only probes for closure-bound inline Ogre members.

Generated wrappers are not native providers.  They only make VS2008 emit an
existing header definition, which native-bulk must independently byte-prove.
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
FLAGS = ('/O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast '
         '/I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')
METHOD = re.compile(
    r'^\s*virtual\s+(.+?)\s+([~A-Za-z_]\w*)\s*\(([^()]*)\)\s*'
    r'(const)?\s*\{[^{}]*\}', re.M)
IDENT = re.compile(r'([A-Za-z_]\w*)\s*$')


def args_and_names(text):
    text = text.strip()
    if not text or text == 'void':
        return '', ''
    parts = [part.strip().split('=', 1)[0].rstrip() for part in text.split(',')]
    names = []
    for part in parts:
        found = IDENT.search(part)
        if not found or part.endswith('...'):
            return None
        names.append(found.group(1))
    return ', '.join(parts), ', '.join(names)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--header', required=True, help='repo-relative native header')
    ap.add_argument('--include', required=True, help='include spelling for header')
    ap.add_argument('--namespace', default='Ogre')
    ap.add_argument('--class-name', required=True)
    ap.add_argument('--closure', required=True)
    ap.add_argument('--output-cpp', required=True)
    ap.add_argument('--output-config', required=True)
    ap.add_argument('--output-evidence', required=True)
    ap.add_argument('--family', required=True)
    ap.add_argument('--limit', type=int, default=20)
    args = ap.parse_args()
    header = ROOT / args.header
    closure = ROOT / args.closure
    data = json.loads(closure.read_text())
    bindings = data['bindings']
    methods = []
    skipped = []
    for match in METHOD.finditer(header.read_text()):
        ret, name, raw_args, const = match.groups()
        parsed = args_and_names(raw_args)
        if parsed is None:
            skipped.append({'name': name, 'reason': 'complex-parameters'})
            continue
        marker = '?%s@%s@%s@@' % (name, args.class_name, args.namespace)
        rows = [row for row in bindings if row['symbol'].startswith(marker)
                and row.get('function_start') and row.get('body_exact')]
        if len(rows) != 1:
            skipped.append({'name': name, 'reason': 'binding-count-%d' % len(rows)})
            continue
        declaration_args, call_args = parsed
        body = ('%s x->%s::%s::%s(%s);' %
                ('return' if ret.strip() != 'void' else '', args.namespace,
                 args.class_name, name, call_args)).replace('return ;', '')
        methods.append({'name': name, 'ret': ret.strip(), 'args': declaration_args,
                        'call': body, 'addr': rows[0]['addr'],
                        'symbol': rows[0]['symbol']})
    methods = methods[:args.limit]
    out_cpp = ROOT / args.output_cpp
    out_config = ROOT / args.output_config
    out_evidence = ROOT / args.output_evidence
    out_cpp.parent.mkdir(parents=True, exist_ok=True)
    nested = set()
    for method in methods:
        for owner in re.findall(r'@([A-Za-z_]\w*)@2', method['symbol']):
            for token in re.findall(r'[A-Za-z_]\w*', method['ret']):
                if token + '@' + owner + '@2' in method['symbol']:
                    nested.add((token, owner))
    lines = ['// native-flags: ' + FLAGS, '#include "%s"' % args.include, '',
             '// Generated compiler-only inline emission probe. Not native source.',
             'namespace %s {' % args.namespace]
    lines.extend('typedef %s::%s %s;' % (owner, token, token)
                 for token, owner in sorted(nested))
    for index, method in enumerate(methods):
        lines.append('%s roc_inline_probe_%d(%s::%s* x%s)%s { %s }' % (
            method['ret'], index, args.namespace, args.class_name,
            (', ' + method['args']) if method['args'] else '', '',
            method['call']))
    lines.append('}')
    out_cpp.write_text('\n'.join(lines) + '\n')
    addrs = [method['addr'] for method in methods]
    command = [sys.executable, str(ROOT / 'work/native-client/native_identity_evidence.py'),
               '--closure', str(closure), '--output', str(out_evidence)]
    for addr in addrs:
        command.extend(['--addr', addr])
    subprocess.check_call(command, cwd=str(ROOT))
    config = {'client': '2008-06', 'targets': addrs, 'families': [{
        'name': args.family, 'sources': [args.output_cpp],
        'evidence': [args.output_evidence]}]}
    out_config.write_text(json.dumps(config, indent=1) + '\n')
    report = {'scope': 'compiler-only probe; not native source/integration',
              'header': args.header, 'class': '%s::%s' % (args.namespace, args.class_name),
              'emitted': methods, 'skipped': skipped}
    print(json.dumps({'eligible': len(methods), 'skipped': len(skipped),
                      'config': args.output_config,
                      'report': report}, indent=1))


if __name__ == '__main__':
    main()
