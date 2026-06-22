#include <stdio.h>
#include <objc/runtime.h>
#include <objc/message.h>

#include "print.h"

extern int UIApplicationMain(
	int argc,
	char** argv,
	id principalClassName,
	id delegateClassName
);

typedef id (*f_stringWithUTF8String)(id, SEL, const char * source);
typedef BOOL (*f_containsString)(id, SEL, id other_NSString);

typedef id (*f_noArgs)(id, SEL);
typedef uint32_t (*f_noArgs32)(id, SEL);

id getProperty(id object, const char* property_name) {
	SEL getter_selector = sel_registerName(property_name);
	return ((f_noArgs)objc_msgSend)(object, getter_selector);
}

uint32_t getProperty32(id object, const char* property_name) {
	SEL getter_selector = sel_registerName(property_name);
	return ((f_noArgs32)objc_msgSend)(object, getter_selector);
}

BOOL didFinishLaunch(id self, SEL _cmd, id application, id options) {
	print_s("inside did finish launch");
	print_class(object_getClass(self));
	print_class(object_getClass(application));
	print_class(object_getClass(options));

	print_class(object_getClass(getProperty(application, "delegate")));
	print_u32(getProperty32(application, "applicationState"));
	print_u32(getProperty32(application, "backgroundRefreshStatus"));

	return true;
}

int main(const int argc, char** argv) {
	log_init();
	print_banner();

	Class NSString = objc_getClass("NSString");
	print_class(NSString);

	Class UIResponder = objc_getClass("UIResponder");
	print_class(UIResponder);

	if (UIResponder == nil) {
		print_s("NO UIResponder");
	}

	Class AppDelegate = objc_allocateClassPair(UIResponder, "AppDelegate", 0);
	Protocol* UIApplicationDelegate = objc_getProtocol("UIApplicationDelegate");
	if (class_addProtocol(AppDelegate, UIApplicationDelegate)) {
		print_s("Protocol YES");
	}
	else {
		print_s("Protocol NO");
	}
	if (class_conformsToProtocol(AppDelegate, UIApplicationDelegate)) {
		print_s("Protocol YES");
	}
	else {
		print_s("Protocol NO");
	}

	SEL didFinishLaunch_sel = sel_registerName("application:didFinishLaunchingWithOptions:");
	class_addMethod(AppDelegate, didFinishLaunch_sel, (IMP) didFinishLaunch, "c@:@@");


	objc_registerClassPair(AppDelegate);
	print_class(AppDelegate);

	SEL stringWithUTF8String_sel = sel_registerName("stringWithUTF8String:");
	f_stringWithUTF8String stringWithUTF8String = (f_stringWithUTF8String)objc_msgSend;

	id string_AppDelegate = stringWithUTF8String((id)NSString, stringWithUTF8String_sel, "AppDelegate");

	UIApplicationMain(argc, argv, nil, string_AppDelegate);

	print_s("After main");
	while (1) {}

	return 0;
}
