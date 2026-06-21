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

int main(const int argc, char** argv) {
	print_s("---START---");
	print_args(argc, argv);

	Class NSString = objc_getClass("NSString");
	print_class(NSString);

	Class UIResponder = objc_getClass("UIResponder");
	print_class(UIResponder);

	Class AppDelegate = objc_allocateClassPair(UIResponder, "AppDelegate", 0);
	print_class(AppDelegate);

	SEL stringWithUTF8String_sel = sel_registerName("stringWithUTF8String:");
	f_stringWithUTF8String stringWithUTF8String = (f_stringWithUTF8String)objc_msgSend;

	id string_instance = stringWithUTF8String((id)NSString, stringWithUTF8String_sel, "AppDelegate");
	id string_instance2 = stringWithUTF8String((id)NSString, stringWithUTF8String_sel, "Del");

	BOOL contains = ((f_containsString) objc_msgSend)(string_instance, sel_registerName("containsString:"), string_instance2);
	printf("contains: %d\n", contains);


	// UIApplicationMain(argc, argv, nil, nil);

	print_s("After main");
	while (1) {}

	return 0;
}
