import os
import mysql.connector 

MigrationsToRun: list[str] = []

for item in os.listdir("."):
    if item.endswith(".sql"):
        MigrationsToRun.append(item.split(".")[0])
    elif item.endswith(".py"):
        pass
    else:
        print("found non sql file")
        
        
db = mysql.connector.connect(
  host="localhost",
  user="root",
  password="",
  database="darkitect"
)

cursor = db.cursor()
cursor.execute("SHOW TABLES")
FoundMigrationTable: bool = False
for x in cursor:
    print("Found table: " + x[0])
    if x[0] == "migrations":
        FoundMigrationTable = True
        
if not FoundMigrationTable:
    cursor.execute("CREATE TABLE migrations (migration TEXT)")

AlreadyRanMigrations: list[str] = []
cursor.execute("SELECT * FROM migrations")
for item in cursor:
    AlreadyRanMigrations.append(item[0])
        
for item in MigrationsToRun:
    if "migration_" + item in AlreadyRanMigrations: continue
    print("Running migration:", item)
    f = open(item + ".sql", "r")
    
    cursor.execute(f.read())
    
    cursor.execute("INSERT INTO migrations (migration) VALUES('migration_" + item + "')")
    db.commit()
    
    