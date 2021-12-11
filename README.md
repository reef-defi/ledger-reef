# Ledger Reef app
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

-------------------

![zondax](docs/zondax.jpg)

_Please visit our website at [zondax.ch](zondax.ch)_

------------------
This project contains the Reef app (https://reef.io/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**

# Reef  2.8.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` _ratio <br/> |
|remark |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` _remark <br/> |
|set_heap_pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|set_code |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> |
|set_code_without_checks |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> |
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> |
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> |
|kill_storage |    |   |   | `Vec<Key>` keys <br/> |
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> |
|suicide |    | :heavy_check_mark: | :heavy_check_mark: |  |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :heavy_check_mark: |   | `Compact<Moment>` now <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_uncles |    |   |   | `Vec<Header>` new_uncles <br/> |

## Indices

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |
|transfer |    | :heavy_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/> |
|free |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |
|force_transfer |    | :heavy_check_mark: |   | `AccountId` new <br/>`AccountIndex` index <br/>`bool` freeze <br/> |
|freeze |    | :heavy_check_mark: |   | `AccountIndex` index <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> |
|set_balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> |
|force_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> |
|transfer_keep_alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> |

## Staking

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupSource` controller <br/>`Compact<BalanceOf>` value <br/>`RewardDestination` payee <br/> |
|bond_extra | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` max_additional <br/> |
|unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/> |
|withdraw_unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> |
|validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> |
|nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<LookupSource>` targets <br/> |
|chill | :heavy_check_mark:  | :heavy_check_mark: |   |  |
|set_payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> |
|set_controller |    | :heavy_check_mark: |   | `LookupSource` controller <br/> |
|set_validator_count |    | :heavy_check_mark: |   | `Compact<u32>` new <br/> |
|increase_validator_count |    | :heavy_check_mark: |   | `Compact<u32>` additional <br/> |
|scale_validator_count |    |   |   | `Percent` factor <br/> |
|force_no_eras |    | :heavy_check_mark: |   |  |
|force_new_era |    | :heavy_check_mark: |   |  |
|set_invulnerables |    | :heavy_check_mark: |   | `Vec<AccountId>` invulnerables <br/> |
|force_unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|force_new_era_always |    | :heavy_check_mark: |   |  |
|cancel_deferred_slash |    | :heavy_check_mark: |   | `EraIndex` era <br/>`Vec<u32>` slash_indices <br/> |
|payout_stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> |
|rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `Compact<BalanceOf>` value <br/> |
|set_history_depth |    | :heavy_check_mark: |   | `Compact<EraIndex>` new_history_depth <br/>`Compact<u32>` _era_items_deleted <br/> |
|reap_stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys | :heavy_check_mark:  |   |   | `Keys` keys <br/>`Bytes` proof <br/> |
|purge_keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## Council

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_members |    | :heavy_check_mark: |   | `Vec<AccountId>` new_members <br/>`Option<AccountId>` prime <br/>`MemberCount` old_count <br/> |
|execute |    |   |   | `Proposal` proposal <br/>`Compact<u32>` length_bound <br/> |
|propose |    |   |   | `Compact<MemberCount>` threshold <br/>`Proposal` proposal <br/>`Compact<u32>` length_bound <br/> |
|vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compact<ProposalIndex>` index <br/>`bool` approve <br/> |
|close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compact<ProposalIndex>` index <br/>`Compact<Weight>` proposal_weight_bound <br/>`Compact<u32>` length_bound <br/> |
|disapprove_proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## Grandpa

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|report_equivocation_unsigned |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|note_stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> |

## Sudo

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|sudo |    |   |   | `Call` call <br/> |
|sudo_unchecked_weight |    |   |   | `Call` call <br/>`Weight` _weight <br/> |
|set_key |    |   |   | `LookupSource` new <br/> |
|sudo_as |    |   |   | `LookupSource` who <br/>`Call` call <br/> |

## ImOnline

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|heartbeat |    |   |   | `Heartbeat` heartbeat <br/>`Signature` _signature <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> |
|set_identity |    |   |   | `IdentityInfo` info <br/> |
|set_subs |    |   |   | `Vec<(AccountId,Data)>` subs <br/> |
|clear_identity |    | :heavy_check_mark: |   |  |
|request_judgement |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` reg_index <br/>`Compact<BalanceOf>` max_fee <br/> |
|cancel_request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> |
|set_fee |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`Compact<BalanceOf>` fee <br/> |
|set_account_id |    | :heavy_check_mark: |   | `Compact<RegistrarIndex>` index <br/>`AccountId` new <br/> |
|set_fields |    |   |   | `Compact<RegistrarIndex>` index <br/>`IdentityFields` fields <br/> |
|provide_judgement |    |   |   | `Compact<RegistrarIndex>` reg_index <br/>`LookupSource` target <br/>`IdentityJudgement` judgement <br/> |
|kill_identity |    | :heavy_check_mark: |   | `LookupSource` target <br/> |
|add_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> |
|rename_sub |    |   |   | `LookupSource` sub <br/>`Data` data <br/> |
|remove_sub |    | :heavy_check_mark: |   | `LookupSource` sub <br/> |
|quit_sub |    | :heavy_check_mark: |   |  |
