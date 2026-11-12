"""Validation for server-generated native library build and executable proofs.

This gate does not accept submissions or grant credit. Its inputs must come from
the server's own isolated build, never from a contributor-supplied report.
"""

PROFILES = {
    'ogre-native-headers': {
        'client': '2008-06',
        'module': 'OgreNativeHeaders',
        'spec': 'rebuild/2008-06/modules/ogre-native-headers.json',
        'source': 'rebuild/2008-06/glue/ogre-native',
        'test': 'ogre_native_vectors',
        'layers': ('client-headers',),
        'imports': ('rgmain.dll',),
    },
}


def profile(name):
    if name not in PROFILES:
        raise ValueError('Unknown native library profile')
    return dict(PROFILES[name])


def validate(name, before, after, layer_errors, linked_proofs, claimed, global_owned):
    """Check a server-built profile before any separate acceptance/credit step."""
    spec = profile(name)
    if before.get('module') != spec['module'] or after.get('module') != spec['module']:
        raise ValueError('Report module does not match profile')
    if not before.get('linked') or before.get('test_exit') != 0 or before.get('unresolved'):
        raise ValueError('Library baseline link or runtime failed')
    if not after.get('linked') or after.get('test_exit') != 0 or after.get('unresolved'):
        raise ValueError('Library link or runtime failed')
    if set(layer_errors) != set(spec['layers']) or any(errors for errors in layer_errors.values()):
        raise ValueError('Library layers missing or have compile errors')
    old, new = set(before.get('owned_addrs', [])), set(after.get('owned_addrs', []))
    if old - new:
        raise ValueError('Library ownership loss')
    added = new - old
    claimed = set(claimed)
    if not added or not claimed or not claimed <= added:
        raise ValueError('Claims must be newly owned by this build')
    proofs = {p['target']: p for p in linked_proofs}
    if set(proofs) != added or len(proofs) != len(linked_proofs):
        raise ValueError('Need one executable proof for every gained address')
    if not all(p.get('code_exact_in_executable') and any(
            hit.get('object_code_data_exact') and hit.get('code_exact')
            and str(hit.get('owner', '')).startswith('linked:')
            for hit in p.get('linked_proofs', [])) for p in proofs.values()):
        raise ValueError('Executable or object code/data proof failed')
    return {'added': sorted(added), 'claimed': sorted(claimed),
            'new_distinct': sorted(claimed - set(global_owned))}
