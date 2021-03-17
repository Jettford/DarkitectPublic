//
// This is for small quick testing shit that doesn't need the server
//

#include <Common/Global.h>

#include <iostream>

int main() {
	std::cout << RandomFromRange<float>(0.0f, 2.0f) << std::endl;
	std::cout << RandomFromRange<uint32_t>(0, 20) << std::endl;
	return 0;
}