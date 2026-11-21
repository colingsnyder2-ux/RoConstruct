"""Route 10: reflection (Lua API) descriptors name the C++ functions they bind.

Every BoundFuncDesc / PropDescriptor / SignalDesc / ... dynamic initializer in 007e-007f
pushes the API strings ("SetBody", "Brightness", category, parameter names) and the address
of the bound member function(s).  The C++ name usually follows the API name (setBody,
getBrightness/setBrightness); measured on already-named bound functions this convention alone
holds only about half the time, so it is used two ways:
  real     - an unnamed bound function whose exact reloc-masked body twins include exactly one
             symbol with the API-derived leaf (lowerCamel / get / set / is / same) is that symbol
             (two independent signals: API string + identical compiled body);
  inferred - otherwise the API-derived name is recorded as an inferred name (descriptor class
             from the descriptor template argument, which ICF can alias).
Outputs: work/native-client/identity-unlock-reflect.json (real) and
         work/native-client/identity-unlock-reflect-inferred.json
"""
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import identity_unlock_init as I  # noqa: E402
from identity_unlock_common import ROOT, REG, CODE_STARTS, refs, dump_json  # noqa: E402

NC = ROOT / 'work/native-client'
OUT = NC / 'identity-unlock-reflect.json'
OUT_INF = NC / 'identity-unlock-reflect-inferred.json'


def api_leafs(strings):
    out = {}
    for s in strings:
        if not re.match(r'[A-Za-z_]\w*$', s):
            continue
        lo = s[:1].lower() + s[1:]
        for k, v in ((lo, 'lowerCamel'), ('get' + s, 'getter'), ('set' + s, 'setter'), ('is' + s, 'is'), (s, 'same')):
            out.setdefault(k, (v, s))
    return out


def main():
    real = {a: r for a, r in json.load(open(NC / 'unnamed-identities.json')).items()
            if r['name_source'] != 'identity-unlock-reflect'}
    cands = json.load(open(NC / 'identity-unlock-bodyhash-candidates.json'))
    code = {'%08x' % v for v in CODE_STARTS}

    def nm(a):
        if a in real:
            return real[a]['name']
        r = REG.get(a)
        return r['name'] if r and not r.get('placeholder') and not r['name'].startswith('func_') else None

    out, inf = {}, {}
    for a in sorted(REG):
        if not ('007e0000' <= a < '007fa000') or REG[a]['kind'] != 'code':
            continue
        ii = I.body(int(a, 16))
        tmpl, ptrs = None, []
        for i in ii:
            r = refs(i)
            if i.mnemonic == 'call' and r:
                n = nm('%08x' % r[0]) or ''
                m = re.search(r'\?\$(\w+)@V(\w+)@', n)
                if m and ('Desc' in m.group(1) or 'Prop' in m.group(1)):
                    tmpl = (m.group(1), m.group(2))
            if i.mnemonic in ('push', 'mov') and r:
                for v in r:
                    t = '%08x' % v
                    if t in code and REG[t]['kind'] == 'code' and not t.startswith('007'):
                        ptrs.append(t)
        if not tmpl or not ptrs:
            continue
        strings = I.facts(int(a, 16))['strings']
        leafs = api_leafs(strings)
        for t in dict.fromkeys(ptrs):
            if nm(t):
                continue
            hits = [] if len(cands.get(t, [])) >= 10 else [s for s in cands.get(t, []) if (re.match(r'\?(\w+)@', s) or [0, ''])[1] in leafs]
            ev = {'kind': 'reflection-descriptor', 'initializer': a, 'descriptor': tmpl[0],
                  'descriptor_class': tmpl[1], 'api_strings': strings}
            if len(hits) == 1:
                leaf = re.match(r'\?(\w+)@', hits[0]).group(1)
                out[t] = {'name': hits[0], 'owner_class': None, 'signature': None, 'kind': 'code',
                          'name_source': 'identity-unlock-reflect',
                          'evidence': [ev, {'kind': 'exact-masked-body-twin-matches-api-name',
                                            'convention': leafs[leaf][0], 'api_name': leafs[leaf][1],
                                            'other_candidates': [s for s in cands[t] if s != hits[0]][:6]}]}
            else:
                api = next((s for s in reversed(strings) if re.match(r'[A-Z]\w*$', s)), None)
                if api:
                    guess = api[:1].lower() + api[1:] if tmpl[0] == 'BoundFuncDesc' else 'get/set' + api
                    inf[t] = {'name': 'RBX::%s::%s' % (tmpl[1], guess), 'inferred': True,
                              'confidence': 'api-name-convention', 'kind': 'code',
                              'name_source': 'identity-unlock-reflect', 'evidence': [ev]}
    dump_json(out, OUT)
    dump_json(inf, OUT_INF)
    print('real', len(out), 'inferred', len(inf))


if __name__ == '__main__':
    main()
