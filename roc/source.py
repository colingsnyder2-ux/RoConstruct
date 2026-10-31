"""Human-readable implementation views, separate from reproducible build pointers."""
import json
from pathlib import Path
from roc import libs, match

ROOT = Path(__file__).resolve().parents[1]


def resolve(client, addr, root=ROOT):
    addr = '%08x' % int(addr, 16)
    wrapper = Path(root)/'src'/client/(addr+'.cpp')
    text = wrapper.read_text(encoding='utf-8-sig', errors='replace')
    directives = match.directives(text)
    result = dict(client=client, addr=addr, build_pointer=str(wrapper), wrapper=text,
                  source=text, source_path=str(wrapper), kind='inline')
    if 'archive' in directives:
        result.update(kind='archive', warning='Archive object reference; C++ implementation not available here.')
    if 'lib' not in directives:
        return result
    recipe, _, relative = directives['lib'].partition(' ')
    definition = libs.RECIPES[recipe]
    folder = libs._case_path(Path(root)/'tools/libs'/definition['src']).resolve()
    path = (folder/relative.strip().replace('\\','/')).resolve()
    if not path.is_relative_to(folder):
        raise ValueError('Implementation path escapes recipe directory')
    body = path.read_text(encoding='utf-8-sig', errors='replace') if path.is_file() else libs.generated_units().get(definition['src'], {}).get(relative.strip())
    if body is None:
        raise RuntimeError('Implementation missing: %s; run roc pull or fetch recipe %s' % (path, recipe))
    result.update(source=body, source_path=str(path), recipe=recipe, kind='library',
                  scope='complete implementation unit; may contain several functions')
    return result


def command(args):
    result = resolve(args.client, args.addr)
    if args.json:
        content = json.dumps(result, indent=2)
    else:
        content = '// Implementation: %s\n// Build pointer preserved: %s\n%s' % (
            result['source_path'], result['build_pointer'], result['source'])
    if args.output:
        path = Path(args.output)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content, encoding='utf-8')
        print(path.resolve())
    else:
        print(content)
