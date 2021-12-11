/*******************************************************************************
*  (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V2(
    parser_context_t* c, pd_balances_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V2(
    parser_context_t* c, pd_balances_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V2(
    parser_context_t* c, pd_staking_bond_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V2(
    parser_context_t* c, pd_staking_bond_extra_V2_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V2(
    parser_context_t* c, pd_staking_unbond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V2(
    parser_context_t* c, pd_staking_withdraw_unbonded_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V2(
    parser_context_t* c, pd_staking_validate_V2_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V2(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V2(
    parser_context_t* c, pd_staking_nominate_V2_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V2(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V2(
    parser_context_t* c, pd_staking_chill_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V2(
    parser_context_t* c, pd_staking_set_payee_V2_t* m)
{
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V2(
    parser_context_t* c, pd_staking_payout_stakers_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V2(
    parser_context_t* c, pd_staking_rebond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V2(
    parser_context_t* c, pd_session_set_keys_V2_t* m)
{
    CHECK_ERROR(_readKeys_V2(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V2(
    parser_context_t* c, pd_session_purge_keys_V2_t* m)
{
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V2(
    parser_context_t* c, pd_system_fill_block_V2_t* m)
{
    CHECK_ERROR(_readPerbill_V2(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V2(
    parser_context_t* c, pd_system_remark_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V2(
    parser_context_t* c, pd_system_set_heap_pages_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V2(
    parser_context_t* c, pd_system_set_code_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V2(
    parser_context_t* c, pd_system_set_code_without_checks_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V2(
    parser_context_t* c, pd_system_set_changes_trie_config_V2_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V2(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V2(
    parser_context_t* c, pd_system_set_storage_V2_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V2(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V2(
    parser_context_t* c, pd_system_kill_storage_V2_t* m)
{
    CHECK_ERROR(_readVecKey_V2(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V2(
    parser_context_t* c, pd_system_kill_prefix_V2_t* m)
{
    CHECK_ERROR(_readKey_V2(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide_V2(
    parser_context_t* c, pd_system_suicide_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V2(
    parser_context_t* c, pd_timestamp_set_V2_t* m)
{
    CHECK_ERROR(_readCompactMoment_V2(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V2(
    parser_context_t* c, pd_authorship_set_uncles_V2_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V2(
    parser_context_t* c, pd_indices_claim_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V2(
    parser_context_t* c, pd_indices_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V2(
    parser_context_t* c, pd_indices_free_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V2(
    parser_context_t* c, pd_indices_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V2(
    parser_context_t* c, pd_indices_freeze_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V2(
    parser_context_t* c, pd_balances_set_balance_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(
    parser_context_t* c, pd_balances_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->source))
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V2(
    parser_context_t* c, pd_staking_set_controller_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V2(
    parser_context_t* c, pd_staking_set_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V2(
    parser_context_t* c, pd_staking_increase_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V2(
    parser_context_t* c, pd_staking_scale_validator_count_V2_t* m)
{
    CHECK_ERROR(_readPercent_V2(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V2(
    parser_context_t* c, pd_staking_force_no_eras_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V2(
    parser_context_t* c, pd_staking_force_new_era_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V2(
    parser_context_t* c, pd_staking_set_invulnerables_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V2(
    parser_context_t* c, pd_staking_force_unstake_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V2(
    parser_context_t* c, pd_staking_force_new_era_always_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V2(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V2_t* m)
{
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V2(
    parser_context_t* c, pd_staking_set_history_depth_V2_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V2(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V2(
    parser_context_t* c, pd_staking_reap_stash_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V2(
    parser_context_t* c, pd_council_set_members_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V2(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V2(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V2(
    parser_context_t* c, pd_council_execute_V2_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V2(
    parser_context_t* c, pd_council_propose_V2_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V2(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V2(
    parser_context_t* c, pd_council_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V2(
    parser_context_t* c, pd_council_close_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V2(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V2(
    parser_context_t* c, pd_council_disapprove_proposal_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V2(
    parser_context_t* c, pd_grandpa_report_equivocation_V2_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V2(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V2(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V2(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V2_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V2(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V2(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V2(
    parser_context_t* c, pd_grandpa_note_stalled_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V2(
    parser_context_t* c, pd_sudo_sudo_V2_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V2(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V2_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V2(c, &m->_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V2(
    parser_context_t* c, pd_sudo_set_key_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V2(
    parser_context_t* c, pd_sudo_sudo_as_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V2(
    parser_context_t* c, pd_imonline_heartbeat_V2_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V2(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V2(
    parser_context_t* c, pd_identity_add_registrar_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V2(
    parser_context_t* c, pd_identity_set_identity_V2_t* m)
{
    CHECK_ERROR(_readIdentityInfo_V2(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V2(
    parser_context_t* c, pd_identity_set_subs_V2_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData_V2(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V2(
    parser_context_t* c, pd_identity_clear_identity_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V2(
    parser_context_t* c, pd_identity_request_judgement_V2_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V2(
    parser_context_t* c, pd_identity_cancel_request_V2_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V2(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V2(
    parser_context_t* c, pd_identity_set_fee_V2_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V2(
    parser_context_t* c, pd_identity_set_account_id_V2_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->index))
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fields_V2(
    parser_context_t* c, pd_identity_set_fields_V2_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->index))
    CHECK_ERROR(_readIdentityFields_V2(c, &m->fields))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V2(
    parser_context_t* c, pd_identity_provide_judgement_V2_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->reg_index))
    CHECK_ERROR(_readLookupSource_V2(c, &m->target))
    CHECK_ERROR(_readIdentityJudgement_V2(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V2(
    parser_context_t* c, pd_identity_kill_identity_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V2(
    parser_context_t* c, pd_identity_add_sub_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V2(
    parser_context_t* c, pd_identity_rename_sub_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V2(
    parser_context_t* c, pd_identity_remove_sub_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V2(
    parser_context_t* c, pd_identity_quit_sub_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V2(
    parser_context_t* c, pd_scheduler_schedule_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V2(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V2(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V2(
    parser_context_t* c, pd_scheduler_cancel_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V2(
    parser_context_t* c, pd_scheduler_schedule_named_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V2(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V2(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V2(
    parser_context_t* c, pd_scheduler_cancel_named_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V2(
    parser_context_t* c, pd_scheduler_schedule_after_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V2(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V2(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V2(
    parser_context_t* c, pd_scheduler_schedule_named_after_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V2(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V2(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_ethereum_transact_V2(
    parser_context_t* c, pd_ethereum_transact_V2_t* m)
{
    CHECK_ERROR(_readEthTransaction_V2(c, &m->transaction))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_withdraw_V2(
    parser_context_t* c, pd_evm_withdraw_V2_t* m)
{
    CHECK_ERROR(_readH160_V2(c, &m->address))
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_call_V2(
    parser_context_t* c, pd_evm_call_V2_t* m)
{
    CHECK_ERROR(_readH160_V2(c, &m->source))
    CHECK_ERROR(_readH160_V2(c, &m->target))
    CHECK_ERROR(_readBytes(c, &m->input))
    CHECK_ERROR(_readU256_V2(c, &m->value))
    CHECK_ERROR(_readu32(c, &m->gas_limit))
    CHECK_ERROR(_readU256_V2(c, &m->gas_price))
    CHECK_ERROR(_readOptionU256_V2(c, &m->nonce))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_create_V2(
    parser_context_t* c, pd_evm_create_V2_t* m)
{
    CHECK_ERROR(_readH160_V2(c, &m->source))
    CHECK_ERROR(_readBytes(c, &m->init))
    CHECK_ERROR(_readU256_V2(c, &m->value))
    CHECK_ERROR(_readu32(c, &m->gas_limit))
    CHECK_ERROR(_readU256_V2(c, &m->gas_price))
    CHECK_ERROR(_readOptionU256_V2(c, &m->nonce))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_create2_V2(
    parser_context_t* c, pd_evm_create2_V2_t* m)
{
    CHECK_ERROR(_readH160_V2(c, &m->source))
    CHECK_ERROR(_readBytes(c, &m->init))
    CHECK_ERROR(_readH256_V2(c, &m->salt))
    CHECK_ERROR(_readU256_V2(c, &m->value))
    CHECK_ERROR(_readu32(c, &m->gas_limit))
    CHECK_ERROR(_readU256_V2(c, &m->gas_price))
    CHECK_ERROR(_readOptionU256_V2(c, &m->nonce))
    return parser_ok;
}


#endif

parser_error_t _readMethod_V2(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V2_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V2(c, &method->nested.balances_transfer_V2))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V2(c, &method->nested.balances_transfer_keep_alive_V2))
        break;
    case 8448: /* module 33 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V2(c, &method->basic.staking_bond_V2))
        break;
    case 8449: /* module 33 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V2(c, &method->basic.staking_bond_extra_V2))
        break;
    case 8450: /* module 33 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V2(c, &method->basic.staking_unbond_V2))
        break;
    case 8451: /* module 33 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V2(c, &method->basic.staking_withdraw_unbonded_V2))
        break;
    case 8452: /* module 33 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V2(c, &method->basic.staking_validate_V2))
        break;
    case 8453: /* module 33 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V2(c, &method->basic.staking_nominate_V2))
        break;
    case 8454: /* module 33 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V2(c, &method->basic.staking_chill_V2))
        break;
    case 8455: /* module 33 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V2(c, &method->basic.staking_set_payee_V2))
        break;
    case 8466: /* module 33 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V2(c, &method->basic.staking_payout_stakers_V2))
        break;
    case 8467: /* module 33 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V2(c, &method->basic.staking_rebond_V2))
        break;
    case 8704: /* module 34 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V2(c, &method->basic.session_set_keys_V2))
        break;
    case 8705: /* module 34 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V2(c, &method->basic.session_purge_keys_V2))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V2(c, &method->nested.system_fill_block_V2))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V2(c, &method->nested.system_remark_V2))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V2(c, &method->nested.system_set_heap_pages_V2))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V2(c, &method->nested.system_set_code_V2))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V2(c, &method->nested.system_set_code_without_checks_V2))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V2(c, &method->nested.system_set_changes_trie_config_V2))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V2(c, &method->nested.system_set_storage_V2))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V2(c, &method->nested.system_kill_storage_V2))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V2(c, &method->nested.system_kill_prefix_V2))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V2(c, &method->nested.system_suicide_V2))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V2(c, &method->basic.timestamp_set_V2))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V2(c, &method->basic.sudo_sudo_V2))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V2(c, &method->basic.sudo_sudo_unchecked_weight_V2))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V2(c, &method->basic.sudo_set_key_V2))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V2(c, &method->basic.sudo_sudo_as_V2))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V2(c, &method->basic.indices_claim_V2))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V2(c, &method->basic.indices_transfer_V2))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V2(c, &method->basic.indices_free_V2))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V2(c, &method->basic.indices_force_transfer_V2))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V2(c, &method->basic.indices_freeze_V2))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V2(c, &method->nested.balances_set_balance_V2))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V2(c, &method->nested.balances_force_transfer_V2))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V2(c, &method->basic.authorship_set_uncles_V2))
        break;
    case 8456: /* module 33 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V2(c, &method->basic.staking_set_controller_V2))
        break;
    case 8457: /* module 33 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V2(c, &method->basic.staking_set_validator_count_V2))
        break;
    case 8458: /* module 33 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V2(c, &method->basic.staking_increase_validator_count_V2))
        break;
    case 8459: /* module 33 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V2(c, &method->basic.staking_scale_validator_count_V2))
        break;
    case 8460: /* module 33 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V2(c, &method->basic.staking_force_no_eras_V2))
        break;
    case 8461: /* module 33 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V2(c, &method->basic.staking_force_new_era_V2))
        break;
    case 8462: /* module 33 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V2(c, &method->basic.staking_set_invulnerables_V2))
        break;
    case 8463: /* module 33 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V2(c, &method->basic.staking_force_unstake_V2))
        break;
    case 8464: /* module 33 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V2(c, &method->basic.staking_force_new_era_always_V2))
        break;
    case 8465: /* module 33 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V2(c, &method->basic.staking_cancel_deferred_slash_V2))
        break;
    case 8468: /* module 33 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V2(c, &method->basic.staking_set_history_depth_V2))
        break;
    case 8469: /* module 33 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V2(c, &method->basic.staking_reap_stash_V2))
        break;
    case 12800: /* module 50 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V2(c, &method->basic.council_set_members_V2))
        break;
    case 12801: /* module 50 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V2(c, &method->basic.council_execute_V2))
        break;
    case 12802: /* module 50 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V2(c, &method->basic.council_propose_V2))
        break;
    case 12803: /* module 50 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V2(c, &method->basic.council_vote_V2))
        break;
    case 12804: /* module 50 call 4 */
        CHECK_ERROR(_readMethod_council_close_V2(c, &method->basic.council_close_V2))
        break;
    case 12805: /* module 50 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V2(c, &method->basic.council_disapprove_proposal_V2))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V2(c, &method->basic.grandpa_report_equivocation_V2))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V2(c, &method->basic.grandpa_report_equivocation_unsigned_V2))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V2(c, &method->basic.grandpa_note_stalled_V2))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V2(c, &method->basic.imonline_heartbeat_V2))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V2(c, &method->basic.identity_add_registrar_V2))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V2(c, &method->basic.identity_set_identity_V2))
        break;
    case 10242: /* module 40 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V2(c, &method->basic.identity_set_subs_V2))
        break;
    case 10243: /* module 40 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V2(c, &method->basic.identity_clear_identity_V2))
        break;
    case 10244: /* module 40 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V2(c, &method->basic.identity_request_judgement_V2))
        break;
    case 10245: /* module 40 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V2(c, &method->basic.identity_cancel_request_V2))
        break;
    case 10246: /* module 40 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V2(c, &method->basic.identity_set_fee_V2))
        break;
    case 10247: /* module 40 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V2(c, &method->basic.identity_set_account_id_V2))
        break;
    case 10248: /* module 40 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V2(c, &method->basic.identity_set_fields_V2))
        break;
    case 10249: /* module 40 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V2(c, &method->basic.identity_provide_judgement_V2))
        break;
    case 10250: /* module 40 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V2(c, &method->basic.identity_kill_identity_V2))
        break;
    case 10251: /* module 40 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V2(c, &method->basic.identity_add_sub_V2))
        break;
    case 10252: /* module 40 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V2(c, &method->basic.identity_rename_sub_V2))
        break;
    case 10253: /* module 40 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V2(c, &method->basic.identity_remove_sub_V2))
        break;
    case 10254: /* module 40 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V2(c, &method->basic.identity_quit_sub_V2))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V2(c, &method->basic.scheduler_schedule_V2))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V2(c, &method->basic.scheduler_cancel_V2))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V2(c, &method->basic.scheduler_schedule_named_V2))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V2(c, &method->basic.scheduler_cancel_named_V2))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V2(c, &method->basic.scheduler_schedule_after_V2))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V2(c, &method->basic.scheduler_schedule_named_after_V2))
        break;
    /*case 8448: [> module 33 call 0 <]*/
        /*[>CHECK_ERROR(_readMethod_ethereum_transact_V2(c, &method->basic.ethereum_transact_V2))<]*/
        /*CHECK_ERROR(_readMethod_staking_bond_V2(c, &method->basic.staking_bond_V2))*/
        /*break;*/
    /*case 8704: [> module 34 call 0 <]*/
        /*CHECK_ERROR(_readMethod_evm_withdraw_V2(c, &method->basic.evm_withdraw_V2))*/
        /*break;*/
    /*case 8705: [> module 34 call 1 <]*/
        /*CHECK_ERROR(_readMethod_evm_call_V2(c, &method->basic.evm_call_V2))*/
        /*break;*/
    /*case 8706: [> module 34 call 2 <]*/
        /*CHECK_ERROR(_readMethod_evm_create_V2(c, &method->basic.evm_create_V2))*/
        /*break;*/
    /*case 8707: [> module 34 call 3 <]*/
        /*CHECK_ERROR(_readMethod_evm_create2_V2(c, &method->basic.evm_create2_V2))*/
        /*break;*/
#endif
    default:
        return parser_value_out_of_range;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V2(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 6:
        return STR_MO_BALANCES;
    case 33:
        return STR_MO_STAKING;
    case 34:
        return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 2:
        return STR_MO_TIMESTAMP;
    case 3:
        return STR_MO_SUDO;
    case 4:
        return STR_MO_SCHEDULER;
    case 5:
        return STR_MO_INDICES;
    case 23:
        return STR_MO_IDENTITY;
    case 30:
        return STR_MO_AUTHORSHIP;
    case 32:
        return STR_MO_GRANDPA;
    case 37:
        return STR_MO_IMONLINE;
    case 50:
        return STR_MO_COUNCIL;
    /*case 33:*/
        /*return STR_MO_ETHEREUM;*/
    /*case 34:*/
        /*return STR_MO_EVM;*/
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        return STR_ME_TRANSFER;
    case 1539: /* module 6 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 8448: /* module 33 call 0 */
        return STR_ME_BOND;
    case 8449: /* module 33 call 1 */
        return STR_ME_BOND_EXTRA;
    case 8450: /* module 33 call 2 */
        return STR_ME_UNBOND;
    case 8451: /* module 33 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 8452: /* module 33 call 4 */
        return STR_ME_VALIDATE;
    case 8453: /* module 33 call 5 */
        return STR_ME_NOMINATE;
    case 8454: /* module 33 call 6 */
        return STR_ME_CHILL;
    case 8455: /* module 33 call 7 */
        return STR_ME_SET_PAYEE;
    case 8466: /* module 33 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 8467: /* module 33 call 19 */
        return STR_ME_REBOND;
    case 8704: /* module 34 call 0 */
        return STR_ME_SET_KEYS;
    case 8705: /* module 34 call 1 */
        return STR_ME_PURGE_KEYS;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 5: /* module 0 call 5 */
        return STR_ME_SET_CHANGES_TRIE_CONFIG;
    case 6: /* module 0 call 6 */
        return STR_ME_SET_STORAGE;
    case 7: /* module 0 call 7 */
        return STR_ME_KILL_STORAGE;
    case 8: /* module 0 call 8 */
        return STR_ME_KILL_PREFIX;
    case 9: /* module 0 call 9 */
        return STR_ME_SUICIDE;
    case 512: /* module 2 call 0 */
        return STR_ME_SET;
    case 7680: /* module 30 call 0 */
        return STR_ME_SET_UNCLES;
    case 1280: /* module 5 call 0 */
        return STR_ME_CLAIM;
    case 1281: /* module 5 call 1 */
        return STR_ME_TRANSFER;
    case 1282: /* module 5 call 2 */
        return STR_ME_FREE;
    case 1283: /* module 5 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 1284: /* module 5 call 4 */
        return STR_ME_FREEZE;
    case 1537: /* module 6 call 1 */
        return STR_ME_SET_BALANCE;
    case 1538: /* module 6 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 8456: /* module 33 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 8457: /* module 33 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 8458: /* module 33 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 8459: /* module 33 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 8460: /* module 33 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 8461: /* module 33 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 8462: /* module 33 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 8463: /* module 33 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 8464: /* module 33 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 8465: /* module 33 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 8468: /* module 33 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 8469: /* module 33 call 21 */
        return STR_ME_REAP_STASH;
    case 768: /* module 3 call 0 */
        return STR_ME_SUDO;
    case 769: /* module 3 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 770: /* module 3 call 2 */
        return STR_ME_SET_KEY;
    case 771: /* module 3 call 3 */
        return STR_ME_SUDO_AS;
    case 1024: /* module 4 call 0 */
        return STR_ME_SCHEDULE;
    case 1025: /* module 4 call 1 */
        return STR_ME_CANCEL;
    case 1026: /* module 4 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 1027: /* module 4 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 1028: /* module 4 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 1029: /* module 4 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 8192: /* module 32 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 8193: /* module 32 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 8194: /* module 32 call 2 */
        return STR_ME_NOTE_STALLED;
    case 9472: /* module 37 call 0 */
        return STR_ME_HEARTBEAT;
    case 10240: /* module 40 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 10241: /* module 40 call 1 */
        return STR_ME_SET_IDENTITY;
    case 10242: /* module 40 call 2 */
        return STR_ME_SET_SUBS;
    case 10243: /* module 40 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 10244: /* module 40 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 10245: /* module 40 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 10246: /* module 40 call 6 */
        return STR_ME_SET_FEE;
    case 10247: /* module 40 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 10248: /* module 40 call 8 */
        return STR_ME_SET_FIELDS;
    case 10249: /* module 40 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 10250: /* module 40 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 10251: /* module 40 call 11 */
        return STR_ME_ADD_SUB;
    case 10252: /* module 40 call 12 */
        return STR_ME_RENAME_SUB;
    case 10253: /* module 40 call 13 */
        return STR_ME_REMOVE_SUB;
    case 10254: /* module 40 call 14 */
        return STR_ME_QUIT_SUB;
    case 12800: /* module 50 call 0 */
        return STR_ME_SET_MEMBERS;
    case 12801: /* module 50 call 1 */
        return STR_ME_EXECUTE;
    case 12802: /* module 50 call 2 */
        return STR_ME_PROPOSE;
    case 12803: /* module 50 call 3 */
        return STR_ME_VOTE;
    case 12804: /* module 50 call 4 */
        return STR_ME_CLOSE;
    case 12805: /* module 50 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    /*case 8448: [> module 33 call 0 <]*/
        /*return STR_ME_TRANSACT;*/
    /*case 8704: [> module 34 call 0 <]*/
        /*return STR_ME_WITHDRAW;*/
    /*case 8705: [> module 34 call 1 <]*/
        /*return STR_ME_CALL;*/
    /*case 8706: [> module 34 call 2 <]*/
        /*return STR_ME_CREATE;*/
    /*case 8707: [> module 34 call 3 <]*/
        /*return STR_ME_CREATE2;*/
    // UNUSED_START: Cannot remove, it does not compile
    case 256: /* module 1 call 0 */
        return STR_ME_BATCH;
    case 258: /* module 1 call 2 */
        return STR_ME_BATCH_ALL;
    case 2560: /* module 10 call 0 */
        return STR_ME_PROPOSE;
    case 2561: /* module 10 call 1 */
        return STR_ME_SECOND;
    case 2562: /* module 10 call 2 */
        return STR_ME_VOTE;
    case 2563: /* module 10 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 2564: /* module 10 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 2565: /* module 10 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 2566: /* module 10 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 2567: /* module 10 call 7 */
        return STR_ME_FAST_TRACK;
    case 2568: /* module 10 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 2569: /* module 10 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 2570: /* module 10 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 2571: /* module 10 call 11 */
        return STR_ME_DELEGATE;
    case 2572: /* module 10 call 12 */
        return STR_ME_UNDELEGATE;
    case 2573: /* module 10 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 2574: /* module 10 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 2575: /* module 10 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 2576: /* module 10 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 2577: /* module 10 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 2578: /* module 10 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 2579: /* module 10 call 19 */
        return STR_ME_UNLOCK;
    case 2580: /* module 10 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 2581: /* module 10 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 2582: /* module 10 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 2583: /* module 10 call 23 */
        return STR_ME_BLACKLIST;
    case 2584: /* module 10 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 3072: /* module 12 call 0 */
        return STR_ME_VOTE;
    case 3073: /* module 12 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 3074: /* module 12 call 2 */
        return STR_ME_REPORT_DEFUNCT_VOTER;
    case 3075: /* module 12 call 3 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 3076: /* module 12 call 4 */
        return STR_ME_RENOUNCE_CANDIDACY;
    case 3077: /* module 12 call 5 */
        return STR_ME_REMOVE_MEMBER;
    case 3840: /* module 15 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 3841: /* module 15 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 3842: /* module 15 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_UPDATE_SCHEDULE;
    case 4097: /* module 16 call 1 */
        return STR_ME_PUT_CODE;
    case 4098: /* module 16 call 2 */
        return STR_ME_CALL;
    case 4099: /* module 16 call 3 */
        return STR_ME_INSTANTIATE;
    case 4100: /* module 16 call 4 */
        return STR_ME_CLAIM_SURCHARGE;
    case 6144: /* module 24 call 0 */
        return STR_ME_AS_RECOVERED;
    case 6145: /* module 24 call 1 */
        return STR_ME_SET_RECOVERED;
    case 6146: /* module 24 call 2 */
        return STR_ME_CREATE_RECOVERY;
    case 6147: /* module 24 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 6148: /* module 24 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 6149: /* module 24 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 6150: /* module 24 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 6151: /* module 24 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 6152: /* module 24 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    // UNUSED_END:
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        return 2;
    case 1539: /* module 6 call 3 */
        return 2;
    case 8448: /* module 33 call 1 */
        return 1;
    case 8449: /* module 33 call 2 */
        return 1;
    case 8451: /* module 33 call 3 */
        return 1;
    case 8452: /* module 33 call 4 */
        return 1;
    case 8453: /* module 33 call 5 */
        return 1;
    case 8454: /* module 33 call 6 */
        return 0;
    case 8455: /* module 33 call 7 */
        return 1;
    case 8466: /* module 33 call 18 */
        return 2;
    case 8467: /* module 33 call 19 */
        return 1;
    case 8704: /* module 34 call 0 */
        return 2;
    case 8705: /* module 34 call 1 */
        return 0;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 5: /* module 0 call 5 */
        return 1;
    case 6: /* module 0 call 6 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 8: /* module 0 call 8 */
        return 2;
    case 9: /* module 0 call 9 */
        return 0;
    case 512: /* module 3 call 0 */
        return 1;
    case 1280: /* module 5 call 0 */
        return 1;
    case 1281: /* module 5 call 1 */
        return 2;
    case 1282: /* module 5 call 2 */
        return 1;
    case 1283: /* module 5 call 3 */
        return 3;
    case 1284: /* module 5 call 4 */
        return 1;
    case 1537: /* module 6 call 1 */
        return 3;
    case 1538: /* module 6 call 2 */
        return 3;
    case 7680: /* module 30 call 0 */
        return 1;
    case 8456: /* module 33 call 8 */
        return 1;
    case 8457: /* module 33 call 9 */
        return 1;
    case 8458: /* module 33 call 10 */
        return 1;
    case 8459: /* module 33 call 11 */
        return 1;
    case 8460: /* module 33 call 12 */
        return 0;
    case 8461: /* module 33 call 13 */
        return 0;
    case 8462: /* module 33 call 14 */
        return 1;
    case 8463: /* module 33 call 15 */
        return 2;
    case 8464: /* module 33 call 16 */
        return 0;
    case 8465: /* module 33 call 17 */
        return 2;
    case 8468: /* module 33 call 20 */
        return 2;
    case 8469: /* module 33 call 21 */
        return 2;
    case 8192: /* module 32 call 0 */
        return 2;
    case 8193: /* module 32 call 1 */
        return 2;
    case 8194: /* module 32 call 2 */
        return 2;
    case 768: /* module 3 call 0 */
        return 1;
    case 769: /* module 3 call 1 */
        return 2;
    case 770: /* module 3 call 2 */
        return 1;
    case 771: /* module 3 call 3 */
        return 2;
    case 9472: /* module 37 call 0 */
        return 2;
    case 10240: /* module 40 call 0 */
        return 1;
    case 10241: /* module 40 call 1 */
        return 1;
    case 10242: /* module 40 call 2 */
        return 1;
    case 10243: /* module 40 call 3 */
        return 0;
    case 10244: /* module 40 call 4 */
        return 2;
    case 10245: /* module 40 call 5 */
        return 1;
    case 10246: /* module 40 call 6 */
        return 2;
    case 10247: /* module 40 call 7 */
        return 2;
    case 10248: /* module 40 call 8 */
        return 2;
    case 10249: /* module 40 call 9 */
        return 3;
    case 10250: /* module 40 call 10 */
        return 1;
    case 10251: /* module 40 call 11 */
        return 2;
    case 10252: /* module 40 call 12 */
        return 2;
    case 10253: /* module 40 call 13 */
        return 1;
    case 10254: /* module 40 call 14 */
        return 0;
    case 12800: /* module 50 call 0 */
        return 3;
    case 12801: /* module 50 call 1 */
        return 2;
    case 12802: /* module 50 call 2 */
        return 3;
    case 12803: /* module 50 call 3 */
        return 3;
    case 12804: /* module 50 call 4 */
        return 4;
    case 12805: /* module 50 call 5 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 4;
    case 1025: /* module 4 call 1 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 5;
    case 1027: /* module 4 call 3 */
        return 1;
    case 1028: /* module 4 call 4 */
        return 4;
    case 1029: /* module 4 call 5 */
        return 5;
    case 6912: /* module 27 call 0 */
        return 3;
    case 6913: /* module 27 call 1 */
        return 3;
    case 6914: /* module 27 call 2 */
        return 3;
    case 6915: /* module 27 call 3 */
        return 0;
    case 6916: /* module 27 call 4 */
        return 3;
    case 6917: /* module 27 call 5 */
        return 5;
    case 6918: /* module 27 call 6 */
        return 2;
    case 6919: /* module 27 call 7 */
        return 2;
    case 6920: /* module 27 call 8 */
        return 2;
    case 6921: /* module 27 call 9 */
        return 4;
    case 7424: /* module 29 call 0 */
        return 4;
    case 7425: /* module 29 call 1 */
        return 4;
    case 7426: /* module 29 call 2 */
        return 2;
    case 7427: /* module 29 call 3 */
        return 2;
    case 7428: /* module 29 call 4 */
        return 3;
    case 7429: /* module 29 call 5 */
        return 3;
    case 7430: /* module 29 call 6 */
        return 3;
    case 7431: /* module 29 call 7 */
        return 4;
    case 7432: /* module 29 call 8 */
        return 2;
    case 7433: /* module 29 call 9 */
        return 2;
    case 7434: /* module 29 call 10 */
        return 2;
    case 7435: /* module 29 call 11 */
        return 4;
    case 7436: /* module 29 call 12 */
        return 2;
    /*case 8704: [> module 34 call 0 <]*/
        /*return 2;*/
    /*case 8705: [> module 34 call 1 <]*/
        /*return 7;*/
    /*case 8706: [> module 34 call 2 <]*/
        /*return 6;*/
    /*case 8707: [> module 34 call 3 <]*/
        /*return 7;*/
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 8449: /* module 33 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max_additional;
        default:
            return NULL;
        }
    case 8450: /* module 33 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 8451: /* module 33 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 8452: /* module 33 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 8453: /* module 33 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 8454: /* module 33 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8455: /* module 33 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 8466: /* module 33 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 8467: /* module 33 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT__ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_changes_trie_config;
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefix;
        case 1:
            return STR_IT__subkeys;
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_uncles;
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 8456: /* module 33 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 8457: /* module 33 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 8458: /* module 33 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 8459: /* module 33 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 8460: /* module 33 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8461: /* module 33 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8462: /* module 33 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 8463: /* module 33 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 8464: /* module 33 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8465: /* module 33 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 8468: /* module 33 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT__era_items_deleted;
        default:
            return NULL;
        }
    case 8469: /* module 33 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT__weight;
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_heartbeat;
        case 1:
            return STR_IT__signature;
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_subs;
        default:
            return NULL;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 10246: /* module 40 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 10247: /* module 40 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 10248: /* module 40 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fields;
        default:
            return NULL;
        }
    case 10249: /* module 40 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_judgement;
        default:
            return NULL;
        }
    case 10250: /* module 40 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 10251: /* module 40 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 10252: /* module 40 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 10253: /* module 40 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 10254: /* module 40 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_when;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_after;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_after;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    /*case 8448: [> module 33 call 0 <]*/
        /*switch (itemIdx) {*/
        /*case 0:*/
            /*return STR_IT_transaction;*/
        /*default:*/
            /*return NULL;*/
        /*}*/
    /*case 8704: [> module 34 call 0 <]*/
        /*switch (itemIdx) {*/
        /*case 0:*/
            /*return STR_IT_address;*/
        /*case 1:*/
            /*return STR_IT_value;*/
        /*default:*/
            /*return NULL;*/
        /*}*/
    /*case 8705: [> module 34 call 1 <]*/
        /*switch (itemIdx) {*/
        /*case 0:*/
            /*return STR_IT_source;*/
        /*case 1:*/
            /*return STR_IT_target;*/
        /*case 2:*/
            /*return STR_IT_input;*/
        /*case 3:*/
            /*return STR_IT_value;*/
        /*case 4:*/
            /*return STR_IT_gas_limit;*/
        /*case 5:*/
            /*return STR_IT_gas_price;*/
        /*case 6:*/
            /*return STR_IT_nonce;*/
        /*default:*/
            /*return NULL;*/
        /*}*/
    /*case 8706: [> module 34 call 2 <]*/
        /*switch (itemIdx) {*/
        /*case 0:*/
            /*return STR_IT_source;*/
        /*case 1:*/
            /*return STR_IT_init;*/
        /*case 2:*/
            /*return STR_IT_value;*/
        /*case 3:*/
            /*return STR_IT_gas_limit;*/
        /*case 4:*/
            /*return STR_IT_gas_price;*/
        /*case 5:*/
            /*return STR_IT_nonce;*/
        /*default:*/
            /*return NULL;*/
        /*}*/
    /*case 8707: [> module 34 call 3 <]*/
        /*switch (itemIdx) {*/
        /*case 0:*/
            /*return STR_IT_source;*/
        /*case 1:*/
            /*return STR_IT_init;*/
        /*case 2:*/
            /*return STR_IT_salt;*/
        /*case 3:*/
            /*return STR_IT_value;*/
        /*case 4:*/
            /*return STR_IT_gas_limit;*/
        /*case 5:*/
            /*return STR_IT_gas_price;*/
        /*case 6:*/
            /*return STR_IT_nonce;*/
        /*default:*/
            /*return NULL;*/
        /*}*/
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(
    pd_Method_V2_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V2 - dest */;
            return _toStringLookupSource_V2(
                &m->nested.balances_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V2 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V2.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V2 - dest */;
            return _toStringLookupSource_V2(
                &m->nested.balances_transfer_keep_alive_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V2 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V2.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V2 - controller */;
            return _toStringLookupSource_V2(
                &m->basic.staking_bond_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V2 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_V2.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V2 - payee */;
            return _toStringRewardDestination_V2(
                &m->basic.staking_bond_V2.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8449: /* module 33 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V2 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V2.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8450: /* module 33 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V2 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_unbond_V2.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8451: /* module 33 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8452: /* module 33 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V2 - prefs */;
            return _toStringValidatorPrefs_V2(
                &m->basic.staking_validate_V2.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8453: /* module 33 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V2 - targets */;
            return _toStringVecLookupSource_V2(
                &m->basic.staking_nominate_V2.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8454: /* module 33 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8455: /* module 33 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V2 - payee */;
            return _toStringRewardDestination_V2(
                &m->basic.staking_set_payee_V2.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8466: /* module 33 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V2 - validator_stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_payout_stakers_V2.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V2 - era */;
            return _toStringEraIndex_V2(
                &m->basic.staking_payout_stakers_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8467: /* module 33 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V2 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_rebond_V2.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V2 - keys */;
            return _toStringKeys_V2(
                &m->basic.session_set_keys_V2.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V2 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V2.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V2 - _ratio */;
            return _toStringPerbill_V2(
                &m->nested.system_fill_block_V2._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V2 - _remark */;
            return _toStringBytes(
                &m->nested.system_remark_V2._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V2 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V2.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V2 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V2 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_without_checks_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V2 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V2(
                &m->nested.system_set_changes_trie_config_V2.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V2 - items */;
            return _toStringVecKeyValue_V2(
                &m->nested.system_set_storage_V2.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V2 - keys */;
            return _toStringVecKey_V2(
                &m->nested.system_kill_storage_V2.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V2 - prefix */;
            return _toStringKey_V2(
                &m->nested.system_kill_prefix_V2.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V2 - _subkeys */;
            return _toStringu32(
                &m->nested.system_kill_prefix_V2._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V2 - now */;
            return _toStringCompactMoment_V2(
                &m->basic.timestamp_set_V2.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V2 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V2.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_claim_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.indices_transfer_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_transfer_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_free_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.indices_force_transfer_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_force_transfer_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V2 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V2.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_freeze_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V2 - who */;
            return _toStringLookupSource_V2(
                &m->nested.balances_set_balance_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V2 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V2 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V2 - source */;
            return _toStringLookupSource_V2(
                &m->nested.balances_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V2 - dest */;
            return _toStringLookupSource_V2(
                &m->nested.balances_force_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V2 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V2.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8456: /* module 33 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V2 - controller */;
            return _toStringLookupSource_V2(
                &m->basic.staking_set_controller_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8457: /* module 33 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V2 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8458: /* module 33 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V2 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V2.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8459: /* module 33 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V2 - factor */;
            return _toStringPercent_V2(
                &m->basic.staking_scale_validator_count_V2.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8460: /* module 33 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8461: /* module 33 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8462: /* module 33 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V2 - invulnerables */;
            return _toStringVecAccountId_V2(
                &m->basic.staking_set_invulnerables_V2.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8463: /* module 33 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V2 - stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_force_unstake_V2.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8464: /* module 33 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8465: /* module 33 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V2 - era */;
            return _toStringEraIndex_V2(
                &m->basic.staking_cancel_deferred_slash_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V2 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V2.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8468: /* module 33 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V2 - new_history_depth */;
            return _toStringCompactEraIndex_V2(
                &m->basic.staking_set_history_depth_V2.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V2 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V2._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8469: /* module 33 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V2 - stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_reap_stash_V2.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V2 - new_members */;
            return _toStringVecAccountId_V2(
                &m->basic.council_set_members_V2.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V2 - prime */;
            return _toStringOptionAccountId_V2(
                &m->basic.council_set_members_V2.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V2 - old_count */;
            return _toStringMemberCount_V2(
                &m->basic.council_set_members_V2.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V2 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V2 - threshold */;
            return _toStringCompactMemberCount_V2(
                &m->basic.council_propose_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V2 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V2 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V2 - index */;
            return _toStringCompactProposalIndex_V2(
                &m->basic.council_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V2 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V2 - index */;
            return _toStringCompactProposalIndex_V2(
                &m->basic.council_close_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V2 - proposal_weight_bound */;
            return _toStringCompactWeight_V2(
                &m->basic.council_close_V2.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V2 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V2(
                &m->basic.grandpa_report_equivocation_V2.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V2 - key_owner_proof */;
            return _toStringKeyOwnerProof_V2(
                &m->basic.grandpa_report_equivocation_V2.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V2 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V2(
                &m->basic.grandpa_report_equivocation_unsigned_V2.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V2 - key_owner_proof */;
            return _toStringKeyOwnerProof_V2(
                &m->basic.grandpa_report_equivocation_unsigned_V2.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V2 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V2.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V2 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V2 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_unchecked_weight_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V2 - _weight */;
            return _toStringWeight_V2(
                &m->basic.sudo_sudo_unchecked_weight_V2._weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V2 - new_ */;
            return _toStringLookupSource_V2(
                &m->basic.sudo_set_key_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V2 - who */;
            return _toStringLookupSource_V2(
                &m->basic.sudo_sudo_as_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V2 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_as_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V2 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V2.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V2 - _signature */;
            return _toStringSignature_V2(
                &m->basic.imonline_heartbeat_V2._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.identity_add_registrar_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V2 - info */;
            return _toStringIdentityInfo_V2(
                &m->basic.identity_set_identity_V2.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V2 - subs */;
            return _toStringVecTupleAccountIdData_V2(
                &m->basic.identity_set_subs_V2.subs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V2 - reg_index */;
            return _toStringCompactRegistrarIndex_V2(
                &m->basic.identity_request_judgement_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V2 - max_fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_request_judgement_V2.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V2 - reg_index */;
            return _toStringRegistrarIndex_V2(
                &m->basic.identity_cancel_request_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10246: /* module 40 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V2 - index */;
            return _toStringCompactRegistrarIndex_V2(
                &m->basic.identity_set_fee_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V2 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_set_fee_V2.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10247: /* module 40 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V2 - index */;
            return _toStringCompactRegistrarIndex_V2(
                &m->basic.identity_set_account_id_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.identity_set_account_id_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10248: /* module 40 call 8 */
        switch (itemIdx) {
        case 0: /* identity_set_fields_V2 - index */;
            return _toStringCompactRegistrarIndex_V2(
                &m->basic.identity_set_fields_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fields_V2 - fields */;
            return _toStringIdentityFields_V2(
                &m->basic.identity_set_fields_V2.fields,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10249: /* module 40 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V2 - reg_index */;
            return _toStringCompactRegistrarIndex_V2(
                &m->basic.identity_provide_judgement_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V2 - target */;
            return _toStringLookupSource_V2(
                &m->basic.identity_provide_judgement_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V2 - judgement */;
            return _toStringIdentityJudgement_V2(
                &m->basic.identity_provide_judgement_V2.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10250: /* module 40 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V2 - target */;
            return _toStringLookupSource_V2(
                &m->basic.identity_kill_identity_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10251: /* module 40 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V2 - sub */;
            return _toStringLookupSource_V2(
                &m->basic.identity_add_sub_V2.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V2 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V2.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10252: /* module 40 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V2 - sub */;
            return _toStringLookupSource_V2(
                &m->basic.identity_rename_sub_V2.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V2 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V2.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10253: /* module 40 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V2 - sub */;
            return _toStringLookupSource_V2(
                &m->basic.identity_remove_sub_V2.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10254: /* module 40 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V2 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V2.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V2 - maybe_periodic */;
            return _toStringOptionPeriod_V2(
                &m->basic.scheduler_schedule_V2.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V2 - priority */;
            return _toStringPriority_V2(
                &m->basic.scheduler_schedule_V2.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V2 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V2 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V2.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V2 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V2 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V2 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V2.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V2 - maybe_periodic */;
            return _toStringOptionPeriod_V2(
                &m->basic.scheduler_schedule_named_V2.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V2 - priority */;
            return _toStringPriority_V2(
                &m->basic.scheduler_schedule_named_V2.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V2 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V2 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V2 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V2.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V2 - maybe_periodic */;
            return _toStringOptionPeriod_V2(
                &m->basic.scheduler_schedule_after_V2.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V2 - priority */;
            return _toStringPriority_V2(
                &m->basic.scheduler_schedule_after_V2.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V2 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_after_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V2 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V2 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V2.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V2 - maybe_periodic */;
            return _toStringOptionPeriod_V2(
                &m->basic.scheduler_schedule_named_after_V2.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V2 - priority */;
            return _toStringPriority_V2(
                &m->basic.scheduler_schedule_named_after_V2.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V2 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_after_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    /*case 8448: [> module 33 call 0 <]*/
        /*switch (itemIdx) {*/
        /*case 0: [> ethereum_transact_V2 - transaction <];*/
            /*return _toStringEthTransaction_V2(*/
                /*&m->basic.ethereum_transact_V2.transaction,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*default:*/
            /*return parser_no_data;*/
        /*}*/
    /*case 8704: [> module 34 call 0 <]*/
        /*switch (itemIdx) {*/
        /*case 0: [> evm_withdraw_V2 - address <];*/
            /*return _toStringH160_V2(*/
                /*&m->basic.evm_withdraw_V2.address,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 1: [> evm_withdraw_V2 - value <];*/
            /*return _toStringBalanceOf(*/
                /*&m->basic.evm_withdraw_V2.value,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*default:*/
            /*return parser_no_data;*/
        /*}*/
    /*case 8705: [> module 34 call 1 <]*/
        /*switch (itemIdx) {*/
        /*case 0: [> evm_call_V2 - source <];*/
            /*return _toStringH160_V2(*/
                /*&m->basic.evm_call_V2.source,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 1: [> evm_call_V2 - target <];*/
            /*return _toStringH160_V2(*/
                /*&m->basic.evm_call_V2.target,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 2: [> evm_call_V2 - input <];*/
            /*return _toStringBytes(*/
                /*&m->basic.evm_call_V2.input,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 3: [> evm_call_V2 - value <];*/
            /*return _toStringU256_V2(*/
                /*&m->basic.evm_call_V2.value,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 4: [> evm_call_V2 - gas_limit <];*/
            /*return _toStringu32(*/
                /*&m->basic.evm_call_V2.gas_limit,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 5: [> evm_call_V2 - gas_price <];*/
            /*return _toStringU256_V2(*/
                /*&m->basic.evm_call_V2.gas_price,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 6: [> evm_call_V2 - nonce <];*/
            /*return _toStringOptionU256_V2(*/
                /*&m->basic.evm_call_V2.nonce,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*default:*/
            /*return parser_no_data;*/
        /*}*/
    /*case 8706: [> module 34 call 2 <]*/
        /*switch (itemIdx) {*/
        /*case 0: [> evm_create_V2 - source <];*/
            /*return _toStringH160_V2(*/
                /*&m->basic.evm_create_V2.source,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 1: [> evm_create_V2 - init <];*/
            /*return _toStringBytes(*/
                /*&m->basic.evm_create_V2.init,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 2: [> evm_create_V2 - value <];*/
            /*return _toStringU256_V2(*/
                /*&m->basic.evm_create_V2.value,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 3: [> evm_create_V2 - gas_limit <];*/
            /*return _toStringu32(*/
                /*&m->basic.evm_create_V2.gas_limit,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 4: [> evm_create_V2 - gas_price <];*/
            /*return _toStringU256_V2(*/
                /*&m->basic.evm_create_V2.gas_price,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 5: [> evm_create_V2 - nonce <];*/
            /*return _toStringOptionU256_V2(*/
                /*&m->basic.evm_create_V2.nonce,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*default:*/
            /*return parser_no_data;*/
        /*}*/
    /*case 8707: [> module 34 call 3 <]*/
        /*switch (itemIdx) {*/
        /*case 0: [> evm_create2_V2 - source <];*/
            /*return _toStringH160_V2(*/
                /*&m->basic.evm_create2_V2.source,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 1: [> evm_create2_V2 - init <];*/
            /*return _toStringBytes(*/
                /*&m->basic.evm_create2_V2.init,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 2: [> evm_create2_V2 - salt <];*/
            /*return _toStringH256_V2(*/
                /*&m->basic.evm_create2_V2.salt,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 3: [> evm_create2_V2 - value <];*/
            /*return _toStringU256_V2(*/
                /*&m->basic.evm_create2_V2.value,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 4: [> evm_create2_V2 - gas_limit <];*/
            /*return _toStringu32(*/
                /*&m->basic.evm_create2_V2.gas_limit,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 5: [> evm_create2_V2 - gas_price <];*/
            /*return _toStringU256_V2(*/
                /*&m->basic.evm_create2_V2.gas_price,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*case 6: [> evm_create2_V2 - nonce <];*/
            /*return _toStringOptionU256_V2(*/
                /*&m->basic.evm_create2_V2.nonce,*/
                /*outValue, outValueLen,*/
                /*pageIdx, pageCount);*/
        /*default:*/
            /*return parser_no_data;*/
        /*}*/
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 8451: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 8463: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 8469: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    /*case 8705: // EVM:Call*/
        /*switch (itemIdx) {*/
        /*case 6: // Nonce*/
            /*return true;*/
        /*default:*/
            /*return false;*/
        /*}*/
    /*case 8706: // EVM:Create*/
        /*switch (itemIdx) {*/
        /*case 5: // Nonce*/
            /*return true;*/
        /*default:*/
            /*return false;*/
        /*}*/
    /*case 8707: // EVM:Create2*/
        /*switch (itemIdx) {*/
        /*case 6: // Nonce*/
            /*return true;*/
        /*default:*/
            /*return false;*/
        /*}*/
    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: // Timestamp:Set
    case 768: // Sudo:Sudo
    case 769: // Sudo:Sudo unchecked weight
    case 770: // Sudo:Set key
    case 771: // Sudo:Sudo as
    case 1024: // Scheduler:Schedule
    case 1025: // Scheduler:Cancel
    case 1026: // Scheduler:Schedule named
    case 1027: // Scheduler:Cancel named
    case 1028: // Scheduler:Schedule after
    case 1029: // Scheduler:Schedule named after
    case 1280: // Indices:Claim
    case 1281: // Indices:Transfer
    case 1282: // Indices:Free
    case 1283: // Indices:Force transfer
    case 1284: // Indices:Freeze
    case 7680: // Authorship:Set uncles
    case 8192: // Grandpa:Report equivocation
    case 8193: // Grandpa:Report equivocation unsigned
    case 8194: // Grandpa:Note stalled
    case 8448: // Staking:Bond
    case 8449: // Staking:Bond extra
    case 8450: // Staking:Unbond
    case 8451: // Staking:Withdraw Unbonded
    case 8452: // Staking:Validate
    case 8453: // Staking:Nominate
    case 8454: // Staking:Chill
    case 8455: // Staking:Set payee
    case 8456: // Staking:Set controller
    case 8457: // Staking:Set validator count
    case 8458: // Staking:Increase validator count
    case 8459: // Staking:Scale validator count
    case 8460: // Staking:Force no eras
    case 8461: // Staking:Force new era
    case 8462: // Staking:Set invulnerables
    case 8463: // Staking:Force unstake
    case 8464: // Staking:Force new era always
    case 8465: // Staking:Cancel deferred slash
    case 8466: // Staking:Payout stakers
    case 8467: // Staking:Rebond
    case 8468: // Staking:Set history depth
    case 8469: // Staking:Reap stash
    case 8704: // Session:Set keys
    case 8705: // Session:Purge keys
    case 9472: // ImOnline:Heartbeat
    case 10240: // Identity:Add registrar
    case 10241: // Identity:Set identity
    case 10242: // Identity:Set subs
    case 10243: // Identity:Clear identity
    case 10244: // Identity:Request judgement
    case 10245: // Identity:Cancel request
    case 10246: // Identity:Set fee
    case 10247: // Identity:Set account id
    case 10248: // Identity:Set fields
    case 10249: // Identity:Provide judgement
    case 10250: // Identity:Kill identity
    case 10251: // Identity:Add sub
    case 10252: // Identity:Rename sub
    case 10253: // Identity:Remove sub
    case 10254: // Identity:Quit sub
    case 12800: // Council:Set members
    case 12801: // Council:Execute
    case 12802: // Council:Propose
    case 12803: // Council:Vote
    case 12804: // Council:Close
    case 12805: // Council:Disapprove proposal
    /*case 8704: // EVM:Withdraw*/
    /*case 8705: // EVM:Call*/
    /*case 8706: // EVM:Create*/
    /*case 8707: // EVM:Create2*/
        return false;
    default:
        return true;
    }
}
