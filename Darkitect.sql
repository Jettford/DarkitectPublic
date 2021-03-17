CREATE TABLE IF NOT EXISTS Accounts(
	ID int NOT NULL AUTO_INCREMENT, 
	Username text, 
	Email text, 
	Password text,
	FirstChar int,
	GMLevel int
);

CREATE TABLE IF NOT EXISTS  Characters (
	CharID int NOT NULL AUTO_INCREMENT,
	AccountID int,
	Name text,
	UnapprovedName text,
	ShirtColor int,
	ShirtStyle int,
	PantsColor int,
	HairStyle int,
	HairColor int,
	LeftHand int,
	RightHand int,
	Eyebrows int,
	Eyes int,
	Mouth int,
	LastZone int default 0,
	Health int default 4,
	MaxHealth float default 4,
	Armor int default 0,
	MaxArmor float default 0,
	Imagination int default 0,
	MaxImagination float default 0,
	InventorySpace int default 20,
	UScore int default 0,
	GMLevel int default 0,
	Reputation int default 0,
	Level int default 1,
	X float default 0.0,
	Y float default 0.0,
	Z float default 0.0,
	PRIMARY KEY (CharID)
);

CREATE TABLE IF NOT EXISTS Inventory
(
	objectID bigint,
	ownerID bigint,
	subkey bigint,
	tab int,
	slot int,
	template int,
	count int,
	attributes smallint,
	metadata text
);

CREATE TABLE IF NOT EXISTS Sessions 
(
	Username text,
	SessionKey text,
	Char int,
);

CREATE TABLE IF NOT EXISTS Servers 
(
	WorldID int,
	Port int
);