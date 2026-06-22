#include <stdio.h>
#include <objc/runtime.h>
#include <objc/message.h>

#include "NSString.h"
#include "print.h"
#include "props.h"

extern int UIApplicationMain(
	int argc,
	char** argv,
	id principalClassName,
	id delegateClassName
);

BOOL didFinishLaunch(id self, SEL _cmd, id application, id options) {
	print_s("inside did finish launch");
	print_class(object_getClass(self));
	print_class(object_getClass(application));
	print_class(object_getClass(options));

	print_class(object_getClass(prop_get_obj(application, "delegate")));
	print_u32(prop_get_long(application, "applicationState"));
	print_u32(prop_get_long(application, "backgroundRefreshStatus"));
	print_class(object_getClass(prop_get_obj(application, "inputAssistantItem")));

	return true;
}

int main(const int argc, char** argv) {
	log_init();
	print_banner();

	Class UIResponder = objc_getClass("UIResponder");
	print_class(UIResponder);

	if (UIResponder == nil) {
		print_s("NO UIResponder");
	}

	Class AppDelegate = objc_allocateClassPair(UIResponder, "AppDelegate", 0);

	SEL didFinishLaunch_sel = sel_registerName("application:didFinishLaunchingWithOptions:");
	class_addMethod(AppDelegate, didFinishLaunch_sel, (IMP) didFinishLaunch, "c@:@@");


	objc_registerClassPair(AppDelegate);
	print_class(AppDelegate);


	UIApplicationMain(argc, argv, nil, NSString_make("AppDelegate"));
}
