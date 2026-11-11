"""Bounded native transplant repair; native byte/reference proof remains authoritative."""
import argparse
import contextlib
import io
import itertools
import hashlib
import json
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
import analog_to_native as transplant


def write(path, text):
    path.write_bytes(text.replace('\r\n', '\n').replace('\n', '\r\n').encode())


def includes(text, errors):
    """Only include headers that exist; never synthesize declarations from guesses."""
    names = set(re.findall(r"(?:undefined type|undeclared identifier)\s*'([^']+)'", errors))
    names.update(re.findall(r"'([^']+)'\s*:\s*(?:undefined type|undeclared identifier)", errors))
    additions = []
    for name in sorted(names):
        leaf = name.rsplit('::', 1)[-1]
        if not re.fullmatch(r'\w+', leaf):
            continue
        candidates = [(transplant.OGRE_INC / ('Ogre' + leaf + '.h'), '<Ogre' + leaf + '.h>')]
        for directory in (transplant.HEADERS / 'G3D', ROOT / 'tools/libs/g3d-6.09/source/include/G3D'):
            candidates.append((directory / (leaf + '.h'), '"G3D/' + leaf + '.h"'))
        # Native headers may define types in differently named files.
        for path in sorted(transplant.HEADERS.rglob('*.h')):
            if re.search(r'\b(?:class|struct)\s+' + re.escape(leaf) + r'\s*(?:[:{])', path.read_text(errors='replace')):
                candidates.append((path, '"' + path.relative_to(transplant.HEADERS).as_posix() + '"'))
        for path, spelling in candidates:
            if path.is_file():
                line = '#include ' + spelling
                if line not in text and line not in additions:
                    additions.append(line)
                break
    if additions:
        matches = list(re.finditer(r'^\s*#include[^\n]*\n', text, re.M))
        at = matches[-1].end() if matches else 0
        text = text[:at] + '\n'.join(additions) + '\n' + text[at:]
    if re.search(r'C2589|C2059', errors) and re.search(r'\b(?:min|max)\b', errors) and '#define NOMINMAX' not in text:
        text = '#define NOMINMAX\n' + text
    return text




def model_body(model, prompt, owner, method):
    import native_llm as nl
    started = time.time()
    with (HERE / 'fix-loop-models.jsonl').open('a') as log:
        log.write(json.dumps({'model': model, 'method': owner + '::' + method, 'event': 'started', 'timestamp': started}) + '\n')
    try:
        if model.endswith('#medium'):
            from roc import providers
            try:
                reply = providers.generate(model.removesuffix('#medium'), prompt,
                    {'allow_cloud': True, 'timeout': 120, 'max_tokens': 4096, 'reasoning_effort': 'medium'}).text
            except providers.ProviderError:
                reply = ''
            blocks = re.findall(r'```(?:cpp|c\+\+)?\s*\n(.*?)```', reply or '', re.S)
            body = blocks[-1] if blocks else reply
        else:
            body = nl.ask(model, prompt, method)
    except subprocess.TimeoutExpired:
        return None
    with (HERE / 'fix-loop-models.jsonl').open('a') as log:
        log.write(json.dumps({'model': model, 'method': owner + '::' + method, 'event': 'returned', 'has_reply': bool(body), 'seconds': round(time.time() - started, 1)}) + '\n')
    if not body:
        return None
    replies = HERE / 'fix-loop-model-replies'
    replies.mkdir(exist_ok=True)
    write(replies / (str(time.time_ns()) + '.cpp'), body)
    if re.search(r'cannot reconstruct|cannot faithfully|provide.*(?:declarations|headers)|missing.*(?:APIs|declarations)', body, re.I | re.S):
        raise RuntimeError('missing native evidence: ' + body.strip().replace('\n', ' ')[:400])
    # Accept harmless namespace wrappers, but extract exactly one target definition.
    if re.search(r'\b(?:__emit|_emit)\b|^\s*#|\bextern\b', body, re.M):
        return None
    definition_pattern = re.compile(transplant.DEF.pattern.replace('^(', r'^[ \t]*(', 1), re.M)
    definitions = list(definition_pattern.finditer(body))
    if len(definitions) != 1:
        return None
    definition = definitions[0]
    if definition.group(3) != owner.rsplit('::', 1)[-1] or definition.group(4) != method:
        return None
    extracted = transplant.block(body, definition.start())
    outside = body[:definition.start()] + body[definition.start() + len(extracted):]
    outside = re.sub(r'//[^\n]*|/\*.*?\*/', '', outside, flags=re.S)
    outside = re.sub(r'namespace\s+\w+\s*\{', '', outside)
    if outside.replace('}', '').strip():
        return None
    at = definition.start(2) - definition.start()
    end = definition.end(4) - definition.start()
    return extracted[:at] + owner + '::' + method + extracted[end:]


def inferred_globals(text, errors, donor):
    """Reuse donor extern types; infer bool only from explicit bool assignments."""
    names = re.findall(r"'([A-Za-z_]\w*)'\s*:\s*undeclared identifier", errors)
    declarations = []
    for name in sorted(set(names)):
        # Members, calls, types and raw-offset placeholders are not global evidence.
        if re.search(r'(?:->|\.|::)\s*' + re.escape(name) + r'\b', text):
            continue
        declaration = re.search(r'\bextern\s+([^;{}()]+?)\s+' + re.escape(name) + r'\s*;', donor)
        if declaration:
            typename = declaration.group(1).strip()
        elif re.search(r'\b' + re.escape(name) + r'\s*=\s*(?:true|false)\s*;', donor):
            typename = 'bool'
        else:
            continue
        declarations.append('// INFERRED: analog global declaration/boolean assignment requires reference proof.\nextern '
                            + typename + ' ' + name + ';')
    if not declarations:
        return text
    # Put declarations in the same namespace as the transplanted method.
    marker = re.search(r'// [0-9a-f]{8}: transplanted[^\n]*\n', text)
    if not marker:
        return text
    tail = text[marker.end():]
    namespaces = re.match(r'(?:namespace \w+ \{\n)*', tail)
    at = marker.end() + namespaces.end()
    return text[:at] + '\n'.join(declarations) + '\n' + text[at:]


def compile_errors(path):
    logs = list((HERE / 'prove-out' / ('prove-' + path.stem)).glob('objects/*/*.log'))
    if not logs:
        return ''
    return '\n'.join(line for line in max(logs, key=lambda p: p.stat().st_mtime_ns).read_text(errors='replace').splitlines() if ' error ' in line or 'fatal error' in line)




def byte_feedback(source, addr, method):
    proof = HERE / 'prove-out' / ('prove-' + Path(source).stem)
    manifest = proof / 'manifest.json'
    if not manifest.is_file():
        return ''
    data = json.loads(manifest.read_text())
    rows = [row for family in data.get('families', []) for row in family.get('symbols', [])
            if row.get('symbol', '').startswith('?' + method + '@')]
    objects = list(proof.glob('objects/*/candidate.obj'))
    if len(rows) != 1 or not objects:
        return 'No unique compiled target symbol for byte comparison.'
    obj = max(objects, key=lambda path: path.stat().st_mtime_ns)
    result = subprocess.run([sys.executable, 'roc.py', 'native-asm', '2008-06', addr,
        '--obj', str(obj), '--sym', rows[0]['symbol'], '--context', '1', '--head', '40'],
        cwd=ROOT, capture_output=True, text=True)
    return (result.stdout + result.stderr)[-12000:]



def near_target_size(source, addr, method):
    manifest = HERE / 'prove-out' / ('prove-' + Path(source).stem) / 'manifest.json'
    if not manifest.is_file():
        return False
    data = json.loads(manifest.read_text())
    target = transplant.match._functions('2008-06')[addr]['size']
    return any(row.get('symbol', '').startswith('?' + method + '@') and row.get('size') is not None
               and abs(row['size'] - target) <= target * .05
               for family in data.get('families', []) for row in family.get('symbols', []))



def header_context(header, limit=100000):
    """Include reachable native declarations, not just the receiver's header."""
    pending = [ROOT / header]
    seen = set()
    chunks = []
    used = 0
    while pending:
        path = pending.pop(0)
        if path in seen or not path.is_file():
            continue
        seen.add(path)
        text = path.read_text(errors='replace')
        if used + len(text) > limit:
            chunks.append('\n// Context budget reached before ' + str(path) + '\n')
            continue
        chunks.append('\n// HEADER ' + str(path) + '\n' + text)
        used += len(text)
        for include in re.findall(r'^\s*#include\s*[<"]([^>"]+)[>"]', text, re.M):
            child = transplant.HEADERS / include
            if child.is_file():
                pending.append(child)
    return ''.join(chunks)


def header_dependents(header):
    """Compiler-recorded dependencies include indirect header users."""
    result = set()
    key = str(header.resolve()).casefold()
    for cache in (HERE / 'prove-cache').glob('*.json'):
        row = json.loads(cache.read_text())
        if any(str(Path(dep).resolve()).casefold() == key for dep in row.get('dependencies', {})):
            source = Path(row['source'])
            if source.is_file():
                result.add(source)
    include = header.relative_to(transplant.HEADERS).as_posix()
    for source in transplant.CLASSES.glob('*.cpp'):
        if re.search(r'#include\s*[<"]' + re.escape(include) + r'[>"]', source.read_text(errors='replace')):
            result.add(source)
    return sorted(result)


def run_target(addr, max_attempts=None, budget_seconds=1500, models=None):
    deadline = time.monotonic() + budget_seconds
    targets = transplant.transplant_targets([addr])
    if not targets:
        return 'blocked: no eligible declared native destination (or already implemented)'
    _, owner, leaf, method, dest = targets[0]
    import ogre_llm_lane as lane
    header = lane.class_header(leaf, method)
    if header and owner.startswith('RBX::View::'):
        declarations = (ROOT / header).read_text(errors='replace')
        if re.search(r'namespace\s+ViewNew\s*\{', declarations) and not re.search(r'namespace\s+View\s*\{', declarations):
            # Native class declarations govern source namespace; registry remains unchanged.
            owner = owner.replace('RBX::View::', 'RBX::ViewNew::', 1)
    path = ROOT / dest
    lease = 'fix-loop-' + addr
    command = [sys.executable, 'roc.py', 'lease']
    taken = subprocess.run(command + ['take', lease, dest, '--hours', '2'], cwd=ROOT, capture_output=True, text=True)
    if taken.returncode:
        return 'blocked: source lease refused'
    original = path.read_bytes()
    original_prove = transplant.prove

    def prove(source):
        if Path(source) == path and ('// %s: transplanted' % addr) in Path(source).read_text():
            trial[:] = [Path(source).read_text()]
        run = subprocess.run([sys.executable, str(HERE / 'prove.py'), str(source),
                              '--infer-names', '--rounds', '3', '--why', ''],
                             cwd=ROOT, capture_output=True, text=True)
        if run.returncode:
            raise RuntimeError('proof command failed: ' + (run.stderr or run.stdout)[-1000:])
        return run.returncode, (run.stdout + run.stderr).splitlines()
    attempts = []
    header_originals = {}
    header_leases = []
    sibling_baselines = {}
    trial = []
    baseline = transplant.exact_addrs(path)

    def repair_prove(source):
        prove(source)
        if ('// %s: transplanted' % addr) not in Path(source).read_text():
            return
        trial[:] = [Path(source).read_text()]
        # A deterministic pass is a hypothesis only when it changes source.
        for _ in range(3):
            trial[:] = [Path(source).read_text()]
            errors = compile_errors(Path(source))
            if not errors:
                break
            text = Path(source).read_text()
            fixed = includes(text, errors)
            donor = (transplant.ANALOGS / (addr + '.cpp')).read_text(errors='replace')
            fixed = inferred_globals(fixed, errors, donor)
            # Access errors name the declaring class; only edit an unambiguous native definition.
            for declaring in re.findall(r"declared in class '([^']+)'", errors):
                if 'C2248' not in errors:
                    continue
                member_leaf = declaring.rsplit('::', 1)[-1]
                found = []
                for candidate in transplant.HEADERS.rglob('*.h'):
                    content = candidate.read_text(errors='replace')
                    definition = re.search(r'\b(?:class|struct)\s+' + re.escape(member_leaf)
                                           + r'\s*(?:\:[^{;]+)?\{', content)
                    if definition:
                        found.append((candidate, content, definition.end()))
                if len(found) != 1:
                    continue
                candidate, content, at = found[0]
                friend = 'friend class ::' + owner + ';'
                if friend in content:
                    continue
                header_lease = lease + '-header-' + str(len(header_leases))
                result = subprocess.run(command + ['take', header_lease,
                    candidate.relative_to(ROOT).as_posix(), '--hours', '2'],
                    cwd=ROOT, capture_output=True, text=True)
                if result.returncode:
                    continue
                header_leases.append(header_lease)
                for sibling in header_dependents(candidate):
                    if sibling == path or sibling in sibling_baselines:
                        continue
                    prove(sibling)
                    sibling_baselines[sibling] = transplant.exact_addrs(sibling)
                header_originals.setdefault(candidate, candidate.read_bytes())
                write(candidate, content[:at] + '\n    ' + friend + '\n' + content[at:])
                fixed += '\n'  # Force reproof after a header-only fix.
            if fixed == text:
                break
            attempts.append(errors.splitlines()[0])
            write(Path(source), fixed)
            prove(source)

        # Existing provider client handles credentials, quotas and fenced replies.
        if addr in transplant.exact_addrs(Path(source)) or (max_attempts is not None and len(attempts) >= max_attempts) or time.monotonic() >= deadline:
            return
        import native_llm as nl
        import ogre_llm_lane as lane
        header = lane.class_header(leaf, method)
        if not header:
            return
        errors = compile_errors(Path(source))
        text = Path(source).read_text()
        marker = '// %s: transplanted' % addr
        if marker not in text:
            return  # Baseline proof: no target body has been appended yet.
        prefix = text[:text.index(marker)]
        prompt = ('Repair one native C++ method. Output only its fully qualified definition in a cpp fence. '
                  'Use authentic header members. No raw offsets, stubs, byte blobs or invented fields. '
                  'Preserve semantics. Do not redefine types.\nHEADER:\n'
                  + header_context(header) + '\nDONOR/TRIAL:\n'
                  + text[text.index(marker):] + '\nCOMPILE ERRORS:\n' + errors)
        cheap = [m for m in nl.LADDER if m.startswith(('nvidia:', 'opencode'))]
        cheap += ['codex:gpt-6-luna']
        if models:
            cheap = models
        requests = set()
        candidates = set()
        strong_tried = False
        base_prompt = prompt
        if not errors:
            prompt += '\nBYTE DIFF:\n' + byte_feedback(source, addr, method)
        for model in itertools.cycle(cheap):
            if (max_attempts is not None and len(attempts) >= max_attempts) or time.monotonic() >= deadline:
                break
            if model in nl.EXHAUSTED:
                if all(candidate in nl.EXHAUSTED for candidate in cheap):
                    break
                continue
            if not models and not strong_tried and not compile_errors(Path(source)) and near_target_size(source, addr, method):
                model = 'codex:gpt-6.1-terra'
                strong_tried = True
            prompt_hash = hashlib.sha256(prompt.encode()).hexdigest()
            request = (model, prompt_hash)
            if request in requests:
                if all((candidate, prompt_hash) in requests for candidate in cheap):
                    raise RuntimeError('providers exhausted unchanged evidence; no identical request retry')
                continue
            requests.add(request)
            body = model_body(model, prompt, owner, method)
            if not body:
                time.sleep(1)
                continue
            digest = hashlib.sha256(body.encode()).hexdigest()
            if digest in candidates:
                raise RuntimeError('model repeated a rejected candidate; new evidence required')
            candidates.add(digest)
            attempts.append('repair model: ' + model)
            write(Path(source), prefix + 'namespace ' + owner.split('::')[0] + ' {\n' + body + '\n}\n')
            trial[:] = [Path(source).read_text()]
            _, feedback = prove(source)
            if addr in transplant.exact_addrs(Path(source)):
                break
            prompt = base_prompt + '\nPREVIOUS REWRITE:\n' + body + '\nPROOF FEEDBACK:\n' + '\n'.join(feedback[-25:]) + '\nCOMPILE ERRORS:\n' + compile_errors(Path(source))
            if not compile_errors(Path(source)):
                prompt += '\nBYTE DIFF:\n' + byte_feedback(source, addr, method)
        if addr in transplant.exact_addrs(Path(source)) or (max_attempts is not None and len(attempts) >= max_attempts) or time.monotonic() >= deadline:
            return
        trial[:] = [Path(source).read_text()]

    try:
        transplant.prove = repair_prove
        with contextlib.redirect_stdout(io.StringIO()):
            result = transplant.transplant(addr, owner, leaf, method, dest)
        if result.startswith('exact'):
            prove(path)
            if addr not in transplant.exact_addrs(path) or not baseline <= transplant.exact_addrs(path):
                result = 'reverted: final destination reproof lost target or baseline'
        if result.startswith('exact'):
            for sibling, previous in sibling_baselines.items():
                prove(sibling)
                if not previous <= transplant.exact_addrs(sibling) or compile_errors(sibling):
                    result = 'reverted: shared header regressed sibling ' + sibling.name
                    break
        if not result.startswith('exact'):
            path.write_bytes(original)
            for header_path, saved in header_originals.items():
                header_path.write_bytes(saved)
            parked = HERE / 'fix-loop-parked'
            parked.mkdir(exist_ok=True)
            proof_dir = HERE / 'prove-out' / ('prove-' + path.stem)
            manifest = proof_dir / 'manifest.json'
            if manifest.is_file():
                shutil.copy2(manifest, parked / (addr + '-manifest.json'))
            logs = list(proof_dir.glob('objects/*/*.log'))
            if logs:
                shutil.copy2(max(logs, key=lambda item: item.stat().st_mtime_ns), parked / (addr + '-compile.log'))
            write(parked / (addr + '.cpp'), '// PARKED: ' + result.replace('\n', ' ') + '\n' + (trial[-1] if trial else path.read_text()))
            evidence = {'addr': addr, 'owner': owner, 'destination': dest, 'status': 'parked', 'reason': result, 'hypotheses': attempts}
            with (HERE / 'fix-loop.jsonl').open('a') as log:
                log.write(json.dumps(evidence) + '\n')
            with (HERE / 'CLAUDE_HANDOFF.md').open('a') as handoff:
                handoff.write('\n- PARKED fix_loop ' + addr + ' (' + owner + '): ' + result.replace('\n', ' ')
                              + '; rejected repair hypotheses=' + str(len(attempts))
                              + '; trial: work/native-client/fix-loop-parked/' + addr + '.cpp. Native source/header bytes restored.\n')
        return result
    except BaseException:
        # Interrupts must restore the transaction as well as ordinary failures.
        path.write_bytes(original)
        for header_path, saved in header_originals.items():
            header_path.write_bytes(saved)
        raise
    finally:
        transplant.prove = original_prove
        for header_lease in header_leases:
            subprocess.run(command + ['release', header_lease], cwd=ROOT, capture_output=True)
        subprocess.run(command + ['release', lease], cwd=ROOT, capture_output=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('addresses', nargs='+')
    parser.add_argument('--attempts', type=int, default=None, help='optional cap; default unlimited')
    parser.add_argument('--minutes', type=float, default=25)
    parser.add_argument('--model', action='append', help='override repair ladder; suffix #medium sets medium effort')
    args = parser.parse_args()
    for addr in args.addresses:
        if not re.fullmatch(r'[0-9a-fA-F]{8}', addr):
            parser.error('addresses must contain eight hexadecimal digits')
    for addr in args.addresses:
        try:
            result = run_target(addr.lower(), args.attempts, args.minutes * 60, args.model)
        except (RuntimeError, OSError) as error:
            result = 'blocked: ' + str(error).replace('\n', ' ')[:500]
        print(addr.lower(), result, flush=True)


if __name__ == '__main__':
    main()
