#include "ServerGMs.h"

void ServerGameMessages::Teleport::Serialize(RakNet::BitStream* bs) {
	bs->Write(bIgnoreY);
	bs->Write(bSetRotation);
	bs->Write(bSkipAllChecks);
	bs->Write<NiPoint3>(pos);
	bs->Write(useNavmesh);
	bs->Write(w != 1.0f);
	if (w != 1.0f) {
		bs->Write<float_t>(w);
	}
	bs->Write<float_t>(x);
	bs->Write<float_t>(y);
	bs->Write<float_t>(z);
}

void ServerGameMessages::DropClientLoot::Serialize(RakNet::BitStream* bs) {
	bs->Write(bUsePosition);
	bs->Write(finalPosition != NiPoint3());
	if (finalPosition != NiPoint3()) {
		bs->Write<NiPoint3>(finalPosition);
	}
	bs->Write<int32_t>(iCurrency);
	bs->Write<int32_t>(itemTemplate);
	bs->Write<int64_t>(lootID);
	bs->Write<int64_t>(owner);
	bs->Write<int64_t>(sourceObj);
	bs->Write(spawnPosition != NiPoint3());
	if (spawnPosition != NiPoint3()) {
		bs->Write<NiPoint3>(spawnPosition);
	}
}

void ServerGameMessages::Die::Serialize(RakNet::BitStream* bs) {
	bs->Write(bClientDeath);
	bs->Write(bSpawnLoot);
	bs->Write<uint32_t>(deathType.size());
	bs->Write(reinterpret_cast<const char*>(deathType.c_str()), deathType.size() * 2); // utf-16 string
	bs->Write<float_t>(directionRelative_AngleXZ);
	bs->Write<float_t>(directionRelative_AngleY);
	bs->Write<float_t>(directionRelative_Force);
	bs->Write(killType != 0);
	if (killType != 0) {
		bs->Write<uint32_t>(killType);
	}
	bs->Write<int64_t>(killerID);
	bs->Write(lootOwnerID != 0);
	if (lootOwnerID != 0) {
		bs->Write<int64_t>(lootOwnerID);
	}
}

void ServerGameMessages::PreloadAnimation::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(animationID.size());
	bs->Write(reinterpret_cast<const char*>(animationID.c_str()), animationID.size() * 2); // utf-16 string
	bs->Write(handled);
	bs->Write<int64_t>(respondObjID);
	bs->Write<uint32_t>(userData.size());
	bs->Write(reinterpret_cast<const char*>(userData.c_str()), userData.size() * 2); // utf-16 string
}

void ServerGameMessages::PlayAnimation::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(animationID.size());
	bs->Write(reinterpret_cast<const char*>(animationID.c_str()), animationID.size() * 2); // utf-16 string
	bs->Write(bExpectAnimToExist);
	bs->Write(bPlayImmediate);
	bs->Write(bTriggerOnCompleteMsg);
	bs->Write(fPriority != 0.400000005960465f);
	if (fPriority != 0.400000005960465f) {
		bs->Write<float_t>(fPriority);
	}
	bs->Write(fScale != 1.0f);
	if (fScale != 1.0f) {
		bs->Write<float_t>(fScale);
	}
}

void ServerGameMessages::SetName::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(name.size());
	bs->Write(reinterpret_cast<const char*>(name.c_str()), name.size() * 2); // utf-16 string
}

void ServerGameMessages::EchoStartSkill::Serialize(RakNet::BitStream* bs) {
	bs->Write(bUsedMouse);
	bs->Write(fCasterLatency != 0.0f);
	if (fCasterLatency != 0.0f) {
		bs->Write<float_t>(fCasterLatency);
	}
	bs->Write(iCastType != 0);
	if (iCastType != 0) {
		bs->Write<int32_t>(iCastType);
	}
	bs->Write(lastClickedPosit != NiPoint3());
	if (lastClickedPosit != NiPoint3()) {
		bs->Write<NiPoint3>(lastClickedPosit);
	}
	bs->Write<int64_t>(optionalOriginatorID);
	bs->Write(optionalTargetID != 0);
	if (optionalTargetID != 0) {
		bs->Write<int64_t>(optionalTargetID);
	}
	bs->Write(originatorRot != NiQuaternion());
	if (originatorRot != NiQuaternion()) {
		bs->Write<NiQuaternion>(originatorRot);
	}
	bs->Write<uint32_t>(sBitStream.size());
	bs->Write(reinterpret_cast<const char*>(sBitStream.c_str()), sBitStream.size()); // utf-8 string
	bs->Write<uint32_t>(skillID);
	bs->Write(uiSkillHandle != 0);
	if (uiSkillHandle != 0) {
		bs->Write<uint32_t>(uiSkillHandle);
	}
}

void ServerGameMessages::AddSkill::Serialize(RakNet::BitStream* bs) {
	bs->Write(AICombatWeight != 0);
	if (AICombatWeight != 0) {
		bs->Write<int32_t>(AICombatWeight);
	}
	bs->Write(bFromSkillSet);
	bs->Write(castType != 0);
	if (castType != 0) {
		bs->Write<int32_t>(castType);
	}
	bs->Write(fTimeSecs != -1.0f);
	if (fTimeSecs != -1.0f) {
		bs->Write<float_t>(fTimeSecs);
	}
	bs->Write(iTimesCanCast != -1);
	if (iTimesCanCast != -1) {
		bs->Write<int32_t>(iTimesCanCast);
	}
	bs->Write<uint32_t>(skillID);
	bs->Write(slotID != -1);
	if (slotID != -1) {
		bs->Write<int32_t>(slotID);
	}
	bs->Write(temporary);
}

void ServerGameMessages::RemoveSkill::Serialize(RakNet::BitStream* bs) {
	bs->Write(bFromSkillSet);
	bs->Write<uint32_t>(skillID);
}

void ServerGameMessages::SetCurrency::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(currency);
	bs->Write(lootType != -1);
	if (lootType != -1) {
		bs->Write<int32_t>(lootType);
	}
	bs->Write<NiPoint3>(position);
	bs->Write(sourceLOT != -1);
	if (sourceLOT != -1) {
		bs->Write<int32_t>(sourceLOT);
	}
	bs->Write(sourceObject != 0);
	if (sourceObject != 0) {
		bs->Write<int64_t>(sourceObject);
	}
	bs->Write(sourceTradeID != 0);
	if (sourceTradeID != 0) {
		bs->Write<int64_t>(sourceTradeID);
	}
	bs->Write(sourceType != -1);
	if (sourceType != -1) {
		bs->Write<int32_t>(sourceType);
	}
}

void ServerGameMessages::TeamPickupItem::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(lootID);
	bs->Write<int64_t>(lootOwnerID);
}

void ServerGameMessages::PlayFXEffect::Serialize(RakNet::BitStream* bs) {
	bs->Write(effectID != -1);
	if (effectID != -1) {
		bs->Write<int32_t>(effectID);
	}
	bs->Write<uint32_t>(effectType.size());
	bs->Write(reinterpret_cast<const char*>(effectType.c_str()), effectType.size() * 2); // utf-16 string
	bs->Write(fScale != 1.0f);
	if (fScale != 1.0f) {
		bs->Write<float_t>(fScale);
	}
	bs->Write<uint32_t>(name.size());
	bs->Write(reinterpret_cast<const char*>(name.c_str()), name.size()); // utf-8 string
	bs->Write(priority != 1.0);
	if (priority != 1.0) {
		bs->Write<float_t>(priority);
	}
	bs->Write(secondary != 0);
	if (secondary != 0) {
		bs->Write<int64_t>(secondary);
	}
	bs->Write(serialize);
}

void ServerGameMessages::StopFXEffect::Serialize(RakNet::BitStream* bs) {
	bs->Write(bKillImmediate);
	bs->Write<uint32_t>(name.size());
	bs->Write(reinterpret_cast<const char*>(name.c_str()), name.size()); // utf-8 string
}

void ServerGameMessages::Resurrect::Serialize(RakNet::BitStream* bs) {
	bs->Write(bRezImmediately);
}

void ServerGameMessages::SetStunned::Serialize(RakNet::BitStream* bs) {
	bs->Write(Originator != 0);
	if (Originator != 0) {
		bs->Write<int64_t>(Originator);
	}
	bs->Write<uint32_t>(StateChangeType);
	bs->Write(bCantAttack);
	bs->Write(bCantAttackOutChangeWasApplied);
	bs->Write(bCantEquip);
	bs->Write(bCantEquipOutChangeWasApplied);
	bs->Write(bCantInteract);
	bs->Write(bCantInteractOutChangeWasApplied);
	bs->Write(bCantJump);
	bs->Write(bCantJumpOutChangeWasApplied);
	bs->Write(bCantMove);
	bs->Write(bCantMoveOutChangeWasApplied);
	bs->Write(bCantTurn);
	bs->Write(bCantTurnOutChangeWasApplied);
	bs->Write(bCantUseItem);
	bs->Write(bCantUseItemOutChangeWasApplied);
	bs->Write(bDontTerminateInteract);
	bs->Write(bIgnoreImmunity);
}

void ServerGameMessages::SetStunImmunity::Serialize(RakNet::BitStream* bs) {
	bs->Write(Caster != 0);
	if (Caster != 0) {
		bs->Write<int64_t>(Caster);
	}
	bs->Write<uint32_t>(StateChangeType);
	bs->Write(bImmuneToStunAttack);
	bs->Write(bImmuneToStunEquip);
	bs->Write(bImmuneToStunInteract);
	bs->Write(bImmuneToStunJump);
	bs->Write(bImmuneToStunMove);
	bs->Write(bImmuneToStunTurn);
	bs->Write(bImmuneToStunUseItem);
}

void ServerGameMessages::Knockback::Serialize(RakNet::BitStream* bs) {
	bs->Write(Caster != 0);
	if (Caster != 0) {
		bs->Write<int64_t>(Caster);
	}
	bs->Write(Originator != 0);
	if (Originator != 0) {
		bs->Write<int64_t>(Originator);
	}
	bs->Write(iKnockBackTimeMS != 0);
	if (iKnockBackTimeMS != 0) {
		bs->Write<int32_t>(iKnockBackTimeMS);
	}
	bs->Write<NiPoint3>(vector);
}

void ServerGameMessages::EnableRebuild::Serialize(RakNet::BitStream* bs) {
	bs->Write(bEnable);
	bs->Write(bFail);
	bs->Write(bSuccess);
	bs->Write(eFailReason != 0);
	if (eFailReason != 0) {
		bs->Write<uint32_t>(eFailReason);
	}
	bs->Write<float_t>(fDuration);
	bs->Write<int64_t>(user);
}

void ServerGameMessages::MoveItemInInventory::Serialize(RakNet::BitStream* bs) {
	bs->Write(destInvType != 100);
	if (destInvType != 100) {
		bs->Write<int32_t>(destInvType);
	}
	bs->Write<int64_t>(iObjID);
	bs->Write<int32_t>(inventoryType);
	bs->Write<int32_t>(responseCode);
	bs->Write<int32_t>(slot);
}

void ServerGameMessages::AddItemToInventoryClientSync::Serialize(RakNet::BitStream* bs) {
	bs->Write(bBound);
	bs->Write(bIsBOE);
	bs->Write(bIsBOP);
	bs->Write(eLootTypeSource != -1);
	if (eLootTypeSource != -1) {
		bs->Write<int32_t>(eLootTypeSource);
	}
	bs->Write<uint32_t>(extraInfo.size());
	bs->Write(reinterpret_cast<const char*>(extraInfo.c_str()), extraInfo.size() * 2); // utf-16 string
	bs->Write<int32_t>(iObjTemplate);
	bs->Write(iSubkey != 0);
	if (iSubkey != 0) {
		bs->Write<int64_t>(iSubkey);
	}
	bs->Write(invType != -1);
	if (invType != -1) {
		bs->Write<int32_t>(invType);
	}
	bs->Write(itemCount != 1);
	if (itemCount != 1) {
		bs->Write<uint32_t>(itemCount);
	}
	bs->Write(itemsTotal != 0);
	if (itemsTotal != 0) {
		bs->Write<uint32_t>(itemsTotal);
	}
	bs->Write<int64_t>(newObjID);
	bs->Write<NiPoint3>(ni3FlyingLootPosit);
	bs->Write(showFlyingLoot);
	bs->Write<int32_t>(slotID);
}

void ServerGameMessages::RemoveItemFromInventory::Serialize(RakNet::BitStream* bs) {
	bs->Write(bConfirmed);
	bs->Write(bDeleteItem);
	bs->Write(bOutSuccess);
	bs->Write(eInvType != 100);
	if (eInvType != 100) {
		bs->Write<int32_t>(eInvType);
	}
	bs->Write(eLootTypeSource != -1);
	if (eLootTypeSource != -1) {
		bs->Write<int32_t>(eLootTypeSource);
	}
	bs->Write<uint32_t>(extraInfo.size());
	bs->Write(reinterpret_cast<const char*>(extraInfo.c_str()), extraInfo.size() * 2); // utf-16 string
	bs->Write(forceDeletion);
	bs->Write(iLootTypeSourceID != 0);
	if (iLootTypeSourceID != 0) {
		bs->Write<int64_t>(iLootTypeSourceID);
	}
	bs->Write(iObjID != 0);
	if (iObjID != 0) {
		bs->Write<int64_t>(iObjID);
	}
	bs->Write(iObjTemplate != -1);
	if (iObjTemplate != -1) {
		bs->Write<int32_t>(iObjTemplate);
	}
	bs->Write(iRequestingObjID != 0);
	if (iRequestingObjID != 0) {
		bs->Write<int64_t>(iRequestingObjID);
	}
	bs->Write(iStackCount != 1);
	if (iStackCount != 1) {
		bs->Write<uint32_t>(iStackCount);
	}
	bs->Write(iStackRemaining != 0);
	if (iStackRemaining != 0) {
		bs->Write<uint32_t>(iStackRemaining);
	}
	bs->Write(iSubkey != 0);
	if (iSubkey != 0) {
		bs->Write<int64_t>(iSubkey);
	}
	bs->Write(iTradeID != 0);
	if (iTradeID != 0) {
		bs->Write<int64_t>(iTradeID);
	}
}

void ServerGameMessages::EquipInventory::Serialize(RakNet::BitStream* bs) {
	bs->Write(bIgnoreCooldown);
	bs->Write(bOutSuccess);
	bs->Write<int64_t>(itemtoequip);
}

void ServerGameMessages::UnEquipInventory::Serialize(RakNet::BitStream* bs) {
	bs->Write(bEvenIfDead);
	bs->Write(bIgnoreCooldown);
	bs->Write(bOutSuccess);
	bs->Write<int64_t>(itemtounequip);
	bs->Write(replacementObjectID != 0);
	if (replacementObjectID != 0) {
		bs->Write<int64_t>(replacementObjectID);
	}
}

void ServerGameMessages::OfferMission::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(missionID);
	bs->Write<int64_t>(offerer);
}

void ServerGameMessages::NotifyMission::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(missionID);
	bs->Write<int32_t>(missionState);
	bs->Write(sendingRewards);
}

void ServerGameMessages::RebuildNotifyState::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(iPrevState);
	bs->Write<int32_t>(iState);
	bs->Write<int64_t>(player);
}

void ServerGameMessages::ToggleInteractionUpdates::Serialize(RakNet::BitStream* bs) {
	bs->Write(bEnable);
}

void ServerGameMessages::TerminateInteraction::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(ObjIDTerminator);
	bs->Write<uint32_t>(type);
}

void ServerGameMessages::VendorOpenWindow::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::EmotePlayed::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(emoteID);
	bs->Write<int64_t>(targetID);
}

void ServerGameMessages::TeamSetOffWorldFlag::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(i64PlayerID);
	bs->Write<int64_t>(zoneID);
}

void ServerGameMessages::SetInventorySize::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(inventoryType);
	bs->Write<int32_t>(size);
}

void ServerGameMessages::ActivityEnter::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::ActivityExit::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::ActivityStart::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::ActivityStop::Serialize(RakNet::BitStream* bs) {
	bs->Write(bExit);
	bs->Write(bUserCancel);
}

void ServerGameMessages::CancelMission::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(missionID);
	bs->Write(resetCompleted);
}

void ServerGameMessages::ResetMissions::Serialize(RakNet::BitStream* bs) {
	bs->Write(missionID != -1);
	if (missionID != -1) {
		bs->Write<int32_t>(missionID);
	}
}

void ServerGameMessages::NotifyClientShootingGalleryScore::Serialize(RakNet::BitStream* bs) {
	bs->Write<float_t>(addTime);
	bs->Write<int32_t>(score);
	bs->Write<int64_t>(target);
	bs->Write<NiPoint3>(targetPos);
}

void ServerGameMessages::SetUserCtrlCompPause::Serialize(RakNet::BitStream* bs) {
	bs->Write(bPaused);
}

void ServerGameMessages::NotifyClientFlagChange::Serialize(RakNet::BitStream* bs) {
	bs->Write(bFlag);
	bs->Write<int32_t>(iFlagID);
}

void ServerGameMessages::Help::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(iHelpID);
}

void ServerGameMessages::VendorTransactionResult::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(iResult);
}

void ServerGameMessages::HasBeenCollectedByClient::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(playerID);
}

void ServerGameMessages::PlayerReady::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::TransferToZone::Serialize(RakNet::BitStream* bs) {
	bs->Write(bCheckTransferAllowed);
	bs->Write(cloneID != 0);
	if (cloneID != 0) {
		bs->Write<uint32_t>(cloneID);
	}
	bs->Write(pos_x != FLT_MAX);
	if (pos_x != FLT_MAX) {
		bs->Write<float_t>(pos_x);
	}
	bs->Write(pos_y != FLT_MAX);
	if (pos_y != FLT_MAX) {
		bs->Write<float_t>(pos_y);
	}
	bs->Write(pos_z != FLT_MAX);
	if (pos_z != FLT_MAX) {
		bs->Write<float_t>(pos_z);
	}
	bs->Write(rot_w != 1);
	if (rot_w != 1) {
		bs->Write<float_t>(rot_w);
	}
	bs->Write(rot_x != 0);
	if (rot_x != 0) {
		bs->Write<float_t>(rot_x);
	}
	bs->Write(rot_y != 0);
	if (rot_y != 0) {
		bs->Write<float_t>(rot_y);
	}
	bs->Write(rot_z != 0);
	if (rot_z != 0) {
		bs->Write<float_t>(rot_z);
	}
	bs->Write<uint32_t>(spawnPoint.size());
	bs->Write(reinterpret_cast<const char*>(spawnPoint.c_str()), spawnPoint.size() * 2); // utf-16 string
	bs->Write<uint8_t>(ucInstanceType);
	bs->Write(zoneID != 0);
	if (zoneID != 0) {
		bs->Write<uint16_t>(zoneID);
	}
}

void ServerGameMessages::TransferToZoneCheckedIM::Serialize(RakNet::BitStream* bs) {
	bs->Write(bIsThereaQueue);
	bs->Write(cloneID != 0);
	if (cloneID != 0) {
		bs->Write<uint32_t>(cloneID);
	}
	bs->Write(pos_x != FLT_MAX);
	if (pos_x != FLT_MAX) {
		bs->Write<float_t>(pos_x);
	}
	bs->Write(pos_y != FLT_MAX);
	if (pos_y != FLT_MAX) {
		bs->Write<float_t>(pos_y);
	}
	bs->Write(pos_z != FLT_MAX);
	if (pos_z != FLT_MAX) {
		bs->Write<float_t>(pos_z);
	}
	bs->Write(rot_w != 1);
	if (rot_w != 1) {
		bs->Write<float_t>(rot_w);
	}
	bs->Write(rot_x != 0);
	if (rot_x != 0) {
		bs->Write<float_t>(rot_x);
	}
	bs->Write(rot_y != 0);
	if (rot_y != 0) {
		bs->Write<float_t>(rot_y);
	}
	bs->Write(rot_z != 0);
	if (rot_z != 0) {
		bs->Write<float_t>(rot_z);
	}
	bs->Write<uint32_t>(spawnPoint.size());
	bs->Write(reinterpret_cast<const char*>(spawnPoint.c_str()), spawnPoint.size() * 2); // utf-16 string
	bs->Write<uint8_t>(ucInstanceType);
	bs->Write(zoneID != 0);
	if (zoneID != 0) {
		bs->Write<uint16_t>(zoneID);
	}
}

void ServerGameMessages::InvalidZoneTransferList::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(CustomerFeedbackURL.size());
	bs->Write(reinterpret_cast<const char*>(CustomerFeedbackURL.c_str()), CustomerFeedbackURL.size() * 2); // utf-16 string
	bs->Write<uint32_t>(InvalidMapTransferList.size());
	bs->Write(reinterpret_cast<const char*>(InvalidMapTransferList.c_str()), InvalidMapTransferList.size() * 2); // utf-16 string
	bs->Write(bCustomerFeedbackOnExit);
	bs->Write(bCustomerFeedbackOnInvalidMapTransfer);
}

void ServerGameMessages::TransferToLastNonInstance::Serialize(RakNet::BitStream* bs) {
	bs->Write(bUseLastPosition);
	bs->Write<int64_t>(playerID);
	bs->Write(pos_x != FLT_MAX);
	if (pos_x != FLT_MAX) {
		bs->Write<float_t>(pos_x);
	}
	bs->Write(pos_y != FLT_MAX);
	if (pos_y != FLT_MAX) {
		bs->Write<float_t>(pos_y);
	}
	bs->Write(pos_z != FLT_MAX);
	if (pos_z != FLT_MAX) {
		bs->Write<float_t>(pos_z);
	}
	bs->Write(rot_w != 1);
	if (rot_w != 1) {
		bs->Write<float_t>(rot_w);
	}
	bs->Write(rot_x != 0);
	if (rot_x != 0) {
		bs->Write<float_t>(rot_x);
	}
	bs->Write(rot_y != 0);
	if (rot_y != 0) {
		bs->Write<float_t>(rot_y);
	}
	bs->Write(rot_z != 0);
	if (rot_z != 0) {
		bs->Write<float_t>(rot_z);
	}
}

void ServerGameMessages::DisplayMessageBox::Serialize(RakNet::BitStream* bs) {
	bs->Write(bShow);
	bs->Write<int64_t>(callbackClient);
	bs->Write<uint32_t>(identifier.size());
	bs->Write(reinterpret_cast<const char*>(identifier.c_str()), identifier.size() * 2); // utf-16 string
	bs->Write<int32_t>(imageID);
	bs->Write<uint32_t>(text.size());
	bs->Write(reinterpret_cast<const char*>(text.c_str()), text.size() * 2); // utf-16 string
	bs->Write<uint32_t>(userData.size());
	bs->Write(reinterpret_cast<const char*>(userData.c_str()), userData.size() * 2); // utf-16 string
}

void ServerGameMessages::Smash::Serialize(RakNet::BitStream* bs) {
	bs->Write(bIgnoreObjectVisibility);
	bs->Write<float_t>(force);
	bs->Write<float_t>(ghostOpacity);
	bs->Write<int64_t>(killerID);
}

void ServerGameMessages::UnSmash::Serialize(RakNet::BitStream* bs) {
	bs->Write(builderID != 0);
	if (builderID != 0) {
		bs->Write<int64_t>(builderID);
	}
	bs->Write(duration != 3.0f);
	if (duration != 3.0f) {
		bs->Write<float_t>(duration);
	}
}

void ServerGameMessages::SetGravityScale::Serialize(RakNet::BitStream* bs) {
	bs->Write<float_t>(scale);
}

void ServerGameMessages::PlaceModelResponse::Serialize(RakNet::BitStream* bs) {
	bs->Write(position != NiPoint3());
	if (position != NiPoint3()) {
		bs->Write<NiPoint3>(position);
	}
	bs->Write(propertyPlaqueID != 0);
	if (propertyPlaqueID != 0) {
		bs->Write<int64_t>(propertyPlaqueID);
	}
	bs->Write(response != 0);
	if (response != 0) {
		bs->Write<int32_t>(response);
	}
	bs->Write(rotation != NiQuaternion());
	if (rotation != NiQuaternion()) {
		bs->Write<NiQuaternion>(rotation);
	}
}

void ServerGameMessages::SetJetPackMode::Serialize(RakNet::BitStream* bs) {
	bs->Write(bBypassChecks);
	bs->Write(bDoHover);
	bs->Write(bUse);
	bs->Write(effectID != -1);
	if (effectID != -1) {
		bs->Write<int32_t>(effectID);
	}
	bs->Write(fAirspeed != 10);
	if (fAirspeed != 10) {
		bs->Write<float_t>(fAirspeed);
	}
	bs->Write(fMaxAirspeed != 15);
	if (fMaxAirspeed != 15) {
		bs->Write<float_t>(fMaxAirspeed);
	}
	bs->Write(fVertVel != 1);
	if (fVertVel != 1) {
		bs->Write<float_t>(fVertVel);
	}
	bs->Write(iWarningEffectID != -1);
	if (iWarningEffectID != -1) {
		bs->Write<int32_t>(iWarningEffectID);
	}
}

void ServerGameMessages::RegisterPetID::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(objID);
}

void ServerGameMessages::RegisterPetDBID::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(petDBID);
}

void ServerGameMessages::ShowActivityCountdown::Serialize(RakNet::BitStream* bs) {
	bs->Write(bPlayAdditionalSound);
	bs->Write(bPlayCountdownSound);
	bs->Write<uint32_t>(sndName.size());
	bs->Write(reinterpret_cast<const char*>(sndName.c_str()), sndName.size() * 2); // utf-16 string
	bs->Write<int32_t>(stateToPlaySoundOn);
}

void ServerGameMessages::DisplayTooltip::Serialize(RakNet::BitStream* bs) {
	bs->Write(DoOrDie);
	bs->Write(NoRepeat);
	bs->Write(NoRevive);
	bs->Write(bIsPropertyTooltip);
	bs->Write(bShow);
	bs->Write(bTranslate);
	bs->Write<int32_t>(iTime);
	bs->Write<uint32_t>(id.size());
	bs->Write(reinterpret_cast<const char*>(id.c_str()), id.size() * 2); // utf-16 string
	bs->Write<uint32_t>(localizeParams.size());
	bs->Write(reinterpret_cast<const char*>(localizeParams.c_str()), localizeParams.size() * 2); // utf-16 string
	bs->Write<uint32_t>(strImageName.size());
	bs->Write(reinterpret_cast<const char*>(strImageName.c_str()), strImageName.size() * 2); // utf-16 string
	bs->Write<uint32_t>(strText.size());
	bs->Write(reinterpret_cast<const char*>(strText.c_str()), strText.size() * 2); // utf-16 string
}

void ServerGameMessages::StartActivityTime::Serialize(RakNet::BitStream* bs) {
	bs->Write<float_t>(startTime);
}

void ServerGameMessages::ActivityPause::Serialize(RakNet::BitStream* bs) {
	bs->Write(bPause);
}

void ServerGameMessages::UseItemResult::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(m_ItemTemplateID);
	bs->Write(m_UseItemResult);
}

void ServerGameMessages::PetResponse::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(ObjIDPet);
	bs->Write<int32_t>(iPetCommandType);
	bs->Write<int32_t>(iResponse);
	bs->Write<int32_t>(iTypeID);
}

void ServerGameMessages::SendActivitySummaryLeaderboardData::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(gameID);
	bs->Write<int32_t>(infoType);
	bs->Write<uint32_t>(leaderboardData.size());
	bs->Write(reinterpret_cast<const char*>(leaderboardData.c_str()), leaderboardData.size() * 2); // utf-16 string
	bs->Write(throttled);
	bs->Write(weekly);
}

void ServerGameMessages::ClientNotifyPet::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(ObjIDSource);
	bs->Write<int32_t>(iPetNotificationType);
}

void ServerGameMessages::NotifyPetTamingMinigame::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(PetID);
	bs->Write<int64_t>(PlayerTamingID);
	bs->Write(bForceTeleport);
	bs->Write<uint32_t>(notifyType);
	bs->Write<NiPoint3>(petsDestPos);
	bs->Write<NiPoint3>(telePos);
	bs->Write(teleRot != NiQuaternion());
	if (teleRot != NiQuaternion()) {
		bs->Write<NiQuaternion>(teleRot);
	}
}

void ServerGameMessages::PetTamingTryBuildResult::Serialize(RakNet::BitStream* bs) {
	bs->Write(bSuccess);
	bs->Write(iNumCorrect != 0);
	if (iNumCorrect != 0) {
		bs->Write<int32_t>(iNumCorrect);
	}
}

void ServerGameMessages::NotifyTamingModelLoadedOnServer::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::AddPetToPlayer::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(iElementalType);
	bs->Write<uint32_t>(name.size());
	bs->Write(reinterpret_cast<const char*>(name.c_str()), name.size() * 2); // utf-16 string
	bs->Write<int64_t>(petDBID);
	bs->Write<int32_t>(petLOT);
}

void ServerGameMessages::SetPetName::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(name.size());
	bs->Write(reinterpret_cast<const char*>(name.c_str()), name.size() * 2); // utf-16 string
	bs->Write(petDBID != 0);
	if (petDBID != 0) {
		bs->Write<int64_t>(petDBID);
	}
}

void ServerGameMessages::PetNameChanged::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(moderationStatus);
	bs->Write<uint32_t>(name.size());
	bs->Write(reinterpret_cast<const char*>(name.c_str()), name.size() * 2); // utf-16 string
	bs->Write<uint32_t>(ownerName.size());
	bs->Write(reinterpret_cast<const char*>(ownerName.c_str()), ownerName.size() * 2); // utf-16 string
}

void ServerGameMessages::ShowPetActionButton::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(ButtonLabel);
	bs->Write(bShow);
}

void ServerGameMessages::SetEmoteLockState::Serialize(RakNet::BitStream* bs) {
	bs->Write(bLock);
	bs->Write<int32_t>(emoteID);
}

void ServerGameMessages::UseItemRequirementsResponse::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(eUseResponse);
}

void ServerGameMessages::PlayEmbeddedEffectOnAllClientsNearObject::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(effectName.size());
	bs->Write(reinterpret_cast<const char*>(effectName.c_str()), effectName.size() * 2); // utf-16 string
	bs->Write<int64_t>(fromObjectID);
	bs->Write<float_t>(radius);
}

void ServerGameMessages::NotifyClientZoneObject::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(name.size());
	bs->Write(reinterpret_cast<const char*>(name.c_str()), name.size() * 2); // utf-16 string
	bs->Write<int32_t>(param1);
	bs->Write<int32_t>(param2);
	bs->Write<int64_t>(paramObj);
	bs->Write<uint32_t>(paramStr.size());
	bs->Write(reinterpret_cast<const char*>(paramStr.c_str()), paramStr.size()); // utf-8 string
}

void ServerGameMessages::UpdateReputation::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(iReputation);
}

void ServerGameMessages::PropertyRentalResponse::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(cloneid);
	bs->Write<int32_t>(code);
	bs->Write<int64_t>(propertyID);
	bs->Write<int64_t>(rentdue);
}

void ServerGameMessages::PlatformResync::Serialize(RakNet::BitStream* bs) {
	bs->Write(bReverse);
	bs->Write(bStopAtDesiredWaypoint);
	bs->Write<int32_t>(eCommand);
	bs->Write<int32_t>(eState);
	bs->Write<int32_t>(eUnexpectedCommand);
	bs->Write<float_t>(fIdleTimeElapsed);
	bs->Write<float_t>(fMoveTimeElapsed);
	bs->Write<float_t>(fPercentBetweenPoints);
	bs->Write<int32_t>(iDesiredWaypointIndex);
	bs->Write<int32_t>(iIndex);
	bs->Write<int32_t>(iNextIndex);
	bs->Write<NiPoint3>(ptUnexpectedLocation);
	bs->Write(qUnexpectedRotation != NiQuaternion());
	if (qUnexpectedRotation != NiQuaternion()) {
		bs->Write<NiQuaternion>(qUnexpectedRotation);
	}
}

void ServerGameMessages::PlayCinematic::Serialize(RakNet::BitStream* bs) {
	bs->Write(allowGhostUpdates);
	bs->Write(bCloseMultiInteract);
	bs->Write(bSendServerNotify);
	bs->Write(bUseControlledObjectForAudioListener);
	bs->Write(endBehavior != 0);
	if (endBehavior != 0) {
		bs->Write<uint32_t>(endBehavior);
	}
	bs->Write(hidePlayerDuringCine);
	bs->Write(leadIn != -1.0f);
	if (leadIn != -1.0f) {
		bs->Write<float_t>(leadIn);
	}
	bs->Write(leavePlayerLockedWhenFinished);
	bs->Write(lockPlayer);
	bs->Write<uint32_t>(pathName.size());
	bs->Write(reinterpret_cast<const char*>(pathName.c_str()), pathName.size() * 2); // utf-16 string
	bs->Write(result);
	bs->Write(skipIfSamePath);
	bs->Write<float_t>(startTimeAdvance);
}

void ServerGameMessages::EndCinematic::Serialize(RakNet::BitStream* bs) {
	bs->Write(leadOut != -1.0f);
	if (leadOut != -1.0f) {
		bs->Write<float_t>(leadOut);
	}
	bs->Write(leavePlayerLocked);
	bs->Write<uint32_t>(pathName.size());
	bs->Write(reinterpret_cast<const char*>(pathName.c_str()), pathName.size() * 2); // utf-16 string
}

void ServerGameMessages::ScriptNetworkVarUpdate::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(tableOfVars.size());
	bs->Write(reinterpret_cast<const char*>(tableOfVars.c_str()), tableOfVars.size() * 2); // utf-16 string
}

void ServerGameMessages::PlayNDAudioEmitter::Serialize(RakNet::BitStream* bs) {
	bs->Write(m_NDAudioCallbackMessageData != 0);
	if (m_NDAudioCallbackMessageData != 0) {
		bs->Write<int64_t>(m_NDAudioCallbackMessageData);
	}
	bs->Write(m_NDAudioEmitterID != 0);
	if (m_NDAudioEmitterID != 0) {
		bs->Write<int64_t>(m_NDAudioEmitterID);
	}
	bs->Write<uint32_t>(m_NDAudioEventGUID.size());
	bs->Write(reinterpret_cast<const char*>(m_NDAudioEventGUID.c_str()), m_NDAudioEventGUID.size()); // utf-8 string
	bs->Write<uint32_t>(m_NDAudioMetaEventName.size());
	bs->Write(reinterpret_cast<const char*>(m_NDAudioMetaEventName.c_str()), m_NDAudioMetaEventName.size()); // utf-8 string
	bs->Write(m_Result);
	bs->Write(m_TargetObjectIDForNDAudioCallbackMessages != 0);
	if (m_TargetObjectIDForNDAudioCallbackMessages != 0) {
		bs->Write<int64_t>(m_TargetObjectIDForNDAudioCallbackMessages);
	}
}

void ServerGameMessages::StopNDAudioEmitter::Serialize(RakNet::BitStream* bs) {
	bs->Write(m_AllowNativeFadeOut);
	bs->Write(m_NDAudioEmitterID != 0);
	if (m_NDAudioEmitterID != 0) {
		bs->Write<int64_t>(m_NDAudioEmitterID);
	}
	bs->Write<uint32_t>(m_NDAudioEventGUID.size());
	bs->Write(reinterpret_cast<const char*>(m_NDAudioEventGUID.c_str()), m_NDAudioEventGUID.size()); // utf-8 string
	bs->Write<uint32_t>(m_NDAudioMetaEventName.size());
	bs->Write(reinterpret_cast<const char*>(m_NDAudioMetaEventName.c_str()), m_NDAudioMetaEventName.size()); // utf-8 string
	bs->Write(m_Result);
}

void ServerGameMessages::SetMissionTypeState::Serialize(RakNet::BitStream* bs) {
	bs->Write(state != 1);
	if (state != 1) {
		bs->Write<uint32_t>(state);
	}
	bs->Write<uint32_t>(subtype.size());
	bs->Write(reinterpret_cast<const char*>(subtype.c_str()), subtype.size()); // utf-8 string
	bs->Write<uint32_t>(type.size());
	bs->Write(reinterpret_cast<const char*>(type.c_str()), type.size()); // utf-8 string
}

void ServerGameMessages::BroadcastTextToChatbox::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(attrs.size());
	bs->Write(reinterpret_cast<const char*>(attrs.c_str()), attrs.size() * 2); // utf-16 string
	bs->Write<uint32_t>(wsText.size());
	bs->Write(reinterpret_cast<const char*>(wsText.c_str()), wsText.size() * 2); // utf-16 string
}

void ServerGameMessages::OpenPropertyVendor::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::ServerTradeInvite::Serialize(RakNet::BitStream* bs) {
	bs->Write(bNeedInvitePopUp);
	bs->Write<int64_t>(i64Requestor);
	bs->Write<uint32_t>(wsName.size());
	bs->Write(reinterpret_cast<const char*>(wsName.c_str()), wsName.size() * 2); // utf-16 string
}

void ServerGameMessages::ServerTradeInitialReply::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(i64Invitee);
	bs->Write<uint32_t>(resultType);
	bs->Write<uint32_t>(wsName.size());
	bs->Write(reinterpret_cast<const char*>(wsName.c_str()), wsName.size() * 2); // utf-16 string
}

void ServerGameMessages::ServerTradeFinalReply::Serialize(RakNet::BitStream* bs) {
	bs->Write(bResult);
	bs->Write<int64_t>(i64Invitee);
	bs->Write<uint32_t>(wsName.size());
	bs->Write(reinterpret_cast<const char*>(wsName.c_str()), wsName.size() * 2); // utf-16 string
}

void ServerGameMessages::ServerTradeAccept::Serialize(RakNet::BitStream* bs) {
	bs->Write(bFirst);
}

void ServerGameMessages::GetLastCustomBuild::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(tokenizedLOTList.size());
	bs->Write(reinterpret_cast<const char*>(tokenizedLOTList.c_str()), tokenizedLOTList.size() * 2); // utf-16 string
}

void ServerGameMessages::SetIgnoreProjectileCollision::Serialize(RakNet::BitStream* bs) {
	bs->Write(bShouldIgnore);
}

void ServerGameMessages::OrientToObject::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(objID);
}

void ServerGameMessages::OrientToPosition::Serialize(RakNet::BitStream* bs) {
	bs->Write<NiPoint3>(ni3Posit);
}

void ServerGameMessages::OrientToAngle::Serialize(RakNet::BitStream* bs) {
	bs->Write(bRelativeToCurrent);
	bs->Write<float_t>(fAngle);
}

void ServerGameMessages::PropertyModerationStatusUpdate::Serialize(RakNet::BitStream* bs) {
	bs->Write(newModerationStatus != -1);
	if (newModerationStatus != -1) {
		bs->Write<int32_t>(newModerationStatus);
	}
	bs->Write<uint32_t>(rejectionReason.size());
	bs->Write(reinterpret_cast<const char*>(rejectionReason.c_str()), rejectionReason.size() * 2); // utf-16 string
}

void ServerGameMessages::RequestClientBounce::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(BounceTargetID);
	bs->Write<NiPoint3>(BounceTargetPosOnServer);
	bs->Write<NiPoint3>(BouncedObjLinVel);
	bs->Write<int64_t>(RequestSourceID);
	bs->Write(bAllBounced);
	bs->Write(bAllowClientOverride);
}

void ServerGameMessages::BouncerActiveStatus::Serialize(RakNet::BitStream* bs) {
	bs->Write(bActive);
}

void ServerGameMessages::MoveInventoryBatch::Serialize(RakNet::BitStream* bs) {
	bs->Write(bAllowPartial);
	bs->Write(bOutSuccess);
	bs->Write(count != 1);
	if (count != 1) {
		bs->Write<uint32_t>(count);
	}
	bs->Write(dstBag != 0);
	if (dstBag != 0) {
		bs->Write<int32_t>(dstBag);
	}
	bs->Write(moveLOT != -1);
	if (moveLOT != -1) {
		bs->Write<int32_t>(moveLOT);
	}
	bs->Write(moveSubkey != 0);
	if (moveSubkey != 0) {
		bs->Write<int64_t>(moveSubkey);
	}
	bs->Write(showFlyingLoot);
	bs->Write(srcBag != 0);
	if (srcBag != 0) {
		bs->Write<int32_t>(srcBag);
	}
	bs->Write(startObjectID != 0);
	if (startObjectID != 0) {
		bs->Write<int64_t>(startObjectID);
	}
}

void ServerGameMessages::ObjectActivatedClient::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(activatorID);
	bs->Write<int64_t>(objectActivatedID);
}

void ServerGameMessages::NotifyClientObject::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(name.size());
	bs->Write(reinterpret_cast<const char*>(name.c_str()), name.size() * 2); // utf-16 string
	bs->Write<int32_t>(param1);
	bs->Write<int32_t>(param2);
	bs->Write<int64_t>(paramObj);
	bs->Write<uint32_t>(paramStr.size());
	bs->Write(reinterpret_cast<const char*>(paramStr.c_str()), paramStr.size()); // utf-8 string
}

void ServerGameMessages::DisplayZoneSummary::Serialize(RakNet::BitStream* bs) {
	bs->Write(isPropertyMap);
	bs->Write(isZoneStart);
	bs->Write(sender != 0);
	if (sender != 0) {
		bs->Write<int64_t>(sender);
	}
}

void ServerGameMessages::ModifyPlayerZoneStatistic::Serialize(RakNet::BitStream* bs) {
	bs->Write(bSet);
	bs->Write<uint32_t>(statName.size());
	bs->Write(reinterpret_cast<const char*>(statName.c_str()), statName.size() * 2); // utf-16 string
	bs->Write(statValue != 0);
	if (statValue != 0) {
		bs->Write<int32_t>(statValue);
	}
	bs->Write(zoneID != 0);
	if (zoneID != 0) {
		bs->Write<uint16_t>(zoneID);
	}
}

void ServerGameMessages::StartArrangingWithItem::Serialize(RakNet::BitStream* bs) {
	bs->Write(bFirstTime);
	bs->Write(buildAreaID != 0);
	if (buildAreaID != 0) {
		bs->Write<int64_t>(buildAreaID);
	}
	bs->Write<NiPoint3>(buildStartPOS);
	bs->Write<int32_t>(sourceBAG);
	bs->Write<int64_t>(sourceID);
	bs->Write<int32_t>(sourceLOT);
	bs->Write<int32_t>(sourceTYPE);
	bs->Write<int64_t>(targetID);
	bs->Write<int32_t>(targetLOT);
	bs->Write<NiPoint3>(targetPOS);
	bs->Write<int32_t>(targetTYPE);
}

void ServerGameMessages::FinishArrangingWithItem::Serialize(RakNet::BitStream* bs) {
	bs->Write(buildAreaID != 0);
	if (buildAreaID != 0) {
		bs->Write<int64_t>(buildAreaID);
	}
	bs->Write<int32_t>(newSourceBAG);
	bs->Write<int64_t>(newSourceID);
	bs->Write<int32_t>(newSourceLOT);
	bs->Write<int32_t>(newSourceTYPE);
	bs->Write<int64_t>(newTargetID);
	bs->Write<int32_t>(newTargetLOT);
	bs->Write<int32_t>(newTargetTYPE);
	bs->Write<NiPoint3>(newtargetPOS);
	bs->Write<int32_t>(oldItemBAG);
	bs->Write<int64_t>(oldItemID);
	bs->Write<int32_t>(oldItemLOT);
	bs->Write<int32_t>(oldItemTYPE);
}

void ServerGameMessages::SetBuildMode::Serialize(RakNet::BitStream* bs) {
	bs->Write(bStart);
	bs->Write(distanceType != -1);
	if (distanceType != -1) {
		bs->Write<int32_t>(distanceType);
	}
	bs->Write(modePaused);
	bs->Write(modeValue != 1);
	if (modeValue != 1) {
		bs->Write<int32_t>(modeValue);
	}
	bs->Write<int64_t>(playerID);
	bs->Write(startPos != NiPoint3());
	if (startPos != NiPoint3()) {
		bs->Write<NiPoint3>(startPos);
	}
}

void ServerGameMessages::BuildModeSet::Serialize(RakNet::BitStream* bs) {
	bs->Write(bStart);
	bs->Write(distanceType != -1);
	if (distanceType != -1) {
		bs->Write<int32_t>(distanceType);
	}
	bs->Write(modePaused);
	bs->Write(modeValue != 1);
	if (modeValue != 1) {
		bs->Write<int32_t>(modeValue);
	}
	bs->Write<int64_t>(playerID);
	bs->Write(startPos != NiPoint3());
	if (startPos != NiPoint3()) {
		bs->Write<NiPoint3>(startPos);
	}
}

void ServerGameMessages::SetBuildModeConfirmed::Serialize(RakNet::BitStream* bs) {
	bs->Write(bStart);
	bs->Write(bWarnVisitors);
	bs->Write(modePaused);
	bs->Write(modeValue != 1);
	if (modeValue != 1) {
		bs->Write<int32_t>(modeValue);
	}
	bs->Write<int64_t>(playerID);
	bs->Write(startPos != NiPoint3());
	if (startPos != NiPoint3()) {
		bs->Write<NiPoint3>(startPos);
	}
}

void ServerGameMessages::BuildModeNotificationReport::Serialize(RakNet::BitStream* bs) {
	bs->Write(bStart);
	bs->Write<int32_t>(numSent);
}

void ServerGameMessages::SetModelToBuild::Serialize(RakNet::BitStream* bs) {
	bs->Write(templateID != -1);
	if (templateID != -1) {
		bs->Write<int32_t>(templateID);
	}
}

void ServerGameMessages::SpawnModelBricks::Serialize(RakNet::BitStream* bs) {
	bs->Write(amount != 0.0f);
	if (amount != 0.0f) {
		bs->Write<float_t>(amount);
	}
	bs->Write(pos != NiPoint3());
	if (pos != NiPoint3()) {
		bs->Write<NiPoint3>(pos);
	}
}

void ServerGameMessages::NotifyClientFailedPrecondition::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(FailedReason.size());
	bs->Write(reinterpret_cast<const char*>(FailedReason.c_str()), FailedReason.size() * 2); // utf-16 string
	bs->Write<int32_t>(PreconditionID);
}

void ServerGameMessages::ModuleAssemblyDBDataForClient::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(assemblyID);
	bs->Write<uint32_t>(blob.size());
	bs->Write(reinterpret_cast<const char*>(blob.c_str()), blob.size() * 2); // utf-16 string
}

void ServerGameMessages::EchoSyncSkill::Serialize(RakNet::BitStream* bs) {
	bs->Write(bDone);
	bs->Write<uint32_t>(sBitStream.size());
	bs->Write(reinterpret_cast<const char*>(sBitStream.c_str()), sBitStream.size()); // utf-8 string
	bs->Write<uint32_t>(uiBehaviorHandle);
	bs->Write<uint32_t>(uiSkillHandle);
}

void ServerGameMessages::DoClientProjectileImpact::Serialize(RakNet::BitStream* bs) {
	bs->Write(i64OrgID != 0);
	if (i64OrgID != 0) {
		bs->Write<int64_t>(i64OrgID);
	}
	bs->Write(i64OwnerID != 0);
	if (i64OwnerID != 0) {
		bs->Write<int64_t>(i64OwnerID);
	}
	bs->Write(i64TargetID != 0);
	if (i64TargetID != 0) {
		bs->Write<int64_t>(i64TargetID);
	}
	bs->Write<uint32_t>(sBitStream.size());
	bs->Write(reinterpret_cast<const char*>(sBitStream.c_str()), sBitStream.size()); // utf-8 string
}

void ServerGameMessages::SetPlayerAllowedRespawn::Serialize(RakNet::BitStream* bs) {
	bs->Write(dontPromptForRespawn);
}

void ServerGameMessages::UncastSkill::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(skillID);
}

void ServerGameMessages::FireEventClientSide::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(args.size());
	bs->Write(reinterpret_cast<const char*>(args.c_str()), args.size() * 2); // utf-16 string
	bs->Write<int64_t>(object);
	bs->Write(param1 != 0);
	if (param1 != 0) {
		bs->Write<int64_t>(param1);
	}
	bs->Write(param2 != -1);
	if (param2 != -1) {
		bs->Write<int32_t>(param2);
	}
	bs->Write<int64_t>(senderID);
}

void ServerGameMessages::ChangeObjectWorldState::Serialize(RakNet::BitStream* bs) {
	bs->Write(newState != 0);
	if (newState != 0) {
		bs->Write<uint32_t>(newState);
	}
}

void ServerGameMessages::VehicleLockInput::Serialize(RakNet::BitStream* bs) {
	bs->Write(bLockWheels);
	bs->Write(bLockedPowerslide);
	bs->Write(fLockedX != 0.0f);
	if (fLockedX != 0.0f) {
		bs->Write<float_t>(fLockedX);
	}
	bs->Write(fLockedY != 0.0f);
	if (fLockedY != 0.0f) {
		bs->Write<float_t>(fLockedY);
	}
}

void ServerGameMessages::VehicleUnlockInput::Serialize(RakNet::BitStream* bs) {
	bs->Write(bLockWheels);
}

void ServerGameMessages::RacingResetPlayerToLastReset::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(playerID);
}

void ServerGameMessages::RacingSetPlayerResetInfo::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(currentLap);
	bs->Write<uint32_t>(furthestResetPlane);
	bs->Write<int64_t>(playerID);
	bs->Write<NiPoint3>(respawnPos);
	bs->Write<uint32_t>(upcomingPlane);
}

void ServerGameMessages::LockNodeRotation::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(nodeName.size());
	bs->Write(reinterpret_cast<const char*>(nodeName.c_str()), nodeName.size()); // utf-8 string
}

void ServerGameMessages::NotifyVehicleOfRacingObject::Serialize(RakNet::BitStream* bs) {
	bs->Write(racingObjectID != 0);
	if (racingObjectID != 0) {
		bs->Write<int64_t>(racingObjectID);
	}
}

void ServerGameMessages::PlayerReachedRespawnCheckpoint::Serialize(RakNet::BitStream* bs) {
	bs->Write<NiPoint3>(pos);
	bs->Write(rot != NiQuaternion());
	if (rot != NiQuaternion()) {
		bs->Write<NiQuaternion>(rot);
	}
}

void ServerGameMessages::HandleUGCEquipPostDeleteBasedOnEditMode::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(invItem);
	bs->Write(itemsTotal != 0);
	if (itemsTotal != 0) {
		bs->Write<int32_t>(itemsTotal);
	}
}

void ServerGameMessages::HandleUGCEquipPreCreateBasedOnEditMode::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(modelCount);
	bs->Write<int64_t>(modelID);
}

void ServerGameMessages::MatchResponse::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(response);
}

void ServerGameMessages::MatchUpdate::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(data.size());
	bs->Write(reinterpret_cast<const char*>(data.c_str()), data.size() * 2); // utf-16 string
	bs->Write<int32_t>(type);
}

void ServerGameMessages::ChangeIdleFlags::Serialize(RakNet::BitStream* bs) {
	bs->Write(off != 0);
	if (off != 0) {
		bs->Write<int32_t>(off);
	}
	bs->Write(on != 0);
	if (on != 0) {
		bs->Write<int32_t>(on);
	}
}

void ServerGameMessages::VehicleAddPassiveBoostAction::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::VehicleRemovePassiveBoostAction::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::NotifyRacingClient::Serialize(RakNet::BitStream* bs) {
	bs->Write(EventType != 0);
	if (EventType != 0) {
		bs->Write<uint32_t>(EventType);
	}
	bs->Write<int32_t>(param1);
	bs->Write<int64_t>(paramObj);
	bs->Write<uint32_t>(paramStr.size());
	bs->Write(reinterpret_cast<const char*>(paramStr.c_str()), paramStr.size() * 2); // utf-16 string
	bs->Write<int64_t>(singleClient);
}

void ServerGameMessages::RacingPlayerLoaded::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(playerID);
	bs->Write<int64_t>(vehicleID);
}

void ServerGameMessages::SetStatusImmunity::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(StateChangeType);
	bs->Write(bImmuneToBasicAttack);
	bs->Write(bImmuneToDOT);
	bs->Write(bImmuneToImaginationGain);
	bs->Write(bImmuneToImaginationLoss);
	bs->Write(bImmuneToInterrupt);
	bs->Write(bImmuneToKnockback);
	bs->Write(bImmuneToPullToPoint);
	bs->Write(bImmuneToQuickbuildInterrupt);
	bs->Write(bImmuneToSpeed);
}

void ServerGameMessages::ActivateBrickMode::Serialize(RakNet::BitStream* bs) {
	bs->Write(buildObjectID != 0);
	if (buildObjectID != 0) {
		bs->Write<int64_t>(buildObjectID);
	}
	bs->Write(buildType != 2);
	if (buildType != 2) {
		bs->Write<uint32_t>(buildType);
	}
	bs->Write(enterBuildFromWorld);
	bs->Write(enterFlag);
}

void ServerGameMessages::SetPetNameModerated::Serialize(RakNet::BitStream* bs) {
	bs->Write(PetDBID != 0);
	if (PetDBID != 0) {
		bs->Write<int64_t>(PetDBID);
	}
	bs->Write<int32_t>(nModerationStatus);
}

void ServerGameMessages::CancelSkillCast::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::ModifyLegoScore::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(score);
	bs->Write(sourceType != -1);
	if (sourceType != -1) {
		bs->Write<int32_t>(sourceType);
	}
}

void ServerGameMessages::RestoreToPostLoadStats::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::SetRailMovement::Serialize(RakNet::BitStream* bs) {
	bs->Write(pathGoForward);
	bs->Write<uint32_t>(pathName.size());
	bs->Write(reinterpret_cast<const char*>(pathName.c_str()), pathName.size() * 2); // utf-16 string
	bs->Write<uint32_t>(pathStart);
	bs->Write(railActivatorComponentID != -1);
	if (railActivatorComponentID != -1) {
		bs->Write<int32_t>(railActivatorComponentID);
	}
	bs->Write(railActivatorObjID != 0);
	if (railActivatorObjID != 0) {
		bs->Write<int64_t>(railActivatorObjID);
	}
}

void ServerGameMessages::StartRailMovement::Serialize(RakNet::BitStream* bs) {
	bs->Write(bDamageImmune);
	bs->Write(bNoAggro);
	bs->Write(bNotifyActivator);
	bs->Write(bShowNameBillboard);
	bs->Write(cameraLocked);
	bs->Write(collisionEnabled);
	bs->Write<uint32_t>(loopSound.size());
	bs->Write(reinterpret_cast<const char*>(loopSound.c_str()), loopSound.size() * 2); // utf-16 string
	bs->Write(pathGoForward);
	bs->Write<uint32_t>(pathName.size());
	bs->Write(reinterpret_cast<const char*>(pathName.c_str()), pathName.size() * 2); // utf-16 string
	bs->Write(pathStart != 0);
	if (pathStart != 0) {
		bs->Write<uint32_t>(pathStart);
	}
	bs->Write(railActivatorComponentID != -1);
	if (railActivatorComponentID != -1) {
		bs->Write<int32_t>(railActivatorComponentID);
	}
	bs->Write(railActivatorObjID != 0);
	if (railActivatorObjID != 0) {
		bs->Write<int64_t>(railActivatorObjID);
	}
	bs->Write<uint32_t>(startSound.size());
	bs->Write(reinterpret_cast<const char*>(startSound.c_str()), startSound.size() * 2); // utf-16 string
	bs->Write<uint32_t>(stopSound.size());
	bs->Write(reinterpret_cast<const char*>(stopSound.c_str()), stopSound.size() * 2); // utf-16 string
	bs->Write(useDB);
}

void ServerGameMessages::NotifyRailActivatorStateChange::Serialize(RakNet::BitStream* bs) {
	bs->Write(bActive);
}

void ServerGameMessages::NotifyRewardMailed::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(objectID);
	bs->Write<NiPoint3>(startPoint);
	bs->Write<int64_t>(subkey);
	bs->Write<int32_t>(templateID);
}

void ServerGameMessages::UpdatePlayerStatistic::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(updateID);
	bs->Write(updateValue != 1);
	if (updateValue != 1) {
		bs->Write<int64_t>(updateValue);
	}
}

void ServerGameMessages::RequeryPropertyModels::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::NotifyNotEnoughInvSpace::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(freeSlotsNeeded);
	bs->Write(inventoryType != -1);
	if (inventoryType != -1) {
		bs->Write<uint32_t>(inventoryType);
	}
}

void ServerGameMessages::NotifyPropertyOfEditMode::Serialize(RakNet::BitStream* bs) {
	bs->Write(bEditingActive);
}

void ServerGameMessages::PropertyEntranceBegin::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::TeamSetLeader::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(i64PlayerID);
}

void ServerGameMessages::TeamInviteConfirm::Serialize(RakNet::BitStream* bs) {
	bs->Write(bLeaderIsFreeTrial);
	bs->Write<int64_t>(i64LeaderID);
	bs->Write<int64_t>(i64LeaderZoneID);
	bs->Write<uint32_t>(SizeOfsTeamBuffer);
	bs->Write(sTeamBuffer, SizeOfsTeamBuffer);
	bs->Write<uint8_t>(ucLootFlag);
	bs->Write<uint8_t>(ucNumOfOtherPlayers);
	bs->Write<uint8_t>(ucResponseCode);
	bs->Write<uint32_t>(wsLeaderName.size());
	bs->Write(reinterpret_cast<const char*>(wsLeaderName.c_str()), wsLeaderName.size() * 2); // utf-16 string
}

void ServerGameMessages::TeamGetStatusResponse::Serialize(RakNet::BitStream* bs) {
	bs->Write<int64_t>(i64LeaderID);
	bs->Write<int64_t>(i64LeaderZoneID);
	bs->Write<uint32_t>(SizeOfsTeamBuffer);
	bs->Write(sTeamBuffer, SizeOfsTeamBuffer);
	bs->Write<uint8_t>(ucLootFlag);
	bs->Write<uint8_t>(ucNumOfOtherPlayers);
	bs->Write<uint32_t>(wsLeaderName.size());
	bs->Write(reinterpret_cast<const char*>(wsLeaderName.c_str()), wsLeaderName.size() * 2); // utf-16 string
}

void ServerGameMessages::TeamAddPlayer::Serialize(RakNet::BitStream* bs) {
	bs->Write(bIsFreeTrial);
	bs->Write(bLocal);
	bs->Write(bNoLootOnDeath);
	bs->Write<int64_t>(i64PlayerID);
	bs->Write<uint32_t>(wsPlayerName.size());
	bs->Write(reinterpret_cast<const char*>(wsPlayerName.c_str()), wsPlayerName.size() * 2); // utf-16 string
	bs->Write(zoneID != 0);
	if (zoneID != 0) {
		bs->Write<int64_t>(zoneID);
	}
}

void ServerGameMessages::TeamRemovePlayer::Serialize(RakNet::BitStream* bs) {
	bs->Write(bDisband);
	bs->Write(bIsKicked);
	bs->Write(bIsLeaving);
	bs->Write(bLocal);
	bs->Write<int64_t>(i64LeaderID);
	bs->Write<int64_t>(i64PlayerID);
	bs->Write<uint32_t>(wsName.size());
	bs->Write(reinterpret_cast<const char*>(wsName.c_str()), wsName.size() * 2); // utf-16 string
}

void ServerGameMessages::SetResurrectRestoreValues::Serialize(RakNet::BitStream* bs) {
	bs->Write(iArmorRestore != -1);
	if (iArmorRestore != -1) {
		bs->Write<int32_t>(iArmorRestore);
	}
	bs->Write(iHealthRestore != -1);
	if (iHealthRestore != -1) {
		bs->Write<int32_t>(iHealthRestore);
	}
	bs->Write(iImaginationRestore != -1);
	if (iImaginationRestore != -1) {
		bs->Write<int32_t>(iImaginationRestore);
	}
}

void ServerGameMessages::SetPropertyModerationStatus::Serialize(RakNet::BitStream* bs) {
	bs->Write(moderationStatus != -1);
	if (moderationStatus != -1) {
		bs->Write<int32_t>(moderationStatus);
	}
}

void ServerGameMessages::UpdatePropertyModelCount::Serialize(RakNet::BitStream* bs) {
	bs->Write(modelCount != 0);
	if (modelCount != 0) {
		bs->Write<uint32_t>(modelCount);
	}
}

void ServerGameMessages::VehicleStopBoost::Serialize(RakNet::BitStream* bs) {
	bs->Write(bAffectPassive);
}

void ServerGameMessages::StartCelebrationEffect::Serialize(RakNet::BitStream* bs) {
	bs->Write<uint32_t>(animation.size());
	bs->Write(reinterpret_cast<const char*>(animation.c_str()), animation.size() * 2); // utf-16 string
	bs->Write(backgroundObject != 11164);
	if (backgroundObject != 11164) {
		bs->Write<int32_t>(backgroundObject);
	}
	bs->Write(cameraPathLOT != 12458);
	if (cameraPathLOT != 12458) {
		bs->Write<int32_t>(cameraPathLOT);
	}
	bs->Write(celeLeadIn != 1.0f);
	if (celeLeadIn != 1.0f) {
		bs->Write<float_t>(celeLeadIn);
	}
	bs->Write(celeLeadOut != 0.8f);
	if (celeLeadOut != 0.8f) {
		bs->Write<float_t>(celeLeadOut);
	}
	bs->Write(celebrationID != -1);
	if (celebrationID != -1) {
		bs->Write<int32_t>(celebrationID);
	}
	bs->Write<float_t>(duration);
	bs->Write<uint32_t>(iconID);
	bs->Write<uint32_t>(mainText.size());
	bs->Write(reinterpret_cast<const char*>(mainText.c_str()), mainText.size() * 2); // utf-16 string
	bs->Write<uint32_t>(mixerProgram.size());
	bs->Write(reinterpret_cast<const char*>(mixerProgram.c_str()), mixerProgram.size()); // utf-8 string
	bs->Write<uint32_t>(musicCue.size());
	bs->Write(reinterpret_cast<const char*>(musicCue.c_str()), musicCue.size()); // utf-8 string
	bs->Write<uint32_t>(pathNodeName.size());
	bs->Write(reinterpret_cast<const char*>(pathNodeName.c_str()), pathNodeName.size()); // utf-8 string
	bs->Write<uint32_t>(soundGUID.size());
	bs->Write(reinterpret_cast<const char*>(soundGUID.c_str()), soundGUID.size()); // utf-8 string
	bs->Write<uint32_t>(subText.size());
	bs->Write(reinterpret_cast<const char*>(subText.c_str()), subText.size() * 2); // utf-16 string
}

void ServerGameMessages::SetLocalTeam::Serialize(RakNet::BitStream* bs) {
	bs->Write(bIsLocal);
}

void ServerGameMessages::ServerDoneLoadingAllObjects::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::AddBuff::Serialize(RakNet::BitStream* bs) {
	bs->Write(bAddedByTeammate);
	bs->Write(bApplyOnTeammates);
	bs->Write(bCancelOnDamageAbsorbRanOut);
	bs->Write(bCancelOnDamaged);
	bs->Write(bCancelOnDeath);
	bs->Write(bCancelOnLogOut);
	bs->Write(bCancelOnMove);
	bs->Write(bCancelOnRemoveBuff);
	bs->Write(bCancelOnUI);
	bs->Write(bCancelOnUnEquip);
	bs->Write(bCancelOnZone);
	bs->Write(bIgnoreImmunities);
	bs->Write(bIsImmunity);
	bs->Write(bUseRefCount);
	bs->Write<int64_t>(casterID);
	bs->Write<int64_t>(i64AddedBy);
	bs->Write<uint32_t>(uiBuffID);
	bs->Write<uint32_t>(uiDurationMS);
}

void ServerGameMessages::RemoveBuff::Serialize(RakNet::BitStream* bs) {
	bs->Write(bFromRemoveBehavior);
	bs->Write(bFromUnEquip);
	bs->Write(bRemoveImmunity);
	bs->Write<uint32_t>(uiBuffID);
}

void ServerGameMessages::PlayerSetCameraCyclingMode::Serialize(RakNet::BitStream* bs) {
	bs->Write(bAllowCyclingWhileDeadOnly);
	bs->Write(cyclingMode != 0);
	if (cyclingMode != 0) {
		bs->Write<uint32_t>(cyclingMode);
	}
}

void ServerGameMessages::SetMountInventoryID::Serialize(RakNet::BitStream* bs) {
	bs->Write(inventoryMountID != 0);
	if (inventoryMountID != 0) {
		bs->Write<int64_t>(inventoryMountID);
	}
}

void ServerGameMessages::NotifyLevelRewards::Serialize(RakNet::BitStream* bs) {
	bs->Write<int32_t>(level);
	bs->Write(sendingRewards);
}

void ServerGameMessages::ClientCancelMoveSkill::Serialize(RakNet::BitStream* bs) {
}

void ServerGameMessages::MarkInventoryItemAsActive::Serialize(RakNet::BitStream* bs) {
	bs->Write(bActive);
	bs->Write(iType != 0);
	if (iType != 0) {
		bs->Write<int32_t>(iType);
	}
	bs->Write(itemID != 0);
	if (itemID != 0) {
		bs->Write<int64_t>(itemID);
	}
}

void ServerGameMessages::VendorStatusUpdate::Serialize(RakNet::BitStream* bs) {
	bs->Write(bUpdateOnly);
	bs->Write<std::uint32_t>(ItemList.size());
	for (auto i : ItemList) {
		bs->Write(i.first);
		bs->Write(i.second);
	}
}