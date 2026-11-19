"""Read-only, heuristic artifact survey. Findings are candidates, never removal proof."""
import re
from collections import Counter, defaultdict

from common import read, relative, save, sources

PATTERNS = {
    'template_class': r'\btemplate\s+class\s+',
    'template_function': r'(?m)^\s*template\s+(?!class\b|<)[^;\n]+;',
    'codegen_pragma': r'#\s*pragma\s+(?:auto_inline|optimize|intrinsic)\b',
    'noinline': r'__declspec\s*\(\s*noinline\s*\)',
    'placeholder': r'\b(?:FUN_|sub_|func_|LAB_)[0-9a-fA-F]+\b',
    'invented_name_candidate': r'\b(?:Native\w*|recovered\w*)\b',
    'tool_residue': r'\b(?:undefined[1248]?|CONCAT\w*|unaff_\w*|in_stack_\w*)\b|TODO\(llm\)',
    'ghidra_cast': r'\(int\)\s*\(char\)',
    'dead_block': r'#\s*if\s+0\b',
    'scratch_include': r'#\s*include\s*[<"][^>"\n]*\broc_[^>"\n]*[>"]',
    'evidence_comment': r'//[^\n]*(?:Original\s+(?:0x)?[0-9a-fA-F]{6,8}|Batch\s+\d+|\b(?:func_|sub_|FUN_)[0-9a-fA-F]+)',
    'provenance_banner': r'//[^\n]*(?:mined exact|verbatim|generated|roc_[\w-]+)',
    'layout_member': r'\b(?:pad_|field_|unk_)\w*',
    'header_guard': r'#\s*ifndef\s+\w+',
    'stub_candidate': r'\)\s*(?:const\s*)?\{\s*(?:return\s+(?:0|false|NULL|nullptr)\s*;\s*)?\}',
}


def strip_comments(text):
    return re.sub(r'//[^\n]*|/\*.*?\*/', lambda m: '\n' * m[0].count('\n'), text, flags=re.S)


def definitions(text):
    # Conservative signatures only; overload/namespace/template resolution needs compiler proof.
    code = strip_comments(text)
    return [re.sub(r'\s+', ' ', m[1]).strip() for m in re.finditer(
        r'(?m)^\s*([^#;{}\n]+\b\w+::~?\w+\s*\([^;{}]*\)\s*(?:const\s*)?)\{', code)]


def survey():
    findings, signatures, headers = [], defaultdict(list), defaultdict(list)
    header_stems = {p.stem.lower() for p in sources() if p.suffix in ('.h', '.hpp')}
    styles = {}
    for path in sources():
        name, text = relative(path), read(path)
        code = strip_comments(text)
        styles[name] = {'tab_indented_lines': len(re.findall(r'(?m)^\t+\S', text)),
                        'space_indented_lines': len(re.findall(r'(?m)^ +\S', text)),
                        'namespace_same_line': len(re.findall(r'\bnamespace\s+\w+\s*\{', code)),
                        'pragma_once': bool(re.search(r'#\s*pragma\s+once\b', code)),
                        'crlf': b'\r\n' in path.read_bytes()}
        if path.suffix == '.cpp':
            for match in re.finditer(r'\b(?:class|struct)\s+(\w+)\s*(?::[^;{]+)?\{', code):
                if match[1].lower() in header_stems:
                    findings.append({'file': name, 'line': code.count('\n', 0, match.start()) + 1,
                                     'category': 'local_type_copy_candidate', 'text': match[1]})
        if re.search(r'AppUnit|AppLeaves2008|2008|Mined|vendor_i|roc_|[0-9a-f]{12,}', path.name) or 'accepted' in path.parts:
            findings.append({'file': name, 'line': 1, 'category': 'recovery_filename'})
        for category, pattern in PATTERNS.items():
            subject = text if category in ('evidence_comment', 'provenance_banner') else code
            for match in re.finditer(pattern, subject):
                findings.append({'file': name, 'line': subject.count('\n', 0, match.start()) + 1,
                                 'category': category, 'text': match[0][:180]})
        if path.suffix in ('.h', '.hpp'):
            headers[path.name.lower()].append(name)
        includes = re.findall(r'#\s*include\s*[<"]([^>"\n]+)', code)
        if path.suffix == '.cpp' and includes and path.stem.lower() != includes[0].replace('\\', '/').split('/')[-1].rsplit('.', 1)[0].lower():
            findings.append({'file': name, 'line': 1, 'category': 'own_header_first_candidate', 'text': includes[0]})
        for sig in definitions(text):
            signatures[sig].append(name)
    counts = Counter(f['category'] for f in findings)
    filecounts = {k: len({f['file'] for f in findings if f['category'] == k}) for k in counts}
    return {'heuristic': True, 'files': len(sources()), 'occurrences': dict(counts),
            'files_by_category': filecounts, 'findings': findings, 'style_observations': styles,
            'duplicate_header_names': {k: v for k, v in headers.items() if len(v) > 1},
            'duplicate_definition_candidates': {k: sorted(set(v)) for k, v in signatures.items() if len(set(v)) > 1},
            'limitations': ['Regex candidates are not semantic C++ definitions or proof of dead/stub code.',
                            'Native/recovered identifiers may be authentic; review evidence before renaming.',
                            'Style observations require review against each original project area.']}


if __name__ == '__main__':
    result = survey()
    save('lint-report.json', result)
    print(result['files'], 'files;', result['files_by_category'])
