#include <objc/runtime.h>
#include <objc/message.h>
#include <os/log.h>

int main() {
	os_log(OS_LOG_DEFAULT, "chuj1");


	Class NSString = objc_getClass("NSString");
	const char* NSString_name = class_getName(NSString);
	printf("%s - %p\n", NSString_name, NSString);

	Class UIResponder = objc_getClass("UIResponder");
	const char* UIResponder_name = class_getName(UIResponder);
	printf("%s - %p\n", UIResponder_name, UIResponder);

	Class AppDelegate = objc_allocateClassPair(UIResponder, "AppDelegate", 0);
	const char* AppDelegate_name = class_getName(AppDelegate);
	printf("%s - %p\n", AppDelegate_name, AppDelegate);

	while (1) {}

	return 0;
}
