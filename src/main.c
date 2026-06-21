#include <objc/runtime.h>
#include <objc/message.h>

#include "print.h"

extern int UIApplicationMain(
	int argc,
	char** argv,
	id principalClassName,
	id delegateClassName
);

int main(const int argc, char** argv) {
	print_s("---START---");
	print_args(argc, argv);

	Class NSString = objc_getClass("NSString");
	print_class(NSString);

	Class UIResponder = objc_getClass("UIResponder");
	print_class(UIResponder);

	Class AppDelegate = objc_allocateClassPair(UIResponder, "AppDelegate", 0);
	print_class(AppDelegate);

	UIApplicationMain(argc, argv, nil, nil);

	print_s("After main");
	while (1) {}

	return 0;
}
