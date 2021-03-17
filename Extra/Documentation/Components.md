# Components

Some boiler plate code for Component classes

```cpp
#pragma once

#include "../Component.h"

class ComponentName : public Component {
private:
	
public:
	void Start(uint32_t ComponentID) override {
		
	}

	void Serialize(RakNet::BitStream* bs, bool IsConstruction) override {
		
	}

	constexpr static uint32_t GetID() {
		return (uint32_t)ComponentID; // Example: Enums::ECOMPONENT_TYPE::VENDOR_COMPONENT
	}
};
```