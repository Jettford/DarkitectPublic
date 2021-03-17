CREATE TABLE IF NOT EXISTS Missions (
	id int NOT NULL AUTO_INCREMENT,
	MissionID int NOT NULL,
	State int NOT NULL default 2,
	CompletionCount int NOT NULL default 0,
	LastCompletion bigint NOT NULL default 0,
	MissionOwner bigint NOT NULL,
	PRIMARY KEY (id)
);