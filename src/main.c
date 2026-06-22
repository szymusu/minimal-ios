#include <stdio.h>
#include <objc/runtime.h>
#include <objc/message.h>

#include "AppDelegate.h"
#include "NSString.h"
#include "print.h"

extern int UIApplicationMain(
	int argc,
	char** argv,
	id principalClassName,
	id delegateClassName
);

int main(const int argc, char** argv) {
	log_init();
	print_banner();

	const NSString delegate_name = AppDelegate_class_setup();

	UIApplicationMain(argc, argv, nil, delegate_name);
}
