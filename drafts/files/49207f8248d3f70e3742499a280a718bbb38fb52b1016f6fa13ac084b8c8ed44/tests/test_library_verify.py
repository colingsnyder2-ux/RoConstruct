import copy

import pytest

from roc import library_verify


def sample():
    before = dict(module='OgreNativeHeaders', linked=True, test_exit=0, unresolved=[], owned_addrs=['00000001'])
    after = dict(module='OgreNativeHeaders', linked=True, test_exit=0, unresolved=[],
                 owned_addrs=['00000001', '00000002', '00000003'])
    proofs = [dict(target=a, code_exact_in_executable=True,
                   linked_proofs=[dict(owner='linked:real.obj', code_exact=True,
                                       object_code_data_exact=True)])
              for a in ['00000002', '00000003']]
    return before, after, {'client-headers': {}}, proofs


def test_library_gate_counts_only_claimed_globally_new_addresses():
    before, after, errors, proofs = sample()
    result = library_verify.validate('ogre-native-headers', before, after, errors, proofs,
                                     ['00000002', '00000003'], {'00000002'})
    assert result['new_distinct'] == ['00000003']
    assert result['added'] == ['00000002', '00000003']


def test_library_gate_rejects_unapproved_profile_and_module():
    before, after, errors, proofs = sample()
    with pytest.raises(ValueError, match='Unknown'):
        library_verify.validate('user-supplied', before, after, errors, proofs, ['00000002'], set())
    after['module'] = 'RbxgsApp'
    with pytest.raises(ValueError, match='module'):
        library_verify.validate('ogre-native-headers', before, after, errors, proofs, ['00000002'], set())


@pytest.mark.parametrize('failure', ['link', 'runtime', 'unresolved', 'compile', 'loss',
                                     'baseline', 'missing_layer', 'unclaimed', 'missing_proof', 'object', 'executable', 'owner'])
def test_library_gate_rejects_incomplete_evidence(failure):
    before, after, errors, proofs = copy.deepcopy(sample())
    claimed = ['00000002']
    if failure == 'link': after['linked'] = False
    if failure == 'runtime': after['test_exit'] = 1
    if failure == 'unresolved': after['unresolved'] = ['missing']
    if failure == 'compile': errors['client-headers'] = {'file.cpp': 'error'}
    if failure == 'baseline': before['test_exit'] = 1
    if failure == 'missing_layer': errors.clear()
    if failure == 'loss': after['owned_addrs'].remove('00000001')
    if failure == 'unclaimed': claimed = ['00000001']
    if failure == 'missing_proof': proofs.pop()
    if failure == 'object': proofs[0]['linked_proofs'][0]['object_code_data_exact'] = False
    if failure == 'executable': proofs[0]['code_exact_in_executable'] = False
    if failure == 'owner': proofs[0]['linked_proofs'][0]['owner'] = 'other.obj'
    with pytest.raises(ValueError):
        library_verify.validate('ogre-native-headers', before, after, errors, proofs, claimed, set())
