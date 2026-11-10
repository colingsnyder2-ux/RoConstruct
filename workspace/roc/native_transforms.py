"""Conservative source-shaped trial generation. Only normal exact gates promote trials."""
import re


def templates(text, spelling):
    """Balanced template arguments, retaining offsets into the original text."""
    from roc.native_sweep import masked_cpp
    clean = masked_cpp(text)
    for found in re.finditer(re.escape(spelling) + r'\s*<', clean):
        start, depth, args, last = found.end(), 1, [], found.end()
        for i in range(start, len(clean)):
            c = clean[i]
            if c == '<':
                depth += 1
            elif c == '>':
                depth -= 1
                if not depth:
                    args.append(text[last:i].strip())
                    yield found.start(), i + 1, args
                    break
            elif c == ',' and depth == 1:
                args.append(text[last:i].strip())
                last = i + 1


def method_variants(text, selected=None, context='', modes=None):
    """One method/one hypothesis. No guessed types, headers, constants or declarations."""
    from roc.native_sweep import methods, masked_cpp, closing
    wanted = set(('map-value-type', 'temporary-inline', 'temporary-name', 'scope-lifetime', 'expression-grouping') if modes is None else modes)
    maps = {}
    declarations = context + '\n' + text
    for _, end, args in templates(declarations, 'std::map'):
        name = re.match(r'\s*(\w+)\s*[;=({]', masked_cpp(declarations[end:]))
        if name and len(args) >= 2:
            maps.setdefault(name[1], set()).add(tuple(args[:2]))
    for method, (start, finish) in methods(text).items():
        if selected is not None and method not in selected:
            continue
        body, clean = text[start:finish], masked_cpp(text[start:finish])
        if 'map-value-type' in wanted:
            for left, end, args in templates(body, 'std::pair'):
                if len(args) != 2 or args[0].startswith('const '):
                    continue
                call = re.search(r'\b(\w+)\s*\.\s*insert\s*\(\s*$', clean[:left])
                if not call or maps.get(call[1]) != {tuple(args)}:
                    continue
                new = body[:left] + 'std::pair<const %s, %s>' % tuple(args) + body[end:]
                yield 'map-value-type:' + method, text[:start] + new + text[finish:], [[body, new]]
                open_args = re.match(r'\s*\(', clean[end:])
                if open_args:
                    opening = end + open_args.end() - 1
                    closing_args = closing(clean, opening, '(', ')')
                    tail = re.match(r'\s*\)\s*;', clean[closing_args + 1:])
                    if tail and 'rocMapEntry' not in clean:
                        last = closing_args + 1 + tail.end()
                        expression = body[opening + 1:closing_args]
                        replacement = '{ std::pair<const %s, %s> rocMapEntry(%s); %s.insert(rocMapEntry); }' % (*args, expression, call[1])
                        new = body[:call.start()] + replacement + body[last:]
                        yield 'map-value-entry:' + method, text[:start] + new + text[finish:], [[body, new]]
        # Keep simple single declarations; references/arrays/auto, pointers and control headers defer.
        pattern = r'(?m)(?:^|(?<=[;{}]))\s*([A-Za-z_]\w*(?:::\w+)*(?:<[^;{}]+>)?)\s+(\w+)\s*=\s*([^;{}]+);'
        for declaration in re.finditer(pattern, clean):
            kind, name = declaration[1], declaration[2]
            if kind in ('return', 'const', 'static', 'volatile', 'auto') or re.search(r'\b(?:goto|case)\b', clean):
                continue
            expression = body[declaration.start(3):declaration.end(3)]
            uses = list(re.finditer(r'\b' + re.escape(name) + r'\b', clean[declaration.end():]))
            if not uses:
                continue
            tail_start = declaration.end()
            use_end = tail_start + uses[-1].end()
            statement_end = clean.find(';', use_end)
            if statement_end < 0:
                continue
            region = clean[tail_start:statement_end + 1]
            if any(c in region for c in '{}') or re.search(r'\b(?:return|throw|break|continue)\b', region):
                continue
            if 'temporary-inline' in wanted and len(uses) == 1 and region.count(';') == 1:
                use_start = tail_start + uses[0].start()
                # No write/reference escape: these candidates move a value expression, not storage.
                if re.search(r'&\s*' + re.escape(name) + r'\b|\b' + re.escape(name) + r'\s*(?:[+*/-]?=|\+\+|--)', region):
                    continue
                new = (body[:declaration.start()] + body[declaration.end():use_start]
                       + '(' + expression + ')' + body[use_end:])
                yield 'temporary-inline:' + method, text[:start] + new + text[finish:], [[body, new]]
            if 'scope-lifetime' in wanted and clean[statement_end + 1:].strip() != '}':
                # Last lexical use is inside this block; lifetime shortening remains a trial only.
                new = body[:declaration.start()] + '{' + body[declaration.start():statement_end + 1] + '}' + body[statement_end + 1:]
                yield 'scope-lifetime:' + method, text[:start] + new + text[finish:], [[body, new]]
        if 'expression-grouping' in wanted:
            for expr in re.finditer(r'\b([A-Za-z_]\w*)\s*([+*])\s*([A-Za-z_]\w*)\s*\2\s*([A-Za-z_]\w*)\b', clean):
                for grouped in ('(%s %s %s) %s %s', '%s %s (%s %s %s)'):
                    replacement = grouped % (expr[1], expr[2], expr[3], expr[2], expr[4])
                    new = body[:expr.start()] + replacement + body[expr.end():]
                    yield 'expression-grouping:' + method, text[:start] + new + text[finish:], [[body, new]]
        if 'temporary-name' in wanted and 'rocExpression' not in clean:
            line = max(text.rfind(c, 0, start) for c in ('\n', ';', '{', '}')) + 1
            kind = text[line:start].strip()
            if re.fullmatch(r'(?:unsigned\s+|signed\s+)?[A-Za-z_]\w*(?:::\w+)*(?:<[^;{}]+>)?', kind) and kind != 'void':
                for statement in re.finditer(r'\breturn\s+([^;{}]+);', clean):
                    value = body[statement.start(1):statement.end(1)]
                    new = body[:statement.start()] + '{ %s rocExpression = %s; return rocExpression; }' % (kind, value) + body[statement.end():]
                    yield 'temporary-name:' + method, text[:start] + new + text[finish:], [[body, new]]


def proven_variants(text, facts, rel):
    """Use explicit binary/source evidence for constants, visible callees and template emission."""
    from roc.native_sweep import apply_edits
    from roc.integration import validate_patches
    for fact in facts:
        if fact.get('file') != rel or not fact.get('evidence') or not fact.get('target'):
            continue
        kind = fact.get('kind')
        edits = fact.get('edits')
        if kind == 'immediate':
            # The caller supplies an exact source anchor plus decoded target value, not a global replacement.
            if not isinstance(fact.get('value'), int) or not isinstance(fact.get('source_value'), str):
                continue
            old = fact.get('anchor', '')
            if not old or old.count(fact['source_value']) != 1:
                continue
            edits = [[old, old.replace(fact['source_value'], str(fact['value']), 1)]]
        elif kind not in ('visible-callee', 'template-emission'):
            continue
        if not edits:
            continue
        try:
            validate_patches({rel: edits})
            changed = apply_edits(text, edits)
        except ValueError:
            continue
        yield 'proven-' + kind + ':' + str(fact['target']), changed, edits


def sibling_variants(texts, winner, original):
    """Propagate winning token edits to methods with the same token sequence modulo identifiers."""
    from roc.native_sweep import methods, masked_cpp, apply_edits
    tokens = lambda text: re.findall(r'[A-Za-z_]\w*|0x[0-9a-fA-F]+|\d+(?:\.\d+)?|[^\s]', masked_cpp(text))
    def shape(items):
        names = {}
        keywords = {'return', 'if', 'else', 'for', 'while', 'const', 'void', 'int', 'float', 'double', 'unsigned', 'std', 'this', 'new', 'delete', 'class', 'struct', 'template', 'bool', 'true', 'false'}
        return tuple(names.setdefault(t, 'id%d' % len(names)) if re.fullmatch(r'[A-Za-z_]\w*', t) and t not in keywords else t for t in items)
    for before, after in winner['edits']:
        source_methods = methods(original)
        match_method = next((m for m, (a, b) in source_methods.items() if original[a:b] == before), None)
        if match_method is None:
            continue
        old_tokens = tokens(before)
        for rel, source in texts.items():
            for method, (a, b) in methods(source).items():
                if rel == winner['file'] and method == match_method:
                    continue
                target = source[a:b]
                target_tokens = tokens(target)
                if shape(old_tokens) != shape(target_tokens):
                    continue
                bindings = dict(zip(old_tokens, target_tokens))
                # Only identifiers already present in the proven source can be rebound.
                clean = masked_cpp(after)
                translated = after
                for found in reversed(list(re.finditer(r'[A-Za-z_]\w*', clean))):
                    translated = translated[:found.start()] + bindings.get(found[0], found[0]) + translated[found.end():]
                edits = [[target, translated]]
                try:
                    changed = apply_edits(source, edits)
                except ValueError:
                    continue
                yield rel, 'sibling:' + method, changed, edits


def immediate_variants(text, diagnostics):
    from roc.native_sweep import methods, symbol_method, masked_cpp
    spans = methods(text)
    for addr, row in diagnostics.items():
        method = symbol_method(row.get('symbol', ''))
        if method not in spans:
            continue
        a, b = spans[method]
        body = text[a:b]
        for fact in row.get('immediates', []):
            candidates = [m for m in re.finditer(r'(?<![\w.])-?(?:0x[0-9a-fA-F]+|\d+)(?![\w.])', masked_cpp(body))
                          if int(m[0], 0) == fact['compiled_value']]
            if len(candidates) != 1:
                continue
            found = candidates[0]
            new = body[:found.start()] + str(fact['value']) + body[found.end():]
            yield 'target-immediate:' + addr, text[:a] + new + text[b:], [[body, new]]


def changed_methods(original, candidate):
    from roc.native_sweep import methods
    before, after = methods(original), methods(candidate)
    return {name for name, (a,b) in before.items()
            if name not in after or original[a:b] != candidate[after[name][0]:after[name][1]]}


def callee_facts(texts, homes, names, by_addr, client='2008-06', limit=3):
    """Expose available genuine exact native callees at callers that actually reference them."""
    from roc import match
    from roc.native_sweep import methods, symbol_method, target_files, masked_cpp
    result = []
    for rel, addresses in homes.items():
        text = texts[rel]
        spans = methods(text)
        for addr in addresses[:3]:
            caller = symbol_method(names.get(addr, {}).get('symbol', ''))
            if caller not in spans:
                continue
            code = match.target(client, addr)[0]
            calls = list(dict.fromkeys(found[1].lower().zfill(8) for line in match.disasm(code, int(addr,16))
                if (found := re.search(r'\bcall 0x([0-9a-fA-F]+)\s*$', line))))
            exact = {a for a in calls if names.get(a,{}).get('score') == 100 and by_addr.get(a,{}).get('unit','').startswith('RBX::')}
            sources = target_files(texts, exact, names, by_addr)
            a, b = spans[caller]
            clean = masked_cpp(text)
            a = max(clean.rfind(c,0,a) for c in ('\n',';','{','}'))+1
            anchor = text[a:b]
            count = 0
            for origin, callees in sources.items():
                if origin == rel:
                    continue
                native = texts[origin]
                callee_spans = methods(native)
                for callee in callees:
                    method = symbol_method(names[callee]['symbol'])
                    if method not in callee_spans or method in spans:
                        continue
                    left, right = callee_spans[method]
                    masked = masked_cpp(native)
                    left = max(masked.rfind(c,0,left) for c in ('\n',';','{','}'))+1
                    definition = native[left:right].strip()
                    if '#' in definition.split('{',1)[0] or definition.startswith('template'):
                        continue
                    definition = definition if definition.startswith('inline ') else 'inline '+definition
                    result.append(dict(file=rel, kind='visible-callee', target=callee,
                        required_symbol=names[callee]['symbol'], definition=definition,
                        evidence=dict(source_file=origin, native_score=100, caller=addr, symbol=names[callee]['symbol']),
                        edits=[[anchor, '\n'+definition+'\n'+anchor]]))
                    count += 1
                    if count >= limit:
                        break
                if count >= limit:
                    break
    return result


def template_variants(text, context):
    """Explicit factory instantiations only when genuine headers prove the zero-arg T* signature."""
    from roc.native_sweep import masked_cpp
    clean = masked_cpp(context)
    factory = re.search(r'template\s*<\s*(?:class|typename)\s+(\w+)\s*>\s*\1\s*\*\s*create\s*\(\s*\)\s*const', clean)
    if not factory or not re.search(r'\bclass\s+ServiceProvider\b', clean):
        return
    for found in re.finditer(r'\bServiceProvider::create\s*<\s*([A-Za-z_]\w*(?:::\w+)*)\s*>\s*\(', masked_cpp(text)):
        declaration = 'template __declspec(noinline) %s* ServiceProvider::create<%s>() const;' % (found[1],found[1])
        namespace = re.search(r'\bnamespace\s+RBX\s*\{', masked_cpp(text))
        if not namespace or declaration in text:
            continue
        anchor = text[:namespace.end()]
        edits = [[anchor,anchor+'\n'+declaration+'\n']]
        yield 'template-emission:'+found[1], edits[0][1]+text[namespace.end():], edits
