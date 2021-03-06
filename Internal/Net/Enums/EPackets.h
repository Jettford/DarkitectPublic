#pragma once

#include <memory>

namespace Enums {
	enum class EServerPacketID : uint32_t {
		VERSION_CONFIRM = 0,
		DISCONNECT_NOTIFY,
		GENERAL_NOTIFY
	};

	enum class EChatPacketID : uint32_t {
		LOGIN_SESSION_NOTIFY = 0,
		GENERAL_CHAT_MESSAGE,
		PRIVATE_CHAT_MESSAGE,
		USER_CHANNEL_CHAT_MESSAGE,
		WORLD_DISCONNECT_REQUEST,
		WORLD_PROXIMITY_RESPONSE,
		WORLD_PARCEL_RESPONSE,
		ADD_FRIEND_REQUEST,
		ADD_FRIEND_RESPONSE,
		REMOVE_FRIEND,
		GET_FRIENDS_LIST,
		ADD_IGNORE,
		REMOVE_IGNORE,
		GET_IGNORE_LIST,
		TEAM_MISSED_INVITE_CHECK,
		TEAM_INVITE,
		TEAM_INVITE_RESPONSE,
		TEAM_KICK,
		TEAM_LEAVE,
		TEAM_SET_LOOT,
		TEAM_SET_LEADER,
		TEAM_GET_STATUS,
		GUILD_CREATE,
		GUILD_INVITE,
		GUILD_INVITE_RESPONSE,
		GUILD_LEAVE,
		GUILD_KICK,
		GUILD_GET_STATUS,
		GUILD_GET_ALL,
		SHOW_ALL,
		BLUEPRINT_MODERATED,
		BLUEPRINT_MODEL_READY,
		PROPERTY_READY_FOR_APPROVAL,
		PROPERTY_MODERATION_CHANGED,
		PROPERTY_BUILDMODE_CHANGED,
		PROPERTY_BUILDMODE_CHANGED_REPORT,
		MAIL,
		WORLD_INSTANCE_LOCATION_REQUEST,
		REPUTATION_UPDATE,
		SEND_CANNED_TEXT,
		GMLEVEL_UPDATE,
		CHARACTER_NAME_CHANGE_REQUEST,
		CSR_REQUEST,
		CSR_REPLY,
		GM_KICK,
		GM_ANNOUCE,
		GM_MUTE,
		ACTIVITY_UPDATE,
		WORLD_ROUTE_PACKET,
		GET_ZONE_POPULATIONS,
		REQUEST_MINIMUM_CHAT_MODE,
		REQUEST_MINIMUM_CHAT_MODE_PRIVATE,
		MATCH_REQUEST,
		UGCMANIFEST_REPORT_MISSING_FILE,
		UGCMANIFEST_REPORT_DONE_FILE,
		UGCMANIFEST_REPORT_DONE_BLUEPRINT,
		UGCC_REQUEST,
		WHO,
		WORLD_PLAYERS_PET_MODERATED_ACKNOWLEDGE,
		ACHIEVEMENT_NOTIFY,
		GM_CLOSE_PRIVATE_CHAT_WINDOW,
		UNEXPECTED_DISCONNECT,
		PLAYER_READY,
		GET_DONATION_TOTAL,
		UPDATE_DONATION,
		PRG_CSR_COMMAND,
		HEARTBEAT_REQUEST_FROM_WORLD,
		UPDATE_FREE_TRIAL_STATUS
	};

	enum class EAuthPacketID : uint32_t {
		LOGIN_RESPONSE = 0,
		LOGOUT_REQUEST,
		CREATE_NEW_ACCOUNT_REQUEST,
		LEGOINTERFACE_AUTH_RESPONSE,
		SESSIONKEY_RECIEVED_CONFIRM,
		RUNTIME_CONFIG
	};

	enum class EWorldPacketID : uint32_t {
		CLIENT_VALIDATION = 1,
		CLIENT_CHARACTER_LIST_REQUEST,
		CLIENT_CHARACTER_CREATE_REQUEST,
		CLIENT_LOGIN_REQUEST,
		CLIENT_GAME_MSG,
		CLIENT_CHARACTER_DELETE_REQUEST,
		CLIENT_CHARACTER_RENAME_REQUEST,
		CLIENT_HAPPY_FLOWER_MODE_NOTIFY,
		CLIENT_SLASH_RELOAD_MAP,
		CLIENT_SLASH_PUSH_MAP_REQUEST,
		CLIENT_SLASH_PUSH_MAP,
		CLIENT_SLASH_PULL_MAP,
		CLIENT_LOCK_MAP_REQUEST,
		CLIENT_GENERAL_CHAT_MESSAGE,
		CLIENT_HTTP_MONITOR_INFO_REQUEST,
		CLIENT_SLASH_DEBUG_SCRIPTS,
		CLIENT_MODELS_CLEAR,
		CLIENT_EXIBIT_INSERT_MODEL,
		CLIENT_LEVEL_LOAD_COMPLETE,
		CLIENT_TMP_GUILD_CREATE,
		CLIENT_ROUTE_PACKET,
		CLIENT_POSITION_UPDATE,
		CLIENT_MAIL,
		CLIENT_WORD_CHECK,
		CLIENT_STRING_CHECK,
		CLIENT_GET_PLAYERS_IN_ZONE,
		CLIENT_REQUEST_UGC_MANIFEST_INFO,
		CLIENT_BLUEPRINT_GET_ALL_DATA_REQUEST,
		CLIENT_CANCEL_MAP_QUEUE,
		CLIENT_HANDLE_FUNNESS,
		CLIENT_FAKE_PRG_CSR_MESSAGE,
		CLIENT_REQUEST_FREE_TRIAL_REFRESH,
		CLIENT_GM_SET_FREE_TRIAL_STATUS,
		UGC_DOWNLOAD_FAILED = 120,
		CLIENT_SURVEY = 32,
		SERVER_STATES = 52
	};

	enum class EClientPacketID : uint32_t {
		MSG_CLIENT_LOAD_STATIC_ZONE = 0x02,
		CHARACTER_LIST = 0x06,
		CHARACTER_CREATION_RESPONSE,
		SERVER_GAME_MSG = 12,
		SERVER_REDIRECT = 14,
		FRIEND_REQUEST = 27,
		FRIEND_REQUEST_RESPONSE = 28,
		FRIENDS_LIST = 30,
		FRIEND_UPDATE = 31,
		MAIL_STUFF = 49
	};

	enum class EMasterPacketID : uint32_t {
		CLIENT_HELLO_MASTER = 0x00,
	};
}