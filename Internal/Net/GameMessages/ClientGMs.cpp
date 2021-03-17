#include "ClientGMs.h"

void ClientGameMessages::RequestDie::Deserialize(RakNet::BitStream* bs) {
	bUnknownBoolean = bs->ReadBit();
	deathType = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	bs->Read<float_t>(directionRelative_AngleXZ);
	bs->Read<float_t>(directionRelative_AngleY);
	bs->Read<float_t>(directionRelative_Force);
	if (bs->ReadBit()) bs->Read<uint32_t>(killType);
	bs->Read<int64_t>(killerID);
	bs->Read<int64_t>(lootOwnerID);
}

void ClientGameMessages::PlayEmote::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(emoteID);
	bs->Read<int64_t>(targetID);
}

void ClientGameMessages::StartSkill::Deserialize(RakNet::BitStream* bs) {
	bUsedMouse = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int64_t>(consumableItemID);
	if (bs->ReadBit()) bs->Read<float_t>(fCasterLatency);
	if (bs->ReadBit()) bs->Read<int32_t>(iCastType);
	if (bs->ReadBit()) bs->Read<NiPoint3>(lastClickedPosit);
	bs->Read<int64_t>(optionalOriginatorID);
	if (bs->ReadBit()) bs->Read<int64_t>(optionalTargetID);
	if (bs->ReadBit()) bs->Read<NiQuaternion>(originatorRot);
	sBitStream = Utils::StringFromBitStream<uint32_t>(bs); // utf-8 string
	bs->Read<uint32_t>(skillID);
	if (bs->ReadBit()) bs->Read<uint32_t>(uiSkillHandle);
}

void ClientGameMessages::CasterDead::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(i64Caster);
	if (bs->ReadBit()) bs->Read<uint32_t>(uiSkillHandle);
}

void ClientGameMessages::VerifyAck::Deserialize(RakNet::BitStream* bs) {
	bDifferent = bs->ReadBit();
	sBitStream = Utils::StringFromBitStream<uint32_t>(bs); // utf-8 string
	if (bs->ReadBit()) bs->Read<uint32_t>(uiHandle);
}

void ClientGameMessages::SelectSkill::Deserialize(RakNet::BitStream* bs) {
	bFromSkillSet = bs->ReadBit();
	bs->Read<int32_t>(skillID);
}

void ClientGameMessages::RemoveSkill::Deserialize(RakNet::BitStream* bs) {
	bFromSkillSet = bs->ReadBit();
	bs->Read<uint32_t>(skillID);
}

void ClientGameMessages::PickupCurrency::Deserialize(RakNet::BitStream* bs) {
	bs->Read<uint32_t>(currency);
	bs->Read<NiPoint3>(position);
}

void ClientGameMessages::PickupItem::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(lootObjectID);
	bs->Read<int64_t>(playerID);
}

void ClientGameMessages::RequestResurrect::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::PopEquippedItemsState::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::RebuildCancel::Deserialize(RakNet::BitStream* bs) {
	bEarlyRelease = bs->ReadBit();
	bs->Read<int64_t>(userID);
}

void ClientGameMessages::MoveItemInInventory::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int32_t>(destInvType);
	bs->Read<int64_t>(iObjID);
	bs->Read<int32_t>(inventoryType);
	bs->Read<int32_t>(responseCode);
	bs->Read<int32_t>(slot);
}

void ClientGameMessages::RemoveItemFromInventory::Deserialize(RakNet::BitStream* bs) {
	bConfirmed = bs->ReadBit();
	bDeleteItem = bs->ReadBit();
	bOutSuccess = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int32_t>(eInvType);
	if (bs->ReadBit()) bs->Read<int32_t>(eLootTypeSource);
	extraInfo = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	forceDeletion = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int64_t>(iLootTypeSourceID);
	if (bs->ReadBit()) bs->Read<int64_t>(iObjID);
	if (bs->ReadBit()) bs->Read<int32_t>(iObjTemplate);
	if (bs->ReadBit()) bs->Read<int64_t>(iRequestingObjID);
	if (bs->ReadBit()) bs->Read<uint32_t>(iStackCount);
	if (bs->ReadBit()) bs->Read<uint32_t>(iStackRemaining);
	if (bs->ReadBit()) bs->Read<int64_t>(iSubkey);
	if (bs->ReadBit()) bs->Read<int64_t>(iTradeID);
}

void ClientGameMessages::EquipInventory::Deserialize(RakNet::BitStream* bs) {
	bIgnoreCooldown = bs->ReadBit();
	bOutSuccess = bs->ReadBit();
	bs->Read<int64_t>(itemtoequip);
}

void ClientGameMessages::UnEquipInventory::Deserialize(RakNet::BitStream* bs) {
	bEvenIfDead = bs->ReadBit();
	bIgnoreCooldown = bs->ReadBit();
	bOutSuccess = bs->ReadBit();
	bs->Read<int64_t>(itemtounequip);
	if (bs->ReadBit()) bs->Read<int64_t>(replacementObjectID);
}

void ClientGameMessages::RespondToMission::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(missionID);
	bs->Read<int64_t>(playerID);
	bs->Read<int64_t>(receiver);
	if (bs->ReadBit()) bs->Read<int32_t>(rewardItem);
}

void ClientGameMessages::ServerTerminateInteraction::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(ObjIDTerminator);
	bs->Read<uint32_t>(type);
}

void ClientGameMessages::RequestUse::Deserialize(RakNet::BitStream* bs) {
	bIsMultiInteractUse = bs->ReadBit();
	bs->Read<uint32_t>(multiInteractID);
	bs->Read<int32_t>(multiInteractType);
	bs->Read<int64_t>(object);
	secondary = bs->ReadBit();
}

void ClientGameMessages::BuyFromVendor::Deserialize(RakNet::BitStream* bs) {
	confirmed = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int32_t>(count);
	bs->Read<int32_t>(item);
}

void ClientGameMessages::SellToVendor::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int32_t>(count);
	bs->Read<int64_t>(itemObjID);
}

void ClientGameMessages::CancelDonationOnPlayer::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::AcknowledgePossession::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(possessedObjID);
}

void ClientGameMessages::RequestActivityExit::Deserialize(RakNet::BitStream* bs) {
	bUserCancel = bs->ReadBit();
	bs->Read<int64_t>(userID);
}

void ClientGameMessages::ShootingGalleryFire::Deserialize(RakNet::BitStream* bs) {
	bs->Read<NiPoint3>(targetPos);
	bs->Read<float_t>(w);
	bs->Read<float_t>(x);
	bs->Read<float_t>(y);
	bs->Read<float_t>(z);
}

void ClientGameMessages::RequestVendorStatusUpdate::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::CancelMission::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(missionID);
	resetCompleted = bs->ReadBit();
}

void ClientGameMessages::ClientItemConsumed::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(item);
}

void ClientGameMessages::UpdateShootingGalleryRotation::Deserialize(RakNet::BitStream* bs) {
	bs->Read<float_t>(angle);
	bs->Read<NiPoint3>(facing);
	bs->Read<NiPoint3>(muzzlePos);
}

void ClientGameMessages::SetTooltipFlag::Deserialize(RakNet::BitStream* bs) {
	bFlag = bs->ReadBit();
	bs->Read<int32_t>(iToolTip);
}

void ClientGameMessages::SetFlag::Deserialize(RakNet::BitStream* bs) {
	bFlag = bs->ReadBit();
	bs->Read<int32_t>(iFlagID);
}

void ClientGameMessages::HasBeenCollected::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(playerID);
}

void ClientGameMessages::DespawnPet::Deserialize(RakNet::BitStream* bs) {
	bDeletePet = bs->ReadBit();
}

void ClientGameMessages::PlayerLoaded::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(playerID);
}

void ClientGameMessages::MissionDialogueOK::Deserialize(RakNet::BitStream* bs) {
	bIsComplete = bs->ReadBit();
	bs->Read<int32_t>(iMissionState);
	bs->Read<int32_t>(missionID);
	bs->Read<int64_t>(responder);
}

void ClientGameMessages::MessageBoxRespond::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(iButton);
	identifier = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	userData = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
}

void ClientGameMessages::ChoiceBoxRespond::Deserialize(RakNet::BitStream* bs) {
	buttonIdentifier = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	bs->Read<int32_t>(iButton);
	identifier = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
}

void ClientGameMessages::UseNonEquipmentItem::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(itemToUse);
}

void ClientGameMessages::FetchModelMetadataRequest::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(context);
	bs->Read<int64_t>(objectID);
	bs->Read<int64_t>(requestorID);
	bs->Read<int64_t>(ugID);
}

void ClientGameMessages::CommandPet::Deserialize(RakNet::BitStream* bs) {
	bs->Read<NiPoint3>(GenericPosInfo);
	bs->Read<int64_t>(ObjIDSource);
	bs->Read<int32_t>(iPetCommandType);
	bs->Read<int32_t>(iTypeID);
	overrideObey = bs->ReadBit();
}

void ClientGameMessages::RequestActivitySummaryLeaderboardData::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int32_t>(gameID);
	if (bs->ReadBit()) bs->Read<int32_t>(queryType);
	if (bs->ReadBit()) bs->Read<int32_t>(resultsEnd);
	if (bs->ReadBit()) bs->Read<int32_t>(resultsStart);
	bs->Read<int64_t>(target);
	weekly = bs->ReadBit();
}

void ClientGameMessages::NotifyPet::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(ObjIDSource);
	bs->Read<int64_t>(ObjToNotifyPetAbout);
	bs->Read<int32_t>(iPetNotificationType);
}

void ClientGameMessages::StartServerPetMinigameTimer::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::ClientExitTamingMinigame::Deserialize(RakNet::BitStream* bs) {
	bVoluntaryExit = bs->ReadBit();
}

void ClientGameMessages::PetTamingMinigameResult::Deserialize(RakNet::BitStream* bs) {
	bSuccess = bs->ReadBit();
}

void ClientGameMessages::NotifyTamingBuildSuccess::Deserialize(RakNet::BitStream* bs) {
	bs->Read<NiPoint3>(BuildPosition);
}

void ClientGameMessages::RequestSetPetName::Deserialize(RakNet::BitStream* bs) {
	name = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
}

void ClientGameMessages::QueryPropertyData::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::PropertyEditorBegin::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int32_t>(distanceType);
	if (bs->ReadBit()) bs->Read<int64_t>(propertyObjectID);
	if (bs->ReadBit()) bs->Read<int32_t>(startMode);
	startPaused = bs->ReadBit();
}

void ClientGameMessages::PropertyEditorEnd::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::RequestPlatformResync::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::CinematicUpdate::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<uint32_t>(event);
	if (bs->ReadBit()) bs->Read<float_t>(overallTime);
	pathName = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	if (bs->ReadBit()) bs->Read<float_t>(pathTime);
	if (bs->ReadBit()) bs->Read<int32_t>(waypoint);
}

void ClientGameMessages::ToggleGhostReferenceOverride::Deserialize(RakNet::BitStream* bs) {
	override = bs->ReadBit();
}

void ClientGameMessages::SetGhostReferencePosition::Deserialize(RakNet::BitStream* bs) {
	bs->Read<NiPoint3>(pos);
}

void ClientGameMessages::FireEventServerSide::Deserialize(RakNet::BitStream* bs) {
	args = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	if (bs->ReadBit()) bs->Read<int32_t>(param1);
	if (bs->ReadBit()) bs->Read<int32_t>(param2);
	if (bs->ReadBit()) bs->Read<int32_t>(param3);
	bs->Read<int64_t>(senderID);
}

void ClientGameMessages::UpdateModelFromClient::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(modelID);
	bs->Read<NiPoint3>(position);
	if (bs->ReadBit()) bs->Read<NiQuaternion>(rotation);
}

void ClientGameMessages::DeleteModelFromClient::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(modelID);
	if (bs->ReadBit()) bs->Read<uint32_t>(reason);
}

void ClientGameMessages::EnterProperty1::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(index);
	returnToZone = bs->ReadBit();
}

void ClientGameMessages::PropertyEntranceSync::Deserialize(RakNet::BitStream* bs) {
	bIncludeNullAddress = bs->ReadBit();
	bIncludeNullDescription = bs->ReadBit();
	bPlayersOwn = bs->ReadBit();
	bUpdateUI = bs->ReadBit();
	bs->Read<int32_t>(lNumResults);
	bs->Read<int32_t>(lReputationTime);
	bs->Read<int32_t>(lSortMethod);
	bs->Read<int32_t>(lStartIndex);
	sfilterText = Utils::StringFromBitStream<uint32_t>(bs); // utf-8 string
}

void ClientGameMessages::ParseChatMessage::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(iClientState);
	wsString = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
}

void ClientGameMessages::SetMissionTypeState::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<uint32_t>(state);
	subtype = Utils::StringFromBitStream<uint32_t>(bs); // utf-8 string
	type = Utils::StringFromBitStream<uint32_t>(bs); // utf-8 string
}

void ClientGameMessages::ClientTradeRequest::Deserialize(RakNet::BitStream* bs) {
	bNeedInvitePopUp = bs->ReadBit();
	bs->Read<int64_t>(i64Invitee);
}

void ClientGameMessages::ClientTradeCancel::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::ClientTradeAccept::Deserialize(RakNet::BitStream* bs) {
	bFirst = bs->ReadBit();
}

void ClientGameMessages::ReadyForUpdates::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(objectID);
}

void ClientGameMessages::SetLastCustomBuild::Deserialize(RakNet::BitStream* bs) {
	tokenizedLOTList = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
}

void ClientGameMessages::SetIgnoreProjectileCollision::Deserialize(RakNet::BitStream* bs) {
	bShouldIgnore = bs->ReadBit();
}

void ClientGameMessages::PropertyModerationAction::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(characterID);
	info = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	if (bs->ReadBit()) bs->Read<int32_t>(newModerationStatus);
}

void ClientGameMessages::PropertyModerationStatusUpdate::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int32_t>(newModerationStatus);
	rejectionReason = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
}

void ClientGameMessages::BounceNotification::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(ObjIDBounced);
	bs->Read<int64_t>(ObjIDBouncer);
	bSuccess = bs->ReadBit();
}

void ClientGameMessages::MoveInventoryBatch::Deserialize(RakNet::BitStream* bs) {
	bAllowPartial = bs->ReadBit();
	bOutSuccess = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<uint32_t>(count);
	if (bs->ReadBit()) bs->Read<int32_t>(dstBag);
	if (bs->ReadBit()) bs->Read<int32_t>(moveLOT);
	if (bs->ReadBit()) bs->Read<int64_t>(moveSubkey);
	showFlyingLoot = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int32_t>(srcBag);
	if (bs->ReadBit()) bs->Read<int64_t>(startObjectID);
}

void ClientGameMessages::SetBBBAutosave::Deserialize(RakNet::BitStream* bs) {
	bs->Read<uint32_t>(SizeOflxfmlDataCompressed);
	lxfmlDataCompressed = (char*)malloc((size_t)SizeOflxfmlDataCompressed);
	bs->Read((char*)lxfmlDataCompressed, SizeOflxfmlDataCompressed);
}

void ClientGameMessages::BBBLoadItemRequest::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(itemID);
}

void ClientGameMessages::BBBSaveRequest::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(localID);
	bs->Read<uint32_t>(SizeOflxfmlDataCompressed);
	lxfmlDataCompressed = (char*)malloc((size_t)SizeOflxfmlDataCompressed);
	bs->Read((char*)lxfmlDataCompressed, SizeOflxfmlDataCompressed);
	bs->Read<uint32_t>(timeTakenInMS);
}

void ClientGameMessages::BBBResetMetadataSourceItem::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::ZoneSummaryDismissed::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(playerID);
}

void ClientGameMessages::ModifyPlayerZoneStatistic::Deserialize(RakNet::BitStream* bs) {
	bSet = bs->ReadBit();
	statName = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	if (bs->ReadBit()) bs->Read<int32_t>(statValue);
	if (bs->ReadBit()) bs->Read<uint16_t>(zoneID);
}

void ClientGameMessages::ActivityStateChangeRequest::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(i64ObjID);
	bs->Read<int32_t>(iNumValue1);
	bs->Read<int32_t>(iNumValue2);
	wsStringValue = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
}

void ClientGameMessages::StartBuildingWithItem::Deserialize(RakNet::BitStream* bs) {
	bFirstTime = bs->ReadBit();
	bSuccess = bs->ReadBit();
	bs->Read<int32_t>(sourceBAG);
	bs->Read<int64_t>(sourceID);
	bs->Read<int32_t>(sourceLOT);
	bs->Read<int32_t>(sourceTYPE);
	bs->Read<int64_t>(targetID);
	bs->Read<int32_t>(targetLOT);
	bs->Read<NiPoint3>(targetPOS);
	bs->Read<int32_t>(targetTYPE);
}

void ClientGameMessages::DoneArrangingWithItem::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(newSourceBAG);
	bs->Read<int64_t>(newSourceID);
	bs->Read<int32_t>(newSourceLOT);
	bs->Read<int32_t>(newSourceTYPE);
	bs->Read<int64_t>(newTargetID);
	bs->Read<int32_t>(newTargetLOT);
	bs->Read<int32_t>(newTargetTYPE);
	bs->Read<NiPoint3>(newtargetPOS);
	bs->Read<int32_t>(oldItemBAG);
	bs->Read<int64_t>(oldItemID);
	bs->Read<int32_t>(oldItemLOT);
	bs->Read<int32_t>(oldItemTYPE);
}

void ClientGameMessages::SetBuildMode::Deserialize(RakNet::BitStream* bs) {
	bStart = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int32_t>(distanceType);
	modePaused = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int32_t>(modeValue);
	bs->Read<int64_t>(playerID);
	if (bs->ReadBit()) bs->Read<NiPoint3>(startPos);
}

void ClientGameMessages::BuildModeSet::Deserialize(RakNet::BitStream* bs) {
	bStart = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int32_t>(distanceType);
	modePaused = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<int32_t>(modeValue);
	bs->Read<int64_t>(playerID);
	if (bs->ReadBit()) bs->Read<NiPoint3>(startPos);
}

void ClientGameMessages::BuildExitConfirmation::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(playerID);
}

void ClientGameMessages::MoveItemBetweenInventoryTypes::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(inventoryTypeA);
	bs->Read<int32_t>(inventoryTypeB);
	bs->Read<int64_t>(objectID);
	showFlyingLoot = bs->ReadBit();
	if (bs->ReadBit()) bs->Read<uint32_t>(stackCount);
	if (bs->ReadBit()) bs->Read<int32_t>(templateID);
}

void ClientGameMessages::MissionDialogueCancelled::Deserialize(RakNet::BitStream* bs) {
	bIsComplete = bs->ReadBit();
	bs->Read<int32_t>(iMissionState);
	bs->Read<int32_t>(missionID);
	bs->Read<int64_t>(responder);
}

void ClientGameMessages::ModuleAssemblyQueryData::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::SyncSkill::Deserialize(RakNet::BitStream* bs) {
	bDone = bs->ReadBit();
	sBitStream = Utils::StringFromBitStream<uint32_t>(bs); // utf-8 string
	bs->Read<uint32_t>(uiBehaviorHandle);
	bs->Read<uint32_t>(uiSkillHandle);
}

void ClientGameMessages::RequestServerProjectileImpact::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(i64LocalID);
	if (bs->ReadBit()) bs->Read<int64_t>(i64TargetID);
	sBitStream = Utils::StringFromBitStream<uint32_t>(bs); // utf-8 string
}

void ClientGameMessages::ToggleSendingPositionUpdates::Deserialize(RakNet::BitStream* bs) {
	bSendUpdates = bs->ReadBit();
}

void ClientGameMessages::PlacePropertyModel::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(modelID);
}

void ClientGameMessages::ResyncEquipment::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::RacingPlayerInfoResetFinished::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(playerID);
}

void ClientGameMessages::VehicleSetWheelLockState::Deserialize(RakNet::BitStream* bs) {
	bExtraFriction = bs->ReadBit();
	bLocked = bs->ReadBit();
}

void ClientGameMessages::PropertyContentsFromClient::Deserialize(RakNet::BitStream* bs) {
	queryDB = bs->ReadBit();
}

void ClientGameMessages::VehicleNotifyServerAddPassiveBoostAction::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::VehicleNotifyServerRemovePassiveBoostAction::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::ZonePropertyModelRotated::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(playerID);
	if (bs->ReadBit()) bs->Read<int64_t>(propertyID);
}

void ClientGameMessages::ZonePropertyModelRemovedWhileEquipped::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(playerID);
	if (bs->ReadBit()) bs->Read<int64_t>(propertyID);
}

void ClientGameMessages::ZonePropertyModelEquipped::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(playerID);
	if (bs->ReadBit()) bs->Read<int64_t>(propertyID);
}

void ClientGameMessages::RacingClientReady::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(playerID);
}

void ClientGameMessages::ResetPropertyBehaviors::Deserialize(RakNet::BitStream* bs) {
	bForce = bs->ReadBit();
	bPause = bs->ReadBit();
}

void ClientGameMessages::SetConsumableItem::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int32_t>(itemTemplateID);
}

void ClientGameMessages::UsedInformationPlaque::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(i64Plaque);
}

void ClientGameMessages::ActivateBrickMode::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(buildObjectID);
	if (bs->ReadBit()) bs->Read<uint32_t>(buildType);
	enterBuildFromWorld = bs->ReadBit();
	enterFlag = bs->ReadBit();
}

void ClientGameMessages::CancelRailMovement::Deserialize(RakNet::BitStream* bs) {
	bImmediate = bs->ReadBit();
}

void ClientGameMessages::ClientRailMovementReady::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::PlayerRailArrivedNotification::Deserialize(RakNet::BitStream* bs) {
	pathName = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	bs->Read<int32_t>(waypointNumber);
}

void ClientGameMessages::RequestRailActivatorState::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::ModifyGhostingDistance::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<float_t>(fDistanceScalar);
}

void ClientGameMessages::ModularAssemblyNIFCompleted::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(objectID);
}

void ClientGameMessages::GetHotPropertyData::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::NotifyPropertyOfEditMode::Deserialize(RakNet::BitStream* bs) {
	bEditingActive = bs->ReadBit();
}

void ClientGameMessages::UpdatePropertyPerformanceCost::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<float_t>(performanceCost);
}

void ClientGameMessages::SetEmotesEnabled::Deserialize(RakNet::BitStream* bs) {
	bEnableEmotes = bs->ReadBit();
}

void ClientGameMessages::VehicleNotifyHitImaginationServer::Deserialize(RakNet::BitStream* bs) {
	if (bs->ReadBit()) bs->Read<int64_t>(pickupObjID);
	if (bs->ReadBit()) bs->Read<int64_t>(pickupSpawnerID);
	if (bs->ReadBit()) bs->Read<int32_t>(pickupSpawnerIndex);
	if (bs->ReadBit()) bs->Read<NiPoint3>(vehiclePosition);
}

void ClientGameMessages::CelebrationCompleted::Deserialize(RakNet::BitStream* bs) {
	animation = Utils::WStringFromBitStream<uint32_t>(bs); // utf-16 string
	if (bs->ReadBit()) bs->Read<int32_t>(celebrationID);
}

void ClientGameMessages::NotifyServerLevelProcessingComplete::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::ServerCancelMoveSkill::Deserialize(RakNet::BitStream* bs) {
}

void ClientGameMessages::DismountComplete::Deserialize(RakNet::BitStream* bs) {
	bs->Read<int64_t>(mountID);
}

