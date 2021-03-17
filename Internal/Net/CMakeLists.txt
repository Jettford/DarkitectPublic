add_library(Net STATIC AuthPackets.cpp 
		AuthPackets.h
		CharPackets.cpp
		CharPackets.h
		Enums/EComponents.h
		Enums/ELoginReturnCode.h
		Enums/EPackets.h
		Enums/ERemoteConnection.h
		Enums/EServerType.h
		GeneralPackets.cpp
		GeneralPackets.h
		GameMessages/GMs.h
		PacketHeader.h
		GameMessages/ServerGMs.cpp
		GameMessages/ServerGMs.h
		WorldPackets.cpp
		WorldPackets.h
		"GameMessages/ClientGMs.h" "GameMessages/ClientGMs.cpp" "GameMessages/GMHandler.h" "ChatPackets.cpp")