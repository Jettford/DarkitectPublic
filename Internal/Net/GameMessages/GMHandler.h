#pragma once

#include "ClientGMs.h"

namespace ClientGameMessages {
	void HandleGameMessage(Entity* Sender, RakNet::BitStream* bs) {
		Entity* Target = Sender->m_Server->m_ReplicaManager->GetObjectByObjectID(bs->Read<LWOOBJID>().second);
		uint16_t MsgID = bs->Read<uint16_t>().second;
		switch (MsgID) {
		case 38:
		{
			RequestDie msg = RequestDie();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 41:
		{
			PlayEmote msg = PlayEmote();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 119:
		{
			StartSkill msg = StartSkill();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 120:
		{
			CasterDead msg = CasterDead();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 121:
		{
			VerifyAck msg = VerifyAck();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 124:
		{
			SelectSkill msg = SelectSkill();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 128:
		{
			RemoveSkill msg = RemoveSkill();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 137:
		{
			PickupCurrency msg = PickupCurrency();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 139:
		{
			PickupItem msg = PickupItem();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 159:
		{
			RequestResurrect msg = RequestResurrect();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 192:
		{
			PopEquippedItemsState msg = PopEquippedItemsState();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 209:
		{
			RebuildCancel msg = RebuildCancel();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 224:
		{
			MoveItemInInventory msg = MoveItemInInventory();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 230:
		{
			RemoveItemFromInventory msg = RemoveItemFromInventory();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 231:
		{
			EquipInventory msg = EquipInventory();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 233:
		{
			UnEquipInventory msg = UnEquipInventory();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 249:
		{
			RespondToMission msg = RespondToMission();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 358:
		{
			ServerTerminateInteraction msg = ServerTerminateInteraction();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 364:
		{
			RequestUse msg = RequestUse();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 373:
		{
			BuyFromVendor msg = BuyFromVendor();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 374:
		{
			SellToVendor msg = SellToVendor();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 379:
		{
			CancelDonationOnPlayer msg = CancelDonationOnPlayer();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 391:
		{
			AcknowledgePossession msg = AcknowledgePossession();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 404:
		{
			RequestActivityExit msg = RequestActivityExit();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 411:
		{
			ShootingGalleryFire msg = ShootingGalleryFire();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 416:
		{
			RequestVendorStatusUpdate msg = RequestVendorStatusUpdate();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 418:
		{
			CancelMission msg = CancelMission();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 428:
		{
			ClientItemConsumed msg = ClientItemConsumed();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 448:
		{
			UpdateShootingGalleryRotation msg = UpdateShootingGalleryRotation();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 469:
		{
			SetTooltipFlag msg = SetTooltipFlag();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 471:
		{
			SetFlag msg = SetFlag();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 486:
		{
			HasBeenCollected msg = HasBeenCollected();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 499:
		{
			DespawnPet msg = DespawnPet();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 505:
		{
			PlayerLoaded msg = PlayerLoaded();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 520:
		{
			MissionDialogueOK msg = MissionDialogueOK();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 530:
		{
			MessageBoxRespond msg = MessageBoxRespond();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 531:
		{
			ChoiceBoxRespond msg = ChoiceBoxRespond();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 603:
		{
			UseNonEquipmentItem msg = UseNonEquipmentItem();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 638:
		{
			FetchModelMetadataRequest msg = FetchModelMetadataRequest();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 640:
		{
			CommandPet msg = CommandPet();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 648:
		{
			RequestActivitySummaryLeaderboardData msg = RequestActivitySummaryLeaderboardData();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 660:
		{
			NotifyPet msg = NotifyPet();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 662:
		{
			StartServerPetMinigameTimer msg = StartServerPetMinigameTimer();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 663:
		{
			ClientExitTamingMinigame msg = ClientExitTamingMinigame();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 667:
		{
			PetTamingMinigameResult msg = PetTamingMinigameResult();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 673:
		{
			NotifyTamingBuildSuccess msg = NotifyTamingBuildSuccess();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 683:
		{
			RequestSetPetName msg = RequestSetPetName();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 717:
		{
			QueryPropertyData msg = QueryPropertyData();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 724:
		{
			PropertyEditorBegin msg = PropertyEditorBegin();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 725:
		{
			PropertyEditorEnd msg = PropertyEditorEnd();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 760:
		{
			RequestPlatformResync msg = RequestPlatformResync();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 764:
		{
			CinematicUpdate msg = CinematicUpdate();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 767:
		{
			ToggleGhostReferenceOverride msg = ToggleGhostReferenceOverride();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 768:
		{
			SetGhostReferencePosition msg = SetGhostReferencePosition();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 770:
		{
			FireEventServerSide msg = FireEventServerSide();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 793:
		{
			UpdateModelFromClient msg = UpdateModelFromClient();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 794:
		{
			DeleteModelFromClient msg = DeleteModelFromClient();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 840:
		{
			EnterProperty1 msg = EnterProperty1();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 842:
		{
			PropertyEntranceSync msg = PropertyEntranceSync();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 850:
		{
			ParseChatMessage msg = ParseChatMessage();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 851:
		{
			SetMissionTypeState msg = SetMissionTypeState();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 868:
		{
			ClientTradeRequest msg = ClientTradeRequest();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 878:
		{
			ClientTradeCancel msg = ClientTradeCancel();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 880:
		{
			ClientTradeAccept msg = ClientTradeAccept();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 888:
		{
			ReadyForUpdates msg = ReadyForUpdates();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 890:
		{
			SetLastCustomBuild msg = SetLastCustomBuild();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 903:
		{
			SetIgnoreProjectileCollision msg = SetIgnoreProjectileCollision();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 915:
		{
			PropertyModerationAction msg = PropertyModerationAction();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 917:
		{
			PropertyModerationStatusUpdate msg = PropertyModerationStatusUpdate();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 932:
		{
			BounceNotification msg = BounceNotification();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 957:
		{
			MoveInventoryBatch msg = MoveInventoryBatch();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 996:
		{
			SetBBBAutosave msg = SetBBBAutosave();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1000:
		{
			BBBLoadItemRequest msg = BBBLoadItemRequest();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1001:
		{
			BBBSaveRequest msg = BBBSaveRequest();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1004:
		{
			BBBResetMetadataSourceItem msg = BBBResetMetadataSourceItem();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1044:
		{
			ZoneSummaryDismissed msg = ZoneSummaryDismissed();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1046:
		{
			ModifyPlayerZoneStatistic msg = ModifyPlayerZoneStatistic();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1053:
		{
			ActivityStateChangeRequest msg = ActivityStateChangeRequest();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1057:
		{
			StartBuildingWithItem msg = StartBuildingWithItem();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1063:
		{
			DoneArrangingWithItem msg = DoneArrangingWithItem();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1068:
		{
			SetBuildMode msg = SetBuildMode();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1069:
		{
			BuildModeSet msg = BuildModeSet();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1072:
		{
			BuildExitConfirmation msg = BuildExitConfirmation();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1093:
		{
			MoveItemBetweenInventoryTypes msg = MoveItemBetweenInventoryTypes();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1129:
		{
			MissionDialogueCancelled msg = MissionDialogueCancelled();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1132:
		{
			ModuleAssemblyQueryData msg = ModuleAssemblyQueryData();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1145:
		{
			SyncSkill msg = SyncSkill();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1148:
		{
			RequestServerProjectileImpact msg = RequestServerProjectileImpact();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1166:
		{
			ToggleSendingPositionUpdates msg = ToggleSendingPositionUpdates();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1170:
		{
			PlacePropertyModel msg = PlacePropertyModel();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1238:
		{
			ResyncEquipment msg = ResyncEquipment();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1255:
		{
			RacingPlayerInfoResetFinished msg = RacingPlayerInfoResetFinished();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1273:
		{
			VehicleSetWheelLockState msg = VehicleSetWheelLockState();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1305:
		{
			PropertyContentsFromClient msg = PropertyContentsFromClient();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1342:
		{
			VehicleNotifyServerAddPassiveBoostAction msg = VehicleNotifyServerAddPassiveBoostAction();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1343:
		{
			VehicleNotifyServerRemovePassiveBoostAction msg = VehicleNotifyServerRemovePassiveBoostAction();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1370:
		{
			ZonePropertyModelRotated msg = ZonePropertyModelRotated();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1371:
		{
			ZonePropertyModelRemovedWhileEquipped msg = ZonePropertyModelRemovedWhileEquipped();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1372:
		{
			ZonePropertyModelEquipped msg = ZonePropertyModelEquipped();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1393:
		{
			RacingClientReady msg = RacingClientReady();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1406:
		{
			ResetPropertyBehaviors msg = ResetPropertyBehaviors();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1409:
		{
			SetConsumableItem msg = SetConsumableItem();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1419:
		{
			UsedInformationPlaque msg = UsedInformationPlaque();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1438:
		{
			ActivateBrickMode msg = ActivateBrickMode();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1474:
		{
			CancelRailMovement msg = CancelRailMovement();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1476:
		{
			ClientRailMovementReady msg = ClientRailMovementReady();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1477:
		{
			PlayerRailArrivedNotification msg = PlayerRailArrivedNotification();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1479:
		{
			RequestRailActivatorState msg = RequestRailActivatorState();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1485:
		{
			ModifyGhostingDistance msg = ModifyGhostingDistance();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1498:
		{
			ModularAssemblyNIFCompleted msg = ModularAssemblyNIFCompleted();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1511:
		{
			GetHotPropertyData msg = GetHotPropertyData();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1546:
		{
			NotifyPropertyOfEditMode msg = NotifyPropertyOfEditMode();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1547:
		{
			UpdatePropertyPerformanceCost msg = UpdatePropertyPerformanceCost();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1577:
		{
			SetEmotesEnabled msg = SetEmotesEnabled();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1606:
		{
			VehicleNotifyHitImaginationServer msg = VehicleNotifyHitImaginationServer();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1632:
		{
			CelebrationCompleted msg = CelebrationCompleted();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1734:
		{
			NotifyServerLevelProcessingComplete msg = NotifyServerLevelProcessingComplete();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1746:
		{
			ServerCancelMoveSkill msg = ServerCancelMoveSkill();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}
		case 1756:
		{
			DismountComplete msg = DismountComplete();
			msg.Deserialize(bs);
			Target->HandleGM(Sender, MsgID, &msg);
			break;
		}

		}
	}
}