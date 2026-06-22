#include "NSString.h"

#include <objc/message.h>
#include <objc/runtime.h>

bool is_ready = false;
Class NSString_class;
SEL stringWithUTF8String_sel;

typedef id (*f_stringWithUTF8String)(id, SEL, const char * source);

void ensure_ready() {
	if (is_ready) return;

	NSString_class = objc_getClass("NSString");
	stringWithUTF8String_sel = sel_registerName("stringWithUTF8String:");
}

NSString NSString_make(const char* source) {
	ensure_ready();

	return  (
		(f_stringWithUTF8String)objc_msgSend)(
			(id)NSString_class,
			stringWithUTF8String_sel,
			source
	);
}