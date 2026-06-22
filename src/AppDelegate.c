#include "AppDelegate.h"

#include <objc/runtime.h>

#include "print.h"
#include "props.h"

#define APP_DELEGATE_CLASS_NAME "AppDelegate"

BOOL didFinishLaunch(id self, SEL _cmd, id application, id options) {
	print_s("inside did finish launch");
	print_class(object_getClass(self));
	print_class(object_getClass(application));
	print_class(object_getClass(options));

	print_class(object_getClass(prop_get_obj(application, "delegate")));
	print_u32(prop_get_long(application, "applicationState"));
	print_u32(prop_get_long(application, "backgroundRefreshStatus"));
	print_class(object_getClass(prop_get_obj(self, "inputAssistantItem")));

	print_s("boolz");
	print_bool(prop_get_bool(self, "isFirstResponder"));
	print_bool(prop_get_bool(self, "canBecomeFirstResponder"));

	return true;
}

void touchesBegan_withEvent(id self, SEL _cmd, id touches_set, id event) {
	print_s("touches began");
	print_class(object_getClass(touches_set));
	print_class(object_getClass(event));
}

NSString AppDelegate_class_setup() {
	Class class = objc_allocateClassPair(
		objc_getClass("UIResponder"),
		APP_DELEGATE_CLASS_NAME,
		0
	);

	SEL didFinishLaunch_sel = sel_registerName("application:didFinishLaunchingWithOptions:");
	class_addMethod(class, didFinishLaunch_sel, (IMP) didFinishLaunch, "c@:@@");

	SEL touchesBegan_withEvent_sel = sel_registerName("touchesBegan:withEvent:");
	class_addMethod(class, touchesBegan_withEvent_sel, (IMP) touchesBegan_withEvent, "v@:@@");

	objc_registerClassPair(class);
	return NSString_make(APP_DELEGATE_CLASS_NAME);
}
